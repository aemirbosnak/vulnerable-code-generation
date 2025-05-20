//FormAI DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct {
    char question[1000];
    char options[4][100];
    int answer;
} Question;

int main() {
    Question questions[MAX_QUESTIONS];
    char username[50];
    int num_questions, score = 0;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    printf("\nEnter the number of questions you want to answer (max %d): ", MAX_QUESTIONS);
    scanf("%d", &num_questions);

    if (num_questions > MAX_QUESTIONS) {
        printf("\nError: Maximum questions exceeded. Defaulting to %d questions.\n", MAX_QUESTIONS);
        num_questions = MAX_QUESTIONS;
    }

    fflush(stdin);

    // Enter questions and answers
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: ", i+1);
        fgets(questions[i].question, 1000, stdin);

        for (int j = 0; j < 4; j++) {
            printf("Option %c: ", 'A'+j);
            fgets(questions[i].options[j], 100, stdin);
        }

        printf("Answer (A/B/C/D): ");
        scanf("%d", &questions[i].answer);
        fflush(stdin);
    }

    // Take the test
    printf("\n\nWelcome %s, your Online Examination starts now!\n", username);
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d: %s", i+1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%c. %s", 'A'+j, questions[i].options[j]);
        }
        printf("Your Answer: ");
        int ans;
        scanf("%d", &ans);
        fflush(stdin);
        if (ans == questions[i].answer) {
            printf("Correct! ");
            score++;
        } else {
            printf("Incorrect! ");
        }
    }

    printf("\n\nYour score is %d/%d.\n", score, num_questions);
    if (score == num_questions) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you did not pass the exam.\n");
    }

    return 0;
}