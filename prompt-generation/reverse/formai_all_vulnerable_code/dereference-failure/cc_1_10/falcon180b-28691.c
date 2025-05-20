//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void die(const char* s)
{
    perror(s);
    exit(1);
}

int main(int argc, char* argv[])
{
    if(argc!= 3)
    {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 1024;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
        die("socket");

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    for(int port = start_port; port < end_port; port++)
    {
        server.sin_port = htons(port);

        if(connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0)
        {
            printf("Port %d is open\n", port);
            close(sock);
            return 0;
        }
    }

    close(sock);
    return 0;
}