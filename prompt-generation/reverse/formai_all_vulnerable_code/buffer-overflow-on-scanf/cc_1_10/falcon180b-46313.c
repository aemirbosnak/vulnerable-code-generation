//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100
#define MAX_STUDENTS 100

struct question {
    char question_text[MAX_ANSWER_LENGTH];
    int answer;
    int difficulty;
};

struct student {
    char name[MAX_ANSWER_LENGTH];
    int score;
};

int main() {
    struct question questions[MAX_QUESTIONS];
    struct student students[MAX_STUDENTS];
    int num_questions, num_students;
    int i, j;

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question_text);
        printf("Enter answer: ");
        scanf("%d", &questions[i].answer);
        printf("Enter difficulty (1-10): ");
        scanf("%d", &questions[i].difficulty);
    }

    for (i = 0; i < num_students; i++) {
        printf("Enter student %d name: ", i+1);
        scanf("%s", students[i].name);
    }

    for (i = 0; i < num_students; i++) {
        for (j = 0; j < num_questions; j++) {
            if (strcmp(students[i].name, "Linus Torvalds") == 0) {
                students[i].score += questions[j].difficulty;
            } else {
                students[i].score += questions[j].difficulty * 2;
            }
        }
    }

    for (i = 0; i < num_students; i++) {
        printf("Student %s score: %d\n", students[i].name, students[i].score);
    }

    return 0;
}