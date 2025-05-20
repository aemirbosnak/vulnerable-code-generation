//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    int answer;
} Question;

int main() {
    int num_students, num_questions;
    scanf("%d %d", &num_students, &num_questions);

    Student students[MAX_STUDENTS];
    for (int i = 0; i < num_students; i++) {
        scanf("%s %d", students[i].name, &students[i].id);
    }

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        scanf("%s", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            scanf("%s", questions[i].options[j]);
        }
        scanf("%d", &questions[i].answer);
    }

    for (int i = 0; i < num_students; i++) {
        int correct_answers = 0;
        for (int j = 0; j < num_questions; j++) {
            char answer[MAX_ANSWER_LENGTH];
            scanf("%s", answer);
            if (strcmp(answer, questions[j].options[questions[j].answer]) == 0) {
                correct_answers++;
            }
        }
        students[i].score = correct_answers;
    }

    for (int i = 0; i < num_students; i++) {
        printf("%s (%d): %d\n", students[i].name, students[i].id, students[i].score);
    }

    return 0;
}