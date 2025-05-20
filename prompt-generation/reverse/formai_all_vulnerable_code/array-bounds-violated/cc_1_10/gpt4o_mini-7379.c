//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define PORT 8888
#define BACKLOG 10

void handle_client(int client_sock);
void serve_the_traffic(int client_sock, const char *domain, int port);
void give_feedback(const char *message);

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size = sizeof(client_addr);
    
    give_feedback("Welcome to the C HTTP Proxy, where your requests delight and traffic is light!");
    
    // Create a socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Can't create socket, did you spill coffee on it?");
        exit(EXIT_FAILURE);
    }
    
    // Allow reuse of address
    int opt = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Ouch! Binding failed. Did the socket trip over a wire?");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_sock, BACKLOG) < 0) {
        perror("Oops! Can't listen, is the internet turned on?");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    give_feedback("The proxy is up and running! Ready to serve the internet delicacies!");

    while (1) {
        // Accept a client connection
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_size);
        if (client_sock < 0) {
            perror("Yikes! A connection problem! Did the cables tangle?");
            continue;
        }
        
        give_feedback("A new client has entered the game. Let the fun begin!");
        
        handle_client(client_sock);
        
        // After serving the requests, we wave goodbye to the client
        close(client_sock);
        give_feedback("The client has left the building, until next time!");
    }

    close(server_sock);
    return 0;
}

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    
    // Read from client socket
    int received = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (received <= 0) {
        perror("I couldn't hear you! Connection issues?");
        return;
    }
    
    buffer[received] = '\0'; // Null terminating to make it chef-friendly

    // Parse the HTTP request
    char method[10], url[256];
    sscanf(buffer, "%s %s", method, url);
    
    give_feedback("Caught a request! Let's send it to the main server kitchen!");

    // Extract the domain and port
    char domain[256];
    int port = 80; // HTTP port by default
    if (sscanf(url, "http://%255[^:/]:%d", domain, &port) != 2) {
        sscanf(url, "http://%255[^:/]", domain);
    }
    
    serve_the_traffic(client_sock, domain, port);
}

void serve_the_traffic(int client_sock, const char *domain, int port) {
    int server_sock;
    struct sockaddr_in server_addr;
    
    // Create socket to the actual server
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Couldn't connect to the server! Maybe it's napping?");
        return;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(domain);
    
    // Connect to the server
    if (connect(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed! Is it on a coffee break?");
        close(server_sock);
        return;
    }

    // Send the request to the server
    send(server_sock, "GET / HTTP/1.0\r\nHost: ", 23, 0);
    send(server_sock, domain, strlen(domain), 0);
    send(server_sock, "\r\nConnection: close\r\n\r\n", 24, 0);
    
    char response[BUFFER_SIZE];
    // Read the response
    while (1) {
        int bytes_received = recv(server_sock, response, BUFFER_SIZE - 1, 0);
        
        if (bytes_received <= 0) {
            break; // End of response
        }
        response[bytes_received] = '\0'; // Make it taste better
        send(client_sock, response, bytes_received, 0); // Serve it to the client
    }

    give_feedback("Served the delicious response to the client, hope they enjoy!");
    close(server_sock);
}

void give_feedback(const char *message) {
    printf("[Proxy Feedback] %s\n", message);
}