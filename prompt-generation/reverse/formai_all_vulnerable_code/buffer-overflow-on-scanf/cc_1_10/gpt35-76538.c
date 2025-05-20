//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
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
    }

    printf("...............................................\n");
    printf("*** Welcome to the Mind-Bending Chatbot Server ***\n");
    printf("...............................................\n\n");
    printf("[You are connected] What is your name?\n");

    while (1) {
        char message[1024] = {0};
        scanf("%s", message);
        send(sock, message, strlen(message), 0);

        if (strcmp(message, "exit") == 0)
            break;

        memset(buffer, 0, sizeof(buffer));
        valread = read(sock, buffer, 1024);
        printf("> %s\n", buffer);
    }

    printf("................................................\n");
    printf("*** Thank you for chatting with Mind-Bending ***\n");
    printf("................................................\n");

    return 0;
}