//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_STUDENTS 100
#define MAX_SCORE 100

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    int numOptions;
    char options[MAX_OPTIONS][100];
    int correctAnswer;
} Question;

void generateRandomQuestion(Question *q) {
    int numOptions = rand() % MAX_OPTIONS + 2;
    q->numOptions = numOptions;
    for (int i = 0; i < numOptions; i++) {
        sprintf(q->options[i], "Option %d", i + 1);
    }
    q->correctAnswer = rand() % numOptions;
}

int main() {
    srand(time(NULL));
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int numQuestions = 0;
    int numCorrectAnswers = 0;

    printf("Online Examination System\n");
    printf("------------------------\n");

    while (numQuestions < MAX_QUESTIONS) {
        Question q;
        generateRandomQuestion(&q);
        printf("Question %d: %s\n", numQuestions + 1, q.question);
        for (int i = 0; i < q.numOptions; i++) {
            printf("%d. %s\n", i + 1, q.options[i]);
        }
        int correctAnswerIndex = rand() % q.numOptions;
        q.correctAnswer = correctAnswerIndex;
        questions[numQuestions] = q;
        numQuestions++;
    }

    while (numStudents < MAX_STUDENTS) {
        printf("Enter name of student %d: ", numStudents + 1);
        scanf("%s", students[numStudents].name);
        numStudents++;
    }

    for (int i = 0; i < numQuestions; i++) {
        int numCorrect = 0;
        for (int j = 0; j < numStudents; j++) {
            int answer = rand() % questions[i].numOptions + 1;
            if (answer == questions[i].correctAnswer) {
                numCorrect++;
            }
            students[j].score += numCorrect;
        }
        numCorrectAnswers += numCorrect;
    }

    printf("Results:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d out of %d\n", students[i].name, students[i].score, numQuestions);
    }

    printf("Number of correct answers: %d out of %d\n", numCorrectAnswers, numQuestions * numStudents);

    return 0;
}