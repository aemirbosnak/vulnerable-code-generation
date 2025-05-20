//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
} Question;

Question questions[MAX_QUESTIONS];

int main() {
    int numQuestions, numOptions, numAnswers, i, j, k, correctAnswers = 0;
    char choice;

    printf("Welcome to the Online Examination System\n");
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the number of options: ");
        scanf("%d", &numOptions);

        for (j = 0; j < numOptions; j++) {
            printf("Enter option %d: ", j+1);
            scanf("%s", questions[i].options[j]);
        }

        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer);
    }

    printf("Enter your name: ");
    scanf("%s", questions[0].answer);

    printf("\n1. Start Exam\n2. Exit\n");
    scanf("%c", &choice);

    if (choice == '1') {
        for (i = 0; i < numQuestions; i++) {
            printf("\nQuestion %d: %s\n", i+1, questions[i].question);

            for (j = 0; j < numOptions; j++) {
                printf("%d. %s\n", j+1, questions[i].options[j]);
            }

            printf("Enter your answer: ");
            scanf("%s", questions[i].answer);

            if (strcmp(questions[i].answer, questions[i].options[0]) == 0) {
                printf("Correct answer!\n");
                correctAnswers++;
            } else {
                printf("Incorrect answer.\n");
            }
        }

        printf("\nYour score is %d out of %d\n", correctAnswers, numQuestions);
    }

    return 0;
}