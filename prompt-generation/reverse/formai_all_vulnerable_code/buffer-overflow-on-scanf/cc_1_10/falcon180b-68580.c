//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_NAME_SIZE 50
#define MAX_ANSWER_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_SIZE];
    char options[MAX_OPTIONS][MAX_ANSWER_SIZE];
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS];

int main() {
    int num_questions, num_students, i, j, k, correct_answers = 0;
    char answer[MAX_ANSWER_SIZE];
    Student students[MAX_STUDENTS];

    printf("Enter number of questions: ");
    scanf("%d", &num_questions);

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter number of options for question %d: ", i+1);
        scanf("%d", &questions[i].correct_answer);

        for (j = 0; j < questions[i].correct_answer; j++) {
            printf("Enter option %d: ", j+1);
            scanf("%s", questions[i].options[j]);
        }
    }

    printf("Enter number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++) {
        printf("Enter student name %d: ", i+1);
        scanf("%s", students[i].name);
    }

    for (i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);

        for (j = 0; j < questions[i].correct_answer; j++) {
            printf("Option %d: %s\n", j+1, questions[i].options[j]);
        }

        printf("Enter your answer: ");
        scanf("%s", answer);

        for (j = 0; j < questions[i].correct_answer; j++) {
            if (strcmp(answer, questions[i].options[j]) == 0) {
                correct_answers++;
                break;
            }
        }
    }

    printf("Your score is %d out of %d\n", correct_answers, num_questions);

    return 0;
}