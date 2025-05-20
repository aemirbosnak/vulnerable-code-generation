//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_MARK 50

struct question {
    char question[100];
    char options[MAX_OPTIONS][100];
    char answer[MAX_ANSWERS];
};

int main() {
    int num_questions, i, j, correct_answers = 0, score = 0;
    char input[MAX_ANSWERS];
    struct question questions[MAX_QUESTIONS];

    // Read the number of questions from the user
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Read the questions and options from the user
    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d: ", i+1);
        scanf("%s", questions[i].question);

        printf("Enter the options (separated by space): ");
        for (j = 0; j < MAX_OPTIONS; j++) {
            scanf("%s", questions[i].options[j]);
        }

        printf("Enter the correct answer: ");
        scanf("%s", questions[i].answer);
    }

    // Start the exam
    for (i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s\n", i+1, questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[i].options[j]);
        }

        printf("Enter your answer (A/B/C/D): ");
        scanf("%s", input);

        if (strcmp(input, questions[i].answer) == 0) {
            correct_answers++;
        }
    }

    // Calculate the score
    score = (correct_answers * 100) / num_questions;

    // Print the results
    printf("\nResults:\n");
    printf("Number of correct answers: %d\n", correct_answers);
    printf("Score: %d%%\n", score);

    return 0;
}