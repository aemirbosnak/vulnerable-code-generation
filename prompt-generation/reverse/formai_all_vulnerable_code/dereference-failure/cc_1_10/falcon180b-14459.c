//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

// Function to print usage instructions
void print_usage(char *prog_name) {
    printf("Usage: %s <hostname/IP address> <port number>\n", prog_name);
}

// Function to resolve hostname/IP address to IP address
int resolve_host(char *hostname, struct sockaddr_in *addr) {
    struct hostent *hostent;
    if ((hostent = gethostbyname(hostname)) == NULL) {
        printf("Error: couldn't resolve hostname '%s'\n", hostname);
        return -1;
    }
    memcpy(&addr->sin_addr, hostent->h_addr, hostent->h_length);
    addr->sin_family = AF_INET;
    return 0;
}

// Function to send a ping request and receive a response
int ping(int sockfd, char *hostname, int port) {
    struct sockaddr_in serv_addr;
    struct timeval timeout;
    int ret;

    // Resolve hostname to IP address
    if (resolve_host(hostname, &serv_addr)!= 0) {
        return -1;
    }

    // Set up socket for sending and receiving data
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        printf("Error: couldn't create socket\n");
        return -1;
    }
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))!= 0) {
        printf("Error: couldn't connect to server\n");
        return -1;
    }

    // Set up timeout for receiving response
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Send ping request
    char data[MAX_DATA_LEN];
    strcpy(data, "PING");
    send(sockfd, data, strlen(data), 0);

    // Receive response
    char response[MAX_DATA_LEN];
    memset(response, 0, sizeof(response));
    ret = recv(sockfd, response, sizeof(response), 0);
    if (ret < 0) {
        printf("Error: couldn't receive response\n");
        return -1;
    }

    // Close socket
    close(sockfd);

    // Check if response is valid
    if (ret < 4 || strncmp(response, "PONG", 4)!= 0) {
        printf("Error: invalid response received\n");
        return -1;
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage(argv[0]);
        return 1;
    }

    // Ping the specified hostname/IP address and port number
    int sockfd;
    if ((sockfd = ping(argv[1], argv[2], atoi(argv[2])))!= 0) {
        return sockfd;
    }

    printf("Ping successful!\n");
    return 0;
}