//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024

void print_help() {
    printf("Usage:./ping <host> <port>\n");
    printf("      ./ping -h\n");
}

void print_error(const char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char** argv) {
    if(argc < 3) {
        print_help();
        return 1;
    }

    char* host = argv[1];
    char* port = argv[2];
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    struct timeval timeout;
    fd_set readfds;
    char send_data[BUFFER_SIZE];
    char recv_data[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        print_error("Error creating socket");
    }

    server = gethostbyname(host);
    if(server == NULL) {
        print_error("Invalid host");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*)server->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        print_error("Error connecting to host");
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    if(select(sockfd+1, &readfds, NULL, NULL, &timeout) < 0) {
        print_error("Error selecting socket");
    }

    if(FD_ISSET(sockfd, &readfds)) {
        n = recv(sockfd, recv_data, BUFFER_SIZE, 0);
        if(n < 0) {
            print_error("Error receiving data");
        }
        recv_data[n] = '\0';
        printf("Response: %s\n", recv_data);
    } else {
        printf("No response received\n");
    }

    close(sockfd);
    return 0;
}