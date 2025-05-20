//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of questions and marks for each question
#define NUM_QUESTIONS 5
#define MARKS_PER_QUESTION 100

int main() {
    // Initialize the total marks
    int totalMarks = 0;

    // Create an array of strings to store the questions
    char* questions[NUM_QUESTIONS] = {"Question 1", "Question 2", "Question 3", "Question 4", "Question 5"};

    // Create an array of integers to store the answers
    int answers[NUM_QUESTIONS] = {0, 0, 0, 0, 0};

    // Display the questions and answers
    printf("Online Examination System\n");
    printf("--------------------------\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s. %s\n", i + 1, questions[i]);
    }
    printf("\nEnter your answers (1-5): ");

    // Read the answers from the user
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int answer;
        scanf("%d", &answer);
        answers[i] = answer - 1;
    }

    // Calculate the total marks
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answers[i] == 1) {
            totalMarks += MARKS_PER_QUESTION;
        }
    }

    // Display the results
    printf("\nResults:\n");
    printf("--------------------------\n");
    printf("Total Marks: %d\n", totalMarks);
    printf("--------------------------\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answers[i] == 1) {
            printf("Question %d: %s\n", i + 1, questions[i]);
            printf("Your answer: %d\n", answers[i]);
        }
    }
    printf("\n--------------------------\n");

    return 0;
}