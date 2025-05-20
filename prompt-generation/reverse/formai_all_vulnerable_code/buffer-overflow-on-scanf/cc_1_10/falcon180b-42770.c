//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100
#define MAX_QUESTION_LENGTH 200

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    int correct_option;
} question_t;

question_t questions[MAX_QUESTIONS];
int num_questions;

void read_questions(char *filename) {
    FILE *fp;
    char line[MAX_QUESTION_LENGTH];
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    num_questions = 0;
    while (fgets(line, MAX_QUESTION_LENGTH, fp)!= NULL) {
        if (num_questions >= MAX_QUESTIONS) {
            printf("Error: too many questions in file\n");
            exit(1);
        }

        questions[num_questions].question[0] = '\0';
        strcat(questions[num_questions].question, line);

        j = 0;
        while (fgets(line, MAX_ANSWER_LENGTH, fp)!= NULL) {
            if (j >= MAX_OPTIONS) {
                printf("Error: too many options for question\n");
                exit(1);
            }

            strcpy(questions[num_questions].options[j], line);
            j++;
        }

        questions[num_questions].correct_option = rand() % j;
        num_questions++;
    }

    fclose(fp);
}

int main() {
    char username[MAX_ANSWER_LENGTH];
    int score;

    printf("Enter your name: ");
    scanf("%s", username);

    read_questions("questions.txt");

    printf("Welcome to the online examination system, %s\n", username);

    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);

        for (int j = 0; j < questions[i].correct_option+1; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        printf("Enter your answer: ");
        scanf("%s", username);

        if (strcmp(username, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nYour final score is: %d out of %d\n", score, num_questions);

    return 0;
}