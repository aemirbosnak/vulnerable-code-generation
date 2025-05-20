//FormAI DATASET v1.0 Category: Networking ; Style: mathematical
/* This program demonstrates basic socket programming in C and the use of mathematical functions*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    double num1, num2;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    
    // Get user input
    printf("Enter two numbers to calculate their mean and standard deviation: ");
    scanf("%lf %lf", &num1, &num2);
    sprintf(buffer, "%lf %lf", num1, num2);
    
    // Send data to server 
    send(sock , buffer , strlen(buffer) , 0);
    printf("Sent: %lf, %lf\n", num1, num2);
    
    // Receive result from server
    valread = read(sock , buffer, 1024);
    buffer[valread] = '\0';
    printf("Received: %s\n", buffer);
    double mean, stddev;
    
    // Parse the result message from the server
    sscanf(buffer, "%lf %lf", &mean, &stddev);
    printf("Mean: %f, Standard Deviation: %f\n", mean, stddev);
    return 0;
}