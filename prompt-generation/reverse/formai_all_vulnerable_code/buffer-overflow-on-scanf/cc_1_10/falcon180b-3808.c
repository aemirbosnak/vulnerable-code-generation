//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_STUDENTS 50
#define MAX_SCORE 100

typedef struct {
    char name[50];
    int id;
    int score;
} Student;

typedef struct {
    char question[100];
    char options[MAX_ANSWERS][100];
    char answer;
} Question;

void generateQuestions() {
    int i, j;
    Question questions[MAX_QUESTIONS];

    for (i = 0; i < MAX_QUESTIONS; i++) {
        questions[i].answer = 'A' + rand() % 4;

        for (j = 0; j < MAX_ANSWERS; j++) {
            sprintf(questions[i].options[j], "Option %d", j + 1);
        }

        sprintf(questions[i].question, "Question %d", i + 1);
    }
}

int main() {
    int i, j;
    Student students[MAX_STUDENTS];
    Question questions[MAX_QUESTIONS];
    int scores[MAX_STUDENTS];
    int numStudents;
    int numQuestions;
    int numCorrectAnswers;
    int currentQuestion;
    int selectedAnswer;
    int correctAnswer;

    srand(time(NULL));

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (i = 0; i < numStudents; i++) {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter the ID of student %d: ", i + 1);
        scanf("%d", &students[i].id);
    }

    generateQuestions();

    for (i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);

        for (j = 0; j < MAX_ANSWERS; j++) {
            printf("%c. %s\n", 'A' + j, questions[i].options[j]);
        }

        printf("Select your solution. ");
        scanf("%c", &selectedAnswer);

        correctAnswer = questions[i].answer - 'A';

        if (selectedAnswer == correctAnswer) {
            numCorrectAnswers++;
        }
    }

    printf("\n\nResults:\n");

    for (i = 0; i < numStudents; i++) {
        printf("Student %s (ID %d) scored %d out of %d\n", students[i].name, students[i].id, scores[i], MAX_SCORE);
    }

    return 0;
}