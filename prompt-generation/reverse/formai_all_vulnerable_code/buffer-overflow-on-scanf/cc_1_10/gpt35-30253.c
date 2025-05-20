//FormAI DATASET v1.0 Category: Firewall ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error in setting socket options");
        exit(EXIT_FAILURE);
    }

    // Set server address and bind the socket
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
        perror("Error in binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) == -1) {
        perror("Error in listening for connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addrlen = sizeof(address);
    int client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (client_socket == -1) {
        perror("Error in accepting connection");
        exit(EXIT_FAILURE);
    }

    // Authenticate client
    char username[10], password[10];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    send(client_socket, username, strlen(username), 0);
    send(client_socket, password, strlen(password), 0);
    char auth_msg[1024];
    recv(client_socket, &auth_msg, 1024, 0);
    if (strcmp(auth_msg, "AUTHENTICATED") != 0) {
        printf("Error: Invalid credentials\n");
        close(client_socket);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Firewall rules
    char buffer[1024];
    recv(client_socket, &buffer, 1024, 0);
    if (strstr(buffer, "DROP") != NULL) {
        printf("Firewall rule matched: DROP\n");
        close(client_socket);
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    else if (strstr(buffer, "ALLOW") == NULL) {
        printf("Error: Invalid input\n");
        close(client_socket);
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Send response
    char response_msg[1024] = "Response from server: SUCCESS";
    send(client_socket, response_msg, strlen(response_msg), 0);
    printf("Response message sent\n");

    // Close sockets
    close(client_socket);
    close(server_fd);
    return 0;
}