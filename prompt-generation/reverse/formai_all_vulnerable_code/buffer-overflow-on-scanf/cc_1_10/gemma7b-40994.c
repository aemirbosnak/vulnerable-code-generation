//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    int ping_status = 0;
    char host_name[256];
    struct sockaddr_in sock_addr;
    int sock_fd;
    char ping_message[1024];

    printf("Enter the host name: ");
    scanf("%s", host_name);

    // Create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the host
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(5000);
    sock_addr.sin_addr.s_addr = inet_addr(host_name);

    if (connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
    {
        printf("Error connecting to host.\n");
        exit(1);
    }

    // Send a ping message
    printf("Enter your message: ");
    scanf("%s", ping_message);

    send(sock_fd, ping_message, strlen(ping_message), 0);

    // Receive a reply message
    char reply_message[1024];
    recv(sock_fd, reply_message, 1024, 0);

    // Print the reply message
    printf("Reply: %s\n", reply_message);

    // Close the socket
    close(sock_fd);

    // Check if the ping was successful
    if (strcmp(reply_message, "alive") == 0)
    {
        ping_status = 1;
    }

    // Print the ping status
    if (ping_status)
    {
        printf("Host is alive.\n");
    }
    else
    {
        printf("Host is not alive.\n");
    }

    return 0;
}