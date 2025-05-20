//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024
#define MAX_SERVERS 5

void send_file_to_server(const char* server_ip, const char* filename) {
    int sock;
    struct sockaddr_in server_addr;
    FILE *file;
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Server address configuration
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return;
    }

    // Open file to be sent
    file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        close(sock);
        return;
    }

    // Send file name to the server
    send(sock, filename, strlen(filename), 0);
    // Sending file data
    while (!feof(file)) {
        size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
        send(sock, buffer, bytes_read, 0);
    }

    printf("File '%s' sent to server %s successfully.\n", filename, server_ip);
    fclose(file);
    close(sock);
}

int main() {
    char* servers[MAX_SERVERS] = {
        "192.168.1.1",
        "192.168.1.2",
        "192.168.1.3",
        "192.168.1.4",
        "192.168.1.5"
    };

    int server_count = sizeof(servers) / sizeof(servers[0]);
    char filename[256];

    printf("Welcome to the Distributed File Backup System\n");
    while (1) {
        printf("Enter the file path to back up (or 'exit' to quit): ");
        scanf("%s", filename);

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        for (int i = 0; i < server_count; i++) {
            send_file_to_server(servers[i], filename);
        }
    }

    printf("Exiting the program.\n");
    return 0;
}