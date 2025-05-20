//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complete
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SERVER_ADDR "pop.somedomain.com"
#define SERVER_PORT "110"
#define BUFFER_SIZE 1024

int main(){
    int sock_fd, num_bytes;
    struct addrinfo hints;
    struct addrinfo *server_res, *rp;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(SERVER_ADDR, SERVER_PORT, &hints, &server_res) != 0){
        perror("getaddrinfo error");
        return 1;
    }

    for(rp = server_res; rp != NULL; rp = rp->ai_next){
        sock_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        if(sock_fd == -1){
            continue;
        }

        if(connect(sock_fd, rp->ai_addr, rp->ai_addrlen) == 0){
            break;
        }

        close(sock_fd);
    }

    if(rp == NULL){
        fprintf(stderr, "Could not connect to server\n");
        return 1;
    }

    freeaddrinfo(server_res);

    num_bytes = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);

    if(num_bytes == -1){
        perror("recv error");
        return 1;
    }

    buffer[num_bytes] = '\0';

    printf("%s", buffer);

    sprintf(command, "USER username\r\n");

    if(send(sock_fd, command, strlen(command), 0) == -1){
        perror("send error");
        return 1;
    }

    num_bytes = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);

    if(num_bytes == -1){
        perror("recv error");
        return 1;
    }

    buffer[num_bytes] = '\0';

    printf("%s", buffer);

    sprintf(command, "PASS password\r\n");

    if(send(sock_fd, command, strlen(command), 0) == -1){
        perror("send error");
        return 1;
    }

    num_bytes = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);

    if(num_bytes == -1){
        perror("recv error");
        return 1;
    }

    buffer[num_bytes] = '\0';

    printf("%s", buffer);

    sprintf(command, "LIST\r\n");

    if(send(sock_fd, command, strlen(command), 0) == -1){
        perror("send error");
        return 1;
    }

    num_bytes = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);

    if(num_bytes == -1){
        perror("recv error");
        return 1;
    }

    buffer[num_bytes] = '\0';

    printf("%s", buffer);

    sprintf(command, "QUIT\r\n");

    if(send(sock_fd, command, strlen(command), 0) == -1){
        perror("send error");
        return 1;
    }

    num_bytes = recv(sock_fd, buffer, BUFFER_SIZE-1, 0);

    if(num_bytes == -1){
        perror("recv error");
        return 1;
    }

    buffer[num_bytes] = '\0';

    printf("%s", buffer);

    close(sock_fd);

    return 0;
}