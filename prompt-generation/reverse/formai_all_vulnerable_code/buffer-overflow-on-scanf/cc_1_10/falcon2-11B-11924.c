//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 100

struct Student {
    char name[50];
    int id;
    int score;
};

struct Question {
    char title[50];
    char text[1000];
    int correct_answer;
};

struct Exam {
    struct Student students[MAX_STUDENTS];
    int num_students;
    struct Question questions[MAX_QUESTIONS];
    int num_questions;
};

int main() {
    struct Exam exam;
    struct Student student1 = {"John", 1, 0};
    struct Student student2 = {"Mary", 2, 0};
    struct Question question1 = {"What is the capital of France?", "Paris", 1};
    struct Question question2 = {"What is the capital of England?", "London", 2};

    exam.students[0] = student1;
    exam.students[1] = student2;
    exam.questions[0] = question1;
    exam.questions[1] = question2;

    exam.num_students = 2;
    exam.num_questions = 2;

    // Print exam details
    printf("Exam Details:\n");
    printf("Students: ");
    for (int i = 0; i < exam.num_students; i++) {
        printf("%s (%d)\n", exam.students[i].name, exam.students[i].id);
    }
    printf("Questions: ");
    for (int i = 0; i < exam.num_questions; i++) {
        printf("%s\n", exam.questions[i].title);
    }

    // Run the exam
    for (int i = 0; i < exam.num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", exam.questions[i].text);
        printf("Enter answer: ");
        scanf("%d", &exam.students[0].score);
    }

    // Print exam results
    printf("\nExam Results:\n");
    printf("Student 1: %s (%d)\n", exam.students[0].name, exam.students[0].id);
    printf("Student 2: %s (%d)\n", exam.students[1].name, exam.students[1].id);
    printf("Score: %d\n", exam.students[0].score);

    return 0;
}