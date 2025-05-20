//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

/* function to get current timestamp */
char* getCurrentTime() {
    time_t now = time(0);
    return ctime(&now);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    // create socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        return -1;
    }

    // set server details
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Google DNS server
    servaddr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error: Connection with the server failed\n");
        return -1;
    }

    // get user input for number of iterations
    int iterations;
    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    // loop for number of iterations
    for (int i = 0; i < iterations; i++) {

        // send data to server
        char* sendData = "Hello from client";
        send(sockfd, sendData, strlen(sendData), 0);

        // receive data from server
        char buffer[BUFFER_SIZE];
        int n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        buffer[n] = '\0';

        // calculate time taken
        clock_t start, end;
        double cpu_time_used;
        start = clock();

        // repeat sending and receiving until BUFFER_SIZE is reached
        while (n < BUFFER_SIZE) {
            send(sockfd, sendData, strlen(sendData), 0);
            n = recv(sockfd, buffer, BUFFER_SIZE, 0);
            buffer[n] = '\0';
        }

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // print result
        printf("Iteration %d:\n", i + 1);
        printf("Time taken: %f seconds\n", cpu_time_used);
        printf("Received: %s\n\n", buffer);

        // wait for 1 second before next iteration
        sleep(1);
    }

    // close socket connection
    close(sockfd);

    return 0;
}