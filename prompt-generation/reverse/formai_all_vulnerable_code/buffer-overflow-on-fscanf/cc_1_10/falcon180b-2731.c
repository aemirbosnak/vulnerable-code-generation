//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 1000

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer[50];
} question_t;

int main() {
    int num_questions;
    question_t questions[MAX_QUESTIONS];
    char username[50];
    int score = 0;
    int i, j, k;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", username);

    // Load questions from file
    FILE* fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        return 1;
    }

    num_questions = 0;
    while (fscanf(fp, "%s\n", questions[num_questions].question)!= EOF) {
        num_questions++;
        if (num_questions == MAX_QUESTIONS) {
            printf("Error: Too many questions in file.\n");
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);

    printf("%s, you have %d questions to answer.\n", username, num_questions);

    // Display questions and get answers
    for (i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (j = 0; j < strlen(questions[i].options[0]); j++) {
            questions[i].options[j][0] = toupper(questions[i].options[j][0]);
        }
        printf("Options:\n");
        for (j = 0; j < MAX_OPTIONS; j++) {
            if (strlen(questions[i].options[j]) > 0) {
                printf("%c. %s\n", 'A' + j, questions[i].options[j]);
            }
        }
        printf("Enter your answer (A/B/C/D): ");
        scanf("%s", questions[i].answer);

        // Check answer
        for (j = 0; j < MAX_OPTIONS; j++) {
            if (strcmp(questions[i].answer, questions[i].options[j]) == 0) {
                score++;
                break;
            }
        }
    }

    // Display score
    printf("%s, you got %d out of %d questions correct.\n", username, score, num_questions);

    return 0;
}