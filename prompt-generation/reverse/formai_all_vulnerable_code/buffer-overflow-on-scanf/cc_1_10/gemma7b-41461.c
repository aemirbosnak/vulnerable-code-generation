//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define PORT_RANGE 1024

int main()
{
    int port_number;
    char host_name[256];
    struct sockaddr_in sock_addr;
    int sock_fd;
    char buffer[1024];

    printf("Enter host name: ");
    scanf("%s", host_name);

    for (port_number = 1; port_number <= PORT_RANGE; port_number++)
    {
        sock_fd = socket(AF_INET, SOCK_STREAM, htons(port_number));

        if (sock_fd == -1)
        {
            perror("Error creating socket");
            continue;
        }

        memset(&sock_addr, 0, sizeof(sock_addr));
        sock_addr.sin_family = AF_INET;
        sock_addr.sin_port = htons(port_number);
        inet_aton(host_name, &sock_addr.sin_addr);

        if (connect(sock_fd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
        {
            perror("Error connecting to socket");
            close(sock_fd);
            continue;
        }

        printf("Port %d is open.\n", port_number);

        // Send and receive data
        send(sock_fd, "Hello, world!", 13, 0);
        recv(sock_fd, buffer, 1024, 0);
        printf("Received: %s\n", buffer);

        close(sock_fd);
    }

    return 0;
}