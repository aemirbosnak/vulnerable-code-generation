//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define WIDTH 50
#define HEIGHT 10
#define CHARS " .:!*oe%$#@"
#define PORT 8080

int main() {
    int sock = 0, new_sock = 0;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char text[WIDTH][HEIGHT];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation error\n");
        return -1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("setsockopt\n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("bind failed\n");
        return -1;
    }

    if (listen(sock, 3) < 0) {
        printf("listen\n");
        return -1;
    }

    printf("Listening on port %d\n", PORT);

    while (1) {
        printf("Waiting for incoming connection...\n");
        if ((new_sock = accept(sock, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            printf("accept\n");
            return -1;
        }

        printf("Connection from: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        char player = 'X';
        int i = 0;

        while (1) {
            memset(text, ' ', WIDTH * HEIGHT);

            if (player == 'X') {
                printf("Player X turn: ");
                fgets(buffer, 1024, stdin);
                buffer[strlen(buffer) - 1] = '\0';
                strncpy(text[i / WIDTH][i % WIDTH], buffer, WIDTH);
                player = 'O';
            } else {
                read(new_sock, buffer, 1024);
                strncpy(text[i / WIDTH][i % WIDTH], buffer, WIDTH);
                printf("Player O turn: %s\n", buffer);
                break;
            }

            i++;
            if (i >= WIDTH * HEIGHT) {
                break;
            }

            for (int j = 0; j < HEIGHT; j++) {
                for (int k = 0; k < WIDTH; k++) {
                    putchar(CHARS[(int)text[j][k]]);
                }
                putchar('\n');
            }
            putchar('\n');

            if (i >= WIDTH * HEIGHT) {
                break;
            }

            send(new_sock, text, WIDTH * HEIGHT, 0);

            memset(text, ' ', WIDTH * HEIGHT);
        }

        close(new_sock);
    }

    return 0;
}