//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

void loadQuestions(Question questions[], int numQuestions) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error loading questions\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        strcpy(questions[i].question, line);
        i++;
    }

    fclose(fp);
}

void loadStudents(Student students[], int numStudents) {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Error loading students\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        strcpy(students[i].name, line);
        i++;
    }

    fclose(fp);
}

int main() {
    int numQuestions, numStudents, i, j, k, correctAnswers = 0;
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    loadQuestions(questions, numQuestions);

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    loadStudents(students, numStudents);

    for (i = 0; i < numStudents; i++) {
        printf("Student %s's score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}