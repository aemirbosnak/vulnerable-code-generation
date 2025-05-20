//FormAI DATASET v1.0 Category: Breakout Game Clone ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

#define ROWS 20
#define COLS 60
#define BLOCK_SIZE 3

char wall[ROWS][COLS];
char paddle[BLOCK_SIZE] = {'=', '=', '='};
char ball = 'O';
int ball_x = ROWS - 4;
int ball_y = COLS / 2;
int paddle_x = ROWS - 1;
int paddle_y = COLS / 2 - 1;
int client_sock;

void handle_exit(int sig) {
    close(client_sock);
    exit(0);
}

void draw_screen() {
     for (int i = 0; i < ROWS; i++) {
         for (int j = 0; j < COLS; j++) {
             if (i == ball_x && j == ball_y) {
                 printf("%c", ball);
             } else if (i == paddle_x && j >= paddle_y && j < paddle_y + BLOCK_SIZE) {
                 printf("%c", paddle[j - paddle_y]);
             } else {
                 printf("%c", wall[i][j]);
             }
         }
         printf("\n");
     }
}

void handle_collisions() {
    if (ball_x == ROWS - 1) {
        if (ball_y >= paddle_y && ball_y < paddle_y + BLOCK_SIZE) {
            ball_x--;
        } else {
            printf("Game Over.\n");
            close(client_sock);
            exit(0);
        }
    }
    if (ball_y == 0 || ball_y == COLS - 1) {
        ball_y *= -1;
    }
    if (ball_x == 0) {
        ball_x++;
    }
    if (wall[ball_x][ball_y] != ' ') {
        wall[ball_x][ball_y] = ' ';
        ball_x++;
    }
}

void update_ball(int x, int y) {
    ball_x += x;
    ball_y += y;
}

void update_paddle(int y) {
    paddle_y += y;
}

void update_screen() {
    draw_screen();
    handle_collisions();
}

int main(int argc, char **argv) {
    signal(SIGINT, handle_exit);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s server_ip server_port\n", argv[0]);
        exit(1);
    }

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(client_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    int x, y, recv_return;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, 1024);
        if ((recv_return = recv(client_sock, buffer, 1024, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        sscanf(buffer, "%d %d", &x, &y);
        update_ball(x, y);

        memset(buffer, 0, 1024);
        fgets(buffer, 1024, stdin);
        int len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        send(client_sock, buffer, strlen(buffer), 0);
        sscanf(buffer, "%d", &y);
        update_paddle(y);

        update_screen();
    }
    return 0;
}