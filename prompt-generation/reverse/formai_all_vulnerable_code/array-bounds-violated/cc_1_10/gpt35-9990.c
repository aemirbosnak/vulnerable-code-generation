//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char* argv[]){
    // Check if all arguments are provided
    if(argc != 4) {
        printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(1);
    }
    
    char *hostname = argv[1];
    char *port = argv[2];
    char *message = argv[3];
    
    // Get host information based on name or IP address
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if(getaddrinfo(hostname, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        exit(1);
    }

    // Create a socket
    int sock_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(sock_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    if(connect(sock_fd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(1);
    }

    // Send message to the server
    if(send(sock_fd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from the server
    char buffer[MAX_BUFFER_SIZE] = {'\0'};
    int recv_bytes = recv(sock_fd, buffer, MAX_BUFFER_SIZE-1, 0);
    if(recv_bytes < 0) {
        perror("recv");
        exit(1);
    }
    buffer[recv_bytes] = '\0';
    printf("%s\n", buffer);

    // Close the socket
    close(sock_fd);

    return 0;
}