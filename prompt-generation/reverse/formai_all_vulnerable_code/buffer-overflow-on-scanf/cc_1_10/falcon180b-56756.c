//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWER_LEN 100

struct question {
    char question[MAX_ANSWER_LEN];
    char correct_answer[MAX_ANSWER_LEN];
};

int main() {
    int num_questions;
    struct question questions[MAX_QUESTIONS];
    int score = 0;
    int i, j;

    printf("Welcome to the Online Examination System!\n");

    // Read number of questions from user
    printf("Enter the number of questions (maximum %d): ", MAX_QUESTIONS);
    scanf("%d", &num_questions);

    // Read questions and correct answers from user
    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter correct answer for question %d: ", i+1);
        scanf("%s", questions[i].correct_answer);
    }

    // Shuffle questions
    for (i = 0; i < num_questions; i++) {
        j = rand() % num_questions;
        struct question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }

    // Ask questions and evaluate answers
    for (i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        char answer[MAX_ANSWER_LEN];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].correct_answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    // Display final score
    printf("\nYour score is: %d out of %d\n", score, num_questions);

    return 0;
}