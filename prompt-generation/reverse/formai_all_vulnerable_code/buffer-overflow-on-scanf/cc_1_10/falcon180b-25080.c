//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100
#define MAX_QUESTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
    int score;
} student;

typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char choice1[MAX_ANSWER_LENGTH];
    char choice2[MAX_ANSWER_LENGTH];
    char choice3[MAX_ANSWER_LENGTH];
    char choice4[MAX_ANSWER_LENGTH];
    char correct_answer[MAX_ANSWER_LENGTH];
} question;

int main() {
    int num_questions, num_students;
    question quiz[MAX_QUESTIONS];
    student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", quiz[i].question);

        printf("Enter choice 1: ");
        scanf("%s", quiz[i].choice1);

        printf("Enter choice 2: ");
        scanf("%s", quiz[i].choice2);

        printf("Enter choice 3: ");
        scanf("%s", quiz[i].choice3);

        printf("Enter choice 4: ");
        scanf("%s", quiz[i].choice4);

        printf("Enter correct answer: ");
        scanf("%s", quiz[i].correct_answer);
    }

    for (int j = 0; j < num_students; j++) {
        printf("Enter student name %d: ", j+1);
        scanf("%s", students[j].name);
    }

    int correct_answers = 0;
    for (int k = 0; k < num_questions; k++) {
        for (int l = 0; l < num_students; l++) {
            printf("Student %s, enter your answer for question %d: ", students[l].name, k+1);
            scanf("%s", students[l].answer);

            if (strcmp(students[l].answer, quiz[k].correct_answer) == 0) {
                correct_answers++;
                students[l].score++;
            }
        }
    }

    printf("The number of correct answers is %d\n", correct_answers);

    return 0;
}