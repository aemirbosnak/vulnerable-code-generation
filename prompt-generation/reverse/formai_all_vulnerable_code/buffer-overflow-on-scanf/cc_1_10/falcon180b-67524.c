//Falcon-180B DATASET v1.0 Category: Educational ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to prompt the user for a yes or no answer
char get_yes_no(void) {
    char answer;
    do {
        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &answer);
    } while (answer!= 'y' && answer!= 'n');
    return answer;
}

// Function to play a simple number guessing game
void number_guessing_game(void) {
    int secret_number, guess, attempts = 0;

    // Generate a random number between 1 and 100
    secret_number = rand_num(1, 100);

    // Prompt the user to guess the number
    printf("I'm thinking of a number between 1 and 100. Can you guess what it is?\n");

    do {
        printf("Guess #%d: ", ++attempts);
        scanf("%d", &guess);

        // Check if the guess is correct
        if (guess == secret_number) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (guess < secret_number) {
            printf("Too low. Try again.\n");
        } else {
            printf("Too high. Try again.\n");
        }

    } while (1);
}

int main(void) {
    srand(time(NULL)); // Seed the random number generator with the current time

    while (get_yes_no() == 'y') {
        number_guessing_game();
    }

    return 0;
}