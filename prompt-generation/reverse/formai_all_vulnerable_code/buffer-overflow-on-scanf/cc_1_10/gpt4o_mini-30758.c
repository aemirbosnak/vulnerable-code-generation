//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUESTIONS 5

void display_welcome_message() {
    printf("**************************************\n");
    printf("* Welcome to the Math Wizard Challenge! *\n");
    printf("**************************************\n");
    printf("Can you conquer the realm of numbers? Let's find out!\n\n");
}

int generate_question(int *answer) {
    int num1 = rand() % 100; // Random number between 0 and 99
    int num2 = rand() % 100; // Another random number
    int operation = rand() % 4; // Choose a random operation

    switch (operation) {
        case 0: // Addition
            printf("What is %d + %d? ", num1, num2);
            *answer = num1 + num2;
            break;
        case 1: // Subtraction
            printf("What is %d - %d? ", num1, num2);
            *answer = num1 - num2;
            break;
        case 2: // Multiplication
            printf("What is %d * %d? ", num1, num2);
            *answer = num1 * num2;
            break;
        case 3: // Division
            while (num2 == 0) {
                num2 = rand() % 100; // Ensure no division by zero
            }
            printf("What is %d / %d (rounded)? ", num1, num2);
            *answer = num1 / num2; // Integer division
            break;
    }
    return operation;
}

void play_game() {
    int score = 0;
    int user_answer;
    int correct_answer;

    // Loop through the number of questions
    for (int i = 0; i < QUESTIONS; i++) {
        printf("\nQuestion %d:\n", i + 1);
        generate_question(&correct_answer);

        // Get user answer
        scanf("%d", &user_answer);
        
        // Check for correct answer
        if (user_answer == correct_answer) {
            printf("Great job! That's correct! 🎉\n");
            score++;
        } else {
            printf("Oops! The correct answer was %d. 😢\n", correct_answer);
        }
    }

    // Final score
    printf("\nYour final score is: %d out of %d\n", score, QUESTIONS);
    if (score == QUESTIONS) {
        printf("You are a Math Wizard! 🧙‍♂️🌟\n");
    } else if (score >= QUESTIONS / 2) {
        printf("Not bad! Keep practicing! 📚\n");
    } else {
        printf("Oh snap! Time to hit the books! 📖\n");
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    display_welcome_message();
    play_game();
    
    printf("\nThank you for playing the Math Wizard Challenge! Goodbye! 👋\n");
    return 0;
}