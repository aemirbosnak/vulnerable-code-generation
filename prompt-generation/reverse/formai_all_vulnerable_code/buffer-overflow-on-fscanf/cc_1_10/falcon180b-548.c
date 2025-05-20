//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 10
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

int numQuestions;
Question questions[MAX_QUESTIONS];
int numStudents;
Student students[MAX_STUDENTS];

int main() {
    int i, j, k;
    char answer[MAX_ANSWER_LENGTH];
    int score = 0;

    printf("Welcome to the Online Examination System!\n");

    // Load questions from file
    FILE* fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open questions file.\n");
        return 1;
    }

    numQuestions = 0;
    while (fscanf(fp, "%s\n", questions[numQuestions].question)!= EOF) {
        numQuestions++;
    }
    fclose(fp);

    // Load students from file
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open students file.\n");
        return 1;
    }

    numStudents = 0;
    while (fscanf(fp, "%s\n", students[numStudents].name)!= EOF) {
        numStudents++;
    }
    fclose(fp);

    // Start exam
    for (i = 0; i < numStudents; i++) {
        printf("\nStudent: %s\n", students[i].name);

        for (j = 0; j < numQuestions; j++) {
            printf("Question %d: %s\n", j + 1, questions[j].question);

            fgets(answer, MAX_ANSWER_LENGTH, stdin);
            answer[strcspn(answer, "\n")] = '\0';

            if (strcmp(answer, questions[j].answer) == 0) {
                score++;
            }
        }

        printf("\nScore: %d/%d\n", score, numQuestions);
        score = 0;
    }

    return 0;
}