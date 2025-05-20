//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

struct question {
    char question[MAX_STUDENTS][MAX_NAME_LENGTH];
    int num_answers;
    char answer[MAX_ANSWERS][MAX_NAME_LENGTH];
    int correct_answer;
};

struct student {
    char name[MAX_NAME_LENGTH];
    int score;
};

int main() {
    int num_questions, num_students;
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question[0]);
        questions[i].num_answers = 0;
        while (questions[i].num_answers < MAX_ANSWERS && questions[i].num_answers < strlen(questions[i].question[0]) - 2) {
            printf("Enter answer %d: ", questions[i].num_answers+1);
            scanf("%s", questions[i].answer[questions[i].num_answers]);
            questions[i].num_answers++;
        }
        printf("Enter the correct answer (%d): ", questions[i].num_answers);
        scanf("%d", &questions[i].correct_answer);
    }

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        printf("Enter student name %d: ", i+1);
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_students; j++) {
            printf("Student %s's answer for question %d: ", students[j].name, i+1);
            scanf("%s", students[j].name);
            for (int k = 0; k < questions[i].num_answers; k++) {
                if (strcmp(students[j].name, questions[i].answer[k]) == 0) {
                    students[j].score++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < num_students; i++) {
        printf("Student %s's score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}