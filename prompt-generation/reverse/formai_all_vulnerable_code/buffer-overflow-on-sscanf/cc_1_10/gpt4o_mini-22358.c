//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 4096

void serveClient(int client_sock) {
    char buffer[BUF_SIZE];
    char method[10], url[BUF_SIZE], protocol[10];
    
    // The reader hears the request through a gentle whisper
    int read_size = recv(client_sock, buffer, BUF_SIZE, 0);
    if (read_size <= 0) {
        close(client_sock);
        return;
    }
    
    // Capture the request like a fleeting moment of bliss
    sscanf(buffer, "%s %s %s", method, url, protocol);

    printf("Ah, the request: %s %s %s\n", method, url, protocol);

    // A connection with the server, a fateful encounter
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        close(client_sock);
        return;
    }
    
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Heart beats at port 80
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example address (example.com)
    
    // The two lovers, the proxy and the server, unite
    if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_sock);
        close(client_sock);
        return;
    }
    
    // Send the request to the server as a message 'twixt two hearts
    send(server_sock, buffer, read_size, 0);

    // Await the response, as we await love's return
    while ((read_size = recv(server_sock, buffer, BUF_SIZE, 0)) > 0) {
        // Relay the response back to the client
        send(client_sock, buffer, read_size, 0);
    }

    // Parting is such sweet sorrow, we must close our connections
    close(server_sock);
    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // In this fair city, we set our stage
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Binding to the address, a promise made
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    
    // The call to rise and welcome all comers
    if (listen(server_sock, 10) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    
    printf("The proxy awaits, a gate for love's requests...\n");
    
    while (1) {
        // Receiving the client, a moment of joy
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Client accept failed");
            continue; // Despair not, we shall keep on
        }
        
        // In the name of love, serve the client
        serveClient(client_sock);
    }

    // Yet, as dusk falls, our proxy shall return to dreams
    close(server_sock);
    return 0;
}