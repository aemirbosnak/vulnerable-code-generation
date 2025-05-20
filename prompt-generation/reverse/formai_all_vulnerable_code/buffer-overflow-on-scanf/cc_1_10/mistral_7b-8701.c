//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_NAME_LENGTH 50
#define MAX_ANSWERS 5
#define MAX_SCORE 100

typedef struct Question {
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer;
} Question;

void generateQuestions(Question* questions) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        sprintf(questions[i].question, "Question %d:", i + 1);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            sprintf(questions[i].options[j], "Option %d:%s", j + 1, (i % 2) ? "A random option" : "A valid option");
            if (j == MAX_OPTIONS - 1) {
                questions[i].answer = i % 2 ? rand() % MAX_OPTIONS : i + 1;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Question questions[MAX_QUESTIONS];
    char name[MAX_NAME_LENGTH];
    int score = 0;

    generateQuestions(questions);

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\n%s\n", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer == questions[i].answer) {
            score += 20;
            printf("Correct answer! Your current score is: %d\n", score);
        } else {
            printf("Incorrect answer. The correct answer is: %s\n", questions[i].options[questions[i].answer - 1]);
            printf("Your current score is: %d\n", score);
        }
    }

    printf("\nCongratulations, %s! Your final score is: %d!\n", name, score);

    return 0;
}