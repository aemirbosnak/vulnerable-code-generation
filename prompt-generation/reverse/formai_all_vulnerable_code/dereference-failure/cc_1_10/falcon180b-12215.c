//Falcon-180B DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX 100

// function to resolve domain name into IP address
void resolve_domain(char *domain, struct sockaddr_in *addr) {
    struct hostent *host = gethostbyname(domain);
    if (host == NULL) {
        printf("ERROR: Unable to resolve hostname\n");
        exit(1);
    }
    memcpy(&addr->sin_addr, host->h_addr, host->h_length);
    addr->sin_family = AF_INET;
}

// function to establish TCP connection with server
int connect_to_server(char *domain, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("ERROR: Unable to create socket\n");
        exit(1);
    }
    resolve_domain(domain, &server_addr);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("ERROR: Unable to connect to server\n");
        exit(1);
    }
    printf("Connected to server\n");
    return sockfd;
}

// function to send message to server
void send_message(int sockfd, char *message) {
    send(sockfd, message, strlen(message), 0);
}

// function to receive message from server
char *receive_message(int sockfd) {
    char buffer[MAX];
    memset(buffer, 0, MAX);
    recv(sockfd, buffer, MAX, 0);
    return buffer;
}

// main function
int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program <domain> <port> <message>\n");
        exit(1);
    }
    char *domain = argv[1];
    int port = atoi(argv[2]);
    char *message = argv[3];

    // establish TCP connection with server
    int sockfd = connect_to_server(domain, port);

    // send message to server
    send_message(sockfd, message);

    // receive message from server
    char *response = receive_message(sockfd);
    printf("Response from server: %s\n", response);

    // close socket
    close(sockfd);
    return 0;
}