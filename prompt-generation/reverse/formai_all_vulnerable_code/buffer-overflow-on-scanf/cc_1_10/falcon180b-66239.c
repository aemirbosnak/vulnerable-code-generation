//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES 4
#define MAX_ANSWERS 100
#define PASS_SCORE 60

typedef struct {
    char question[100];
    char choiceA[100];
    char choiceB[100];
    char choiceC[100];
    char choiceD[100];
    char answer[3];
} Question;

int main() {
    int numQuestions, i, j, score = 0;
    char input[100];
    Question questions[MAX_QUESTIONS];

    printf("Welcome to the Happy Online Examination System!\n");
    printf("Please enter the number of questions: ");
    scanf("%d", &numQuestions);

    for (i = 0; i < numQuestions; i++) {
        printf("Enter question %d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter choice A:\n");
        scanf("%s", questions[i].choiceA);

        printf("Enter choice B:\n");
        scanf("%s", questions[i].choiceB);

        printf("Enter choice C:\n");
        scanf("%s", questions[i].choiceC);

        printf("Enter choice D:\n");
        scanf("%s", questions[i].choiceD);

        printf("Enter the correct answer (A, B, C or D): ");
        scanf("%s", questions[i].answer);
    }

    printf("\nExamination begins:\n");

    for (i = 0; i < numQuestions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);

        for (j = 0; j < MAX_CHOICES; j++) {
            printf("%c. %s\n", j+1, questions[i].choiceA);
        }

        printf("Enter your answer: ");
        scanf("%s", input);

        if (strcmp(input, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("\nExamination ends.\n");

    if (score >= PASS_SCORE) {
        printf("Congratulations! You passed the examination with a score of %d out of %d.\n", score, numQuestions);
    } else {
        printf("Sorry, you failed the examination with a score of %d out of %d.\n", score, numQuestions);
    }

    return 0;
}