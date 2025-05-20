//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_CHAR 256
#define MAX_LINE 1024

typedef struct Question {
    char question[MAX_CHAR];
    char options[MAX_OPTIONS][MAX_CHAR];
    int answer;
} Question;

typedef struct Student {
    char name[MAX_CHAR];
    int roll_no;
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[100];
int num_questions = 0;
int num_students = 0;
int current_question = 0;

void init_questions() {
    FILE *fp = fopen("questions.txt", "r");

    if (fp == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, fp) != NULL) {
        sscanf(line, "%s %s %d", questions[num_questions].question, questions[num_questions].options[0], &questions[num_questions].answer);

        for (int i = 1; i < MAX_OPTIONS; i++) {
            fgets(questions[num_questions].options[i], MAX_CHAR, fp);
            questions[num_questions].options[i][strlen(questions[num_questions].options[i]) - 1] = '\0'; // remove newline character
            questions[num_questions].options[i][0] = toupper(questions[num_questions].options[i][0]); // capitalize first letter
        }

        num_questions++;
    }

    fclose(fp);
}

void init_students() {
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Error opening students file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", students[num_students].name, &students[num_students].roll_no) != EOF) {
        num_students++;
    }

    fclose(fp);
}

int main() {
    srand(time(NULL));

    init_questions();
    init_students();

    printf("\nONLINE EXAMINATION SYSTEM\n");

    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d: %s\n", students[i].roll_no, students[i].name);

        current_question = rand() % num_questions;

        printf("\nQuestion %d:\n%s\n", current_question + 1, questions[current_question].question);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[current_question].options[j]);
        }

        int answer;
        scanf("%d", &answer);

        if (answer == questions[current_question].answer) {
            students[i].score += 10;
            printf("Correct answer. You scored 10 points.\n");
        } else {
            printf("Incorrect answer. Try again.\n");
        }

        printf("\n");
    }

    printf("\nResults:\n");

    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d: %s\nRoll No: %d\nScore: %d", i + 1, students[i].name, students[i].roll_no, students[i].score);
    }

    return 0;
}