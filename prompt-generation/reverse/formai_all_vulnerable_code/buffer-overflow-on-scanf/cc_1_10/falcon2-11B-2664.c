//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

struct student {
    char name[50];
    char roll[10];
    char email[50];
    int age;
};

struct question {
    char question[100];
    char options[5][100];
    int correct_option;
};

struct exam {
    struct student students[100];
    int num_students;
    struct question questions[100];
    int num_questions;
};

int main() {
    struct exam exam;
    int i, j, choice, correct;

    srand(time(NULL));

    printf("Enter the number of students: ");
    scanf("%d", &exam.num_students);

    for (i = 0; i < exam.num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", exam.students[i].name);
        printf("Enter student roll number: ");
        scanf("%s", exam.students[i].roll);
        printf("Enter student email: ");
        scanf("%s", exam.students[i].email);
        printf("Enter student age: ");
        scanf("%d", &exam.students[i].age);
    }

    for (i = 0; i < exam.num_questions; i++) {
        printf("Enter question: ");
        scanf("%s", exam.questions[i].question);
        printf("Enter options: ");
        for (j = 0; j < 5; j++) {
            scanf("%s", exam.questions[i].options[j]);
        }
        printf("Enter correct option: ");
        scanf("%d", &exam.questions[i].correct_option);
    }

    for (i = 0; i < exam.num_students; i++) {
        printf("Student %d: ", i + 1);
        for (j = 0; j < exam.num_questions; j++) {
            printf("%s. %s\n", exam.questions[j].question, exam.questions[j].options[exam.questions[j].correct_option]);
        }
    }

    for (i = 0; i < exam.num_students; i++) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice!= exam.questions[choice - 1].correct_option) {
            printf("Wrong answer. Correct answer was %d.\n", exam.questions[choice - 1].correct_option);
        } else {
            printf("Correct answer!\n");
        }
    }

    return 0;
}