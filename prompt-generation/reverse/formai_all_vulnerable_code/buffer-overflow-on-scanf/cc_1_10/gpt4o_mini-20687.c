//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void show_menu() {
    printf("Welcome to the Puzzling C Email Client!\n");
    printf("1. Connect to Email Server\n");
    printf("2. Fetch Messages\n");
    printf("3. Disconnect\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

void connect_to_server(int *sock, const char *server_ip) {
    struct sockaddr_in server_addr;
    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (*sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(*sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(*sock);
        exit(EXIT_FAILURE);
    }
    printf("Connected to server at %s:%d\n", server_ip, SERVER_PORT);
}

void fetch_messages(int sock) {
    char buffer[BUFFER_SIZE] = {0};
    send(sock, "RETR 1\r\n", strlen("RETR 1\r\n"), 0);  
    recv(sock, buffer, BUFFER_SIZE, 0);
    
    printf("Fetched Message:\n%s\n", buffer);
}

int main(int argc, char *argv[]) {
    int option;
    int sock = 0;
    const char *server_ip = "127.0.0.1";

    while (1) {
        show_menu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                connect_to_server(&sock, server_ip);
                break;
            case 2:
                if (sock != 0) {
                    fetch_messages(sock);
                } else {
                    printf("You must connect to the server first!\n");
                }
                break;
            case 3:
                if (sock != 0) {
                    close(sock);
                    sock = 0;
                    printf("Disconnected from server.\n");
                } else {
                    printf("No active connection to disconnect.\n");
                }
                break;
            case 4:
                if (sock != 0) {
                    close(sock);
                }
                printf("Exiting..\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}