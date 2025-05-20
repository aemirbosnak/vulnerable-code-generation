//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ANSWER_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char correctAnswer[MAX_ANSWER_LENGTH];
} Question;

int main() {
    int numStudents, numQuestions;
    char input[MAX_ANSWER_LENGTH];
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];

    // Get number of students
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // Get student names
    for (int i = 0; i < numStudents; i++) {
        printf("Enter student name %d: ", i+1);
        scanf("%s", students[i].name);
    }

    // Get number of questions
    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    // Get questions
    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        int numOptions = 0;
        while (true) {
            printf("Enter option %d: ", numOptions+1);
            scanf("%s", questions[i].options[numOptions]);

            if (numOptions == MAX_OPTIONS-1) {
                break;
            } else {
                numOptions++;
            }
        }

        printf("Enter correct answer: ");
        scanf("%s", questions[i].correctAnswer);
    }

    // Start exam
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent: %s\n", students[i].name);

        for (int j = 0; j < numQuestions; j++) {
            int correctAnswers = 0;

            printf("Question %d: %s\n", j+1, questions[j].question);

            for (int k = 0; k < MAX_OPTIONS; k++) {
                printf("%d. %s\n", k+1, questions[j].options[k]);
            }

            printf("Answer: ");
            scanf("%s", input);

            if (strcmp(input, questions[j].correctAnswer) == 0) {
                correctAnswers++;
            }

            students[i].score++;
        }

        printf("\nTotal score: %d\n\n", students[i].score);
    }

    return 0;
}