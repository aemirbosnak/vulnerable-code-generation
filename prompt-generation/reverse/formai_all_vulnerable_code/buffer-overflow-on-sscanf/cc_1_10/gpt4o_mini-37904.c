//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define PORT 8080

void whisper(const char *message) {
    printf("[Whisper]: %s\n", message);
}

void bounceResponse(int client_sock, int server_sock) {
    char buffer[BUFFER_SIZE];
    int bytes;
    
    while ((bytes = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        whisper("Bouncing server response to the client.");
        send(client_sock, buffer, bytes, 0);
    }
}

void serveRequest(int client_sock) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    char method[10], host[100], path[100], protocol[10];
    
    int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        whisper("Alas! I cannot hear you.");
        close(client_sock);
        return;
    }

    sscanf(buffer, "%s http://%99[^/]%99[^\n] %s", method, host, path, protocol);
    whisper("Oh! A request has been captured!");

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        whisper("Unable to create a socket for the server.");
        close(client_sock);
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        whisper("The server is silent. Connection failed.");
        close(server_sock);
        close(client_sock);
        return;
    }
    
    whisper("Sending the request to the server...");
    send(server_sock, buffer, bytes_received, 0);
    bounceResponse(client_sock, server_sock);

    close(server_sock);
    close(client_sock);
    whisper("The transaction is complete, my friend.");
}

int main() {
    whisper("Welcome to the HTTP Proxy - where requests dance through!");
    
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        whisper("Oh dear! The proxy can't be established.");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_sock, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        whisper("Binding the proxy has failed!");
        close(proxy_sock);
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_sock, 10) < 0) {
        whisper("Listening... but I can’t seem to hear!");
        close(proxy_sock);
        exit(EXIT_FAILURE);
    }

    whisper("The proxy awaits you!");

    while (1) {
        int client_sock = accept(proxy_sock, NULL, NULL);
        if (client_sock < 0) {
            whisper("A phantom disrupted my hearing.");
            continue;
        }
        whisper("A curious client has arrived!");
        serveRequest(client_sock);
    }

    close(proxy_sock);
    whisper("The proxy is now closed. Farewell!");

    return 0;
}