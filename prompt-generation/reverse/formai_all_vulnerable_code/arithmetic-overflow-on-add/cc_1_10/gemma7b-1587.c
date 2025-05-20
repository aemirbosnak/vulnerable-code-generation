//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_ADDR "localhost"

int main() {
    int sockfd, n, port, i, client_fd, server_fd;
    char buf[1024], msg[1024], hostname[256];
    struct sockaddr_in server_addr, client_addr;
    time_t start_time, end_time, uptime;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        client_fd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (client_fd < 0) {
            perror("Error accepting client connection");
            continue;
        }

        // Get the client's hostname
        gethostname(client_addr.sin_addr.s_addr, hostname);

        // Send a welcome message to the client
        sprintf(msg, "Welcome, %s!", hostname);
        send(client_fd, msg, strlen(msg), 0);

        // Receive the client's uptime
        recv(client_fd, buf, 1024, 0);
        uptime = atoi(buf);

        // Calculate the client's uptime
        start_time = time(NULL);
        end_time = start_time + uptime;
        printf("Client uptime: %s hours\n", uptime);

        // Send the client's uptime to the client
        sprintf(msg, "Your uptime is: %s hours", uptime);
        send(client_fd, msg, strlen(msg), 0);

        // Close the client connection
        close(client_fd);
    }

    return 0;
}