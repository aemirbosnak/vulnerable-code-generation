//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4
#define TOTAL_CARDS (SIZE * SIZE / 2)
#define HIDDEN_SYMBOL '?'

char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
char symbols[TOTAL_CARDS * 2];
int max_attempts = 10;

void init_board() {
    int k = 0;
    for(int i = 0; i < TOTAL_CARDS; ++i) {
        symbols[k++] = 'A' + i; // fill symbols A to Z
        symbols[k++] = 'A' + i; // duplicate symbols
    }
    
    // Shuffle symbols
    for(int i = k - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = symbols[i];
        symbols[i] = symbols[j];
        symbols[j] = temp;
    }
    
    // Initialize board
    k = 0;
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            board[i][j] = symbols[k++];
            revealed[i][j] = HIDDEN_SYMBOL;
        }
    }
}

void print_board() {
    printf("\nCurrent Board:\n");
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            printf("%c ", revealed[i][j]);
        }
        printf("\n");
    }
}

void reveal_card(int x, int y) {
    revealed[x][y] = board[x][y];
}

void hide_card(int x, int y) {
    revealed[x][y] = HIDDEN_SYMBOL;
}

int check_match(int x1, int y1, int x2, int y2) {
    return board[x1][y1] == board[x2][y2];
}

int is_game_over() {
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if(revealed[i][j] == HIDDEN_SYMBOL) {
                return 0; // Still hidden cards exist
            }
        }
    }
    return 1; // No hidden cards left
}

void play_game() {
    int attempts = 0;
    while(attempts < max_attempts && !is_game_over()) {
        print_board();
        int x1, y1, x2, y2;
        
        printf("Pick first card (row col): ");
        scanf("%d %d", &x1, &y1);
        reveal_card(x1, y1);
        
        print_board();
        
        printf("Pick second card (row col): ");
        scanf("%d %d", &x2, &y2);
        reveal_card(x2, y2);
        
        print_board();

        if(check_match(x1, y1, x2, y2)) {
            printf("Match Found!\n");
        } else {
            printf("No Match! Hiding cards again.\n");
            sleep(1);
            hide_card(x1, y1);
            hide_card(x2, y2);
        }
        
        attempts++;
        printf("Attempts taken: %d/%d\n", attempts, max_attempts);
    }
    
    if(is_game_over()) {
        printf("Congratulations! You've matched all cards!\n");
    } else {
        printf("Game Over! Better luck next time!\n");
    }
}

int main() {
    srand(time(NULL));
    init_board();
    play_game();
    return 0;
}