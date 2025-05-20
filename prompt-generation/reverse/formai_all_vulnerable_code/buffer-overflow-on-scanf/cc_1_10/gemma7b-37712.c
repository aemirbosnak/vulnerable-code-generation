//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char host_name[256];
    int port_num;
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *hp;
    char buffer[1024];
    int bytes_sent;
    int bytes_recv;
    int i;

    printf("Enter the host name: ");
    scanf("%s", host_name);

    printf("Enter the port number: ");
    scanf("%d", &port_num);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port_num));

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_num);
    serv_addr.sin_addr.s_addr = inet_addr(host_name);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connecting to the server");
        exit(1);
    }

    // Send a message to the server
    printf("Enter your message: ");
    scanf("%s", buffer);

    bytes_sent = send(sockfd, buffer, strlen(buffer) + 1, 0);

    // Receive a message from the server
    bytes_recv = recv(sockfd, buffer, 1024, 0);

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}