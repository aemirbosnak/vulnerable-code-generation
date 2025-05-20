//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_TIMEOUT 30

struct pop3_client {
    int sockfd;
    char *server_ip;
    char *username;
    char *password;
};

int pop3_connect(struct pop3_client *client) {
    struct sockaddr_in server_addr;
    int server_fd;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket()");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(client->server_ip);

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        return -1;
    }

    client->sockfd = server_fd;
    return 0;
}

int pop3_login(struct pop3_client *client) {
    char buf[1024];
    char cmd[128];

    sprintf(cmd, "USER %s\r\n", client->username);
    if (write(client->sockfd, cmd, strlen(cmd)) < 0) {
        perror("write()");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) < 0) {
        perror("read()");
        return -1;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        return -1;
    }

    sprintf(cmd, "PASS %s\r\n", client->password);
    if (write(client->sockfd, cmd, strlen(cmd)) < 0) {
        perror("write()");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) < 0) {
        perror("read()");
        return -1;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        return -1;
    }

    return 0;
}

int pop3_retr(struct pop3_client *client, int msg_id) {
    char buf[1024];
    char cmd[128];

    sprintf(cmd, "RETR %d\r\n", msg_id);
    if (write(client->sockfd, cmd, strlen(cmd)) < 0) {
        perror("write()");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) < 0) {
        perror("read()");
        return -1;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        return -1;
    }

    return 0;
}

int pop3_quit(struct pop3_client *client) {
    char buf[1024];
    char cmd[128];

    sprintf(cmd, "QUIT\r\n");
    if (write(client->sockfd, cmd, strlen(cmd)) < 0) {
        perror("write()");
        return -1;
    }

    if (read(client->sockfd, buf, sizeof(buf)) < 0) {
        perror("read()");
        return -1;
    }

    if (strncmp(buf, "+OK", 3) != 0) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    struct pop3_client client;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <username>\n", argv[0]);
        return -1;
    }

    client.server_ip = argv[1];
    client.username = argv[2];

    if (pop3_connect(&client) < 0) {
        fprintf(stderr, "Failed to connect to server\n");
        return -1;
    }

    if (pop3_login(&client) < 0) {
        fprintf(stderr, "Failed to login\n");
        return -1;
    }

    if (pop3_retr(&client, 1) < 0) {
        fprintf(stderr, "Failed to retrieve message\n");
        return -1;
    }

    if (pop3_quit(&client) < 0) {
        fprintf(stderr, "Failed to quit\n");
        return -1;
    }

    return 0;
}