//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26

typedef struct {
    char question[200];
    char options[MAX_OPTIONS][50];
    char answer[MAX_ANSWERS];
} QUESTION;

void loadQuestions(QUESTION *questions) {
    FILE *fp;
    int i, j;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (fscanf(fp, "Question %d: %s\n", &i+1, questions[i].question)!= 2) {
            printf("Error reading question.\n");
            exit(1);
        }

        for (j = 0; j < MAX_OPTIONS; j++) {
            if (fscanf(fp, "Option %d: %s\n", &j+1, questions[i].options[j])!= 2) {
                printf("Error reading option.\n");
                exit(1);
            }
        }

        if (fscanf(fp, "Answer: %s\n", questions[i].answer)!= 1) {
            printf("Error reading answer.\n");
            exit(1);
        }

        if (strlen(questions[i].answer)!= strlen(questions[i].options[0])) {
            printf("Error: answer and options have different lengths.\n");
            exit(1);
        }
    }

    fclose(fp);
}

int main() {
    QUESTION questions[MAX_QUESTIONS];
    int numQuestions, i, j, score = 0;
    char answer[MAX_ANSWERS];

    loadQuestions(questions);
    printf("How many questions do you want to answer? ");
    scanf("%d", &numQuestions);

    for (i = 0; i < numQuestions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("Option %d: %s\n", j+1, questions[i].options[j]);
        }

        printf("Enter your answer: ");
        scanf(" %s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Your final score is: %d/%d\n", score, numQuestions);

    return 0;
}