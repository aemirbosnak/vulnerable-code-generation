//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, portno, clilen;
    char buffer[BUFFER_SIZE], req_buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server running on port %d\n", SERVER_PORT);

    while (1) {
        clilen = sizeof(cli_addr);

        // accept incoming connection
        new_sockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
        if (new_sockfd < 0) {
            perror("Error accepting connection");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, BUFFER_SIZE);
        memset(req_buffer, 0, BUFFER_SIZE);

        // receive request from client
        if (recv(new_sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving data");
            exit(EXIT_FAILURE);
        }

        printf("\n***********************************\n");
        printf("REQUEST FROM CLIENT:\n%s", buffer);

        // get the URL from the request
        char *tok = strtok(buffer, "\n");
        char *url = strtok(strtok(strtok(tok, " "), "://"), "/");
        printf("URL: %s\n", url);

        // resolve the hostname using DNS
        server = gethostbyname(url);
        if (server == NULL) {
            perror("Error resolving hostname");
            exit(EXIT_FAILURE);
        }

        // Open new socket to the destination server
        int dest_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (dest_sockfd < 0) {
            perror("Error opening socket to destination");
            exit(EXIT_FAILURE);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

        // get destination port number from URL or use default port 80
        if (strstr(url, ":")) {
            portno = atoi(strtok(strstr(url, ":"), "/"));
            printf("PORT: %d\n", portno);
        } else {
            portno = 80;
        }
        serv_addr.sin_port = htons(portno);

        // connect to destination server
        if (connect(dest_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("Error connecting to destination");
            exit(EXIT_FAILURE);
        }

        // Forward the request to the server
        if (send(dest_sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending request to destination");
            exit(EXIT_FAILURE);
        }

        // Receive the response from the server
        int resp_len;
        while ((resp_len = recv(dest_sockfd, req_buffer, BUFFER_SIZE, 0)) > 0) {
            // forward response to the client
            if (send(new_sockfd, req_buffer, resp_len, 0) < 0) {
                perror("Error forwarding response to client");
                exit(EXIT_FAILURE);
            }
            memset(req_buffer, 0, BUFFER_SIZE);
        }

        // close the sockets
        close(dest_sockfd);
        close(new_sockfd);
    }

    close(sockfd);

    return 0;
}