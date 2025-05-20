//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE    1
#define FALSE   0
#define PORT    8080
#define BACKLOG 10

int main(int argc, char *argv[])
{
    int listen_sock, conn_sock;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1)
    {
        printf("socket failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) < 0)
    {
        printf("listen failed\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE)
    {
        addrlen = sizeof(client_addr);
        conn_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_sock == -1)
        {
            printf("accept failed\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[1024];
        int bytes_received;

        while ((bytes_received = recv(conn_sock, buffer, sizeof(buffer), 0)) > 0)
        {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            send(conn_sock, buffer, strlen(buffer), 0);
        }

        close(conn_sock);
    }

    close(listen_sock);

    return 0;
}