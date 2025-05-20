//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct {
    char question[100];
    char answers[MAX_ANSWERS][50];
    int correct_answer;
} Question;

int main() {

    Question questions[MAX_QUESTIONS];

    printf("*** Welcome to the C Online Examination System ***\n\n");

    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("\n%s, let's start the exam!\n", name);

    // Generate random questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {

        // Generate random question
        char question[100];
        sprintf(question, "What is the value of %d + %d?", rand() % 10, rand() % 10);
        strcpy(questions[i].question, question);

        // Generate random answers
        char answers[MAX_ANSWERS][50];
        for (int j = 0; j < MAX_ANSWERS; j++) {
            sprintf(answers[j], "%d", rand() % 20);
        }

        // Set correct answer
        int correct_answer = rand() % MAX_ANSWERS;
        strcpy(questions[i].answers[correct_answer], answers[0]);
        strcpy(questions[i].answers[0], answers[correct_answer]);
        questions[i].correct_answer = correct_answer;
        for (int j = 1; j < MAX_ANSWERS; j++) {
            strcpy(questions[i].answers[j], answers[j]);
        }
    }

    // Run the exam
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQ%d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d: %s\n", j+1, questions[i].answers[j]);
        }
        printf("Please enter your answer (1-4): ");
        int answer;
        scanf("%d", &answer);
        if (answer == questions[i].correct_answer + 1) {
            score++;
        }
    }

    // Display results
    printf("\n\nCongratulations, %s! You have completed the exam.\n", name);
    printf("Your score is: %d out of %d.\n", score, MAX_QUESTIONS);
    printf("Thanks for using the C Online Examination System.\n");

    return 0;
}