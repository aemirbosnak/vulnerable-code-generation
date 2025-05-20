//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 4096

typedef struct {
    char cmd[5];
    char args[10][32];
} smtp_command;

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc != 3) {
        printf("Usage: %s <Recipient email> <Sender email>\n", argv[0]);
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if ((server = gethostbyname("smtp.gmail.com")) == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", gai_strerror(h_errno));
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Could not create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Could not connect to server");
        exit(1);
    }

    printf("\033[1;1H"); // Move cursor to the top of the terminal

    smtp_command commands[] = {
        {"HELO", "MyCuriousSMTPClient"},
        {"MAIL FROM:<", argv[2], ">"},
        {"RCPT TO:<", argv[1], ">"},
        {"DATA"},
        {".\r\n"},
        {"QUIT"}
    };

    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
        write(sockfd, commands[i].cmd, strlen(commands[i].cmd));

        if (strcmp(commands[i].cmd, "MAIL FROM:") == 0 ||
            strcmp(commands[i].cmd, "RCPT TO:") == 0) {

            for (int j = 1; j < 10 && commands[i].args[j][0] != '\0'; j++) {
                write(sockfd, commands[i].args[j], strlen(commands[i].args[j]));

                if (j < 9) {
                    write(sockfd, ": ", 2);
                }
            }

            write(sockfd, "\r\n", 2);
        } else {
            write(sockfd, commands[i].cmd, strlen(commands[i].cmd));

            if (strcmp(commands[i].cmd, "DATA") == 0) {
                write(sockfd, "\r\n\r\n", 3);
            }
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("%s", buffer);
        }

        if (strcmp(commands[i].cmd, "QUIT") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}