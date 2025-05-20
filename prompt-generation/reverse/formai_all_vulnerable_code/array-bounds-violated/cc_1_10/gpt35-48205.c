//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 2048
#define SERVER_PORT 110

int create_socket(const char *hostname) {
    struct addrinfo hints, *results, *p;
    int sockfd;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    getaddrinfo(hostname, "pop3", &hints, &results);
    
    for (p = results; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) != -1) {
            break;
        }
        close(sockfd);
    }
    
    freeaddrinfo(results);
    
    if (p == NULL) {
        printf("Error: connection failed\n");
        return -1;
    }
    
    return sockfd;
}

void receive_data(int sockfd, char *response) {
    int bytes_received;
    char buffer[MAX_SIZE];
    while ((bytes_received = recv(sockfd, buffer, MAX_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        strcat(response, buffer);
        if (buffer[bytes_received-1] == '\n') {
            break;
        }   
    }
}

void send_data(int sockfd, const char *message) {
    write(sockfd, message, strlen(message));
}

int main(int argc, char *argv[]) {
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    int sockfd, state = 0;
    char response[MAX_SIZE];
    
    sockfd = create_socket(hostname);
    if (sockfd == -1) {
        return -1;
    }
    
    receive_data(sockfd, response);
    printf("%s", response);
    
    send_data(sockfd, "USER ");
    send_data(sockfd, username);
    send_data(sockfd, "\r\n");
    
    memset(response, 0, MAX_SIZE);
    receive_data(sockfd, response);
    printf("%s", response);
    
    send_data(sockfd, "PASS ");
    send_data(sockfd, password);
    send_data(sockfd, "\r\n");
    
    memset(response, 0, MAX_SIZE);
    receive_data(sockfd, response);
    printf("%s", response);
    
    send_data(sockfd, "LIST\r\n");
    
    memset(response, 0, MAX_SIZE);
    receive_data(sockfd, response);
    printf("%s", response);
    
    send_data(sockfd, "QUIT\r\n");
    
    memset(response, 0, MAX_SIZE);
    receive_data(sockfd, response);
    printf("%s", response);
    
    close(sockfd);
    
    return 0;
}