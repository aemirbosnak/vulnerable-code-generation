//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
// POP3 client example program in an introspective style
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// POP3 client struct
struct pop3_client {
    int sockfd; // socket file descriptor
    char *host; // server hostname
    char *user; // username
    char *pass; // password
};

// POP3 client functions
void pop3_connect(struct pop3_client *client);
void pop3_login(struct pop3_client *client);
void pop3_list(struct pop3_client *client);
void pop3_retr(struct pop3_client *client, int num);
void pop3_quit(struct pop3_client *client);

// POP3 client main function
int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc < 3) {
        printf("Usage: %s <host> <user> <pass>\n", argv[0]);
        return 1;
    }

    // initialize pop3 client struct
    struct pop3_client client;
    client.host = argv[1];
    client.user = argv[2];
    client.pass = argv[3];

    // connect to POP3 server
    pop3_connect(&client);

    // login to POP3 server
    pop3_login(&client);

    // list all emails in inbox
    pop3_list(&client);

    // retrieve first email
    pop3_retr(&client, 1);

    // quit POP3 session
    pop3_quit(&client);

    return 0;
}

// connect to POP3 server
void pop3_connect(struct pop3_client *client) {
    // create socket
    client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // set up address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    server_addr.sin_addr.s_addr = inet_addr(client->host);

    // connect to server
    if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }
}

// login to POP3 server
void pop3_login(struct pop3_client *client) {
    // send login request
    char request[] = "USER ";
    strcat(request, client->user);
    strcat(request, "\r\n");
    send(client->sockfd, request, strlen(request), 0);

    // receive response
    char response[256];
    recv(client->sockfd, response, sizeof(response), 0);
    printf("%s\n", response);

    // send password
    request[0] = '\0';
    strcat(request, "PASS ");
    strcat(request, client->pass);
    strcat(request, "\r\n");
    send(client->sockfd, request, strlen(request), 0);

    // receive response
    recv(client->sockfd, response, sizeof(response), 0);
    printf("%s\n", response);
}

// list all emails in inbox
void pop3_list(struct pop3_client *client) {
    // send LIST request
    char request[] = "LIST\r\n";
    send(client->sockfd, request, strlen(request), 0);

    // receive response
    char response[256];
    recv(client->sockfd, response, sizeof(response), 0);
    printf("%s\n", response);
}

// retrieve email
void pop3_retr(struct pop3_client *client, int num) {
    // send RETR request
    char request[256];
    sprintf(request, "RETR %d\r\n", num);
    send(client->sockfd, request, strlen(request), 0);

    // receive response
    char response[256];
    recv(client->sockfd, response, sizeof(response), 0);
    printf("%s\n", response);
}

// quit POP3 session
void pop3_quit(struct pop3_client *client) {
    // send QUIT request
    char request[] = "QUIT\r\n";
    send(client->sockfd, request, strlen(request), 0);

    // receive response
    char response[256];
    recv(client->sockfd, response, sizeof(response), 0);
    printf("%s\n", response);

    // close socket
    close(client->sockfd);
}