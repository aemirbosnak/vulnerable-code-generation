//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define PASS_MARK 50

struct question {
    char question_text[100];
    int correct_answer;
    char options[MAX_OPTIONS][50];
};

struct student {
    char name[50];
    int roll_number;
    int score;
};

void read_questions(struct question questions[]) {
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d %s %s %s %s", questions[i].question_text, &questions[i].correct_answer, questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3])!= EOF) {
        i++;
    }
    fclose(fp);
}

void read_students(struct student students[]) {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(fp, "%s %d", students[i].name, &students[i].roll_number)!= EOF) {
        i++;
    }
    fclose(fp);
}

void display_question(struct question question) {
    printf("%s\n", question.question_text);
    int j = 0;
    while (j < MAX_OPTIONS && question.options[j]!= NULL) {
        printf("%d. %s\n", j + 1, question.options[j]);
        j++;
    }
}

int evaluate_answer(struct question question, int answer) {
    if (answer == question.correct_answer) {
        return 1;
    }
    return 0;
}

int main() {
    struct question questions[MAX_QUESTIONS];
    read_questions(questions);

    struct student students[MAX_STUDENTS];
    read_students(students);

    int i, j;
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("\nStudent Name: %s\nRoll Number: %d\n", students[i].name, students[i].roll_number);
        for (j = 0; j < MAX_QUESTIONS; j++) {
            display_question(questions[j]);
            int answer;
            scanf("%d", &answer);
            if (evaluate_answer(questions[j], answer)) {
                students[i].score++;
            }
        }
        printf("\nScore: %d\n\n", students[i].score);
    }

    return 0;
}