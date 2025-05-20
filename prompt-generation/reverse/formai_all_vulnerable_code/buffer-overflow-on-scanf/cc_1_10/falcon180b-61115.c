//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int num_problems;
    int num_correct;
    int num_incorrect;
    int num_skipped;
    double score;
    double correct_answers[1000];
    double user_answers[1000];
    double problem_difficulties[1000];

    printf("Welcome to the C Math Funhouse!\n\n");

    // Get number of problems from user
    printf("How many problems would you like to solve? ");
    scanf("%d", &num_problems);

    srand(time(NULL));

    // Generate random problems
    for (int i = 0; i < num_problems; i++) {
        correct_answers[i] = rand() % 1000;
        problem_difficulties[i] = rand() % 10;
    }

    num_correct = 0;
    num_incorrect = 0;
    num_skipped = 0;

    printf("\nLet's get started!\n\n");

    for (int i = 0; i < num_problems; i++) {
        printf("Problem #%d:\n", i + 1);
        printf("Difficulty: %d/10\n", problem_difficulties[i]);
        printf("Correct answer: %.0f\n", correct_answers[i]);

        double user_answer;
        int answer_input_status;

        // Get user answer
        do {
            printf("Your answer: ");
            answer_input_status = scanf("%lf", &user_answer);

            if (answer_input_status!= 1) {
                printf("Invalid input. Please enter a number.\n");
                fflush(stdin);
            }
        } while (answer_input_status!= 1);

        if (abs(user_answer - correct_answers[i]) < 0.1) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %.0f.\n", correct_answers[i]);
            num_incorrect++;
        }

        printf("\n");
    }

    printf("\n\nYou solved %d out of %d problems correctly.\n", num_correct, num_problems);

    if (num_skipped > 0) {
        printf("You skipped %d problems.\n", num_skipped);
    }

    score = (double)num_correct / num_problems * 100;
    printf("Your score is %.2f%%\n", score);

    return 0;
}