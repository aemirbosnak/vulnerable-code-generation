//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    int i = 0;

    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error loading questions.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %s\n", questions[i].question, questions[i].options[0], questions[i].options[1])!= EOF) {
        i++;
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int numQuestions, i, j, correctAnswers = 0;
    char answer[MAX_ANSWERS];

    loadQuestions(questions);

    printf("Welcome to the Online Examination System.\n");

    numQuestions = rand() % MAX_QUESTIONS;

    for (i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            if (questions[i].options[j][0]!= '\0') {
                printf("%c. %s\n", 'A' + j, questions[i].options[j]);
            }
        }

        printf("\nEnter your answer: ");
        scanf("%s", answer);

        tolower(answer);
        tolower(questions[i].answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            correctAnswers++;
            printf("\nCorrect!\n");
        } else {
            printf("\nIncorrect.\n");
        }
    }

    printf("\nYou got %d out of %d questions correct.\n", correctAnswers, numQuestions);

    return 0;
}