//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int port = atoi(argv[2]);
    char* server_ip = argv[1];

    // create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1) {
        printf("Error creating socket...\n");
        return 1;
    }

    // prepare server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(server_ip);

    // connect to server
    if(connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        printf("Error connecting to server...\n");
        return 1;
    }

    char user_command[MAX_SIZE];

    // receive welcome message from server
    char welcome_message[MAX_SIZE];
    recv(socket_fd, welcome_message, MAX_SIZE, 0);
    printf("%s", welcome_message);

    while(1) {
        printf("> ");
        fgets(user_command, MAX_SIZE, stdin);

        // remove trailing newline character
        user_command[strcspn(user_command, "\n")] = 0;

        if(strncmp(user_command, "quit", 4) == 0) {
            printf("Closing connection...\n");
            close(socket_fd);
            return 0;
        }
        else if(strncmp(user_command, "get", 3) == 0) {
            char filename[MAX_SIZE];
            sscanf(user_command+4, "%s", filename);
            send(socket_fd, user_command, strlen(user_command), 0);

            char response[MAX_SIZE];
            recv(socket_fd, response, MAX_SIZE, 0);

            if(strncmp(response, "File not found.", 15) == 0) {
                printf("%s\n", response);
            }
            else {
                printf("Receiving file \"%s\"...\n", filename);
                int file_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
                if(file_fd == -1) {
                    printf("Error creating file...\n");
                    continue;
                }
                while(1) {
                    char buffer[MAX_SIZE];
                    int bytes_received = recv(socket_fd, buffer, MAX_SIZE, 0);
                    if(bytes_received == 0) break; // end of file
                    if(bytes_received == -1) {
                        printf("Error receiving file...\n");
                        break;
                    }
                    int bytes_written = write(file_fd, buffer, bytes_received);
                    if(bytes_written == -1) {
                        printf("Error writing file...\n");
                        break;
                    }
                }
                printf("File received successfully.\n");
                close(file_fd);
            }
        }
        else {
            send(socket_fd, user_command, strlen(user_command), 0);

            char server_response[MAX_SIZE];
            recv(socket_fd, server_response, MAX_SIZE, 0);
            printf("%s", server_response);
        }
    }

    return 0;
}