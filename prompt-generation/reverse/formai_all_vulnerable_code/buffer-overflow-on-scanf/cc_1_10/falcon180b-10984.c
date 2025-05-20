//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 10
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char choices[MAX_CHOICES][MAX_NAME_LENGTH];
    char answer[MAX_NAME_LENGTH];
    int num_choices;
    int correct_answer;
} question;

int main() {
    int num_questions, num_students;
    question questions[MAX_QUESTIONS];
    student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);
        printf("Enter the number of choices: ");
        scanf("%d", &questions[i].num_choices);

        for (int j = 0; j < questions[i].num_choices; j++) {
            printf("Enter choice %d: ", j+1);
            scanf("%s", questions[i].choices[j]);
        }

        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer);
        questions[i].correct_answer = 0;
    }

    for (int i = 0; i < num_students; i++) {
        printf("Enter student name %d: ", i+1);
        scanf("%s", students[i].name);
    }

    int correct_answers[MAX_STUDENTS];
    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_students; j++) {
            printf("Student %s, question %d: ", students[j].name, i+1);
            int choice;
            scanf("%d", &choice);

            if (choice == questions[i].correct_answer) {
                correct_answers[j]++;
            }
        }
    }

    printf("Student scores:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, correct_answers[i]);
    }

    return 0;
}