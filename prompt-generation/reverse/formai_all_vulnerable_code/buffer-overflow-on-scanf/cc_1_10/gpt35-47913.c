//FormAI DATASET v1.0 Category: Table Game ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome message
    printf("Welcome to the C Table Game!\n");

    // Declare variables
    int table_num, guess, count = 1, i;

    // Generate random number between 1 and 10
    srand(time(NULL));
    table_num = rand() % 10 + 1;

    // Ask user to guess the number
    printf("Guess the number between 1 and 10: ");
    scanf("%d", &guess);

    // Game loop
    while (guess != table_num) {
        
        // Check if guess is too low
        if (guess < table_num) {
            printf("Your guess was too low! Try again: ");
        }
        // Check if guess is too high
        else {
            printf("Your guess was too high! Try again: ");
        }

        // Increment guess count
        count++;

        // Get new guess from user
        scanf("%d", &guess);
    }

    // Player wins!
    printf("Congratulations! You guessed the correct number in %d tries.\n", count);

    // Generate table
    printf("\nHere is your multiplication table:\n");
    printf("------------------------------\n");

    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", table_num, i, table_num*i);
    }

    // Exit message
    printf("Thanks for playing!\n");

    return 0;
}