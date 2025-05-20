//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4

struct Question {
    char question[100];
    char correctAnswer[MAX_OPTIONS][50];
    int numOptions;
    int correctOption;
};

struct Student {
    char name[50];
    int score;
};

void readQuestions(struct Question questions[]) {
    FILE *fp;
    int i = 0;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", questions[i].question, &questions[i].numOptions)!= EOF) {
        for (int j = 0; j < questions[i].numOptions; j++) {
            fscanf(fp, "%s", questions[i].correctAnswer[j]);
        }
        i++;
    }

    fclose(fp);
}

void readStudents(struct Student students[]) {
    FILE *fp;
    int i = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", students[i].name)!= EOF) {
        i++;
    }

    fclose(fp);
}

void takeExam(struct Question questions[], struct Student students[]) {
    int i, j, k, correctAnswers = 0;

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        for (j = 0; j < questions[i].numOptions; j++) {
            printf("%d. %s\n", j+1, questions[i].correctAnswer[j]);
        }
        printf("Enter your answer (1-%d): ", questions[i].numOptions);
        scanf("%d", &k);

        if (k == questions[i].correctOption) {
            correctAnswers++;
        }
    }

    printf("\nYour score is %d out of %d.\n", correctAnswers, MAX_QUESTIONS);
}

int main() {
    struct Question questions[MAX_QUESTIONS];
    struct Student students[MAX_QUESTIONS];

    readQuestions(questions);
    readStudents(students);

    takeExam(questions, students);

    return 0;
}