//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: irregular
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 65536
#define OK 200
#define BAD_REQUEST 400

int port = 3000;

int main() {
    int sockfd;
    struct sockaddr_in addr;
    char request_message[MAX_PACKET_SIZE], response_message[MAX_PACKET_SIZE];
    char *ip_address = "127.0.0.1";
    int request_size, response_size;

    // initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // bind socket to IP and port
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    srand(time(0)); // seed for random values

    while (1) {
        // generate random request message
        int rand_num = rand() % 1000 + 1; // random number between 1-1000
        sprintf(request_message, "Request %d", rand_num);

        // send request to server
        request_size = strlen(request_message);
        if (send(sockfd, request_message, request_size, 0) == -1) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        // receive response from server
        response_size = recv(sockfd, response_message, MAX_PACKET_SIZE, 0);
        if (response_size == -1) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        // check response status code
        int status_code;
        sscanf(response_message, "HTTP/1.1 %d", &status_code);

        // print results based on status code
        if (status_code == OK) {
            printf("%s\n", response_message); // print entire response message
        } else if (status_code == BAD_REQUEST) {
            printf("Request %d: Bad Request\n", rand_num); // print request number and response message
        } else {
            printf("Request %d: Error\n", rand_num); // print request number and response message
        }
    }

    close(sockfd);
    return 0;
}