//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5
#define MAX_PLAYERS 10
#define MIN_PLAYERS 2

typedef struct {
    char name[20];
    int score;
    int **board;
} player;

void init_board(int **board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
}

void print_board(int **board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int check_win(int **board, int player_num) {
    int i, j;
    int count = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == player_num) {
                count++;
            }
        }
    }
    if (count == 15) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int num_players = rand() % (MAX_PLAYERS - MIN_PLAYERS + 1) + MIN_PLAYERS;
    player *players = malloc(num_players * sizeof(player));
    int i;
    for (i = 0; i < num_players; i++) {
        strcpy(players[i].name, "Player ");
        sprintf(&players[i].name[7], "%d", i + 1);
        players[i].score = 0;
        players[i].board = malloc(ROWS * sizeof(int *));
        for (int j = 0; j < ROWS; j++) {
            players[i].board[j] = malloc(COLS * sizeof(int));
        }
        init_board(players[i].board);
    }
    int current_player = 0;
    while (1) {
        system("clear");
        printf("Current player: %s\n", players[current_player].name);
        print_board(players[current_player].board);
        int num = rand() % 75 + 1;
        if (num < 16) {
            printf("Bingo! Player %s wins!\n", players[current_player].name);
            players[current_player].score++;
        } else {
            int x = rand() % ROWS;
            int y = rand() % COLS;
            if (players[current_player].board[x][y] == -1) {
                players[current_player].board[x][y] = current_player;
            }
        }
        current_player = (current_player + 1) % num_players;
        if (check_win(players[current_player].board, current_player)) {
            printf("Player %s wins!\n", players[current_player].name);
            break;
        }
    }
    for (i = 0; i < num_players; i++) {
        free(players[i].board[0]);
        free(players[i].board);
        free(players[i].name);
    }
    free(players);
    return 0;
}