//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_NAME_LENGTH 20

typedef struct {
    char username[MAX_NAME_LENGTH];
    int score;
} Player;

Player* players[10];
int num_players = 0;

int board[ROWS][COLS];
int flipped[ROWS][COLS];
int num_flipped = 0;

void print_board() {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            if (flipped[i][j]) {
                printf("%d ", board[i][j]);
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

void initialize_board() {
    int num_pairs = ROWS * COLS / 2;
    int pairs[num_pairs];
    for (int i = 1; i <= num_pairs; i++) {
        pairs[i-1] = i;
    }
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int index = rand() % num_pairs;
            board[i][j] = pairs[index];
            pairs[index] = pairs[num_pairs-1];
            num_pairs--;
            flipped[i][j] = 0;
        }
    }
}

void flip_card(int row, int col) {
    if (!flipped[row][col]) {
        flipped[row][col] = 1;
        printf("Flipping card at (%d,%d): %d\n", row, col, board[row][col]);
        num_flipped++;
    }
}

void check_match(int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        printf("Match found!\n");
    } else {
        printf("No match. Flipping cards back over...\n");
        flipped[row1][col1] = 0;
        flipped[row2][col2] = 0;
    }
}

void update_score(Player* player, int score) {
    player->score += score;
    printf("%s's score is now %d.\n", player->username, player->score);
}

void add_player(char* username) {
    Player* player = malloc(sizeof(Player));
    strncpy(player->username, username, MAX_NAME_LENGTH-1);
    player->score = 0;
    players[num_players++] = player;
    printf("Welcome, %s!\n", username);
}

int main() {
    printf("Welcome to the Memory Game!\n");
    char username[MAX_NAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);
    add_player(username);
    char play_again = 'y';
    while (play_again == 'y') {
        initialize_board();
        num_flipped = 0;
        int row1, col1, row2, col2;
        while (num_flipped < ROWS * COLS) {
            print_board();
            printf("Enter the row and column of the card you would like to flip: ");
            scanf("%d %d", &row1, &col1);
            flip_card(row1, col1);
            if (num_flipped % 2 == 0) {
                row2 = row1;
                col2 = col1;
            } else {
                print_board();
                printf("Enter the row and column of the second card you would like to flip: ");
                scanf("%d %d", &row2, &col2);
                flip_card(row2, col2);
                check_match(row1, col1, row2, col2);
                if (board[row1][col1] == board[row2][col2]) {
                    update_score(players[0], 10);
                }
            }
        }
        printf("Game over!\n");
        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &play_again);
    }
    printf("Thanks for playing!\n");
    for (int i = 0; i < num_players; i++) {
        free(players[i]);
    }
    return 0;
}