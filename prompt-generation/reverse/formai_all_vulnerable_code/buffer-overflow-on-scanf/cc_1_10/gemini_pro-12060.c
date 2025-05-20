//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char options[4][100];
    int correct_answer;
};

struct Student {
    char name[100];
    int score;
};

struct Exam {
    char title[100];
    int num_questions;
    struct Question questions[100];
    int num_students;
    struct Student students[100];
};

struct Exam exam = {
    .title = "My Awesome Exam",
    .num_questions = 5,
    .questions = {
        {
            .question = "What is the capital of France?",
            .options = {"Paris", "London", "Berlin", "Rome"},
            .correct_answer = 0
        },
        {
            .question = "Who painted the Mona Lisa?",
            .options = {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Salvador Dali"},
            .correct_answer = 0
        },
        {
            .question = "What is the largest ocean in the world?",
            .options = {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
            .correct_answer = 0
        },
        {
            .question = "What is the chemical symbol for gold?",
            .options = {"Au", "Ag", "Cu", "Fe"},
            .correct_answer = 0
        },
        {
            .question = "Who wrote the Harry Potter series?",
            .options = {"J.K. Rowling", "Stephen King", "George R.R. Martin", "Rick Riordan"},
            .correct_answer = 0
        }
    },
    .num_students = 0,
    .students = {}
};

void add_student(char *name) {
    strcpy(exam.students[exam.num_students].name, name);
    exam.students[exam.num_students].score = 0;
    exam.num_students++;
}

void take_exam(char *name) {
    int score = 0;
    for (int i = 0; i < exam.num_questions; i++) {
        int answer;
        printf("%s\n", exam.questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, exam.questions[i].options[j]);
        }
        scanf("%d", &answer);
        if (answer == exam.questions[i].correct_answer) {
            score++;
        }
    }
    for (int i = 0; i < exam.num_students; i++) {
        if (strcmp(exam.students[i].name, name) == 0) {
            exam.students[i].score = score;
            break;
        }
    }
}

void print_results() {
    for (int i = 0; i < exam.num_students; i++) {
        printf("%s: %d%%\n", exam.students[i].name, exam.students[i].score * 100 / exam.num_questions);
    }
}

int main() {
    int choice;
    char name[100];
    do {
        printf("1. Add student\n");
        printf("2. Take exam\n");
        printf("3. Print results\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                add_student(name);
                break;
            case 2:
                printf("Enter your name: ");
                scanf("%s", name);
                take_exam(name);
                break;
            case 3:
                print_results();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}