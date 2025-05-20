//LLAMA2-13B DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define some constants and variables
#define MAX_NAME_LENGTH 20
#define MAX_GREETING_LENGTH 50
#define MAX_NUMBER_OF_QUESTIONS 5
#define POINTS_PER_CORRECT_ANSWER 10

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} user_info_t;

// Function to greet the user
void greet(user_info_t *user) {
    printf("Hello, %s! Let's get this quiz started! 🎉\n", user->name);
}

// Function to ask a question
void ask_question(user_info_t *user, int question_number) {
    int correct_answer;
    printf("Question %d: What is the capital of France? 🤔\n", question_number + 1);
    scanf("%d", &correct_answer);
    if (correct_answer == 75) {
        printf("Correct! The capital of France is indeed Paris! 😊\n");
    } else {
        printf("Incorrect... 😔 But don't worry, there's always next time! 😜\n");
    }
}

// Function to update the user's score
void update_score(user_info_t *user, int points_earned) {
    user->score += points_earned;
    printf("Your current score is: %d\n", user->score);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    // Create a user structure to store the user's information
    user_info_t user;
    gets(user.name); // Get the user's name

    // Greet the user
    greet(&user);

    // Ask the user a series of questions
    for (int i = 0; i < MAX_NUMBER_OF_QUESTIONS; i++) {
        ask_question(&user, i);
    }

    // Update the user's score
    update_score(&user, POINTS_PER_CORRECT_ANSWER);

    // Print the user's final score
    printf("Your final score is: %d\n", user.score);

    return 0;
}