//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct chat_message {
    char *message;
    size_t len;
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        struct chat_message message;
        printf("Client message: ");
        scanf("%s", message.message);
        message.len = strlen(message.message);

        send(sock, message.message, message.len, 0);

        char *message_from_client = malloc(1024);
        recv(sock, message_from_client, 1024, 0);

        printf("Server message: %s\n", message_from_client);

        free(message_from_client);
    }

    close(sock);

    return 0;
}