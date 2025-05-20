//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REPLY_LENGTH 2048
#define MAX_MAIL_BODY_LENGTH 10000

int main(int argc, char *argv[]) {
    // Pop3 server IP address and port number
    char *server_address = "pop3.example.com";
    int server_port = 110;

    char *username = "yourusername";
    char *password = "yourpassword";

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_address, &server.sin_addr) != 1) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char reply[MAX_REPLY_LENGTH];
    ssize_t num_bytes = recv(sock, reply, sizeof(reply), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    reply[num_bytes] = '\0';

    printf("%s\n", reply);

    char user_command[128];
    sprintf(user_command, "USER %s\r\n", username);
    if (send(sock, user_command, strlen(user_command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    num_bytes = recv(sock, reply, sizeof(reply), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    reply[num_bytes] = '\0';

    printf("%s\n", reply);

    char pass_command[128];
    sprintf(pass_command, "PASS %s\r\n", password);
    if (send(sock, pass_command, strlen(pass_command), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    num_bytes = recv(sock, reply, sizeof(reply), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    reply[num_bytes] = '\0';

    printf("%s\n", reply);

    if (send(sock, "LIST\r\n", 6, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    num_bytes = recv(sock, reply, sizeof(reply), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    reply[num_bytes] = '\0';

    printf("%s\n", reply);

    if (send(sock, "RETR 1\r\n", 8, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    char mail_body[MAX_MAIL_BODY_LENGTH];
    ssize_t mail_body_length = 0;

    while ((num_bytes = recv(sock, reply, sizeof(reply), 0)) > 0) {
        if (mail_body_length + num_bytes > MAX_MAIL_BODY_LENGTH) {
            fprintf(stderr, "Mail body too large\n");
            exit(EXIT_FAILURE);
        }

        memcpy(mail_body + mail_body_length, reply, num_bytes);
        mail_body_length += num_bytes;

        if (memcmp(reply + num_bytes - 5, "\r\n.\r\n", 5) == 0) {
            break;
        }
    }

    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    mail_body[mail_body_length] = '\0';
    printf("%s\n", mail_body);

    if (send(sock, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    num_bytes = recv(sock, reply, sizeof(reply), 0);
    if (num_bytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    reply[num_bytes] = '\0';

    printf("%s\n", reply);

    close(sock);

    return EXIT_SUCCESS;
}