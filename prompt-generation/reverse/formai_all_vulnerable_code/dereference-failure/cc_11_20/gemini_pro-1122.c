//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUF 1024

struct client_info {
    int client_sockfd;
    struct sockaddr_in client_addr;
};

void *handle_client(void *arg) {
    struct client_info *info = (struct client_info *)arg;

    char buf[MAX_BUF];
    int n;

    // Request line
    n = read(info->client_sockfd, buf, MAX_BUF);
    if (n < 0) {
        perror("read");
        close(info->client_sockfd);
        free(info);
        pthread_exit(NULL);
    }

    // Parse request line
    char *method = strtok(buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    printf("Request: %s %s %s\n", method, path, version);

    // Send request to server
    struct sockaddr_in server_addr;
    int server_sockfd;
    
    if (strcmp(method, "CONNECT") == 0) {
        // Parse host and port from request
        char *host = strtok(path, ":");
        int port = atoi(strtok(NULL, ":"));

        // Create server socket
        server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            perror("socket");
            close(info->client_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Connect to server
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(host);
        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Send request to server
        n = write(server_sockfd, buf, strlen(buf));
        if (n < 0) {
            perror("write");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Receive response from server
        n = read(server_sockfd, buf, MAX_BUF);
        if (n < 0) {
            perror("read");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Send response to client
        n = write(info->client_sockfd, buf, n);
        if (n < 0) {
            perror("write");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Forward data between client and server
        while ((n = read(info->client_sockfd, buf, MAX_BUF)) > 0) {
            if (write(server_sockfd, buf, n) < 0) {
                perror("write");
                break;
            }
        }

        if (n < 0) {
            perror("read");
        }

        close(info->client_sockfd);
        close(server_sockfd);
    } else {
        // Parse host and port from request
        char *host = strtok(path, "/");
        int port = 80;

        // Create server socket
        server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            perror("socket");
            close(info->client_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Connect to server
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(host);
        if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Send request to server
        n = write(server_sockfd, buf, strlen(buf));
        if (n < 0) {
            perror("write");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Receive response from server
        n = read(server_sockfd, buf, MAX_BUF);
        if (n < 0) {
            perror("read");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        // Send response to client
        n = write(info->client_sockfd, buf, n);
        if (n < 0) {
            perror("write");
            close(info->client_sockfd);
            close(server_sockfd);
            free(info);
            pthread_exit(NULL);
        }

        close(info->client_sockfd);
        close(server_sockfd);
    }

    free(info);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd, newsockfd;
    struct sockaddr_in addr, client_addr;
    socklen_t client_addr_len;

    // Create server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind server socket to port
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept client connection
        client_addr_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Create thread to handle client
        pthread_t thread;
        struct client_info *info = malloc(sizeof(struct client_info));
        info->client_sockfd = newsockfd;
        info->client_addr = client_addr;
        if (pthread_create(&thread, NULL, handle_client, info) != 0) {
            perror("pthread_create");
            close(newsockfd);
            free(info);
            continue;
        }

        // Detach thread so it does not need to be joined
        pthread_detach(thread);
    }

    close(sockfd);

    return 0;
}