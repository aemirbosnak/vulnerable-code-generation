//FormAI DATASET v1.0 Category: Client Server Application ; Style: brave
// Brave Style Chat Application
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[])
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    while (1)
    {
        char message[1024] = {0};
        printf("Enter your message: ");
        scanf("%[^\n]", message);
        send(sock, message, strlen(message), 0);

        char buffer[1024] = {0};
        int valread = read(sock, buffer, 1024);
        printf("Server: %s\n", buffer);
        getchar();
    }

    return 0;
}