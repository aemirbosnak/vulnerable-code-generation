//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock_fd, pop3_port = 110, status;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc < 2) {
        perror("No hostname provided.");
        exit(1);
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed.");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Invalid hostname.");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(pop3_port);

    status = connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status < 0) {
        perror("Error occurred while connecting.");
        exit(1);
    }

    printf("Connected to POP3 server.\n\n");

    status = recv(sock_fd, buffer, BUF_SIZE, 0);
    buffer[status] = '\0';
    printf("%s\n", buffer);

    char user[BUF_SIZE], pass[BUF_SIZE];

    printf("Enter username: ");
    fgets(user, BUF_SIZE, stdin);

    char* pos = strchr(user, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }

    printf("Enter password: ");
    fgets(pass, BUF_SIZE, stdin);

    pos = strchr(pass, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }

    char auth[BUF_SIZE];
    sprintf(auth, "USER %s\r\nPASS %s\r\n", user, pass);
    send(sock_fd, auth, strlen(auth), 0);

    status = recv(sock_fd, buffer, BUF_SIZE, 0);
    buffer[status] = '\0';
    printf("%s\n", buffer);

    char list[] = "LIST\r\n";
    send(sock_fd, list, strlen(list), 0);

    status = recv(sock_fd, buffer, BUF_SIZE, 0);
    buffer[status] = '\0';
    printf("%s\n", buffer);

    printf("Enter message number to retrieve: ");
    char num[BUF_SIZE];
    fgets(num, BUF_SIZE, stdin);

    pos = strchr(num, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }

    char retr[BUF_SIZE];
    sprintf(retr, "RETR %s\r\n", num);
    send(sock_fd, retr, strlen(retr), 0);

    status = recv(sock_fd, buffer, BUF_SIZE, 0);
    buffer[status] = '\0';
    printf("%s\n", buffer);

    close(sock_fd);
    printf("Connection closed.\n");
    return 0;
}