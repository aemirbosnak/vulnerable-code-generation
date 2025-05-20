//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
/* FTP client in C */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    /* Check for correct number of command-line arguments */
    if (argc != 3) {
        printf("Usage: %s server_address port_number\n", argv[0]);
        exit(0);
    }

    /* Create socket */
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    /* Convert server address to binary format */
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    /* Connect to server */
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    /* Receive welcome message from server */
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    /* Login with username and password */
    char username[BUFFER_SIZE], password[BUFFER_SIZE];
    printf("User: ");
    scanf("%s", username);
    send(sock, username, strlen(username)+1, 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    if (strcmp(buffer, "OK") != 0) {
        printf("Error: Invalid username.\n");
        exit(1);
    }
    printf("Password: ");
    scanf("%s", password);
    send(sock, password, strlen(password)+1, 0);
    memset(buffer, 0, BUFFER_SIZE);
    recv(sock, buffer, BUFFER_SIZE, 0);
    if (strcmp(buffer, "OK") != 0) {
        printf("Error: Invalid password.\n");
        exit(1);
    }

    /* Enter main loop */
    while (1) {
        /* Get command from user */
        char command[BUFFER_SIZE], filename[BUFFER_SIZE];
        printf("ftp> ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            break;
        }
        else if (strcmp(command, "get") == 0) {
            scanf("%s", filename);

            /* Send command and filename to server */
            send(sock, command, strlen(command)+1, 0);
            memset(buffer, 0, BUFFER_SIZE);
            recv(sock, buffer, BUFFER_SIZE, 0);
            if (strcmp(buffer, "READY") != 0) {
                printf("Error: Server not ready.\n");
                exit(1);
            }
            send(sock, filename, strlen(filename)+1, 0);
            memset(buffer, 0, BUFFER_SIZE);
            recv(sock, buffer, BUFFER_SIZE, 0);

            /* Check if file exists */
            if (strcmp(buffer, "ERROR") == 0) {
                printf("Error: File does not exist.\n");
                continue;
            }

            /* Receive file from server */
            FILE *fp = fopen(filename, "wb");
            while (1) {
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
                if (bytes_received <= 0) {
                    break;
                }
                fwrite(buffer, bytes_received, 1, fp);
            }
            fclose(fp);
            printf("File received.\n");
        }
        else {
            printf("Error: Invalid command.\n");
        }
    }

    /* Close socket */
    close(sock);

    return 0;
}