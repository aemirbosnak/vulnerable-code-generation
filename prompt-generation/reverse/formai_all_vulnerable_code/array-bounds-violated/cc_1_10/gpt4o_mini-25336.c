//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_LEN 1024

void obtain_current_time(char *buffer, size_t len) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, len, "%Y-%m-%d %H:%M:%S", tm_info);
}

void craft_http_response(char *response_buffer, const char *content) {
    sprintf(response_buffer,
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %lu\r\n"
            "Connection: close\r\n"
            "\r\n"
            "<html>"
            "<head><title>Medieval Web Server</title></head>"
            "<body><h1>Well met, traveler!</h1>"
            "<p>Your request hath been received at this hour:</p>"
            "<p>%s</p>"
            "<p>%s</p>"
            "</body></html>",
            strlen(content), content);
}

void handle_client(int client_socket) {
    char buffer[MAX_LEN];
    char response[MAX_LEN];
    
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive message");
        close(client_socket);
        return;
    }
    buffer[bytes_received] = '\0'; // Null terminate

    char current_time[20];
    obtain_current_time(current_time, sizeof(current_time));

    craft_http_response(response, current_time);
    
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Dungeon failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT); 

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to attach socket to our realm");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, BACKLOG) < 0) {
        perror("The castle gates are unyielding!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("The Medieval Web Server hath emerged, awaiting quests upon port %d!\n", PORT);

    while (1) {
        printf("A new traveler hast approached!\n");
        
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Alas! Failed to accept the traveler");
            continue;
        }

        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}