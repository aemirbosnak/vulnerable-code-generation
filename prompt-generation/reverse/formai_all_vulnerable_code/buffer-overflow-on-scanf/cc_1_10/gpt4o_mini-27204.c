//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100
#define MAX_TRIES 10

// Function to calculate the entropy of the game
double calculateEntropy(int outcomes, int total) {
    if (outcomes == 0 || total == 0) return 0.0;
    double p = (double)outcomes / total;
    if (p == 0) return 0.0;
    return -p * log2(p);
}

// Function to generate random number with Shannon's entropy concept
int generateSecretNumber() {
    srand(time(NULL));
    int secret = rand() % MAX_NUM + 1; 
    return secret;
}

// Function to display the game's rules
void displayRules() {
    printf("Welcome to the Claude Shannon Guessing Game!\n");
    printf("Your objective is to guess the secret number between 1 and %d.\n", MAX_NUM);
    printf("You have %d attempts to find the number. Good luck!\n", MAX_TRIES);
}

// Main function
int main() {
    int secretNumber = generateSecretNumber();
    int guess;
    int tries = 0;
    int successfulGuesses = 0;

    displayRules();

    while (tries < MAX_TRIES) {
        printf("Attempt %d: Enter your guess: ", tries + 1);
        scanf("%d", &guess);

        // Validate input
        if (guess < 1 || guess > MAX_NUM) {
            printf("Please enter a number between 1 and %d!\n", MAX_NUM);
            continue;
        }

        tries++;
        successfulGuesses++;

        if (guess == secretNumber) {
            printf("Congratulations! You've guessed the right number: %d\n", secretNumber);
            break;
        } else if (guess < secretNumber) {
            printf("Higher! Try again.\n");
        } else {
            printf("Lower! Try again.\n");
        }
    }

    if (tries == MAX_TRIES) {
        printf("Out of attempts! The secret number was: %d\n", secretNumber);
    }

    // Calculate and display the entropy of the guessing game
    double entropy = calculateEntropy(successfulGuesses, MAX_TRIES);
    printf("Entropy of your guessing game: %.2f bits\n", entropy);

    printf("Thank you for playing! Remember: Information is power!\n");
    
    return 0;
}