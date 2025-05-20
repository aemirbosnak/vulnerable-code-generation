//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int answer;
} Question;

void readQuestions(Question *questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open questions file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s\n", questions[count].question)!= EOF) {
        int numOptions = 0;
        while (fscanf(fp, "%s\n", questions[count].options[numOptions])!= EOF) {
            numOptions++;
            if (numOptions == MAX_OPTIONS) {
                break;
            }
        }
        questions[count].answer = numOptions - 1;
        count++;
    }

    fclose(fp);
}

void readStudents(Student *students) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open students file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s\n", students[count].name)!= EOF) {
        count++;
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    readQuestions(questions);

    Student students[MAX_STUDENTS];
    int numStudents = 0;
    while (numStudents < MAX_STUDENTS) {
        printf("Enter student name (or press enter to finish):\n");
        scanf("%s", students[numStudents].name);
        if (strcmp(students[numStudents].name, "") == 0) {
            break;
        }
        numStudents++;
    }

    int numCorrect = 0;
    for (int i = 0; i < numStudents; i++) {
        students[i].score = 0;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Student %s's score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}