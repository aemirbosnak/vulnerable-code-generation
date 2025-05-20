//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 8080

int main() {
    int sockfd, clientfd, new_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Bind the socket to a port
    server_addr.sin_port = htons(SERVER_PORT);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for connections
    listen(sockfd, 10);

    // Accept a connection
    clientfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

    // Start the timer
    start_time = time(NULL);

    // Send a message to the client
    write(clientfd, "Hello, world!", 13);

    // Receive a message from the client
    read(clientfd, buffer, 1024);

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the time taken
    printf("Time taken: %d seconds\n", time_taken);

    // Close the connection
    close(clientfd);

    return 0;
}