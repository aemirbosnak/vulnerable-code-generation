//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 4096

void print_response(char *response) {
    printf("Response from server:\n");
    printf("%s\n", response);
}

bool send_request(const char *hostname, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    ssize_t bytes;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create a socket.");
        return false;
    }
    
    // Resolve server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed.");
        close(sock);
        return false;
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send request
    send(sock, request, strlen(request), 0);

    // Receive response
    while ((bytes = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes] = '\0'; // Null-terminate response
        print_response(response);
    }

    // Close socket
    close(sock);
    return true;
}

void display_menu() {
    printf("========================================\n");
    printf("           FUTURISTIC HTTP CLIENT       \n");
    printf("========================================\n");
    printf("[1] Send GET Request                  \n");
    printf("[0] Exit                               \n");
    printf("========================================\n");
}

int main() {
    int choice;
    char hostname[256];
    char path[256];

    while (true) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter hostname (IPv4 address): ");
            scanf("%s", hostname);
            printf("Enter path (e.g., /api/data): ");
            scanf("%s", path);

            if (!send_request(hostname, path)) {
                printf("An error occurred while sending request.\n");
            }
        } else if (choice == 0) {
            printf("Exiting... \n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}