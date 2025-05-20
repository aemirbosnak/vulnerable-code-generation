//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 1000

int main()
{
    int sock;
    struct sockaddr_in server;
    char buffer[MAX];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1)
    {
        printf("Socket creation failed\n");
        exit(0);
    }

    printf("Enter IP Address: ");
    scanf("%s", &buffer);

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    inet_pton(AF_INET, buffer, &server.sin_addr);

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
    {
        printf("Connection Failed\n");
        exit(0);
    }

    while(1)
    {
        memset(buffer, 0, MAX);
        n = recv(sock, buffer, MAX, 0);

        if(n <= 0)
        {
            printf("Disconnected\n");
            break;
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}