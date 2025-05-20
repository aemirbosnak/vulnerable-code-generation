//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to send a request to the server and receive a response
int send_request(int sockfd, char *server_ip, int port) {
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", server_ip);

    send(sockfd, request, strlen(request), 0);

    char response[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[bytes_received] = '\0';
        printf("%s", response);
    }

    if (bytes_received == -1) {
        error("Error receiving response");
    }

    return 0;
}

// Function to get the IP address of a domain name
char *get_ip_address(char *domain_name) {
    struct hostent *host;
    if ((host = gethostbyname(domain_name)) == NULL) {
        error("Invalid domain name");
    }

    return inet_ntoa(*(struct in_addr *)host->h_addr);
}

// Main function to test internet speed
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <domain_name>\n", argv[0]);
        return 1;
    }

    char *domain_name = argv[1];
    char *server_ip = get_ip_address(domain_name);
    int port = 80;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("Error connecting to server");
    }

    send_request(sockfd, server_ip, port);

    close(sockfd);

    return 0;
}