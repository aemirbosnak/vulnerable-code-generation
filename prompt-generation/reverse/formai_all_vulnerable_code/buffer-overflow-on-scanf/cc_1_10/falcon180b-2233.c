//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 100
#define MAX_ANSWERS 100

typedef struct {
    char question[100];
    char choice1[50];
    char choice2[50];
    char choice3[50];
    char choice4[50];
    char correct_answer;
} Question;

typedef struct {
    char name[50];
    int score;
} Student;

Question questions[MAX_QUESTIONS];
int num_questions;

Student students[MAX_STUDENTS];
int num_students;

int main() {
    srand(time(NULL));

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter choice 1: ");
        scanf("%s", questions[i].choice1);

        printf("Enter choice 2: ");
        scanf("%s", questions[i].choice2);

        printf("Enter choice 3: ");
        scanf("%s", questions[i].choice3);

        printf("Enter choice 4: ");
        scanf("%s", questions[i].choice4);

        questions[i].correct_answer = rand() % 5;
    }

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    for (int i = 0; i < num_students; i++) {
        printf("Enter student %d's name: ", i+1);
        scanf("%s", students[i].name);
    }

    int student_index = 0;
    while (student_index < num_students) {
        printf("Student %s, press enter to begin exam\n", students[student_index].name);
        getchar();

        int score = 0;
        for (int i = 0; i < num_questions; i++) {
            int choice;
            printf("Question %d: %s\n", i+1, questions[i].question);
            for (int j = 1; j <= 4; j++) {
                printf("%c. %s\n", j+'A', questions[i].choice1);
            }
            scanf("%d", &choice);

            if (choice == questions[i].correct_answer) {
                score++;
            }
        }

        students[student_index].score = score;
        printf("Student %s's score: %d\n", students[student_index].name, score);
        student_index++;
    }

    return 0;
}