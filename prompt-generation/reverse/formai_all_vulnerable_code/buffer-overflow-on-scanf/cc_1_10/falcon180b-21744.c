//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_STUDENTS 100
#define MAX_SCORES 100

struct question {
    char question[100];
    int num_options;
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char correct_answer;
};

struct student {
    char name[50];
    int score;
};

void read_questions(struct question *questions) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d %c %s %s %s %s %c\n", questions[i].question, &questions[i].num_options, questions[i].correct_answer, questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4)!= EOF) {
        i++;
        if (i >= MAX_QUESTIONS) {
            printf("Maximum number of questions exceeded\n");
            exit(1);
        }
    }
    fclose(fp);
}

void read_students(struct student *students) {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d\n", students[i].name, &students[i].score)!= EOF) {
        i++;
        if (i >= MAX_STUDENTS) {
            printf("Maximum number of students exceeded\n");
            exit(1);
        }
    }
    fclose(fp);
}

void evaluate_answers(struct question *questions, struct student *students, int num_students) {
    int i, j, k;
    for (i = 0; i < num_students; i++) {
        for (j = 0; j < MAX_QUESTIONS; j++) {
            if (strcmp(students[i].name, questions[j].correct_answer) == 0) {
                students[i].score += 1;
            }
        }
    }
}

void display_results(struct student *students, int num_students) {
    int i;
    printf("\nResults\n");
    printf("Name\tScore\n");
    for (i = 0; i < num_students; i++) {
        printf("%s\t%d\n", students[i].name, students[i].score);
    }
}

int main() {
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];
    int num_questions, num_students;
    char filename[50];
    printf("Enter number of questions: ");
    scanf("%d", &num_questions);
    printf("Enter number of students: ");
    scanf("%d", &num_students);
    sprintf(filename, "questions.txt");
    read_questions(questions);
    sprintf(filename, "students.txt");
    read_students(students);
    evaluate_answers(questions, students, num_students);
    display_results(students, num_students);
    return 0;
}