//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(0));

    // Declare variables
    int num_questions;
    int num_choices;
    int num_correct_answers;
    int correct_answers;

    // Get the number of questions and choices
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    printf("Enter the number of choices for each question: ");
    scanf("%d", &num_choices);

    // Allocate memory for questions and choices
    int** questions = malloc(num_questions * sizeof(int*));
    int** choices = malloc(num_questions * sizeof(int*));
    int** correct_choices = malloc(num_questions * sizeof(int*));

    // Generate questions and choices
    for (int i = 0; i < num_questions; i++) {
        questions[i] = malloc(num_choices * sizeof(int));
        choices[i] = malloc(num_choices * sizeof(int));
        correct_choices[i] = malloc(num_choices * sizeof(int));

        for (int j = 0; j < num_choices; j++) {
            questions[i][j] = rand() % 100;
            choices[i][j] = rand() % 100;
            correct_choices[i][j] = rand() % 100;
        }
    }

    // Start the exam
    printf("Welcome to the C Online Examination System!\n");
    printf("You have %d minutes to complete the exam.\n", num_questions * 60);
    printf("Please select your answers by entering the corresponding choice number.\n\n");

    // Loop through all questions and choices
    for (int i = 0; i < num_questions; i++) {
        printf("%d. ", i + 1);
        for (int j = 0; j < num_choices; j++) {
            printf("%d. ", j + 1);
            printf("%d ", questions[i][j]);
        }
        printf("\n");

        // Get the user's answer
        printf("Enter the choice number for question %d: ", i + 1);
        scanf("%d", &correct_answers);

        // Check the correctness of the answer
        if (correct_answers == correct_choices[i][0]) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect!\n");
        }
    }

    // Calculate the score
    int score = correct_answers * 100 / num_questions;
    printf("Your score is: %.2f%%\n", score);

    // Free memory
    for (int i = 0; i < num_questions; i++) {
        free(questions[i]);
        free(choices[i]);
        free(correct_choices[i]);
    }
    free(questions);
    free(choices);
    free(correct_choices);

    return 0;
}