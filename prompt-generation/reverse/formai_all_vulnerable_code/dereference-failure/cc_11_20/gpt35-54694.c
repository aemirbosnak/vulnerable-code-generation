//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>

#define IMAP_PORT 143

int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s <imap_server> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *he = gethostbyname(argv[1]);
    if(he == NULL){
        perror("Error: Cannot resolve hostname");
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0){
        perror("Error: Cannot create socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr*)he->h_addr);
    server_addr.sin_port = htons(IMAP_PORT);

    if(connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("Error: Cannot connect to server");
        exit(EXIT_FAILURE);
    }

    char buf[512];
    int num_bytes;

    // receive welcome message
    num_bytes = recv(sock_fd, buf, sizeof(buf), 0);
    if(num_bytes < 0){
        perror("Error: Cannot receive from server");
        exit(EXIT_FAILURE);
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);

    // login
    sprintf(buf, "login %s password\n", argv[2]);
    if(send(sock_fd, buf, strlen(buf), 0) < 0){
        perror("Error: Cannot send login command");
        exit(EXIT_FAILURE);
    }

    // receive login response
    num_bytes = recv(sock_fd, buf, sizeof(buf), 0);
    if(num_bytes < 0){
        perror("Error: Cannot receive from server");
        exit(EXIT_FAILURE);
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);

    // list all messages
    sprintf(buf, "list\n");
    if(send(sock_fd, buf, strlen(buf), 0) < 0){
        perror("Error: Cannot send list command");
        exit(EXIT_FAILURE);
    }

    // receive list response
    num_bytes = recv(sock_fd, buf, sizeof(buf), 0);
    if(num_bytes < 0){
        perror("Error: Cannot receive from server");
        exit(EXIT_FAILURE);
    }
    buf[num_bytes] = '\0';
    printf("%s", buf);

    // logout
    sprintf(buf, "logout\n");
    if(send(sock_fd, buf, strlen(buf), 0) < 0){
        perror("Error: Cannot send logout command");
        exit(EXIT_FAILURE);
    }

    close(sock_fd);

    return 0;
}