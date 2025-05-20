//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define MAX_STUDENTS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int roll_no;
    int score;
} Student;

typedef struct {
    char question[200];
    char options[MAX_OPTIONS][100];
    char answer;
} Question;

void readQuestions(Question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %c", questions[i].question, &questions[i].answer)!= EOF) {
        int j = 0;
        while (fscanf(fp, "%s", questions[i].options[j])!= EOF) {
            j++;
            if (j == MAX_OPTIONS)
                break;
        }
        i++;
        if (i == MAX_QUESTIONS)
            break;
    }

    fclose(fp);
}

void readStudents(Student students[]) {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d", students[i].name, &students[i].roll_no)!= EOF) {
        i++;
        if (i == MAX_STUDENTS)
            break;
    }

    fclose(fp);
}

void evaluateAnswers(Question questions[], Student students[]) {
    int i, j;
    for (i = 0; i < MAX_STUDENTS; i++) {
        students[i].score = 0;
        for (j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(students[i].name, questions[j].answer) == 0) {
                students[i].score++;
            }
        }
    }
}

void printResults(Student students[]) {
    int i;
    printf("Student Name\tRoll No.\tScore\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("%s\t%d\t%d\n", students[i].name, students[i].roll_no, students[i].score);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    readQuestions(questions);
    readStudents(students);

    evaluateAnswers(questions, students);

    printResults(students);

    return 0;
}