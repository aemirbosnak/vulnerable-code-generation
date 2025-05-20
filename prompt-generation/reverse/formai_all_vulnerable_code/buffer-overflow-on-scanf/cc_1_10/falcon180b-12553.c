//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 3
#define PORT 8080
#define IP "127.0.0.1"

char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

int check_win() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

void print_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char input[10];
    while (1) {
        memset(input, 0, sizeof(input));
        printf("Enter your move: ");
        scanf("%s", input);
        send(server_socket, input, strlen(input), 0);

        char response[10];
        recv(server_socket, response, sizeof(response), 0);
        printf("Server's move: %s\n", response);

        int player = response[0] - '0';
        int x = response[1] - '0';
        int y = response[2] - '0';

        if (player == 1) {
            board[x][y] = 'X';
            board[y][x] = 'O';
        } else {
            board[x][y] = 'O';
            board[y][x] = 'X';
        }

        print_board();

        if (check_win() == 1) {
            printf("Player %d wins!\n", player);
            break;
        }
    }

    close(server_socket);
    return 0;
}