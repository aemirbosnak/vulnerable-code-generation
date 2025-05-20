//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions and the maximum score
#define NUM_QUESTIONS 10
#define MAX_SCORE 100

// Define the question bank
const char* QUESTION_BANK[] = {
    "What is the capital of India?",
    "What is the sum of 3 and 4?",
    "What is the square root of 16?",
    "What is the product of 7 and 9?",
    "What is the result of 5 + 2?",
    "What is the factorial of 5?",
    "What is the remainder when 12 is divided by 4?",
    "What is the result of 10 - 2?",
    "What is the quotient of 20 divided by 4?",
    "What is the result of 5 * 3?"
};

int main() {
    int score = 0;
    int current_question = 1;

    // Print the instructions
    printf("Welcome to the online examination system!\n");
    printf("You have %d questions to answer.\n", NUM_QUESTIONS);

    // Generate random questions and display them to the user
    srand(time(NULL));
    while (current_question <= NUM_QUESTIONS) {
        int random_question = rand() % (sizeof(QUESTION_BANK) / sizeof(QUESTION_BANK[0]));
        printf("Question %d: %s\n", current_question, QUESTION_BANK[random_question]);
        printf("Answer: ");
        int answer = scanf("%d", &score);
        if (answer == 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is: %d\n", QUESTION_BANK[random_question]);
        }
        current_question++;
    }

    // Display the final score
    printf("Your final score is: %d/%d\n", score, MAX_SCORE);
    return 0;
}