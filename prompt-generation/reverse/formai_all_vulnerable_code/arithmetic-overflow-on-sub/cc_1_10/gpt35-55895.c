//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <math.h>

#define PORT 8080
#define MAXLINE 1024

int main(){
    int sockfd, n;
    long double total_time = 0;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];

    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
  
    memset(&servaddr, 0, sizeof(servaddr));
  
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Starting the timer
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Connects the socket referred to by the file descriptor sockfd
    // to the address specified by addr.
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // End the timer
    gettimeofday(&end, NULL);

    // Calculates the connection time in seconds
    total_time += (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec)/1000000.0);

    while (1){
        printf("Enter message to send to server: ");
        memset(buffer, 0, MAXLINE);

        // User inputs message to send to server
        fgets(buffer, MAXLINE, stdin);

        // Send the message to server
        write(sockfd, buffer, strlen(buffer));

        if (strcmp(buffer, "exit\n")==0){
            printf("Client Exit...\n");
            break;
        }

        memset(buffer, 0, MAXLINE);

        // Read the message sent by server
        n = read(sockfd, buffer, MAXLINE);

        if (n< 0){
            perror("Read error");
            exit(EXIT_FAILURE);
        }

        printf("From Server: %s", buffer);
    }

    // Prints the total connection time in seconds
    printf("Total connection time in seconds: %Lf \n", total_time);
    
    close(sockfd);
    return 0;
}