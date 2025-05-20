//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define MAX_STUDENTS 100

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer;
} Question;

typedef struct {
    char name[50];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];

void readQuestions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open questions file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s\n", questions[count].question)!= EOF) {
        int optionCount = 0;
        while (fscanf(fp, "%s\n", questions[count].options[optionCount])!= EOF) {
            optionCount++;
            if (optionCount >= MAX_OPTIONS) {
                break;
            }
        }
        questions[count].answer = tolower(fgetc(fp));
        count++;
    }

    fclose(fp);
}

void readStudents() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open students file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s\n", students[count].name)!= EOF) {
        count++;
    }

    fclose(fp);
}

int main() {
    readQuestions();
    readStudents();

    int numStudents = 0;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    if (numStudents > MAX_STUDENTS) {
        printf("Error: Maximum number of students is %d.\n", MAX_STUDENTS);
        return 1;
    }

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
    }

    int numCorrectAnswers = 0;
    for (int i = 0; i < numStudents; i++) {
        printf("Student %s's score: %d\n", students[i].name, numCorrectAnswers);
    }

    return 0;
}