//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>

#define ROWS 3
#define COLS 3
#define SIZE ROWS * COLS

int memory[SIZE];

int main() {
    int i, j;
    int turn = 0;
    int wins = 0;
    
    printf("Welcome to the Memory Game!\n");
    printf("Press any key to start\n");
    getchar();
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf(" ");
        }
        printf("\n");
    }
    
    printf("Turn: %d\n", turn);
    
    while (wins < 2) {
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf(" ");
            }
            printf("\n");
        }
        
        printf("Turn: %d\n", turn);
        
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printf(" ");
            }
            printf("\n");
        }
        
        if (turn % 2 == 0) {
            printf("Player 1's turn\n");
            printf("Guess a number (0-9)\n");
            scanf("%d", &memory[turn / 2]);
            printf("Player 1's guess: %d\n", memory[turn / 2]);
            if (memory[turn / 2] == 0) {
                printf("Congratulations! You won!\n");
                wins = 1;
            } else if (memory[turn / 2]!= 0) {
                printf("Sorry, try again\n");
            }
        } else {
            printf("Player 2's turn\n");
            printf("Guess a number (0-9)\n");
            scanf("%d", &memory[turn / 2]);
            printf("Player 2's guess: %d\n", memory[turn / 2]);
            if (memory[turn / 2] == 0) {
                printf("Congratulations! You won!\n");
                wins = 1;
            } else if (memory[turn / 2]!= 0) {
                printf("Sorry, try again\n");
            }
        }
        
        turn++;
    }
    
    printf("Game over!\n");
    
    return 0;
}