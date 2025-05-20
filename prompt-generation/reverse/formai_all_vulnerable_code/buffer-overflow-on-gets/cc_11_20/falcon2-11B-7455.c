//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define POP3_PORT 110
#define MAX_DATA_LENGTH 1024
#define MAX_SERVER_NAME 50

int main() {
    int socket_fd, port, i, len, num_bytes_read;
    struct sockaddr_in server_address;
    char buffer[MAX_DATA_LENGTH], message[MAX_SERVER_NAME], password[MAX_SERVER_NAME];
    FILE *fp;

    if ( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(POP3_PORT);

    if (inet_pton(AF_INET, "localhost", &(server_address.sin_addr)) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Welcome to our POP3 client!\n");
    printf("Please enter your email address: ");
    gets(message);
    printf("Please enter your password: ");
    gets(password);

    if (send(socket_fd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(socket_fd, password, strlen(password), 0) < 0) {
        perror("send");
        exit(1);
    }

    printf("Logging in...\n");

    if (recv(socket_fd, buffer, MAX_DATA_LENGTH, 0) <= 0) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buffer);

    if (strcmp(buffer, "OK")!= 0) {
        printf("Invalid email or password. Exiting...\n");
        exit(1);
    }

    printf("Please enter the number of messages you want to download: ");
    scanf("%d", &num_bytes_read);
    if (num_bytes_read > 0) {
        fp = popen("cat /dev/null", "r");
        if (fp == NULL) {
            perror("popen");
            exit(1);
        }

        printf("Downloading messages...\n");
        while (num_bytes_read > 0) {
            if (pwrite(fp, buffer, MAX_DATA_LENGTH, num_bytes_read)!= MAX_DATA_LENGTH) {
                perror("pwrite");
                exit(1);
            }
            num_bytes_read -= MAX_DATA_LENGTH;
        }

        pclose(fp);
        printf("Messages downloaded successfully!\n");
    } else {
        printf("No messages to download.\n");
    }

    printf("Logging out...\n");

    if (send(socket_fd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(socket_fd, buffer, MAX_DATA_LENGTH, 0) <= 0) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buffer);

    close(socket_fd);
    return 0;
}