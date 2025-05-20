//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to simulate an online examination
void online_exam(int num_questions, char** questions, char** answers) {
    // Display the instructions
    printf("Welcome to the online examination system!\n");
    printf("You have %d questions to answer.\n", num_questions);

    // Display the questions
    int current_question = 0;
    while (current_question < num_questions) {
        printf("Question %d:\n", current_question + 1);
        printf("%s\n", questions[current_question]);
        printf("Answer:\n");
        printf("%s\n", answers[current_question]);
        printf("Enter your answer:\n");
        scanf("%s", answers[current_question]);
        current_question++;
    }

    // Display the results
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (strcmp(answers[i], questions[i]) == 0) {
            score++;
        }
    }
    printf("Your score is: %d/%d\n", score, num_questions);
}

int main() {
    int num_questions = 5;
    char** questions = malloc(num_questions * sizeof(char*));
    char** answers = malloc(num_questions * sizeof(char*));

    // Define the questions and answers
    questions[0] = "What is the capital of India?";
    answers[0] = "New Delhi";
    questions[1] = "What is the largest planet in our solar system?";
    answers[1] = "Jupiter";
    questions[2] = "What is the sum of 3 and 4?";
    answers[2] = "7";
    questions[3] = "What is the product of 2 and 3?";
    answers[3] = "6";
    questions[4] = "What is the square root of 16?";
    answers[4] = "4";

    // Call the online examination function
    online_exam(num_questions, questions, answers);

    // Free the allocated memory
    for (int i = 0; i < num_questions; i++) {
        free(questions[i]);
        free(answers[i]);
    }
    free(questions);
    free(answers);

    return 0;
}