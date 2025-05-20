//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char *options[MAX_OPTIONS];
    int correct_answer;
} Question;

int main() {
    int num_questions;
    Question questions[MAX_QUESTIONS];
    int num_incorrect_answers = 0;
    int i, j, k;

    printf("Welcome to the Online Examination System!\n\n");

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the questions and options:\n");
    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the options (separated by spaces): ");
        for (j = 0; j < MAX_OPTIONS; j++) {
            scanf("%s", questions[i].options[j]);
        }

        printf("Enter the correct answer (0-4): ");
        scanf("%d", &questions[i].correct_answer);
    }

    printf("\nOnline Examination System\n\n");

    for (i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        printf("Enter your answer (1-5): ");
        scanf("%d", &k);

        if (k == questions[i].correct_answer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
            num_incorrect_answers++;
        }
    }

    printf("\nYou answered %d out of %d questions correctly.\n", num_questions - num_incorrect_answers, num_questions);

    return 0;
}