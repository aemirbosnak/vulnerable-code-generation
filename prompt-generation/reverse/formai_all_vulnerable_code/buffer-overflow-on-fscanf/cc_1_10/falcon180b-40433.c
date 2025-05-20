//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 1000
#define MAX_STUDENTS 100

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[100];
} Question;

typedef struct {
    char name[50];
    int rollNo;
    int score;
} Student;

void readQuestions(Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s %s %s", questions[i].question, questions[i].options[0], questions[i].answer)!= EOF) {
        for (int j = 1; j < MAX_OPTIONS; j++) {
            fscanf(fp, " %s", questions[i].options[j]);
        }
        i++;
    }
    fclose(fp);
}

void readStudents(Student students[]) {
    FILE *fp;
    fp = fopen("students.txt", "r");
    int i = 0;
    while (fscanf(fp, "%s %d", students[i].name, &students[i].rollNo)!= EOF) {
        i++;
    }
    fclose(fp);
}

void evaluateAnswers(Question questions[], Student students[], int numStudents) {
    int i, j, k;
    for (i = 0; i < numStudents; i++) {
        students[i].score = 0;
        for (j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(students[i].name, questions[j].answer) == 0) {
                students[i].score++;
            }
        }
    }
}

void printResults(Student students[], int numStudents) {
    int i;
    for (i = 0; i < numStudents; i++) {
        printf("%s (%d) scored %d out of %d\n", students[i].name, students[i].rollNo, students[i].score, MAX_QUESTIONS);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int numQuestions, numStudents;

    readQuestions(questions);
    numQuestions = sizeof(questions) / sizeof(questions[0]);

    readStudents(students);
    numStudents = sizeof(students) / sizeof(students[0]);

    evaluateAnswers(questions, students, numStudents);

    printResults(students, numStudents);

    return 0;
}