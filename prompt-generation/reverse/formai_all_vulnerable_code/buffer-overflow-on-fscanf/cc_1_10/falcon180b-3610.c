//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_ANSWERS 26
#define PASSING_SCORE 60

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    char answer[MAX_ANSWERS];
} Question;

void loadQuestions(Question questions[]) {
    FILE *fp;
    int i, j;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (fscanf(fp, "%s", questions[i].question)!= 1) {
            printf("Error: Invalid question format.\n");
            exit(1);
        }

        questions[i].answer[0] = '\0';
        for (j = 0; j < MAX_CHOICES; j++) {
            if (fscanf(fp, "%s", questions[i].choices[j])!= 1) {
                printf("Error: Invalid choice format.\n");
                exit(1);
            }
        }

        fscanf(fp, "%s", questions[i].answer);
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int numQuestions, i, j, score;

    loadQuestions(questions);
    numQuestions = 0;

    while (questions[numQuestions].question[0]!= '\0') {
        numQuestions++;
    }

    for (i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i].question);

        for (j = 0; j < MAX_CHOICES; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].choices[j]);
        }

        scanf("%s", questions[i].answer);

        if (strcmp(questions[i].answer, questions[i].choices[0]) == 0) {
            score++;
        }
    }

    if (score >= (numQuestions * PASSING_SCORE) / 100) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    return 0;
}