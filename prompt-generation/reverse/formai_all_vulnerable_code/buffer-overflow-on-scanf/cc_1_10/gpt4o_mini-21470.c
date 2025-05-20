//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define SIZE 3 // Tic-Tac-Toe Board Size
#define BUFFER_SIZE 1024

char board[SIZE][SIZE];
int current_player = 0; // 0 for player1, 1 for player2
int game_over = 0;

void initialize_board() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
}

int check_winner() {
    for (int i = 0; i < SIZE; i++) {
        // Check rows
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2; // 1 for X, 2 for O
        }
        // Check columns
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return (board[0][i] == 'X') ? 1 : 2; // 1 for X, 2 for O
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return (board[0][0] == 'X') ? 1 : 2; // 1 for X, 2 for O
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return (board[0][2] == 'X') ? 1 : 2; // 1 for X, 2 for O
    }
    return 0; // No winner yet
}

void *player_turn(void *arg) {
    int sock = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int row, col;
    
    while (!game_over) {
        if (current_player == 0) {
            display_board();
            printf("Player 1 (X), enter your move (row and column): ");
            scanf("%d %d", &row, &col);
            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
                board[row][col] = 'X';
                current_player = 1; // Switch turn
                send(sock, "move", sizeof("move"), 0);
                sprintf(buffer, "%d %d", row, col);
                send(sock, buffer, sizeof(buffer), 0);
                if (check_winner() == 1) {
                    game_over = 1;
                    display_board();
                    printf("Player 1 (X) wins!\n");
                    return NULL;
                }
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            recv(sock, buffer, sizeof(buffer), 0);
            sscanf(buffer, "%d %d", &row, &col);
            board[row][col] = 'O';
            current_player = 0; // Switch turn
            if (check_winner() == 2) {
                game_over = 1;
                display_board();
                printf("Player 2 (O) wins!\n");
                return NULL;
            }
        }
    }
    return NULL;
}

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(board, ' ', sizeof(board));
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

    pthread_t tid;
    pthread_create(&tid, NULL, player_turn, (void *)&sock);
    pthread_join(tid, NULL);

    close(sock);
    return 0;
}