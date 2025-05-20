//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the game variables
    int score = 0;
    int questions_answered = 0;

    // Loop through the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Generate a random number between 1 and 100
        int num = generate_random_number(1, 100);

        // Ask the user if the number is prime
        printf("Question %d of %d: Is the number %d prime? (Y/N)\n", i + 1, NUM_QUESTIONS, num);
        char answer;
        scanf(" %c", &answer);

        // Check if the user's answer is correct
        int is_correct = is_prime(num);
        if ((answer == 'Y' || answer == 'y') && is_correct == 1) {
            score++;
            questions_answered++;
        } else if ((answer == 'N' || answer == 'n') && is_correct == 0) {
            score++;
            questions_answered++;
        } else {
            printf("Incorrect answer.\n");
        }
    }

    // Print the final score
    printf("Your final score is %d out of %d.\n", score, questions_answered);

    return 0;
}