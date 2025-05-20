//FormAI DATASET v1.0 Category: Networking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s SERVER_IP_ADDRESS\n", argv[0]);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Failed to create socket!\n");
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0 ) {
        printf("Failed to connect to: %s\n", argv[1]);
        exit(1);
    }

    printf("Connected to: %s\n", argv[1]);

    char message[1024];
    char reply[1024];

    printf("To exit type 'exit'\n\n");

    while (1) {
        printf("Enter a message: ");
        scanf("%s", message);

        if (send(sock, message, strlen(message), 0) < 0) {
            printf("Failed to send message!\n");
            exit(1);
        }

        if (strcmp(message, "exit") == 0) {
            break;
        }

        if (recv(sock, reply, 1024, 0) < 0) {
            printf("Failed to receive message!\n");
            exit(1);
        }

        printf("Server reply: %s\n", reply);
    }

    close(sock);

    return 0;
}