//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4
#define MAX_OPTIONS 4
#define PASS_MARK 50
#define USER_NAME_LENGTH 50
#define QUESTION_LENGTH 200
#define ANSWER_LENGTH 50

typedef struct {
    char question[QUESTION_LENGTH];
    char answers[MAX_ANSWERS][ANSWER_LENGTH];
    int correctIndex;
} Question;

typedef struct {
    char name[USER_NAME_LENGTH];
    int score;
} User;

void generateRandomQuestions(Question questions[], int numQuestions) {
    srand(time(NULL));
    for (int i = 0; i < numQuestions; i++) {
        strcpy(questions[i].question, "Question ");
        int numAnswers = rand() % MAX_ANSWERS + 1;
        for (int j = 0; j < numAnswers; j++) {
            strcpy(questions[i].answers[j], "Answer ");
        }
        questions[i].correctIndex = rand() % numAnswers;
    }
}

int main() {
    int numQuestions;
    printf("Enter the number of questions: ");
    scanf("%d", &numQuestions);

    Question questions[numQuestions];
    generateRandomQuestions(questions, numQuestions);

    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);

    int correctAnswers = 0;

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j+1, questions[i].answers[j]);
        }

        int choice;
        scanf("%d", &choice);

        if (choice == questions[i].correctIndex) {
            correctAnswers++;
        }
    }

    printf("\nYour score: %d out of %d\n", correctAnswers, numQuestions);

    if (correctAnswers >= PASS_MARK) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    return 0;
}