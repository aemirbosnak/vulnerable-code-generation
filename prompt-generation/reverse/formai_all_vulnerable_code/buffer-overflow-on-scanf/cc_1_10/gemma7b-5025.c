//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    char *hostname;
    int sockfd, ping_status, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_aton(hostname, &server_addr.sin_addr);

    ping_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ping_status < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    bytes_sent = send(sockfd, "PING", 5, 0);
    if (bytes_sent < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    bytes_received = recv(sockfd, "RESPONSE", 10, 0);
    if (bytes_received < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    printf("Response: %s\n", bytes_received);

    close(sockfd);
    return 0;
}