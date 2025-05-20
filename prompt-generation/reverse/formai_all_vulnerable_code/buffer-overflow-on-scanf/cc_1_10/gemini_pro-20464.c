//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct {
    char question[100];
    char answer[100];
} Question;

// Constants
#define NUM_QUESTIONS 5
#define MAX_NAME_LENGTH 50

// Function prototypes
void welcome_user(char *name);
void display_questions(Question *questions);
int get_user_answers(Question *questions);
int check_answers(Question *questions, int *answers);
void display_results(int score);

int main() {
    // Declare variables
    char name[MAX_NAME_LENGTH];
    Question questions[NUM_QUESTIONS];
    int answers[NUM_QUESTIONS];
    int score;

    // Welcome the user
    welcome_user(name);

    // Display the questions
    display_questions(questions);

    // Get the user's answers
    score = get_user_answers(questions);

    // Check the answers
    score = check_answers(questions, answers);

    // Display the results
    display_results(score);

    return 0;
}

// Welcome the user
void welcome_user(char *name) {
    printf("Welcome to the online examination system!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s!\n", name);
}

// Display the questions
void display_questions(Question *questions) {
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
    }
}

// Get the user's answers
int get_user_answers(Question *questions) {
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char answer[100];
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
        }
    }
    return score;
}

// Check the answers
int check_answers(Question *questions, int *answers) {
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (answers[i] == questions[i].answer) {
            score++;
        }
    }
    return score;
}

// Display the results
void display_results(int score) {
    printf("Your score is %d out of %d\n", score, NUM_QUESTIONS);
    if (score >= 3) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }
}