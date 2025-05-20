//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define SIZE 4 // Defines a 4x4 grid
#define EMPTY 'X' // Character for unrevealed cards

void initialize_board(char board[SIZE][SIZE], char symbols[SIZE * SIZE]) {
    int index = 0;
    for (int i = 0; i < SIZE * SIZE / 2; i++) {
        board[index / SIZE][index % SIZE] = symbols[i];
        board[(SIZE * SIZE - 1 - index) / SIZE][(SIZE * SIZE - 1 - index) % SIZE] = symbols[i];
        index += 2;
    }
}

void shuffle_board(char board[SIZE][SIZE]) {
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (row * SIZE + col == i) {
                    char temp = board[row][col];
                    board[row][col] = board[j / SIZE][j % SIZE];
                    board[j / SIZE][j % SIZE] = temp;
                }
            }
        }
    }
}

void print_board(char board[SIZE][SIZE], int revealed[SIZE][SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("%c ", EMPTY);
            }
        }
        printf("\n");
    }
}

int check_match(char board[SIZE][SIZE], int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int main() {
    char board[SIZE][SIZE];
    char symbols[SIZE * SIZE / 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int revealed[SIZE][SIZE] = {0};
    int pairs_found = 0;
    int total_pairs = SIZE * SIZE / 2;
    
    srand(time(NULL));
    initialize_board(board, symbols);
    shuffle_board(board);

    while (pairs_found < total_pairs) {
        print_board(board, revealed);
        printf("Enter coordinates of the first card (row and column): ");
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        
        printf("Enter coordinates of the second card (row and column): ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);

        if (check_match(board, x1, y1, x2, y2)) {
            revealed[x1][y1] = 1;
            revealed[x2][y2] = 1;
            pairs_found++;
            printf("Match found!\n");
        } else {
            printf("Not a match. Try again!\n");
        }
        
        sleep(1); // Pause for visibility
        system("clear"); // Clear screen for better UX
    }
    
    printf("Congratulations! You've matched all pairs!\n");
    return 0;
}