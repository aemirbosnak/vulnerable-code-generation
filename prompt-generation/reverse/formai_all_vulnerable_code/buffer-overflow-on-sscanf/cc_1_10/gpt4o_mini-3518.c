//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER 4096
#define PORT 80

void sendGetRequest(const char *hostname, const char *path);
void sendPostRequest(const char *hostname, const char *path, const char *data);
void handleClient(int client_id);

int main() {
    int client_id = 1;
    char command[100], url[100], path[100], data[200];

    printf("Welcome to the Multiplayer HTTP Client!\n");
    printf("Enter your commands (GET/POST URL [path] [data]), type 'exit' to quit.\n");

    while (1) {
        printf("Client %d> ", client_id);
        fgets(command, sizeof(command), stdin);

        // Remove newline character from the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("Exiting client %d.\n", client_id);
            break;
        }

        if (sscanf(command, "GET %s %[^\n]", url, path) == 2) {
            sendGetRequest(url, path);
        } else if (sscanf(command, "POST %s %[^\n] %[^\n]", url, path, data) == 3) {
            sendPostRequest(url, path, data);
        } else {
            printf("Invalid command. Use GET/POST URL [path] [data].\n");
        }
        
        client_id++;
    }

    return 0;
}

void sendGetRequest(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER];
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(sock, buffer, strlen(buffer), 0);
    
    while (recv(sock, buffer, sizeof(buffer)-1, 0) > 0) {
        fputs(buffer, stdout);
    }

    close(sock);
}

void sendPostRequest(const char *hostname, const char *path, const char *data) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER];
    
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    snprintf(buffer, sizeof(buffer), "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %lu\r\n\r\n%s", 
             path, hostname, strlen(data), data);
    
    send(sock, buffer, strlen(buffer), 0);
    
    while (recv(sock, buffer, sizeof(buffer) - 1, 0) > 0) {
        fputs(buffer, stdout);
    }

    close(sock);
}