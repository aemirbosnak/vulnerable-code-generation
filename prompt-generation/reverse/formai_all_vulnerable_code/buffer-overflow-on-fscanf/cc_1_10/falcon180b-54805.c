//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 4
#define MAX_ANSWERS 26
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char question[MAX_QUESTIONS];
    char choiceA[MAX_CHOICES][MAX_ANSWERS];
    char choiceB[MAX_CHOICES][MAX_ANSWERS];
    char choiceC[MAX_CHOICES][MAX_ANSWERS];
    char choiceD[MAX_CHOICES][MAX_ANSWERS];
    char answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int numQuestions, numStudents;

void loadQuestions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open questions file.\n");
        exit(1);
    }
    numQuestions = 0;
    while (fscanf(fp, "%s", questions[numQuestions].question)!= EOF) {
        numQuestions++;
        if (numQuestions >= MAX_QUESTIONS) {
            printf("Error: Too many questions.\n");
            exit(1);
        }
    }
    fclose(fp);
}

void loadStudents() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open students file.\n");
        exit(1);
    }
    numStudents = 0;
    while (fscanf(fp, "%s", students[numStudents].name)!= EOF) {
        numStudents++;
        if (numStudents >= MAX_STUDENTS) {
            printf("Error: Too many students.\n");
            exit(1);
        }
    }
    fclose(fp);
}

void askQuestion(int questionIndex, int studentIndex) {
    printf("Question %d: %s\n", questionIndex + 1, questions[questionIndex].question);
    printf("A. %s\n", questions[questionIndex].choiceA[0]);
    printf("B. %s\n", questions[questionIndex].choiceB[0]);
    printf("C. %s\n", questions[questionIndex].choiceC[0]);
    printf("D. %s\n", questions[questionIndex].choiceD[0]);
    char answer;
    scanf(" %c", &answer);
    if (tolower(answer) == tolower(questions[questionIndex].answer)) {
        printf("Correct!\n");
        students[studentIndex].score++;
    } else {
        printf("Incorrect.\n");
    }
}

int main() {
    loadQuestions();
    loadStudents();
    int i, j, score = 0;
    for (i = 0; i < numStudents; i++) {
        score = 0;
        for (j = 0; j < numQuestions; j++) {
            askQuestion(j, i);
        }
        printf("Your score: %d out of %d\n", score, numQuestions);
    }
    return 0;
}