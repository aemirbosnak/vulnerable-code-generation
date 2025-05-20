//FormAI DATASET v1.0 Category: Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 20
#define QUESTION_LENGTH 100
#define MAX_ATTEMPTS 3

typedef struct {
    char question[QUESTION_LENGTH];
    char answer[QUESTION_LENGTH];
} trivia_question;

int main() {
    // Variables to hold information about the game
    int num_questions;
    int num_attempts;
    int num_correct = 0;
    char player_answer[QUESTION_LENGTH];

    // Create an array of trivia questions
    trivia_question questions[MAX_QUESTIONS] = {
        {"In what year did Apple release the first iPhone?", "2007"},
        {"What is the name of the tallest mammal?", "Giraffe"},
        {"What was the first video game ever created?", "Tennis for Two"},
        {"What is the capital of Australia?", "Canberra"},
        {"What year did World War II end?", "1945"}
        // Add more questions here
    };

    // Count how many questions are in the array
    num_questions = sizeof(questions) / sizeof(questions[0]);

    // Prompt the player for the number of attempts they want per question
    printf("How many attempts would you like per question? ");
    scanf("%d", &num_attempts);

    // Loop through each question
    for (int i = 0; i < num_questions; i++) {
        // Display the question
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);

        // Loop until the player answers correctly or runs out of attempts
        for (int j = 1; j <= num_attempts; j++) {
            // Prompt the player for their answer
            printf("\nAttempt %d: ", j);
            scanf("%s", player_answer);

            // Convert the player's answer to lowercase
            char lowercase_answer[QUESTION_LENGTH];
            strcpy(lowercase_answer, player_answer);
            for (int k = 0; k < strlen(player_answer); k++) {
                lowercase_answer[k] = tolower(player_answer[k]);
            }

            // Convert the correct answer to lowercase
            char lowercase_target[QUESTION_LENGTH];
            strcpy(lowercase_target, questions[i].answer);
            for (int k = 0; k < strlen(questions[i].answer); k++) {
                lowercase_target[k] = tolower(questions[i].answer[k]);
            }

            // Check if the player's answer is correct
            if (strcmp(lowercase_answer, lowercase_target) == 0) {
                printf("Correct!\n");
                num_correct++;
                break; // Move on to the next question
            } else {
                printf("Incorrect. ");
                if (j == num_attempts) {
                    printf("The correct answer was \"%s\".\n", questions[i].answer);
                } else {
                    printf("You have %d attempts left.\n", num_attempts - j);
                }
            }
        }
    }

    // Display the player's score
    printf("\nYou got %d/%d questions correct.\n", num_correct, num_questions);

    // Wait for the player to press enter before exiting
    printf("\nPress enter to exit.");
    getchar();
    getchar();

    return 0;
}