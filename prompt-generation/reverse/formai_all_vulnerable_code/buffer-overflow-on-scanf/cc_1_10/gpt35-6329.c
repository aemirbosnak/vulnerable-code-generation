//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of questions 
#define MAX_QUESTIONS 10

// Define struct for each periodic table question
typedef struct {
    char question[100];
    char answer[3];
} PeriodicTableQuestion;

// Define array of PeriodicTableQuestion structures
PeriodicTableQuestion periodic_table_questions[] = {
    {"What is the symbol for gold?", "Au"},
    {"What is the symbol for oxygen?", "O"},
    {"What is the symbol for iron?", "Fe"},
    {"What is the symbol for nitrogen?", "N"},
    {"What is the symbol for carbon?", "C"},
    {"What is the symbol for mercury?", "Hg"},
    {"What is the symbol for sodium?", "Na"},
    {"What is the symbol for silver?", "Ag"},
    {"What is the symbol for chlorine?", "Cl"},
    {"What is the symbol for copper?", "Cu"}
};

// Main function
int main() {
    int correct_answers = 0;
    int question_number = 0;
    int chosen_questions[MAX_QUESTIONS];
    int number_of_questions = sizeof(periodic_table_questions) / sizeof(periodic_table_questions[0]);
    char user_answer[3];
    char play_again = 'y';

    // Set random seed for shuffling questions
    srand(time(NULL));

    printf("Welcome to the Periodic Table Quiz!\n");

    // Play again loop
    while (play_again == 'y' || play_again == 'Y') {
        correct_answers = 0;
        question_number = 0;
        memset(chosen_questions, 0, sizeof(chosen_questions)); // Reset array of chosen questions

        printf("\nLet's begin!\n");

        // Question loop
        while (question_number < MAX_QUESTIONS) {
            // Choose random question that hasn't been asked yet
            int random_index = rand() % number_of_questions;
            while (chosen_questions[random_index] == 1) {
                random_index = rand() % number_of_questions;
            }
            chosen_questions[random_index] = 1;

            // Ask question and get user answer
            printf("\nQuestion %d: %s\n", question_number + 1, periodic_table_questions[random_index].question);
            printf("Answer: ");
            scanf("%s", user_answer);

            // Check if answer is correct
            if (strcmp(user_answer, periodic_table_questions[random_index].answer) == 0) {
                printf("Correct!\n");
                correct_answers++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", periodic_table_questions[random_index].answer);
            }

            question_number++;
        }

        // Print final score and ask if user wants to play again
        printf("\nCongratulations, you finished the quiz!\n");
        printf("You got %d out of %d correct answers.\n", correct_answers, MAX_QUESTIONS);
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("Thank you for playing the Periodic Table Quiz!\n");

    return 0;
}