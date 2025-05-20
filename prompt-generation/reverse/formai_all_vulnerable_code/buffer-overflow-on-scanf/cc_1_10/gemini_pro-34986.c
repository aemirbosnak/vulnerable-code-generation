//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[256];
    char options[4][64];
    int correct_option;
};

struct Exam {
    char name[64];
    int num_questions;
    struct Question questions[100];
};

struct Student {
    char name[64];
    int score;
};

void create_exam(struct Exam *exam) {
    printf("Enter the name of the exam: ");
    scanf("%s", exam->name);

    printf("Enter the number of questions in the exam: ");
    scanf("%d", &exam->num_questions);

    for (int i = 0; i < exam->num_questions; i++) {
        printf("Enter the question %d: ", i + 1);
        scanf(" %[^\n]", exam->questions[i].question);

        printf("Enter the options for question %d: ", i + 1);
        for (int j = 0; j < 4; j++) {
            scanf(" %[^\n]", exam->questions[i].options[j]);
        }

        printf("Enter the correct option for question %d: ", i + 1);
        scanf(" %d", &exam->questions[i].correct_option);
    }
}

void take_exam(struct Exam *exam, struct Student *student) {
    int score = 0;

    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].options[j]);
        }

        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == exam->questions[i].correct_option) {
            score++;
        }
    }

    student->score = score;
}

void print_results(struct Exam *exam, struct Student *student) {
    printf("Exam name: %s\n", exam->name);
    printf("Student name: %s\n", student->name);
    printf("Score: %d\n", student->score);
}

int main() {
    struct Exam exam;
    create_exam(&exam);

    struct Student student;
    printf("Enter your name: ");
    scanf(" %[^\n]", student.name);

    take_exam(&exam, &student);
    print_results(&exam, &student);

    return 0;
}