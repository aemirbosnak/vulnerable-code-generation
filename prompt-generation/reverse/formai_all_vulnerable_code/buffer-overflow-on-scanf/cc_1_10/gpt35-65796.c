//FormAI DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define TOTAL_CARDS (BOARD_SIZE * BOARD_SIZE)

char board[BOARD_SIZE][BOARD_SIZE];
char hidden_board[BOARD_SIZE][BOARD_SIZE];
char pair[TOTAL_CARDS];
char found[TOTAL_CARDS];

void init_board() {
    int h;
    for (h = 0; h < BOARD_SIZE; h++) {
        int w;
        for (w = 0; w < BOARD_SIZE; w++) {
            board[h][w] = ' ';
            hidden_board[h][w] = '_';
        }
    }
}

int is_valid_position(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

int is_pair_found(int index1, int index2) {
    if (pair[index1] == pair[index2]) {
        found[index1] = 1;
        found[index2] = 1;
        printf("Found a pair!\n");
        return 1;
    }
    return 0;
}

int main() {
    int i;
    srand(time(NULL));
    // Generate pairs of cards
    for (i = 0; i < TOTAL_CARDS; i += 2) {
        pair[i] = 'A' + (i / 2);
        pair[i + 1] = 'A' + (i / 2);
        found[i] = found[i + 1] = 0;
    }
    // Shuffle pairs of cards
    for (i = 0; i < TOTAL_CARDS; i++) {
        int j = rand() % TOTAL_CARDS;
        char temp = pair[i];
        pair[i] = pair[j];
        pair[j] = temp;
    }
    init_board();
    while (1) {
        // Print board
        printf("\n\n");
        int h;
        for (h = 0; h < BOARD_SIZE; h++) {
            int w;
            for (w = 0; w < BOARD_SIZE; w++) {
                printf("%c ", hidden_board[h][w]);
            }
            printf("\n");
        }
        // Get user input
        int x1, y1, x2, y2;
        printf("Enter the coordinate of 1st card: ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinate of 2nd card: ");
        scanf("%d %d", &x2, &y2);
        // Check if user input is valid
        if (!is_valid_position(x1, y1) || !is_valid_position(x2, y2)) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if (found[x1*BOARD_SIZE+y1] || found[x2*BOARD_SIZE+y2]) {
            printf("Card(s) already found.\n");
            continue;
        }
        // Check if user input is a pair
        if (is_pair_found(x1*BOARD_SIZE+y1, x2*BOARD_SIZE+y2)) {
            hidden_board[x1][y1] = pair[x1*BOARD_SIZE+y1];
            hidden_board[x2][y2] = pair[x2*BOARD_SIZE+y2];
        } else {
            hidden_board[x1][y1] = '_';
            hidden_board[x2][y2] = '_';
        }
        // Check if game is finished
        int done = 1;
        for (i = 0; i < TOTAL_CARDS; i++) {
            if (!found[i]) {
                done = 0;
                break;
            }
        }
        if (done) {
            printf("Congratulations! You have found all the pairs!\n");
            break;
        }
    }
    return 0;
}