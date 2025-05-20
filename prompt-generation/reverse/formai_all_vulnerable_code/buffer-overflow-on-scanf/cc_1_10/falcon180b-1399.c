//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 100
#define MAX_NAME 100
#define MAX_ANSWER 100
#define MAX_SCORE 100

typedef struct {
    char question[MAX_QUESTIONS];
    char choices[MAX_CHOICES][MAX_ANSWER];
    char answer[MAX_ANSWER];
    int score;
} question_t;

typedef struct {
    char name[MAX_NAME];
    int score;
} student_t;

int main() {
    int num_questions, num_students;
    question_t questions[MAX_QUESTIONS];
    student_t students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);
        printf("Enter the number of choices: ");
        scanf("%d", &questions[i].score);
        for (int j = 0; j < questions[i].score; j++) {
            printf("Enter choice %d: ", j+1);
            scanf("%s", questions[i].choices[j]);
        }
        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer);
    }

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        printf("Enter student name %d: ", i+1);
        scanf("%s", students[i].name);
    }

    for (int i = 0; i < num_questions; i++) {
        int correct_answers = 0;
        for (int j = 0; j < num_students; j++) {
            printf("Student %s's answer to question %d: ", students[j].name, i+1);
            char answer[MAX_ANSWER];
            scanf("%s", answer);
            if (strcmp(answer, questions[i].answer) == 0) {
                students[j].score += questions[i].score;
                correct_answers++;
            }
        }
        if (correct_answers == 0) {
            printf("No one answered question %d correctly.\n", i+1);
        }
    }

    for (int i = 0; i < num_students; i++) {
        printf("Student %s's score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}