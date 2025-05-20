//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    char buffer[MAX_BUFFER_SIZE];
    int socket_fd, num_bytes_read;

    if(argc < 2) {
        printf("Usage: %s <email_address>\n", argv[0]);
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if(inet_pton(AF_INET, "localhost", &(server.sin_addr)) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if(connect(socket_fd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Please enter your email message:\n");
    gets(buffer);

    if(send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    num_bytes_read = recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0);
    if(num_bytes_read <= 0) {
        perror("recv");
        return 1;
    }

    printf("Received: %s\n", buffer);

    close(socket_fd);
    return 0;
}