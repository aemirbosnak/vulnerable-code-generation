//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

// Function to handle incoming connections
void handle_connection(int sockfd, struct sockaddr_in* client_addr) {
    printf("Incoming connection from %s:%d\n",
           inet_ntoa(client_addr->sin_addr),
           ntohs(client_addr->sin_port));

    // Check firewall rules here...
    
    // If allowed, handle the connection normally
    char buf[1024];
    int num_read = recv(sockfd, buf, sizeof(buf), 0);
    if (num_read > 0) {
        buf[num_read] = '\0';
        printf("Received message: %s\n", buf);
        // Do something with the data...
    } else {
        printf("Error reading from socket: %s\n", strerror(errno));
    }
}

int main(int argc, char** argv) {
    // Create a socket for incoming connections
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Bind to a specific IP address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8000);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, 10) < 0) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    // Loop to handle incoming connections
    while (1) {
        // Accept a new incoming connection
        struct sockaddr_in client_addr;
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t client_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_fd < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        // Handle the incoming connection (with firewall rules)
        handle_connection(client_fd, &client_addr);

        // Close the connection
        close(client_fd);
    }

    return 0;
}