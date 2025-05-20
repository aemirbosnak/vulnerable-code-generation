//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <time.h>

#define MAX_MSG_LEN 1024
#define MAX_SERVER_NAME_LEN 256

int main(int argc, char **argv)
{
    if (argc!= 6) {
        fprintf(stderr, "Usage: %s <host> <port> <sender> <recipient> <subject> <message>\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_SERVER_NAME_LEN] = "";
    char *host = argv[1];
    int port = atoi(argv[2]);
    char sender[MAX_MSG_LEN] = "";
    char recipient[MAX_MSG_LEN] = "";
    char subject[MAX_MSG_LEN] = "";
    char message[MAX_MSG_LEN] = "";
    memset(sender, 0, sizeof(sender));
    memset(recipient, 0, sizeof(recipient));
    memset(subject, 0, sizeof(subject));
    memset(message, 0, sizeof(message));

    strcpy(hostname, host);
    strcpy(sender, argv[3]);
    strcpy(recipient, argv[4]);
    strcpy(subject, argv[5]);
    strcpy(message, argv[6]);

    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int client_addr_len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR: Failed to create socket.\n");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Invalid hostname.\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to connect to the server.\n");
        exit(1);
    }

    int msg_len = strlen(message);
    bzero((char *) &cli_addr, sizeof(cli_addr));
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_port = htons(5000);
    cli_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to bind socket.\n");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        fprintf(stderr, "ERROR: Failed to listen on socket.\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &cli_addr, sizeof(cli_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to connect to client.\n");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(struct timeval)) < 0) {
        fprintf(stderr, "ERROR: Failed to set socket timeout.\n");
        exit(1);
    }

    if (recv(sockfd, (char *)&msg_len, sizeof(msg_len), 0) < 0) {
        fprintf(stderr, "ERROR: Failed to receive message length from client.\n");
        exit(1);
    }

    if (msg_len > MAX_MSG_LEN) {
        fprintf(stderr, "ERROR: Message is too long.\n");
        exit(1);
    }

    char buf[MAX_MSG_LEN];
    bzero(buf, MAX_MSG_LEN);

    if (recv(sockfd, buf, MAX_MSG_LEN, 0) < 0) {
        fprintf(stderr, "ERROR: Failed to receive message from client.\n");
        exit(1);
    }

    buf[msg_len] = '\0';

    if (send(sockfd, sender, strlen(sender), 0) < 0) {
        fprintf(stderr, "ERROR: Failed to send sender to server.\n");
        exit(1);
    }

    if (send(sockfd, recipient, strlen(recipient), 0) < 0) {
        fprintf(stderr, "ERROR: Failed to send recipient to server.\n");
        exit(1);
    }

    if (send(sockfd, subject, strlen(subject), 0) < 0) {
        fprintf(stderr, "ERROR: Failed to send subject to server.\n");
        exit(1);
    }

    if (send(sockfd, buf, msg_len, 0) < 0) {
        fprintf(stderr, "ERROR: Failed to send message to server.\n");
        exit(1);
    }

    if (close(sockfd) < 0) {
        fprintf(stderr, "ERROR: Failed to close socket.\n");
        exit(1);
    }

    return 0;
}