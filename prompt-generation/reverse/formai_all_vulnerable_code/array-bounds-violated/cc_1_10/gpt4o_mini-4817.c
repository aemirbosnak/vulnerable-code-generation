//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8888
#define BUF_SIZE 4096

// The tragic character, the proxy
void start_proxy();
void handle_client(int client_sock);

// The star-crossed lovers; destined requests and responses
void send_to_server(int client_sock, char *request);
void relay_response(int server_sock, int client_sock);

int main() {
    // The scene is set, a noble endeavor to create a proxy
    start_proxy();
    return 0;
}

void start_proxy() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    // The hearts beat, our server listens
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Prepare the noble structures
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the fates together
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Ready the stage, our resolve to listen
    if (listen(server_sock, 10) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }
    printf("Proxy server listening on port %d...\n", PORT);
    
    // The wheel of fortune turns, we await encounters
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }
        
        // A chance meeting, handle the client
        handle_client(client_sock);
        close(client_sock); // A bitter departure, the socket is closed
    }
}

void handle_client(int client_sock) {
    char buf[BUF_SIZE];
    int read_size;

    // A fleeting moment, what dost thou desire?
    read_size = recv(client_sock, buf, sizeof(buf) - 1, 0);
    if (read_size < 0) {
        perror("Receive failed");
        return;
    }
    buf[read_size] = '\0'; // Succumbing to null

    // A yearning to traverse to the server of fate
    send_to_server(client_sock, buf);
}

void send_to_server(int client_sock, char *request) {
    int server_sock;
    struct sockaddr_in server_addr;
    char method[10], url[100];
    char *http_version;

    // Parse the request for purpose and direction
    sscanf(request, "%s %s %s", method, url, http_version);
    
    // In search of the destination, here lies the tale
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Socket creation failed");
        return;
    }

    // Addressing the server, where our desires lead
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // The default port of sorrow
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example: "example.com"

    // The drama of connection unfolds
    if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_sock);
        return;
    }

    // Dispatching the request to the server, as if love letters
    send(server_sock, request, strlen(request), 0);
    // The response comes swift like passion's fire
    relay_response(server_sock, client_sock);
    close(server_sock); // Golden moments pass, another socket closes
}

void relay_response(int server_sock, int client_sock) {
    char buf[BUF_SIZE];
    int recv_size;

    while ((recv_size = recv(server_sock, buf, sizeof(buf), 0)) > 0) {
        // Carry the response back through the veil of shadows
        send(client_sock, buf, recv_size, 0);
    }
    if (recv_size < 0) {
        perror("Receive failed");
    }
}