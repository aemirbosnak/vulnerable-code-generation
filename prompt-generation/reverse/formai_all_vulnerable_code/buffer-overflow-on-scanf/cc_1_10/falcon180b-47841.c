//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 20

typedef struct {
    char question[MAX_QUESTIONS];
    char answer[MAX_ANSWERS][MAX_OPTIONS];
    int correct_answer;
} Question;

typedef struct {
    char name[MAX_QUESTIONS];
    int score;
} Student;

int main() {
    int num_questions, num_students;
    Question questions[MAX_QUESTIONS];
    Student students[MAX_QUESTIONS];
    int i, j, k;

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);
        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer[0]);
        for (j = 1; j < MAX_ANSWERS; j++) {
            printf("Enter an incorrect answer: ");
            scanf("%s", questions[i].answer[j]);
        }
        questions[i].correct_answer = 0;
    }

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_students; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    for (i = 0; i < num_questions; i++) {
        for (j = 0; j < num_students; j++) {
            printf("Student %s's answer for question %d: ", students[j].name, i+1);
            scanf("%s", students[j].name);
            for (k = 0; k < MAX_ANSWERS; k++) {
                if (strcmp(students[j].name, questions[i].answer[k]) == 0) {
                    students[j].score++;
                    break;
                }
            }
        }
    }

    for (i = 0; i < num_students; i++) {
        printf("Student %s's score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}