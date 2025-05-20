//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_CONNECTIONS 10

// A structure to represent a connection
typedef struct connection {
    int sockfd;
    struct sockaddr_in addr;
    char *hostname;
    time_t last_active;
} connection;

// An array of connections
connection connections[MAX_CONNECTIONS];

// The main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the port number and log file name
    int port = atoi(argv[1]);
    char *log_file = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set the socket options
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Open the log file
    FILE *logfile = fopen(log_file, "a");
    if (logfile == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // The main loop
    while (1) {
        // Accept a connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Get the hostname of the client
        char hostname[NI_MAXHOST];
        if (getnameinfo((struct sockaddr *)&client_addr, client_addr_len, hostname, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) != 0) {
            strcpy(hostname, "unknown");
        }

        // Add the connection to the array
        int i;
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].sockfd == 0) {
                connections[i].sockfd = client_sockfd;
                connections[i].addr = client_addr;
                connections[i].hostname = strdup(hostname);
                connections[i].last_active = time(NULL);
                break;
            }
        }

        // If the array is full, close the oldest connection
        if (i == MAX_CONNECTIONS) {
            int oldest_connection = 0;
            for (i = 1; i < MAX_CONNECTIONS; i++) {
                if (connections[i].last_active < connections[oldest_connection].last_active) {
                    oldest_connection = i;
                }
            }
            close(connections[oldest_connection].sockfd);
            free(connections[oldest_connection].hostname);
            connections[oldest_connection].sockfd = 0;
        }

        // Log the connection
        fprintf(logfile, "%s:%d connected\n", hostname, ntohs(client_addr.sin_port));
        fflush(logfile);

        // Handle the connection
        while (1) {
            // Receive data from the client
            char buffer[1024];
            int n = recv(client_sockfd, buffer, sizeof(buffer), 0);
            if (n == 0) {
                // The client has closed the connection
                break;
            } else if (n == -1) {
                perror("recv");
                break;
            }

            // Log the data
            fprintf(logfile, "%s:%d: %s", hostname, ntohs(client_addr.sin_port), buffer);
            fflush(logfile);

            // Send data back to the client
            n = send(client_sockfd, buffer, n, 0);
            if (n == -1) {
                perror("send");
                break;
            }
        }

        // Close the connection
        close(client_sockfd);

        // Log the disconnection
        fprintf(logfile, "%s:%d disconnected\n", hostname, ntohs(client_addr.sin_port));
        fflush(logfile);
    }

    // Close the log file
    fclose(logfile);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}