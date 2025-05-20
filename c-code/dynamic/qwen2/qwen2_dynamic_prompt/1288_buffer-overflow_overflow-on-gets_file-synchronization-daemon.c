#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    printf("Client connected\n");
    
    // Vulnerable gets call
    gets(buffer);
    
    printf("Received data: %s\n", buffer);
}

int main() {
    int server_socket = 42; // Simulated server socket
    int client_socket = 1337; // Simulated client socket
    
    handle_client(client_socket);
    
    return 0;
}
