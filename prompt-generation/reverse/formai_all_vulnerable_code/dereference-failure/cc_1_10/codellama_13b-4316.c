//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
// POP3 client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_CMD_RETR 1
#define POP3_CMD_QUIT 2
#define POP3_CMD_USER 3
#define POP3_CMD_PASS 4
#define POP3_CMD_LIST 5

typedef struct {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[64];
    char password[64];
    int msg_num;
    char **msg_list;
} pop3_client;

int pop3_init(pop3_client *c, char *server, int port) {
    c->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    c->server_addr.sin_family = AF_INET;
    c->server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &c->server_addr.sin_addr);
    return 0;
}

int pop3_connect(pop3_client *c) {
    connect(c->sockfd, (struct sockaddr *)&c->server_addr, sizeof(c->server_addr));
    return 0;
}

int pop3_send_cmd(pop3_client *c, char *cmd) {
    send(c->sockfd, cmd, strlen(cmd), 0);
    return 0;
}

int pop3_recv_resp(pop3_client *c, char *resp) {
    recv(c->sockfd, resp, 1024, 0);
    return 0;
}

int pop3_login(pop3_client *c, char *username, char *password) {
    char cmd[1024];
    char resp[1024];
    sprintf(cmd, "USER %s\r\n", username);
    pop3_send_cmd(c, cmd);
    pop3_recv_resp(c, resp);
    sprintf(cmd, "PASS %s\r\n", password);
    pop3_send_cmd(c, cmd);
    pop3_recv_resp(c, resp);
    return 0;
}

int pop3_list(pop3_client *c, int *msg_num, char ***msg_list) {
    char cmd[1024];
    char resp[1024];
    sprintf(cmd, "LIST\r\n");
    pop3_send_cmd(c, cmd);
    pop3_recv_resp(c, resp);
    *msg_num = atoi(resp);
    *msg_list = (char **)malloc(sizeof(char *) * (*msg_num));
    for (int i = 0; i < *msg_num; i++) {
        pop3_recv_resp(c, resp);
        (*msg_list)[i] = strdup(resp);
    }
    return 0;
}

int pop3_retr(pop3_client *c, int msg_num, char **msg_body) {
    char cmd[1024];
    char resp[1024];
    sprintf(cmd, "RETR %d\r\n", msg_num);
    pop3_send_cmd(c, cmd);
    pop3_recv_resp(c, resp);
    *msg_body = strdup(resp);
    return 0;
}

int pop3_quit(pop3_client *c) {
    char cmd[1024];
    char resp[1024];
    sprintf(cmd, "QUIT\r\n");
    pop3_send_cmd(c, cmd);
    pop3_recv_resp(c, resp);
    close(c->sockfd);
    return 0;
}

int main() {
    pop3_client c;
    int msg_num;
    char **msg_list;
    char *msg_body;
    pop3_init(&c, "pop.example.com", POP3_PORT);
    pop3_connect(&c);
    pop3_login(&c, "user1", "password1");
    pop3_list(&c, &msg_num, &msg_list);
    pop3_retr(&c, msg_num, &msg_body);
    printf("%s\n", msg_body);
    pop3_quit(&c);
    return 0;
}