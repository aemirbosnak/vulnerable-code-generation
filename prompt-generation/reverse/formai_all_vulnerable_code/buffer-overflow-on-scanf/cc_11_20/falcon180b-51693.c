//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 5
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_SCORE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answers[MAX_ANSWERS][MAX_NAME_LENGTH];
    int correctAnswer;
} Question;

int main() {
    int numQuestions, numStudents, i, j, k;
    char input[MAX_NAME_LENGTH];
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    for (i = 0; i < numStudents; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
    }

    printf("Enter questions and answers (separated by ~):\n");
    for (i = 0; i < numQuestions; i++) {
        scanf("%s", questions[i].question);
        questions[i].correctAnswer = -1;
        for (j = 0; j < MAX_ANSWERS; j++) {
            scanf("%s", questions[i].answers[j]);
            if (tolower(questions[i].answers[j][0]) == '*') {
                questions[i].correctAnswer = j;
            }
        }
    }

    printf("Enter answers for each student:\n");
    for (i = 0; i < numStudents; i++) {
        for (j = 0; j < numQuestions; j++) {
            scanf("%s", input);
            k = 0;
            while (k < MAX_ANSWERS && strcmp(input, questions[j].answers[k])!= 0) {
                k++;
            }
            if (k == MAX_ANSWERS) {
                printf("Invalid answer for question %d\n", j+1);
            } else if (k == questions[j].correctAnswer) {
                students[i].score++;
            }
        }
    }

    printf("Scores:\n");
    for (i = 0; i < numStudents; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}