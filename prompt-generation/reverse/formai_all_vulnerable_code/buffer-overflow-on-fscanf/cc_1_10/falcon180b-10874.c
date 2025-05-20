//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_MARK 50

struct question {
    char question[200];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
};

void readQuestions(struct question questions[]) {
    FILE *fp;
    int i, j;

    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open questions file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_QUESTIONS; i++) {
        fscanf(fp, "%s", questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            fscanf(fp, "%s", questions[i].options[j]);
        }

        fscanf(fp, "%s", questions[i].answer);
    }

    fclose(fp);
}

void displayQuestion(struct question question) {
    int i;

    printf("%s\n", question.question);

    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s\n", 'A' + i, question.options[i]);
    }
}

int main() {
    struct question questions[MAX_QUESTIONS];
    int numQuestions, i, j, score = 0;
    char answer[MAX_ANSWERS];

    readQuestions(questions);

    numQuestions = sizeof(questions) / sizeof(questions[0]);

    for (i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n", i + 1);
        displayQuestion(questions[i]);

        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }

    printf("\nYour final score is %d out of %d.\n", score, numQuestions);

    return 0;
}