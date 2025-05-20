//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Unveil the mystery of FTP commands!
const char* commands[] = {
    "USER",
    "PASS",
    "QUIT",
    "LIST",
    "RETR",
    "STOR",
    NULL
};

// Wield the power of sockets to connect!
int connect_to_server(const char* ip_addr, int port) {
    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    // Call forth the connection!
    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

// Cast off the commands to the server for response!
void send_command(int sock, const char* command) {
    send(sock, command, strlen(command), 0);
    send(sock, "\r\n", 2, 0);
}

// Gaze into the orb of responses!
void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int valread = recv(sock, buffer, BUFFER_SIZE, 0);
    if (valread > 0) {
        buffer[valread] = '\0';  // Null terminate the string
        printf("Server Response: %s", buffer);
    } else {
        printf("Failed to read response.\n");
    }
}

// The riddle of the user input
void user_authentication(int sock) {
    char username[100], password[100];
    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline

    send_command(sock, strcat(strdup(commands[0]), username));
    receive_response(sock);

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; // Remove newline

    send_command(sock, strcat(strdup(commands[1]), password));
    receive_response(sock);
}

// Linked to the treasures of the remote connection!
void list_files(int sock) {
    send_command(sock, commands[3]);
    receive_response(sock);
}

// The retrieval of files from the vaults of the server!
void retrieve_file(int sock) {
    char filename[100];
    printf("Enter filename to retrieve: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline

    char command[150];
    snprintf(command, sizeof(command), "%s %s", commands[4], filename);
    send_command(sock, command);
    receive_response(sock);
}

// The final portal to exit the realm
void exit_ftp(int sock) {
    send_command(sock, commands[2]);
    receive_response(sock);
    close(sock);
}

int main() {
    // The starting point of this odyssey.
    const char* server_ip = "127.0.0.1"; // Change as needed for your server.
    int server_port = 21;

    int sock = connect_to_server(server_ip, server_port);
    user_authentication(sock);

    // The loop of choice.
    while (1) {
        printf("Choose an action: (1) List files (2) Retrieve file (3) Exit: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Clear the newline

        switch (choice) {
            case 1:
                list_files(sock);
                break;
            case 2:
                retrieve_file(sock);
                break;
            case 3:
                exit_ftp(sock);
                return 0;
            default:
                printf("Unknown choice. Try again.\n");
                break;
        }
    }

    return 0;
}