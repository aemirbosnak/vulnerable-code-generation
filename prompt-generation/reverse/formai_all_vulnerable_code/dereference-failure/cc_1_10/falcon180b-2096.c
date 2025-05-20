//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define SERVER_PORT 12345

struct sockaddr_in server_addr;
char *server_ip;
int sockfd, bytes_received, bytes_sent;
char buffer[MAX];

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int create_socket() {
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
    }
    return sockfd;
}

int connect_to_server(int sockfd, char *ip, int port) {
    struct hostent *server;
    server = gethostbyname(ip);
    if (server == NULL) {
        error_handling("no such host");
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = *(unsigned long *) server->h_addr;
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error_handling("connect failed");
    }
}

int send_data(int sockfd, char *data) {
    if (send(sockfd, data, strlen(data), 0) < 0) {
        error_handling("send failed");
    }
}

int receive_data(int sockfd, char *buffer) {
    if ((bytes_received = recv(sockfd, buffer, MAX, 0)) < 0) {
        error_handling("recv failed");
    }
    buffer[bytes_received] = '\0';
}

int main() {
    char ip[MAX];
    printf("Enter the IP address of the server: ");
    scanf("%s", ip);
    server_ip = ip;
    sockfd = create_socket();
    connect_to_server(sockfd, server_ip, SERVER_PORT);
    send_data(sockfd, "PING");
    receive_data(sockfd, buffer);
    printf("Received response: %s\n", buffer);
    close(sockfd);
    return 0;
}