//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define COMMAND_SIZE 256

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        printf("Failed to create socket.\n");
        return 1;
    }
    printf("Socket created.\n");

    // Connect to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0)
    {
        printf("Invalid IP address.\n");
        return 1;
    }

    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        printf("Failed to connect to server.\n");
        return 1;
    }
    printf("Connected to server.\n");

    // Authenticate user
    char username[COMMAND_SIZE], password[COMMAND_SIZE], command[BUFFER_SIZE];
    printf("Username: ");
    fgets(username, COMMAND_SIZE, stdin);
    printf("Password: ");
    fgets(password, COMMAND_SIZE, stdin);
    sprintf(command, "USER %s%s", username, password);
    send(client_socket, command, strlen(command), 0);
    char server_response[BUFFER_SIZE];
    recv(client_socket, server_response, BUFFER_SIZE, 0);
    printf("%s\n", server_response);

    // Loop for user commands
    char ftp_command[COMMAND_SIZE];
    while (1)
    {
        printf("ftp> ");
        fgets(ftp_command, COMMAND_SIZE, stdin);
        send(client_socket, ftp_command, strlen(ftp_command), 0);

        // Handle commands
        if (strncmp(ftp_command, "LIST", 4) == 0)
        {
            char server_response[BUFFER_SIZE];
            recv(client_socket, server_response, BUFFER_SIZE, 0);
            printf("%s", server_response);
        }
        else if (strncmp(ftp_command, "QUIT", 4) == 0)
        {
            char server_response[BUFFER_SIZE];
            recv(client_socket, server_response, BUFFER_SIZE, 0);
            printf("%s\n", server_response);
            break;
        }
        else if (strncmp(ftp_command, "GET", 3) == 0)
        {
            char filename[COMMAND_SIZE];
            sscanf(ftp_command, "GET %s", filename);
            printf("Downloading %s...\n", filename);
            FILE *fp = fopen(filename, "wb");
            if (fp == NULL)
            {
                printf("Failed to create file.\n");
                continue;
            }
            char server_response[BUFFER_SIZE];
            int bytes_received;
            while ((bytes_received = recv(client_socket, server_response, BUFFER_SIZE, 0)) > 0)
            {
                fwrite(server_response, 1, bytes_received, fp);
            }
            fclose(fp);
            printf("File downloaded.\n");
        }
        else
        {
            char server_response[BUFFER_SIZE];
            recv(client_socket, server_response, BUFFER_SIZE, 0);
            printf("%s\n", server_response);
        }
    }

    close(client_socket);
    return 0;
}