//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FTP_PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    char user[50], password[50], command[50], filename[50], path[100];

    if(argc < 2) {
        fprintf(stderr, "Usage: %s <FTP Server Address>\n", argv[0]);
        exit(1);
    }

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Error");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(FTP_PORT);
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if(connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connect Error");
        exit(1);
    }

    printf("Connected to FTP Server...\n");

    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    printf("Enter Username: ");
    scanf("%s", user);

    sprintf(command, "USER %s\r\n", user);

    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    printf("Enter Password: ");
    scanf("%s", password);

    sprintf(command, "PASS %s\r\n", password);

    send(sock, command, strlen(command), 0);
    recv(sock, buffer, BUFFER_SIZE, 0);

    printf("%s", buffer);

    while(1) {
        printf("Enter Command (e.g. GET /file.txt): ");
        scanf("%s %s", command, filename);

        if(strcmp(command, "GET") == 0) {
            sprintf(path, "RETR %s\r\n", filename);

            send(sock, path, strlen(path), 0);
            recv(sock, buffer, BUFFER_SIZE, 0);

            printf("%s", buffer);

            FILE *file;
            file = fopen(filename, "w");

            while(recv(sock, buffer, BUFFER_SIZE, 0) > 0) {
                fwrite(buffer, 1, sizeof(buffer), file);
            }

            fclose(file);
        } else if(strcmp(command, "QUIT") == 0) {
            send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
            recv(sock, buffer, BUFFER_SIZE, 0);

            printf("%s", buffer);

            close(sock);
            printf("Disconnected from FTP Server...\n");
            break;
        } else {
            printf("Invalid Command\n");
        }
    }

    return 0;
}