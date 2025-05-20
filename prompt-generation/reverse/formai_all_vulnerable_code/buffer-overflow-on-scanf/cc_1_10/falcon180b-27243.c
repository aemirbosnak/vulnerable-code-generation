//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_STUDENTS 50
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} student_t;

typedef struct {
    char question[MAX_NAME_LENGTH];
    char options[MAX_OPTIONS][MAX_NAME_LENGTH];
    int answer;
} question_t;

int main() {
    int num_questions, num_students;
    char input[MAX_NAME_LENGTH];
    question_t questions[MAX_QUESTIONS];
    student_t students[MAX_STUDENTS];

    printf("Welcome to the Online Examination System!\n\n");

    // Read in the number of questions
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Read in the questions
    for (int i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i].question);
        printf("Enter the number of options: ");
        scanf("%d", &questions[i].answer);
        for (int j = 0; j < questions[i].answer; j++) {
            printf("Enter option %d: ", j + 1);
            scanf("%s", questions[i].options[j]);
        }
    }

    // Read in the number of students
    printf("\nEnter the number of students: ");
    scanf("%d", &num_students);

    // Read in the students
    for (int i = 0; i < num_students; i++) {
        printf("\nEnter student %d's name: ", i + 1);
        scanf("%s", students[i].name);
    }

    // Start the exam
    printf("\n\nThe exam has started!\n\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < questions[i].answer; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Enter your answer (1-%d): ", questions[i].answer);
        scanf("%d", &students[0].score);
    }

    // Display the results
    printf("\n\nThe exam has ended!\n\n");
    printf("Results:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %s: %d\n", students[i].name, students[i].score);
    }

    return 0;
}