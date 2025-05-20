//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_COUNT 15

// Function to generate random numbers
int generate_random(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to print the bingo card
void print_card(int card[BINGO_SIZE][BINGO_SIZE]) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            printf("%3d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is on the card
int check_card(int card[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == number) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if a row is complete
int check_row(int card[BINGO_SIZE][BINGO_SIZE]) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] != 0) {
                count++;
            }
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a column is complete
int check_column(int card[BINGO_SIZE][BINGO_SIZE]) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[j][i] != 0) {
                count++;
            }
        }
        if (count == BINGO_SIZE) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a diagonal is complete
int check_diagonal(int card[BINGO_SIZE][BINGO_SIZE]) {
    int count = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][i] != 0) {
            count++;
        }
    }
    if (count == BINGO_SIZE) {
        return 1;
    }
    count = 0;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][BINGO_SIZE - i - 1] != 0) {
            count++;
        }
    }
    if (count == BINGO_SIZE) {
        return 1;
    }
    return 0;
}

// Function to check if a bingo is complete
int check_bingo(int card[BINGO_SIZE][BINGO_SIZE]) {
    if (check_row(card) || check_column(card) || check_diagonal(card)) {
        return 1;
    }
    return 0;
}

// Main function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create the bingo card
    int card[BINGO_SIZE][BINGO_SIZE];
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            card[i][j] = generate_random(1, BINGO_COUNT);
        }
    }

    // Print the bingo card
    print_card(card);

    // Prompt the user to pick a number
    int number;
    printf("Pick a number: ");
    scanf("%d", &number);

    // Check if the number is on the card
    int on_card = check_card(card, number);

    // Check if a bingo is complete
    int bingo = check_bingo(card);

    // Print the result
    if (on_card) {
        printf("You got a bingo! The number %d is on the card.\n", number);
    } else {
        printf("Sorry, the number %d is not on the card.\n", number);
    }
    if (bingo) {
        printf("You got a bingo! The card is complete.\n");
    } else {
        printf("Sorry, the card is not complete.\n");
    }

    return 0;
}