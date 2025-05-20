//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: careful
/*
 * Bingo Simulator
 *
 * Generates a random bingo card with 25 numbers
 * and allows the user to mark off the numbers as they are called.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 5
#define NUM_NUM 25

// Function to generate a random number between 1 and 75
int generate_random_num() {
    return (rand() % 75) + 1;
}

// Function to print the bingo card
void print_card(int *card) {
    int i;
    printf("Bingo Card:\n");
    for (i = 0; i < NUM_NUM; i++) {
        printf("%d ", card[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

// Function to check if the user has won the game
int check_win(int *card) {
    int i;
    for (i = 0; i < NUM_NUM; i++) {
        if (card[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, j, k;
    int card[NUM_NUM];
    int num_cards[NUM_CARDS];

    // Initialize the cards and the numbers
    for (i = 0; i < NUM_CARDS; i++) {
        num_cards[i] = generate_random_num();
    }
    for (i = 0; i < NUM_NUM; i++) {
        card[i] = 1;
    }

    // Print the cards
    printf("Bingo Cards:\n");
    for (i = 0; i < NUM_CARDS; i++) {
        printf("Card %d: ", i + 1);
        for (j = 0; j < NUM_NUM; j++) {
            printf("%d ", num_cards[i]);
            if ((j + 1) % 5 == 0) {
                printf("\n");
            }
        }
    }

    // Allow the user to mark off the numbers as they are called
    while (1) {
        int num = generate_random_num();
        for (i = 0; i < NUM_CARDS; i++) {
            if (num_cards[i] == num) {
                card[num - 1] = 0;
                break;
            }
        }
        print_card(card);
        if (check_win(card)) {
            printf("You won the game!\n");
            break;
        }
    }

    return 0;
}