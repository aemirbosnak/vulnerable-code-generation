//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define BOARD_SIZE 10

int board[BOARD_SIZE][BOARD_SIZE];
int player_count = 0;
int current_player = 0;

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void draw_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void add_player() {
    if (player_count < MAX_PLAYERS) {
        player_count++;
        printf("Player %d added!\n", player_count);
    } else {
        printf("No more players can join!\n");
    }
}

void remove_player(int player_id) {
    for (int i = 0; i < player_count; i++) {
        if (player_id == i) {
            player_count--;
            printf("Player %d removed!\n", player_id);
            return;
        }
    }
    printf("Player not found!\n");
}

void next_player() {
    current_player = (current_player + 1) % player_count;
}

void play_game() {
    int choice;
    do {
        draw_board();
        printf("Player %d's turn:\n", current_player + 1);
        printf("1. Place X\n2. Place O\n3. Quit\n");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            int x, y;
            printf("Enter coordinates (row, column): ");
            scanf("%d %d", &x, &y);
            if (board[x][y] == 0) {
                board[x][y] = (choice == 1)? 1 : 2;
            } else {
                printf("Cell already occupied!\n");
            }
        }
        if (choice == 3) {
            remove_player(current_player);
            if (player_count == 1) {
                printf("Player %d wins!\n", current_player + 1);
                break;
            }
        }
        next_player();
    } while (player_count > 1);
}

int main() {
    init_board();
    int num_players;
    printf("Enter number of players (1-4): ");
    scanf("%d", &num_players);
    for (int i = 0; i < num_players; i++) {
        add_player();
    }
    play_game();
    return 0;
}