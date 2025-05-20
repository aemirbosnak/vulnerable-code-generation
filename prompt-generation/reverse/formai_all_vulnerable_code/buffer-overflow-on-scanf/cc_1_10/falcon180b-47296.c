//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char choices[MAX_CHOICES][MAX_NAME_LENGTH];
    int answer;
} Question;

void generate_questions(Question questions[], int num_questions) {
    srand(time(NULL));
    for (int i = 0; i < num_questions; i++) {
        questions[i].answer = rand() % MAX_CHOICES;
        for (int j = 0; j < MAX_CHOICES; j++) {
            sprintf(questions[i].choices[j], "Choice %d", j + 1);
        }
        sprintf(questions[i].question, "Question %d", i + 1);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    int num_students, num_questions;

    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    generate_questions(questions, num_questions);

    for (int i = 0; i < num_students; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        students[i].score = 0;
    }

    printf("\nOnline Examination System\n");

    for (int i = 0; i < num_questions; i++) {
        printf("\n%s\n", questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, questions[i].choices[j]);
        }

        int choice;
        scanf("%d", &choice);

        if (choice == questions[i].answer) {
            for (int j = 0; j < num_students; j++) {
                if (strcmp(students[j].name, "")!= 0) {
                    students[j].score++;
                }
            }
        }
    }

    printf("\nResults:\n");
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, "")!= 0) {
            printf("%s: %d/%d\n", students[i].name, students[i].score, num_questions);
        }
    }

    return 0;
}