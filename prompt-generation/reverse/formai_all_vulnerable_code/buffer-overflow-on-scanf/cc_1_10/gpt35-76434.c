//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[1024] = {0};
    char response[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    } else {
        printf("\n Socket created successfully! \n");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    } else {
        printf("\nConnected to server! \n");
    }

    while (1) {
        printf("\nEnter a message to send to the server: ");
        scanf("%s", message);

        if (send(sock, message, strlen(message), 0) == -1) {
            printf("\nFailed to send message! \n");
        }

        int valread = read(sock, response, 1024);
        response[valread] = '\0';

        printf("\nServer responded: %s\n", response);

        if (strcmp(response, "bye") == 0) {
            printf("\nServer closed the connection! \n");
            break;
        }
    }

    close(sock);
    printf("\nConnection closed! \n");

    return 0;
}