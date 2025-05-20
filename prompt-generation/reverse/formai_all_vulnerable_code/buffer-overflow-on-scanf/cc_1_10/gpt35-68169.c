//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
/* Medieval Style Chatroom Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int sock_fd;
    struct sockaddr_in serv_addr;
    char message[1000];

    // Socket Creation
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd == -1)
    {
        printf("Could not create socket\n");
        return 1;
    }

    // Server Address Configuration
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connection Establishment
    if(connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("Could not connect to server\n");
        return 1;
    }

    // Chatroom Begins
    printf("Welcome to the Medieval Chatroom!\n");
    while(strcmp(message, "exit") != 0)
    {
        printf(">>> ");
        scanf("%s", message);
        write(sock_fd, message, strlen(message));
        read(sock_fd, message, 1000);
        printf("Knight: %s\n", message);
    }

    // Connection Termination
    close(sock_fd);
    printf("Farewell from the Medieval Chatroom!\n");

    return 0;
}