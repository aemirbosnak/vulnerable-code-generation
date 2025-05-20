//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
/*
 * Unique C Online Examination System
 * Ada Lovelace Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4

struct question {
    char question[100];
    char answers[MAX_ANSWERS][100];
    char correct_answer[100];
};

struct question questions[MAX_QUESTIONS];

int main() {
    int i, j, n;
    char answer[100];

    // Initialize random seed
    srand(time(NULL));

    // Read questions and answers from file
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open questions.txt file\n");
        return 1;
    }
    for (i = 0; i < MAX_QUESTIONS; i++) {
        fscanf(fp, "%s\n", questions[i].question);
        for (j = 0; j < MAX_ANSWERS; j++) {
            fscanf(fp, "%s\n", questions[i].answers[j]);
        }
        fscanf(fp, "%s\n", questions[i].correct_answer);
    }
    fclose(fp);

    // Shuffle the questions
    for (i = 0; i < MAX_QUESTIONS; i++) {
        n = rand() % MAX_QUESTIONS;
        struct question tmp = questions[i];
        questions[i] = questions[n];
        questions[n] = tmp;
    }

    // Print the questions and prompt the user to enter answers
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        for (j = 0; j < MAX_ANSWERS; j++) {
            printf("%s\n", questions[i].answers[j]);
        }
        printf("Enter your answer: ");
        scanf("%s", answer);
        if (strcmp(answer, questions[i].correct_answer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s\n", questions[i].correct_answer);
        }
    }

    return 0;
}