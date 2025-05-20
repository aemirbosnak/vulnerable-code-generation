//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    int sockfd, bytes_received, msg_len;
    struct hostent *he;
    struct sockaddr_in server_addr;
    char recv_buffer[MAX_BUFFER_SIZE], send_buffer[MAX_BUFFER_SIZE];

    if(argc < 2) {
        printf("Please provide the IMAP server hostname.\n");
        exit(EXIT_FAILURE);
    }

    if((he = gethostbyname(argv[1])) == NULL) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // login to IMAP server
    snprintf(send_buffer, MAX_BUFFER_SIZE, ". login %s %s\n", argv[2], argv[3]);
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bytes_received = recv(sockfd, recv_buffer, MAX_BUFFER_SIZE, 0);
    recv_buffer[bytes_received] = '\0';
    printf("%s", recv_buffer);

    // select INBOX
    snprintf(send_buffer, MAX_BUFFER_SIZE, ". select INBOX\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bytes_received = recv(sockfd, recv_buffer, MAX_BUFFER_SIZE, 0);
    recv_buffer[bytes_received] = '\0';
    printf("%s", recv_buffer);

    // get message count
    snprintf(send_buffer, MAX_BUFFER_SIZE, ". search ALL\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bytes_received = recv(sockfd, recv_buffer, MAX_BUFFER_SIZE, 0);
    recv_buffer[bytes_received] = '\0';
    printf("%s", recv_buffer);

    // fetch first message
    snprintf(send_buffer, MAX_BUFFER_SIZE, ". fetch 1 body[header]\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bytes_received = recv(sockfd, recv_buffer, MAX_BUFFER_SIZE, 0);
    recv_buffer[bytes_received] = '\0';
    printf("%s", recv_buffer);

    // logout
    snprintf(send_buffer, MAX_BUFFER_SIZE, ". logout\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    bytes_received = recv(sockfd, recv_buffer, MAX_BUFFER_SIZE, 0);
    recv_buffer[bytes_received] = '\0';
    printf("%s", recv_buffer);

    close(sockfd);
    return 0;
}