//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_CHOICES 5
#define MAX_STUDENTS 50

typedef struct {
    char name[20];
    int id;
    int score;
} student;

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][20];
    int correct_choice;
} question;

void read_questions(question questions[]);
void read_students(student students[]);
void start_exam(student students[], question questions[]);
void evaluate_answers(student students[], question questions[]);

int main() {
    student students[MAX_STUDENTS];
    question questions[MAX_QUESTIONS];

    read_students(students);
    read_questions(questions);

    start_exam(students, questions);

    evaluate_answers(students, questions);

    return 0;
}

void read_questions(question questions[]) {
    int i, j;

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter number of choices (max %d): ", MAX_CHOICES);
        scanf("%d", &questions[i].correct_choice);

        for (j = 0; j < questions[i].correct_choice; j++) {
            printf("Enter choice %d: ", j+1);
            scanf("%s", questions[i].choices[j]);
        }
    }
}

void read_students(student students[]) {
    int i;

    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Enter student %d name: ", i+1);
        scanf("%s", students[i].name);

        printf("Enter student %d ID: ", i+1);
        scanf("%d", &students[i].id);
    }
}

void start_exam(student students[], question questions[]) {
    int i, j, k;

    for (i = 0; i < MAX_STUDENTS; i++) {
        students[i].score = 0;
    }

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d:\n%s", i+1, questions[i].question);

        for (j = 0; j < questions[i].correct_choice; j++) {
            printf("%d. %s\n", j+1, questions[i].choices[j]);
        }

        printf("Enter your answer: ");
        scanf("%d", &k);

        if (k == questions[i].correct_choice) {
            printf("Correct!\n");
            students[0].score++;
        } else {
            printf("Incorrect.\n");
        }
    }
}

void evaluate_answers(student students[], question questions[]) {
    int i;

    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("\nStudent %s (%d) scored %d out of %d.\n", students[i].name, students[i].id, students[i].score, MAX_QUESTIONS);
    }
}