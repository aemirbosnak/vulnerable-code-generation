//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in serv_addr;
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    long int start, end;
    double time_taken;
    
    if (argc < 2) {
        printf("Usage: %s <Server IP>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
        error("Invalid server IP address");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    printf("Connected successfully...\n");

    // start timer
    start = clock();

    // send data to the server
    char* msg = "Test data from client";
    n = write(sockfd, msg, strlen(msg));
    if (n < 0) {
        error("Error sending data to server");
    }

    // receive data from the server
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        error("Error receiving data from server");
    }

    // end timer
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Received: %s\n", buffer);
    printf("Time taken: %f seconds\n", time_taken);

    // close the socket
    close(sockfd);

    return 0;
}