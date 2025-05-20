//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[100];
    char *answers[MAX_ANSWERS];
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int num_questions;
int num_students;

void read_questions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        Question *q = &questions[num_questions];
        strcpy(q->question, line);

        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL && i < MAX_ANSWERS) {
            strcpy(q->answers[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        q->correct_answer = i - 1;
        num_questions++;
    }

    fclose(fp);
}

void read_students() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening students file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp)!= NULL) {
        Student *s = &students[num_students];
        strcpy(s->name, line);
        num_students++;
    }

    fclose(fp);
}

int main() {
    read_questions();
    read_students();

    int i;
    for (i = 0; i < num_students; i++) {
        printf("Student %d: %s\n", i + 1, students[i].name);
    }

    int j;
    for (j = 0; j < num_questions; j++) {
        printf("Question %d: %s\n", j + 1, questions[j].question);
        int k;
        for (k = 0; k < questions[j].correct_answer + 1; k++) {
            printf("  %s\n", questions[j].answers[k]);
        }
    }

    return 0;
}