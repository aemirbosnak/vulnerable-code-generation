//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SIZE 4
#define TOTAL_TILES (SIZE * SIZE / 2)

typedef struct {
    int value;
    int revealed;
} Tile;

Tile board[SIZE][SIZE];
int turn = 0, score = 0;

void init_board() {
    int values[TOTAL_TILES] = {0};
    for (int i = 0; i < TOTAL_TILES; i++)
        values[i] = i + 1;
    
    for (int i = 0; i < TOTAL_TILES; i++)
        values[i + TOTAL_TILES] = values[i];
    
    for (int i = 0; i < TOTAL_TILES * 2; i++)
        for (int j = 0; j < TOTAL_TILES * 2 - 1; j++) 
            if (rand() % 2) {
                int temp = values[j + 1];
                values[j + 1] = values[j];
                values[j] = temp;
            }
    
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++) {
            board[r][c].value = values[r * SIZE + c];
            board[r][c].revealed = 0;
        }
}

void draw_board() {
    printf("\nCurrent Board:\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (board[r][c].revealed)
                printf(" %d ", board[r][c].value);
            else
                printf(" ? ");
        }
        printf("\n");
    }
}

int check_match(int r1, int c1, int r2, int c2) {
    return board[r1][c1].value == board[r2][c2].value;
}

void reveal_tiles(int r, int c) {
    board[r][c].revealed = 1;
    draw_board();
    usleep(2000000);  // Pause for effect
}

void hide_tiles(int r1, int c1, int r2, int c2) {
    board[r1][c1].revealed = 0;
    board[r2][c2].revealed = 0;
}

int all_matched() {
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (!board[r][c].revealed)
                return 0;
    return 1;
}

int main() {
    int r1, c1, r2, c2;
    char choice[100];
    srand(time(NULL));
    init_board();

    printf("Welcome to the Memory Game!\n\n");
    while (1) {
        draw_board();
        printf("Turn %d | Current Score: %d\n", turn + 1, score);
        
        printf("Select first tile (row col): ");
        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d %d", &r1, &c1);
        
        reveal_tiles(r1, c1);
        draw_board();
        
        printf("Select second tile (row col): ");
        fgets(choice, sizeof(choice), stdin);
        sscanf(choice, "%d %d", &r2, &c2);
        
        reveal_tiles(r2, c2);
        
        if (check_match(r1, c1, r2, c2)) {
            printf("Match Found!\n");
            score += 1;
        } else {
            printf("No Match. Hiding tiles again.\n");
            usleep(1000000);  // Pause before hiding
            hide_tiles(r1, c1, r2, c2);
        }
        
        turn += 1;
        
        if (all_matched()) {
            printf("Congratulations! You matched all tiles in %d turns.\n", turn);
            break;
        }
    }

    return 0;
}