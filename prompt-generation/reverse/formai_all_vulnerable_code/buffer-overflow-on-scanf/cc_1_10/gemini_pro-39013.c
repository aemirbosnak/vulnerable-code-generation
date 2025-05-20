//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the array of questions and answers
const char *questions[] = {
    "What is the capital of France?",
    "What is the largest planet in our solar system?",
    "What is the name of the biggest ocean in the world?",
    "What is the chemical symbol for gold?",
    "What is the name of the largest country in the world by land area?",
};

const char *answers[] = {
    "Paris",
    "Jupiter",
    "Pacific Ocean",
    "Au",
    "Russia",
};

// Declare the main function
int main() {
    // Welcome the user to the exam
    printf("Welcome to the Online Examination System!\n");
    printf("Please answer the following questions to the best of your ability.\n");

    // Loop through the questions and get the user's answers
    int score = 0;
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, questions[i]);
        char answer[100];
        scanf("%s", answer);

        // Check if the user's answer is correct
        if (strcmp(answer, answers[i]) == 0) {
            score++;
        }
    }

    // Print the user's score
    printf("Your score is %d out of 5.\n", score);

    // Congratulate the user if they passed the exam
    if (score >= 3) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have failed the exam.\n");
    }

    // Return 0 to indicate that the program ran successfully
    return 0;
}