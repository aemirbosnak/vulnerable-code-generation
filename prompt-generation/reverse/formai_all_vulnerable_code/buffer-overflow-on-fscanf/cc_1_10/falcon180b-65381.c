//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 50

typedef struct {
    char question[MAX_QUESTIONS];
    char options[MAX_QUESTIONS][MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char correct_answer[MAX_QUESTIONS][MAX_ANSWER_LENGTH];
    int num_options;
} Question;

void read_questions(Question* questions) {
    FILE* fp = fopen("questions.txt", "r");
    int i = 0;

    if (fp == NULL) {
        printf("Error: questions.txt not found\n");
        exit(1);
    }

    while (fscanf(fp, "%s", questions[i].question)!= EOF) {
        int j = 0;
        while (fscanf(fp, "%s", questions[i].options[j])!= EOF) {
            j++;
            if (j >= MAX_OPTIONS) {
                printf("Error: too many options for question %d\n", i+1);
                exit(1);
            }
        }
        questions[i].num_options = j;
        fscanf(fp, "%s", questions[i].correct_answer);
        i++;
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    int correct_answers = 0;
    int user_answers[MAX_QUESTIONS];

    read_questions(questions);
    num_questions = sizeof(questions)/sizeof(Question);

    printf("Online Examination System\n");
    printf("-------------------------\n");

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < questions[i].num_options; j++) {
            printf("  (%c) %s\n", 'A'+j, questions[i].options[j]);
        }
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &user_answers[i]);
    }

    for (int i = 0; i < num_questions; i++) {
        if (strcmp(questions[i].correct_answer, questions[i].options[user_answers[i]-1]) == 0) {
            correct_answers++;
        }
    }

    printf("\nResults:\n");
    printf("Correct answers: %d\n", correct_answers);
    printf("Incorrect answers: %d\n", num_questions - correct_answers);

    return 0;
}