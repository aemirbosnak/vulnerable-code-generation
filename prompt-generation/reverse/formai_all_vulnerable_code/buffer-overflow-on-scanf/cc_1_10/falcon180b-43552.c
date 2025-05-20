//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_CHOICES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answer[MAX_ANSWERS][MAX_NAME_LENGTH];
    int correct_answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];

int num_questions = 0;
int num_students = 0;

void add_question(char* question, char* answer, int correct_answer) {
    strcpy(questions[num_questions].question, question);
    strcpy(questions[num_questions].answer[0], answer);
    questions[num_questions].correct_answer = correct_answer;
    num_questions++;
}

void add_student(char* name) {
    strcpy(students[num_students].name, name);
    students[num_students].score = 0;
    num_students++;
}

void start_exam() {
    int i, j, k;
    char choice;

    for (i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        for (j = 0; j < MAX_ANSWERS; j++) {
            printf("%c) %s\n", 'A' + j, questions[i].answer[j]);
        }
        printf("Enter your choice: ");
        scanf("%c", &choice);
        if (choice == 'A' + questions[i].correct_answer) {
            students[0].score++;
        }
    }

    printf("\nResults:\n");
    for (i = 0; i < num_students; i++) {
        printf("Student %s: %d/%d\n", students[i].name, students[i].score, num_questions);
    }
}

int main() {
    add_question("What is the capital of France?", "Paris", 0);
    add_question("Who wrote 'To Kill a Mockingbird'?", "Harper Lee", 0);
    add_student("John");
    add_student("Jane");

    start_exam();

    return 0;
}