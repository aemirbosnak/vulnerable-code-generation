//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_answer;
} Question;

void load_questions(Question questions[]) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error loading questions\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        strcpy(questions[i].question, line);
        questions[i].correct_answer = 0;
        i++;
    }

    fclose(fp);
}

int main() {
    int num_questions;
    Question questions[MAX_QUESTIONS];
    int score = 0;

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    load_questions(questions);

    for (int i = 0; i < num_questions; i++) {
        int correct_answers = 0;

        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);

        for (int j = 0; j < questions[i].correct_answer; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        for (int j = 0; j < MAX_OPTIONS; j++) {
            scanf("%d", &questions[i].options[j][strlen(questions[i].options[j])]);
        }

        for (int j = 0; j < MAX_OPTIONS; j++) {
            if (strcmp(questions[i].options[j], "True") == 0 && questions[i].correct_answer == j + 1) {
                correct_answers++;
            }
        }

        score += correct_answers;
    }

    printf("\nYour final score is: %d out of %d\n", score, num_questions);

    return 0;
}