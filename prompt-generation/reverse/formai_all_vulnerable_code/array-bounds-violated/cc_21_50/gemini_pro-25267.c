//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFF 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <forbidden_sites_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read forbidden sites file
    FILE *f = fopen(argv[2], "r");
    if (f == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    char line[MAX_BUFF];
    char forbidden_sites[1024][MAX_BUFF];
    int num_forbidden_sites = 0;
    while (fgets(line, MAX_BUFF, f)) {
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }
        if (line[0] != '#' && strlen(line) > 0) {
            strcpy(forbidden_sites[num_forbidden_sites++], line);
        }
    }
    fclose(f);

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket to non-blocking mode
    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }
    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    // Bind the socket to the specified port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main event loop
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                perror("accept");
                return EXIT_FAILURE;
            }
            continue;
        }

        // Set client socket to non-blocking mode
        flags = fcntl(client_sockfd, F_GETFL, 0);
        if (flags == -1) {
            perror("fcntl");
            return EXIT_FAILURE;
        }
        if (fcntl(client_sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("fcntl");
            return EXIT_FAILURE;
        }

        // Read the request from the client
        char request[MAX_BUFF];
        int bytes_read = read(client_sockfd, request, MAX_BUFF - 1);
        if (bytes_read == -1) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                perror("read");
                return EXIT_FAILURE;
            }
            continue;
        }
        request[bytes_read] = '\0';

        // Check if the request is for a forbidden site
        char *hostname = strstr(request, "Host:");
        if (hostname == NULL) {
            // No Host header, close connection
            close(client_sockfd);
            continue;
        }
        hostname += 6;
        while (*hostname == ' ' || *hostname == '\t') {
            hostname++;
        }
        char *end_hostname = strchr(hostname, '\n');
        if (end_hostname == NULL) {
            // Malformed Host header, close connection
            close(client_sockfd);
            continue;
        }
        *end_hostname = '\0';

        int i;
        for (i = 0; i < num_forbidden_sites; i++) {
            if (strcmp(hostname, forbidden_sites[i]) == 0) {
                // Forbidden site, close connection
                close(client_sockfd);
                break;
            }
        }

        // If the request is not for a forbidden site, forward it to the server
        char *port = strstr(request, ":");
        if (port == NULL) {
            port = "80";
        } else {
            port[0] = '\0';
            port++;
        }

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(hostname);
        server_addr.sin_port = htons(atoi(port));

        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd == -1) {
            perror("socket");
            return EXIT_FAILURE;
        }

        // Set server socket to non-blocking mode
        flags = fcntl(server_sockfd, F_GETFL, 0);
        if (flags == -1) {
            perror("fcntl");
            return EXIT_FAILURE;
        }
        if (fcntl(server_sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
            perror("fcntl");
            return EXIT_FAILURE;
        }

        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            if (errno != EINPROGRESS) {
                perror("connect");
                return EXIT_FAILURE;
            }
        }

        // Forward the request to the server
        write(server_sockfd, request, bytes_read);

        // Read the response from the server
        char response[MAX_BUFF];
        while ((bytes_read = read(server_sockfd, response, MAX_BUFF - 1)) > 0) {
            // Forward the response to the client
            write(client_sockfd, response, bytes_read);
        }

        // Close the client and server sockets
        close(client_sockfd);
        close(server_sockfd);
    }

    // Close the listening socket
    close(sockfd);

    return EXIT_SUCCESS;
}