//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} student_t;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    int correct_answer;
} question_t;

void load_questions(question_t questions[], int num_questions) {
    FILE *fp;
    char filename[100];
    int i;

    for (i = 0; i < num_questions; i++) {
        sprintf(filename, "question%d.txt", i+1);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: could not open file %s\n", filename);
            exit(1);
        }
        fscanf(fp, "%s", questions[i].question);
        fscanf(fp, "%s", questions[i].answer);
        fscanf(fp, "%d", &questions[i].correct_answer);
        fclose(fp);
    }
}

int main() {
    int num_students, num_questions;
    char filename[100];
    student_t students[MAX_STUDENTS];
    question_t questions[MAX_QUESTIONS];

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    load_questions(questions, num_questions);

    for (int i = 0; i < num_students; i++) {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    int correct_answers = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        for (int j = 0; j < num_students; j++) {
            printf("Student %d's answer: ", j+1);
            scanf("%s", students[j].name);
            if (strcmp(students[j].name, questions[i].answer) == 0) {
                students[j].score++;
                correct_answers++;
            }
        }
    }

    printf("Total correct answers: %d\n", correct_answers);

    return 0;
}