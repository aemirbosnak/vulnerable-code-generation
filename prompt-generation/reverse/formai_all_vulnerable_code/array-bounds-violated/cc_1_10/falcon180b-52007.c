//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]) {

    if(argc!= 4) {
        printf("Usage: %s <IP Address> <Port> <Message>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port = atoi(argv[2]);
    char *message = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct hostent *server = gethostbyname(ip_address);
    if(server == NULL) {
        printf("Error: No such host\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    char buf[MAX_BUF_SIZE];
    sprintf(buf, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", ip_address);

    send(sockfd, buf, strlen(buf), 0);

    char response[MAX_BUF_SIZE];
    memset(response, 0, sizeof(response));

    int bytes_received = 0;
    while((bytes_received = recv(sockfd, response + bytes_received, MAX_BUF_SIZE - bytes_received, 0)) > 0) {
        response[bytes_received] = '\0';
    }

    printf("Response:\n%s\n", response);

    close(sockfd);

    return 0;
}