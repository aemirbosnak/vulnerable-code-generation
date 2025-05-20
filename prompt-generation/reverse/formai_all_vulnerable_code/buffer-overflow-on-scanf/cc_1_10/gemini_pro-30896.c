//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Question {
    char question[256];
    char options[4][64];
    int correct_answer;
};

struct Student {
    char name[64];
    int score;
};

struct Exam {
    struct Question questions[10];
    int num_questions;
    int duration;
};

void generate_exam(struct Exam *exam) {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        sprintf(exam->questions[i].question, "Question %d:", i + 1);

        for (int j = 0; j < 4; j++) {
            sprintf(exam->questions[i].options[j], "Option %d", j + 1);
        }

        exam->questions[i].correct_answer = rand() % 4;
    }

    exam->num_questions = 10;
    exam->duration = 60;
}

void take_exam(struct Exam *exam, struct Student *student) {
    int answers[10];

    printf("Welcome to the online exam, %s!\n", student->name);
    printf("You have %d minutes to complete the exam.\n", exam->duration);

    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].options[j]);
        }

        printf("Enter your answer: ");
        scanf("%d", &answers[i]);
    }

    student->score = 0;

    for (int i = 0; i < exam->num_questions; i++) {
        if (answers[i] == exam->questions[i].correct_answer) {
            student->score++;
        }
    }
}

void print_results(struct Exam *exam, struct Student *student) {
    printf("Congratulations, %s!\n", student->name);
    printf("You scored %d out of %d.\n", student->score, exam->num_questions);
}

int main() {
    struct Exam exam;
    struct Student student;

    printf("Enter your name: ");
    scanf("%s", student.name);

    generate_exam(&exam);
    take_exam(&exam, &student);
    print_results(&exam, &student);

    return 0;
}