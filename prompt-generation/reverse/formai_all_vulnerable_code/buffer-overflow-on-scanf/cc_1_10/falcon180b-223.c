//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions that can be stored in the system
#define MAX_QUESTIONS 100

// Define the structure of a question
typedef struct {
    char question[100];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    char answer[100];
} question_t;

int main() {
    // Declare variables
    int num_questions;
    question_t questions[MAX_QUESTIONS];
    int score = 0;

    // Get the number of questions from the user
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Prompt the user to enter the questions
    printf("Enter the questions:\n");
    for (int i = 0; i < num_questions; i++) {
        strcpy(questions[i].question, "");
        printf("Question %d: ", i+1);
        scanf("%s", questions[i].question);

        // Get the options for the question
        printf("Enter option 1: ");
        scanf("%s", questions[i].option1);
        printf("Enter option 2: ");
        scanf("%s", questions[i].option2);
        printf("Enter option 3: ");
        scanf("%s", questions[i].option3);
        printf("Enter option 4: ");
        scanf("%s", questions[i].option4);

        // Get the correct answer for the question
        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer);
    }

    // Prompt the user to start the exam
    printf("Press any key to start the exam...\n");
    getchar();

    // Loop through the questions
    for (int i = 0; i < num_questions; i++) {
        // Display the question
        printf("\nQuestion %d:\n%s", i+1, questions[i].question);

        // Display the options
        printf("\nOptions:\n1. %s\n2. %s\n3. %s\n4. %s\n", questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4);

        // Get the user's answer
        char answer[100];
        printf("\nEnter your answer: ");
        scanf("%s", answer);

        // Compare the user's answer with the correct answer
        if (strcmp(answer, questions[i].answer) == 0) {
            // Correct answer
            printf("\nCorrect!\n");
            score++;
        } else {
            // Incorrect answer
            printf("\nIncorrect.\n");
        }
    }

    // Display the score
    printf("\nYour score is: %d/%d\n", score, num_questions);

    return 0;
}