//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 110
#define MAX_BUF_SIZE 1024

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        printf("Usage: ./pop3-client <server-addr> <username> <password>\n");
        return 1;
    }

    // create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(SERVER_PORT);

    // connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // receive welcome message
    char buf[MAX_BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    if (recv(sock_fd, buf, sizeof(buf), 0) < 0) {
        perror("Error receiving data");
        return 1;
    }
    printf("%s", buf);

    // send username and password
    char username[MAX_BUF_SIZE], password[MAX_BUF_SIZE];
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);
    sprintf(buf, "USER %s\r\n", username);
    if (send(sock_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending data");
        return 1;
    }

    memset(buf, 0, sizeof(buf));
    if (recv(sock_fd, buf, sizeof(buf), 0) < 0) {
        perror("Error receiving data");
        return 1;
    }
    printf("%s", buf);

    sprintf(buf, "PASS %s\r\n", password);
    if (send(sock_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending data");
        return 1;
    }

    memset(buf, 0, sizeof(buf));
    if (recv(sock_fd, buf, sizeof(buf), 0) < 0) {
        perror("Error receiving data");
        return 1;
    }
    printf("%s", buf);

    // list all emails
    sprintf(buf, "LIST\r\n");
    if (send(sock_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending data");
        return 1;
    }

    memset(buf, 0, sizeof(buf));
    if (recv(sock_fd, buf, sizeof(buf), 0) < 0) {
        perror("Error receiving data");
        return 1;
    }
    printf("%s", buf);

    // retrieve the first email
    printf("Enter the email number to retrieve: ");
    int email_num;
    scanf("%d", &email_num);

    sprintf(buf, "RETR %d\r\n", email_num);
    if (send(sock_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending data");
        return 1;
    }

    memset(buf, 0, sizeof(buf));
    if (recv(sock_fd, buf, sizeof(buf), 0) < 0) {
        perror("Error receiving data");
        return 1;
    }
    printf("%s", buf);

    // quit connection
    sprintf(buf, "QUIT\r\n");
    if (send(sock_fd, buf, strlen(buf), 0) < 0) {
        perror("Error sending data");
        return 1;
    }

    memset(buf, 0, sizeof(buf));
    if (recv(sock_fd, buf, sizeof(buf), 0) < 0) {
        perror("Error receiving data");
        return 1;
    }
    printf("%s", buf);

    // close socket
    close(sock_fd);

    return 0;
}