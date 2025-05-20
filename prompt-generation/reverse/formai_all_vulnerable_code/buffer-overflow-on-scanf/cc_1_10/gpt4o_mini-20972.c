//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 10
#define MAX_NUM_EASY 50
#define MAX_NUM_MEDIUM 100
#define MAX_NUM_HARD 200

void print_instructions() {
    printf("Welcome to 'Guess the Number' Table Game!\n");
    printf("You will think of a number between 1 and a specified maximum based on your chosen difficulty level, and I will try to guess it.\n");
    printf("You will provide hints for my guesses: 'h' for high, 'l' for low, and 'c' for correct.\n");
    printf("Let's play!\n");
}

int get_max_number(int difficulty) {
    if (difficulty == 1) {
        return MAX_NUM_EASY;
    } else if (difficulty == 2) {
        return MAX_NUM_MEDIUM;
    } else {
        return MAX_NUM_HARD;
    }
}

int main() {
    int difficulty;
    int max_number;
    int low_range = 1, high_range;
    char response;

    print_instructions();
    
    printf("Choose difficulty level (1 = Easy, 2 = Medium, 3 = Hard): ");
    scanf("%d", &difficulty);

    if (difficulty < 1 || difficulty > 3) {
        printf("Invalid difficulty level. Exiting game.\n");
        return 1;
    }

    max_number = get_max_number(difficulty);
    high_range = max_number;

    printf("Think of a number between %d and %d.\n", low_range, high_range);

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        int guess = low_range + (rand() % (high_range - low_range + 1));
        printf("Guess %d: Is your number %d? (h/l/c): ", attempt, guess);
        
        // Get response from user
        getchar(); // to consume newline from previous input
        scanf("%c", &response);
        
        if (response == 'c') {
            printf("Hooray! I guessed your number %d in %d attempts!\n", guess, attempt);
            break;
        } else if (response == 'h') {
            high_range = guess - 1; // the number is lower than the guess
        } else if (response == 'l') {
            low_range = guess + 1; // the number is higher than the guess
        } else {
            printf("Invalid input. Please respond with 'h', 'l', or 'c'.\n");
            attempt--; // do not count this attempt
        }

        // Check if the range for guesses is still valid
        if (low_range > high_range) {
            printf("Hmm, I think there might be some mistake. The ranges do not align. Exiting.\n");
            break;
        }
    }

    if (response != 'c') {
        printf("I could not guess your number in %d attempts. Better luck next time!\n", MAX_ATTEMPTS);
    }

    return 0;
}