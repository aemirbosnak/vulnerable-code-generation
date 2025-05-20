//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Welcome the user to the program
    printf("Welcome to the Math Exercise Program!\n");
    printf("This program will test your math skills with a variety of questions.\n");
    printf("Are you ready to get started? (y/n)\n");

    // Get the user's input
    char input;
    scanf("%c", &input);

    // If the user is not ready, exit the program
    if (input == 'n') {
        printf("Okay, goodbye!\n");
        return 0;
    }

    // Create an array of math questions
    int questions[] = {
        1 + 1,
        2 * 2,
        3 / 3,
        4 + 5,
        6 - 2,
        7 * 8,
        9 / 3,
        10 + 20,
        11 - 5,
        12 * 12
    };

    // Create an array of answer choices
    int choices[] = {
        2,
        4,
        1,
        9,
        4,
        56,
        3,
        30,
        6,
        144
    };

    // Create a variable to store the user's score
    int score = 0;

    // Loop through the array of questions
    for (int i = 0; i < 10; i++) {
        // Get the question and answer choices
        int question = questions[i];
        int choice1 = choices[i];
        int choice2 = choices[i + 1];
        int choice3 = choices[i + 2];

        // Print the question
        printf("Question %d: What is %d?\n", i + 1, question);

        // Print the answer choices
        printf("a) %d\n", choice1);
        printf("b) %d\n", choice2);
        printf("c) %d\n", choice3);

        // Get the user's input
        int answer;
        scanf("%d", &answer);

        // Check if the user's answer is correct
        if (answer == question) {
            // Increment the user's score
            score++;

            // Print a message to the user
            printf("Correct!\n");
        } else {
            // Print a message to the user
            printf("Incorrect.\n");
        }
    }

    // Print the user's score
    printf("Your score is %d out of 10.\n", score);

    // If the user scored 8 or more points, congratulate them
    if (score >= 8) {
        printf("Congratulations! You are a math master!\n");
    } else {
        // If the user scored less than 8 points, encourage them to practice
        printf("Don't give up! Keep practicing and you will improve.\n");
    }

    // Return 0 to indicate that the program ran successfully
    return 0;
}