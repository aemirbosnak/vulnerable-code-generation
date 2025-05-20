//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up the bingo cards
    int num_cards = 10; // Number of bingo cards
    int card_size = 5; // Size of each bingo card (5x5)
    
    // Initialize the bingo cards
    int* cards = (int*)malloc(num_cards * sizeof(int));
    for (int i = 0; i < num_cards; i++) {
        for (int j = 0; j < card_size; j++) {
            cards[i * card_size + j] = rand() % 25 + 1; // Generate random numbers between 1 and 25
        }
    }
    
    // Initialize the bingo board
    int board_size = 5; // Size of the bingo board (5x5)
    int board[board_size][board_size]; // 2D array to store the bingo board
    
    // Initialize the bingo board with random numbers between 1 and 25
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            board[i][j] = rand() % 25 + 1;
        }
    }
    
    // Display the bingo cards and the bingo board
    printf("Bingo Cards:\n");
    for (int i = 0; i < num_cards; i++) {
        printf("Card %d:\n", i + 1);
        for (int j = 0; j < card_size; j++) {
            printf("%d ", cards[i * card_size + j]);
        }
        printf("\n");
    }
    printf("\nBingo Board:\n");
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    // Generate random numbers and update the bingo board
    for (int i = 0; i < 25; i++) {
        int num = rand() % 25 + 1;
        int x = rand() % board_size;
        int y = rand() % board_size;
        board[x][y] = num;
        printf("Generated number: %d\n", num);
        printf("New board:\n");
        for (int i = 0; i < board_size; i++) {
            for (int j = 0; j < board_size; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    
    // Check for a bingo
    int card_num = 0; // Index of the card to check
    int card[card_size]; // Copy of the card to check
    
    for (int i = 0; i < board_size; i++) {
        for (int j = 0; j < board_size; j++) {
            if (board[i][j] == cards[card_num * card_size + j]) {
                printf("Bingo!\n");
                return 0;
            }
        }
        card_num++;
    }
    
    // Clean up
    free(cards);
    return 0;
}