//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_ANSWER_LEN 20
#define MAX_STUDENTS 100

typedef struct {
    char name[20];
    char answers[MAX_QUESTIONS][MAX_ANSWER_LEN];
} Student;

typedef struct {
    char question[100];
    char correctAnswer[MAX_ANSWER_LEN];
    int numAnswers;
    char answers[MAX_ANSWERS][MAX_ANSWER_LEN];
} Question;

int main() {
    int numStudents, numQuestions;
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    for (int i = 0; i < numStudents; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
    }

    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter correct answer for question %d: ", i+1);
        scanf("%s", questions[i].correctAnswer);

        printf("Enter number of possible answers for question %d: ", i+1);
        scanf("%d", &questions[i].numAnswers);

        for (int j = 0; j < questions[i].numAnswers; j++) {
            printf("Enter possible answer %d for question %d: ", j+1, i+1);
            scanf("%s", questions[i].answers[j]);
        }
    }

    FILE *fp;
    fp = fopen("results.txt", "w");

    if (fp == NULL) {
        printf("Cannot open file results.txt\n");
        exit(1);
    }

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            int correct = 0;

            for (int k = 0; k < questions[j].numAnswers; k++) {
                if (strcmp(students[i].answers[j], questions[j].answers[k]) == 0) {
                    correct++;
                }
            }

            if (correct == 1) {
                fprintf(fp, "Student %s got question %d correct\n", students[i].name, j+1);
            }
        }
    }

    fclose(fp);

    return 0;
}