//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 5
#define MIN_NUMBER 1
#define MAX_NUMBER 10

void print_table(int table[TABLE_SIZE][TABLE_SIZE]);
int generate_random_number();
int check_guess(int guess, int number);

int main() {
    int table[TABLE_SIZE][TABLE_SIZE];
    int number, guess, row, col;

    srand(time(NULL));
    number = generate_random_number();

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have generated a random number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);

    print_table(table);

    for (row = 0; row < TABLE_SIZE; row++) {
        for (col = 0; col < TABLE_SIZE; col++) {
            table[row][col] = row * TABLE_SIZE + col + 1;
            printf(" %d ", table[row][col]);
        }
        printf("\n");
    }

    do {
        printf("\nPlease enter a row and column to guess the number: ");
        scanf("%d %d", &row, &col);
        guess = table[row][col];
    } while (guess != number);

    printf("\nCongratulations! You have guessed the number correctly. The number was %d.\n", number);

    return 0;
}

void print_table(int table[TABLE_SIZE][TABLE_SIZE]) {
    int row, col;

    printf("\nPrinting the table for reference:\n");

    for (row = 0; row < TABLE_SIZE; row++) {
        for (col = 0; col < TABLE_SIZE; col++) {
            printf(" %d ", table[row][col]);
        }
        printf("\n");
    }
}

int generate_random_number() {
    int number;

    number = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;

    return number;
}

int check_guess(int guess, int number) {
    if (guess == number) {
        return 1;
    }
    return 0;
}