//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100
#define PASS_PERCENTAGE 60

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

Question questions[MAX_QUESTIONS];

int main() {
    int numQuestions;
    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    printf("Enter questions and answers:\n");
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d:\n", i + 1);
        scanf(" %[^\n]", questions[i].question);

        printf("Enter options (separated by spaces): ");
        scanf(" %[^\n]", questions[i].options[0]);
        for (int j = 1; j < MAX_OPTIONS; j++) {
            scanf(" %s", questions[i].options[j]);
        }

        scanf(" %[^\n]", questions[i].answer);
    }

    int score = 0;
    printf("Online Examination System\n");
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        char answer[MAX_ANSWER_LENGTH];
        printf("Enter your answer: ");
        scanf(" %s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Your score is: %d\n", score);

    if (score >= (numQuestions * PASS_PERCENTAGE) / 100) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you did not pass the exam.\n");
    }

    return 0;
}