//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 50
#define MAX_NAME 50

typedef struct {
    char question[MAX_QUESTIONS];
    char answer[MAX_ANSWERS][MAX_OPTIONS][MAX_NAME];
    int correct_answer;
} Question;

typedef struct {
    char name[MAX_NAME];
    int score;
} Student;

int main() {
    int num_questions, num_students, i, j, k;
    char filename[MAX_NAME];
    FILE *fp;
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the name of the question file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (i = 0; i < num_questions; i++) {
        fscanf(fp, "%s", questions[i].question);
        fscanf(fp, "%d", &questions[i].correct_answer);

        for (j = 0; j < MAX_ANSWERS; j++) {
            for (k = 0; k < MAX_OPTIONS; k++) {
                fscanf(fp, "%s", questions[i].answer[j][k]);
            }
        }
    }

    fclose(fp);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
    }

    for (i = 0; i < num_questions; i++) {
        for (j = 0; j < num_students; j++) {
            students[j].score += questions[i].correct_answer;
        }
    }

    printf("Student scores:\n");
    for (i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}