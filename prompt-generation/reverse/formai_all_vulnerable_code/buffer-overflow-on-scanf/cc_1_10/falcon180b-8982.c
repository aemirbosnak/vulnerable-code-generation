//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 50

struct student {
    char name[50];
    int score;
};

struct question {
    char question[100];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    char correct_answer[10];
};

void read_questions(struct question questions[]) {
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d:\n", i + 1);
        scanf("%s", questions[i].question);
        printf("Enter option 1:\n");
        scanf("%s", questions[i].option1);
        printf("Enter option 2:\n");
        scanf("%s", questions[i].option2);
        printf("Enter option 3:\n");
        scanf("%s", questions[i].option3);
        printf("Enter option 4:\n");
        scanf("%s", questions[i].option4);
        printf("Enter correct answer:\n");
        scanf("%s", questions[i].correct_answer);
    }
}

void read_students(struct student students[]) {
    int i;
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter student name for %d:\n", i + 1);
        scanf("%s", students[i].name);
        students[i].score = 0;
    }
}

void evaluate_answers(struct question questions[], struct student students[]) {
    int i, j;
    for (i = 0; i < MAX_STUDENTS; i++) {
        for (j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(students[i].name, questions[j].correct_answer) == 0) {
                students[i].score++;
            }
        }
    }
}

void print_results(struct student students[]) {
    int i;
    printf("Student\tScore\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("%s\t%d\n", students[i].name, students[i].score);
    }
}

int main() {
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];

    read_questions(questions);
    read_students(students);
    evaluate_answers(questions, students);
    print_results(students);

    return 0;
}