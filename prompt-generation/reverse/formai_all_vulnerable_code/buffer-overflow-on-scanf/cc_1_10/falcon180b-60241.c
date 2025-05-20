//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 100

typedef struct {
    char question[MAX_QUESTIONS];
    char answer[MAX_ANSWERS][MAX_OPTIONS];
    int correct_answer;
} question_t;

int main() {
    int num_questions;
    int i, j, k;
    int score = 0;
    char response[MAX_ANSWERS][MAX_OPTIONS];
    question_t questions[MAX_QUESTIONS];

    printf("Welcome to the Ada Lovelace Online Examination System!\n");
    printf("Please enter the number of questions: ");
    scanf("%d", &num_questions);

    // Populate the questions array
    for (i = 0; i < num_questions; i++) {
        printf("Enter question #%d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the number of options: ");
        scanf("%d", &questions[i].correct_answer);

        for (j = 0; j < questions[i].correct_answer; j++) {
            printf("Enter option #%d: ", j+1);
            scanf("%s", questions[i].answer[j]);
        }
    }

    // Administer the exam
    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion #%d:\n%s\n", i+1, questions[i].question);

        for (j = 0; j < questions[i].correct_answer; j++) {
            printf("%d. %s\n", j+1, questions[i].answer[j]);
        }

        printf("Enter your answer: ");
        scanf("%s", response[i]);

        // Check if the response is correct
        for (j = 0; j < questions[i].correct_answer; j++) {
            if (strcmp(response[i], questions[i].answer[j]) == 0) {
                score++;
                break;
            }
        }
    }

    // Display the results
    printf("\nExam Results:\n");
    printf("You answered %d out of %d questions correctly.\n", score, num_questions);

    return 0;
}