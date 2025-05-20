//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 10

// Define the maximum length of question and answer
#define MAX_LENGTH 100

// Define a struct for the questions
typedef struct {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
} Question;

// Define a function to get user input
void get_input(char *input, int length) {
    fflush(stdin);
    printf("> ");
    fgets(input, length, stdin);
    fflush(stdin);
}

int main() {
    // Initialize variables
    Question questions[MAX_QUESTIONS];
    int current_question = 0;
    int correct_answers = 0;
    int total_questions;
    char input[MAX_LENGTH];

    // Get the number of questions
    printf("Enter the number of questions: ");
    scanf("%d", &total_questions);

    // Get the questions and answers
    while (current_question < total_questions) {
        printf("Enter question %d: ", current_question + 1);
        get_input(questions[current_question].question, MAX_LENGTH);
        printf("Enter the answer to question %d: ", current_question + 1);
        get_input(questions[current_question].answer, MAX_LENGTH);
        current_question++;
    }

    // Display the questions and get the user's answers
    current_question = 0;
    while (current_question < total_questions) {
        printf("\nQuestion %d: %s", current_question + 1, questions[current_question].question);
        get_input(input, MAX_LENGTH);
        if (strcmp(input, questions[current_question].answer) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[current_question].answer);
        }
        current_question++;
    }

    // Display the results
    printf("\nYou got %d out of %d questions correct.\n", correct_answers, total_questions);

    return 0;
}