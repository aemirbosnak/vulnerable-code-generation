//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define RECV_BUFF_SIZE 2048

int connect_to_imap_server(char *server, char *port)
{
    int sockfd, ret, opt = 1;
    struct addrinfo hints, *result, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((ret = getaddrinfo(server, port, &hints, &result)) != 0)
    {
        fprintf(stderr, "Error in getaddrinfo: %s\n", gai_strerror(ret));
        exit(EXIT_FAILURE);
    }

    // Loop through all the results and connect to the first we can
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1)
            continue;

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }

        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1)
            break;

        close(sockfd);
    }

    if (rp == NULL)
    {
        fprintf(stderr, "Could not connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(result);

    return sockfd;
}

int main(int argc, char **argv)
{
    int sockfd, n;
    char recv_buff[RECV_BUFF_SIZE + 1];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s server port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Connect to the IMAP server
    sockfd = connect_to_imap_server(argv[1], argv[2]);

    // Receive the server greeting
    n = recv(sockfd, recv_buff, RECV_BUFF_SIZE, 0);

    if (n == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    recv_buff[n] = '\0';
    printf("%s", recv_buff);

    // Send the login command
    char *user = "username";
    char *pass = "password";
    char login_command[100];

    sprintf(login_command, "LOGIN %s %s\r\n", user, pass);
    n = send(sockfd, login_command, strlen(login_command), 0);

    if (n == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the login response
    n = recv(sockfd, recv_buff, RECV_BUFF_SIZE, 0);

    if (n == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    recv_buff[n] = '\0';
    printf("%s", recv_buff);

    // Send the select command
    char *mailbox = "INBOX";
    char select_command[100];

    sprintf(select_command, "SELECT %s\r\n", mailbox);
    n = send(sockfd, select_command, strlen(select_command), 0);

    if (n == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the select response
    n = recv(sockfd, recv_buff, RECV_BUFF_SIZE, 0);

    if (n == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    recv_buff[n] = '\0';
    printf("%s", recv_buff);

    // Send the fetch command
    char fetch_command[100];

    sprintf(fetch_command, "FETCH 1 BODY[TEXT]\r\n");
    n = send(sockfd, fetch_command, strlen(fetch_command), 0);

    if (n == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the fetch response
    n = recv(sockfd, recv_buff, RECV_BUFF_SIZE, 0);

    if (n == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    recv_buff[n] = '\0';
    printf("%s", recv_buff);

    // Logout of the IMAP server
    n = send(sockfd, "LOGOUT\r\n", 8, 0);

    if (n == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}