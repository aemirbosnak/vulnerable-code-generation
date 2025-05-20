//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char choices[MAX_CHOICES][MAX_ANSWER_LENGTH];
    int answer;
} Question;

int main() {
    int num_questions, num_students;
    scanf("%d %d", &num_questions, &num_students);

    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < num_questions; i++) {
        scanf("%s", questions[i].question);
        int num_choices;
        scanf("%d", &num_choices);
        for (int j = 0; j < num_choices; j++) {
            scanf("%s", questions[i].choices[j]);
        }
        scanf("%d", &questions[i].answer);
    }

    Student students[MAX_STUDENTS];
    for (int i = 0; i < num_students; i++) {
        scanf("%s", students[i].name);
    }

    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_students; j++) {
            int choice_index = -1;
            scanf("%d", &choice_index);
            if (choice_index == questions[i].answer) {
                students[j].score++;
            }
        }
    }

    for (int i = 0; i < num_students; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}