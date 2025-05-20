//FormAI DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define MIN_PORT 1
#define MAX_PORT 65535
#define TIMEOUT 2

int scanPort(char *target, int port){
    int sock, result;
    struct sockaddr_in targetAddr;

    // Create the socket
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock == -1){
        perror("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    // Set targetAddr fields
    targetAddr.sin_family = AF_INET; // IPv4
    targetAddr.sin_port = htons(port); // Convert from host to network order
    result = inet_pton(AF_INET, target, &targetAddr.sin_addr); // Convert dotted quad to binary
    if(result == 0){
        printf("%s is not a valid IP address\n", target);
        exit(EXIT_FAILURE);
    }
    else if(result == -1){
        perror("Error setting target address\n");
        exit(EXIT_FAILURE);
    }

    // Set the socket to non-blocking
    fcntl(sock, F_SETFL, O_NONBLOCK);

    // Attempt to connect to the target
    connect(sock, (struct sockaddr *)&targetAddr, sizeof(targetAddr));

    // Set a timeout for the connection
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(sock, &fds);
    int ready = select(sock + 1, NULL, &fds, NULL, &timeout);

    // Check if the connection was successful
    if(FD_ISSET(sock, &fds)){
        printf("%s:%d is open\n", target, port);
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target = argv[1];
    int port;

    for(port = MIN_PORT; port <= MAX_PORT; port++){
        scanPort(target, port);
    }

    return 0;
}