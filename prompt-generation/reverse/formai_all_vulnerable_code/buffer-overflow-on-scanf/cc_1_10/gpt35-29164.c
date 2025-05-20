//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_RESPONSE_LENGTH 1024
#define COMMAND_BUFFER_SIZE 1024
#define RESPONSE_BUFFER_SIZE 1048576

void initiate_connection(int* socket_fd, struct sockaddr_in* server_addr, char server_IP[50], int server_port);

void send_message(int socket_fd, char message[MAX_COMMAND_LENGTH]);

void receive_message(int socket_fd, char* response);

int main(int argc, char const *argv[])
{
    int socket_fd;
    struct sockaddr_in server_addr;
    char server_IP[50];
    int server_port;
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    char command_buffer[COMMAND_BUFFER_SIZE];
    char response_buffer[RESPONSE_BUFFER_SIZE] = {0};
    char* ptr = response_buffer;

    printf("Enter the IP address of the server you would like to connect to: ");
    scanf("%s", server_IP);
    printf("Enter the port number: ");
    scanf("%d", &server_port);

    initiate_connection(&socket_fd, &server_addr, server_IP, server_port);

    while (1) {
        printf("ftp> ");
        memset(command_buffer, 0, COMMAND_BUFFER_SIZE);
        fgets(command_buffer, MAX_COMMAND_LENGTH, stdin);
        strncpy(command, command_buffer, strlen(command_buffer) - 1);

        send_message(socket_fd, command);
        receive_message(socket_fd, response);

        if (strncmp(command, "quit", 4) == 0) {
            printf("%s", response);
            break;
        } else if (strncmp(command, "get", 3) == 0) {
            printf("Downloading file...\n");
            while (1) {
                memcpy(ptr, response, strlen(response));
                ptr += strlen(response);
                if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) <= 0) break;
            }
            printf("File downloaded successfully!\n");
        } else {
            printf("%s", response);
        }
    }

    close(socket_fd);

    return 0;
}

void initiate_connection(int* socket_fd, struct sockaddr_in* server_addr, char server_IP[50], int server_port) {
    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    server_addr->sin_port = htons(server_port);
    inet_pton(AF_INET, server_IP, &server_addr->sin_addr);

    if ((*socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(-1);
    }

    if (connect(*socket_fd, (struct sockaddr*)server_addr, sizeof(*server_addr)) < 0) {
        perror("Connection failed");
        exit(-1);
    }

    printf("Connected to server!\n");
}

void send_message(int socket_fd, char message[MAX_COMMAND_LENGTH]) {
    if (send(socket_fd, message, strlen(message) + 1, 0) < 0) {
        perror("Send failed");
    }
}

void receive_message(int socket_fd, char* response) {
    memset(response, 0, MAX_RESPONSE_LENGTH);
    if (recv(socket_fd, response, MAX_RESPONSE_LENGTH, 0) < 0) {
        perror("Receive failed");
    }
}