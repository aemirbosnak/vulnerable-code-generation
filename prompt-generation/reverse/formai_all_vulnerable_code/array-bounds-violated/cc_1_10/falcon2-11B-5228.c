//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5

int main() {
    srand(time(NULL));
    int questions[MAX_QUESTIONS];
    int options[MAX_OPTIONS][MAX_OPTIONS];
    int correctAnswer[MAX_QUESTIONS];
    int score = 0;

    // Fill in the questions and options
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i] = rand() % 10 + 1;
        for (int j = 0; j < MAX_OPTIONS; j++) {
            options[i][j] = rand() % 10 + 1;
        }
        correctAnswer[i] = rand() % (MAX_OPTIONS - 1) + 1;
    }

    // Start the exam
    printf("Welcome to the Online Examination System!\n");
    printf("Please answer %d questions.\n", MAX_QUESTIONS);
    printf("The questions are multiple-choice, with %d options for each question.\n", MAX_OPTIONS);
    printf("Good luck!\n\n");

    // Display the questions and options
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %d. ", i + 1, questions[i]);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. ", options[i][j]);
        }
        printf("(Correct answer: %d)\n", correctAnswer[i]);
    }

    // Get the user's answers
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int answer;
        printf("Question %d: ", i + 1);
        printf("What is the correct answer? (1-%d): ", options[i][correctAnswer[i]]);
        scanf("%d", &answer);

        if (answer == correctAnswer[i]) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %d.\n", correctAnswer[i]);
        }
    }

    // Print the final score
    printf("You got %d out of %d questions correct.\n", score, MAX_QUESTIONS);

    return 0;
}