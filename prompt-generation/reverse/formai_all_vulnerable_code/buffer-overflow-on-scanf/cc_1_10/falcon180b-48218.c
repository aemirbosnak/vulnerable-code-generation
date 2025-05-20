//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER 100
#define MAX_STUDENTS 100
#define MAX_NAME 100
#define MAX_ID 10

struct student {
    char id[MAX_ID];
    char name[MAX_NAME];
};

struct question {
    char question[MAX_QUESTIONS];
    char answer[MAX_ANSWER];
};

int main() {
    int num_students, num_questions;
    struct student *students;
    struct question *questions;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    students = (struct student *)malloc(num_students * sizeof(struct student));

    printf("Enter the student IDs and names (ID name):\n");
    for (int i = 0; i < num_students; i++) {
        scanf("%s %s", students[i].id, students[i].name);
    }

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    questions = (struct question *)malloc(num_questions * sizeof(struct question));

    printf("Enter the questions and answers (question answer):\n");
    for (int i = 0; i < num_questions; i++) {
        scanf("%s %s", questions[i].question, questions[i].answer);
    }

    int num_correct = 0;

    for (int i = 0; i < num_students; i++) {
        for (int j = 0; j < num_questions; j++) {
            printf("Student %s, question %d: ", students[i].name, j+1);
            char answer[MAX_ANSWER];
            scanf("%s", answer);

            if (strcmp(answer, questions[j].answer) == 0) {
                num_correct++;
            }
        }
    }

    printf("Total number of correct answers: %d\n", num_correct);

    return 0;
}