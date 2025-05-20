//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STUDENTS 100
#define MAX_QUESTIONS 100
#define MAX_ANSWERS 100
#define MAX_SCORE 100
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char answer[MAX_NAME_LENGTH];
} Question;

Question questions[MAX_QUESTIONS];
Student students[MAX_STUDENTS];
int num_students;
int num_questions;
int num_answers;

void init() {
    num_students = 0;
    num_questions = 0;
    num_answers = 0;
}

void add_student() {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the student: ");
    scanf("%s", name);
    strcpy(students[num_students].name, name);
    num_students++;
}

void add_question() {
    char question[MAX_NAME_LENGTH];
    char answer[MAX_NAME_LENGTH];
    printf("Enter the question: ");
    scanf("%s", question);
    printf("Enter the answer: ");
    scanf("%s", answer);
    strcpy(questions[num_questions].question, question);
    strcpy(questions[num_questions].answer, answer);
    num_questions++;
}

void start_exam() {
    int i, j, score = 0;
    for(i = 0; i < num_questions; i++) {
        int correct_answers = 0;
        for(j = 0; j < num_students; j++) {
            if(strcmp(students[j].name, questions[i].answer) == 0) {
                correct_answers++;
                score++;
            }
        }
        printf("%d out of %d students answered correctly.\n", correct_answers, num_students);
    }
    for(i = 0; i < num_students; i++) {
        printf("Student %s got a score of %d.\n", students[i].name, score);
    }
}

int main() {
    init();
    int choice;
    while(1) {
        printf("1. Add student\n2. Add question\n3. Start exam\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                add_question();
                break;
            case 3:
                start_exam();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}