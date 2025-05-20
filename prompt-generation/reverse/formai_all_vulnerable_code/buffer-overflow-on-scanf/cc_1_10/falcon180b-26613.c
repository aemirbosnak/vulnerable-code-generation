//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define MAX_STUDENTS 1000
#define MAX_SCORE 100

typedef struct {
    char question[MAX_QUESTIONS];
    char options[MAX_OPTIONS][MAX_ANSWERS];
    int correct_answer;
} question_t;

typedef struct {
    int id;
    char name[MAX_ANSWERS];
    int score;
} student_t;

int main() {
    int n_questions, n_students;
    question_t questions[MAX_QUESTIONS];
    student_t students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &n_questions);

    for (int i = 0; i < n_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the number of options: ");
        scanf("%d", &questions[i].correct_answer);

        for (int j = 0; j < questions[i].correct_answer; j++) {
            printf("Enter option %d: ", j+1);
            scanf("%s", questions[i].options[j]);
        }
    }

    printf("Enter the number of students: ");
    scanf("%d", &n_students);

    for (int i = 0; i < n_students; i++) {
        printf("Enter student %d's name: ", i+1);
        scanf("%s", students[i].name);
    }

    int score = 0;
    for (int i = 0; i < n_questions; i++) {
        for (int j = 0; j < n_students; j++) {
            printf("Student %s's answer for question %d: ", students[j].name, i+1);
            char answer[MAX_ANSWERS];
            scanf("%s", answer);

            int correct = 0;
            for (int k = 0; k < questions[i].correct_answer; k++) {
                if (strcmp(answer, questions[i].options[k]) == 0) {
                    correct = 1;
                    break;
                }
            }

            if (correct) {
                score++;
            }
        }
    }

    printf("The final score is: %d\n", score);

    return 0;
}