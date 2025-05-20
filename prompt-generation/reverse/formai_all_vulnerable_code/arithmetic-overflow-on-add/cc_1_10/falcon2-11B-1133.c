//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: systematic
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

// Function to send data to the server
void sendData(int sockfd, char* data)
{
    int sent = 0;
    while (sent < strlen(data))
    {
        sent += send(sockfd, data + sent, strlen(data) - sent, 0);
    }
}

// Function to receive data from the server
void receiveData(int sockfd, char* buffer, int bufferSize)
{
    int received = 0;
    while (received < bufferSize)
    {
        received += recv(sockfd, buffer + received, bufferSize - received, 0);
    }
}

int main()
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Server address information
    portno = 12345;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    char message[1024] = "Hello, world!";

    // Send message to server
    sendData(sockfd, message);

    // Receive response from server
    receiveData(sockfd, buffer, sizeof(buffer));

    printf("Response from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}