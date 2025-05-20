//FormAI DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT "80" // port to connect to
#define DATA_SIZE 1024 // size of data to send
#define TIMEOUT 5 // timeout for connection

// function to calculate the time difference
double timediff(struct timespec start, struct timespec end) {
    double elapsed_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1e9;
    return elapsed_time;
}

int main(int argc, char *argv[]) {
    // check if hostname is provided as an argument
    if(argc < 2) {
        printf("Please specify hostname as argument.\n");
        return 1;
    }

    char *hostname = argv[1];
    struct addrinfo hints, *res;
    struct sockaddr_in *saddr;
    int sockfd;
    double elapsed_time;

    // set up hints struct with relevant options
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    // get the IP address of the hostname provided
    int status = getaddrinfo(hostname, PORT, &hints, &res);
    if(status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        return 1;
    }

    saddr = (struct sockaddr_in *)res->ai_addr;

    // create a socket for connecting to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    // connect to the server and measure the time it takes
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    status = connect(sockfd, (struct sockaddr *)saddr, sizeof *saddr);
    clock_gettime(CLOCK_REALTIME, &end);
    elapsed_time = timediff(start, end);

    if(status == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    // send some random data to the server
    char data[DATA_SIZE];
    memset(data, 'a', DATA_SIZE);
    int bytes_sent = send(sockfd, data, DATA_SIZE, 0);
    if(bytes_sent == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    // set a timeout for receiving data from the server
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv);

    // receive some data from the server
    char received_data[DATA_SIZE];
    memset(received_data, 0, DATA_SIZE);
    int bytes_received = recv(sockfd, received_data, DATA_SIZE, 0);
    if(bytes_received == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    // print the results
    printf("Ping to %s (%s) took %f seconds.\n", hostname, inet_ntoa(saddr->sin_addr), elapsed_time);
    printf("Sent %d bytes of data to the server.\n", bytes_sent);
    printf("Received %d bytes of data from the server: %s\n", bytes_received, received_data);

    // close the socket and free the memory used by res
    close(sockfd);
    freeaddrinfo(res);

    return 0;
}