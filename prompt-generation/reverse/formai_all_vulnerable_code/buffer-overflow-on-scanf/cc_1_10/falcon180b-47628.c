//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 10
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_answer;
} Question;

typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Student;

int main() {
    int num_questions, num_students;
    scanf("%d %d", &num_questions, &num_students);

    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    for (int i = 0; i < num_questions; i++) {
        scanf("%s", questions[i].question);
        int num_options;
        scanf("%d", &num_options);
        for (int j = 0; j < num_options; j++) {
            scanf("%s", questions[i].options[j]);
        }
        scanf("%d", &questions[i].correct_answer);
    }

    for (int i = 0; i < num_students; i++) {
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_students; j++) {
            int answer;
            scanf("%d", &answer);
            if (answer == questions[i].correct_answer) {
                students[j].score++;
            }
        }
    }

    for (int i = 0; i < num_students; i++) {
        printf("Student %s scored %d out of %d\n", students[i].name, students[i].score, num_questions);
    }

    return 0;
}