//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

/* Function to get the IP address and port number from the user */
void get_ip_port(char *ip, int *port) {
    printf("Enter the IP address: ");
    scanf("%s", ip);
    printf("Enter the port number: ");
    scanf("%d", port);
}

/* Function to establish a TCP connection with the server */
int tcp_connect(const char *ip, int port) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    int rv;

    /* Get the address information for the server */
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    rv = getaddrinfo(ip, NULL, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    /* Connect to the server */
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

/* Function to send a HTTP request to the server */
void send_request(int sockfd, const char *method, const char *path, const char *version) {
    char request[BUFFER_SIZE];
    sprintf(request, "%s %s HTTP/%s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, version, "localhost");
    send(sockfd, request, strlen(request), 0);
}

/* Function to receive a HTTP response from the server */
void receive_response(int sockfd, char *buffer) {
    int bytes_received = 0;
    while (bytes_received < BUFFER_SIZE) {
        int rv = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (rv == 0) {
            fprintf(stderr, "Connection closed by server\n");
            exit(1);
        } else if (rv == -1) {
            perror("recv");
            exit(1);
        }
        bytes_received += rv;
    }
    buffer[bytes_received] = '\0';
}

/* Function to print the HTTP response from the server */
void print_response(const char *response) {
    printf("HTTP response:\n%s", response);
}

int main() {
    char ip[BUFFER_SIZE];
    int port;
    get_ip_port(ip, &port);
    int sockfd = tcp_connect(ip, port);
    char buffer[BUFFER_SIZE];

    /* Send a GET request to the server */
    send_request(sockfd, "GET", "/", "1.1");

    /* Receive the response from the server */
    receive_response(sockfd, buffer);
    print_response(buffer);

    close(sockfd);
    return 0;
}