//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100

struct question {
    char question[100];
    char answer[MAX_ANSWERS][100];
    int correct_answer;
};

struct student {
    char name[50];
    int score;
};

int main() {
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];
    int num_questions, num_students;

    printf("Welcome to the Online Examination System\n");
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("Enter the questions and answers:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: ", i + 1);
        scanf("%s", questions[i].question);

        printf("Enter the answers:\n");
        for (int j = 0; j < MAX_ANSWERS; j++) {
            scanf("%s", questions[i].answer[j]);
        }

        printf("Enter the correct answer (1-4): ");
        scanf("%d", &questions[i].correct_answer);
    }

    printf("Enter the students' names:\n");
    for (int i = 0; i < num_students; i++) {
        scanf("%s", students[i].name);
    }

    printf("The examination has started\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        for (int j = 0; j < num_students; j++) {
            printf("Student %s's answer: ", students[j].name);
            scanf("%d", &students[j].score);

            if (students[j].score == questions[i].correct_answer) {
                printf("%s got the correct answer\n", students[j].name);
            } else {
                printf("%s got the wrong answer\n", students[j].name);
            }
        }
    }

    printf("The examination has ended\n");

    return 0;
}