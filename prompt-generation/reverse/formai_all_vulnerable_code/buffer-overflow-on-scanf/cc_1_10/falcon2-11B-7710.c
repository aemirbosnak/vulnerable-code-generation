//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char sendbuf[100], recvbuf[100];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        return 1;
    }

    // Initialize the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);

    // Convert the IP address to network byte order
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        return 1;
    }

    // Prompt the user for the host to ping
    printf("Enter the name of the host to ping: ");
    scanf("%s", sendbuf);

    // Send the message to the server
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    // Receive the response from the server
    bzero(recvbuf, sizeof(recvbuf));
    n = recv(sockfd, recvbuf, sizeof(recvbuf), 0);

    // Print the response
    printf("Received response from %s: %s\n", sendbuf, recvbuf);

    // Close the socket
    close(sockfd);
    return 0;
}