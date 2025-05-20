//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;
    
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        
        char operation[10];
        int operand1, operand2;
        sscanf(buffer, "%s %d %d", operation, &operand1, &operand2);
        
        int result = 0;
        if (strcmp(operation, "add") == 0) {
            result = operand1 + operand2;
        } else if (strcmp(operation, "subtract") == 0) {
            result = operand1 - operand2;
        } else if (strcmp(operation, "multiply") == 0) {
            result = operand1 * operand2;
        } else if (strcmp(operation, "divide") == 0 && operand2 != 0) {
            result = operand1 / operand2;
        } else {
            strcpy(buffer, "Invalid operation");
            send(client_socket, buffer, strlen(buffer), 0);
            continue;
        }
        
        sprintf(buffer, "Result: %d", result);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    
    close(client_socket);
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d\n", PORT);
    
    addr_size = sizeof(client_addr);
    
    while ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_size)) >= 0) {
        printf("Connection accepted\n");
        handle_client(client_socket);
    }

    close(server_fd);
    return 0;
}