//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_ANSWERS 50

struct question {
    char question[100];
    int num_options;
    char options[MAX_OPTIONS][100];
    int correct_answer;
};

int main() {
    int num_questions, i, j, correct_answers = 0;
    char filename[50];
    printf("Enter the name of the question file: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(fp, "%d", &num_questions);
    struct question questions[MAX_QUESTIONS];
    for (i = 0; i < num_questions; i++) {
        fscanf(fp, "%s", questions[i].question);
        fscanf(fp, "%d", &questions[i].num_options);
        for (j = 0; j < questions[i].num_options; j++) {
            fscanf(fp, "%s", questions[i].options[j]);
        }
        fscanf(fp, "%d", &questions[i].correct_answer);
    }
    fclose(fp);
    printf("Enter your name: ");
    char name[50];
    scanf("%s", name);
    printf("Welcome %s!\n", name);
    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].question);
        for (j = 0; j < questions[i].num_options; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }
        printf("Enter your answer: ");
        char answer[50];
        scanf("%s", answer);
        int is_correct = 0;
        for (j = 0; j < questions[i].num_options; j++) {
            if (strcmp(answer, questions[i].options[j]) == 0) {
                is_correct = 1;
                break;
            }
        }
        if (is_correct) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", questions[i].options[questions[i].correct_answer-1]);
        }
    }
    printf("\nYou got %d out of %d questions correct.\n", correct_answers, num_questions);
    return 0;
}