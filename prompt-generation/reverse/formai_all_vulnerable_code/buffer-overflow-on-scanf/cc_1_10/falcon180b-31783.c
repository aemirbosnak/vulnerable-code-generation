//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX 1024

int main(int argc, char *argv[])
{
    int sock, newsock, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char send_data[MAX], recv_data[MAX];
    int addrlen = sizeof(cli_addr);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
    {
        printf("\n Socket creation failed \n");
        exit(0);
    }

    // Connect to remote server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\nConnection Failed \n");
        exit(0);
    }

    printf("\n Connected to %s:%d \n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while(1)
    {
        // Receive data from server
        memset(recv_data, '\0', MAX);
        valread = recv(sock, recv_data, MAX, 0);

        if (valread <= 0)
        {
            printf("\nDisconnected from %s:%d \n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
            break;
        }

        printf("\n%s", recv_data);

        // Send data to server
        memset(send_data, '\0', MAX);
        printf("\nEnter Data to Send: ");
        scanf("%[^\n]s", send_data);

        send(sock, send_data, strlen(send_data), 0);
    }

    close(sock);
    return 0;
}