//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX_QUESTIONS 100
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    char options[4][50];
    int answer;
} Question;

Student students[MAX_STUDENTS];
Question questions[MAX_QUESTIONS];

int numQuestions = 0;
int numStudents = 0;

void loadQuestions() {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp)) {
        Question question;
        sscanf(line, "%[^|]|%[^|]|%[^|]|%[^|]|%d", question.question, question.options[0], question.options[1], question.options[2], &question.answer);
        questions[numQuestions++] = question;
    }

    fclose(fp);
}

void loadStudents() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening students file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, 100, fp)) {
        Student student;
        sscanf(line, "%s", student.name);
        students[numStudents++] = student;
    }

    fclose(fp);
}

void takeExam() {
    for (int i = 0; i < numStudents; i++) {
        printf("Student: %s\n", students[i].name);

        int score = 0;
        for (int j = 0; j < numQuestions; j++) {
            printf("%s\n", questions[j].question);
            for (int k = 0; k < 4; k++) {
                printf("(%d) %s\n", k + 1, questions[j].options[k]);
            }

            int answer;
            scanf("%d", &answer);
            if (answer == questions[j].answer) {
                score++;
            }
        }

        students[i].score = score;
        printf("Score: %d\n", score);
    }
}

void generateReport() {
    FILE *fp = fopen("report.txt", "w");
    if (fp == NULL) {
        printf("Error opening report file.\n");
        exit(1);
    }

    fprintf(fp, "Student Exam Report\n");
    fprintf(fp, "--------------------\n");
    for (int i = 0; i < numStudents; i++) {
        fprintf(fp, "%s: %d\n", students[i].name, students[i].score);
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    loadQuestions();
    loadStudents();
    takeExam();
    generateReport();

    return 0;
}