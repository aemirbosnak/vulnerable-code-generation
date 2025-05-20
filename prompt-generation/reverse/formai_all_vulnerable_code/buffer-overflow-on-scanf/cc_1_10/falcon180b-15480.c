//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char *answers[MAX_ANSWERS];
    int correctAnswer;
} Question;

void readQuestions(Question questions[], int numQuestions) {
    FILE *fp;
    int i, j;

    fp = fopen("questions.txt", "r");

    for (i = 0; i < numQuestions; i++) {
        fscanf(fp, "%s", questions[i].question);
        questions[i].correctAnswer = -1;
        for (j = 0; j < MAX_ANSWERS; j++) {
            fscanf(fp, "%s", questions[i].answers[j]);
            if (strcmp(questions[i].answers[j], "correct") == 0) {
                questions[i].correctAnswer = j;
            }
        }
    }

    fclose(fp);
}

void readStudents(Student students[], int numStudents) {
    FILE *fp;
    int i;

    fp = fopen("students.txt", "r");

    for (i = 0; i < numStudents; i++) {
        fscanf(fp, "%s", students[i].name);
        students[i].score = 0;
    }

    fclose(fp);
}

void writeStudents(Student students[], int numStudents) {
    FILE *fp;
    int i;

    fp = fopen("students.txt", "w");

    for (i = 0; i < numStudents; i++) {
        fprintf(fp, "%s %d\n", students[i].name, students[i].score);
    }

    fclose(fp);
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int numQuestions, numStudents, i, j;

    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    readQuestions(questions, numQuestions);

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    readStudents(students, numStudents);

    for (i = 0; i < numStudents; i++) {
        for (j = 0; j < numQuestions; j++) {
            if (strcmp(students[i].name, questions[j].question) == 0) {
                students[i].score += questions[j].correctAnswer + 1;
            }
        }
    }

    writeStudents(students, numStudents);

    return 0;
}