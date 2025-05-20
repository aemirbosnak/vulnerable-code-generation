//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions in the system
#define MAX_QUESTIONS 100

// Define the maximum length of a question and answer
#define MAX_LENGTH 256

// Define the structure for a question in the system
typedef struct {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
} Question;

// Define the key for a correct answer
const char* CORRECT_ANSWER = "correct";

// Define the function to display the menu
void displayMenu() {
    printf("Welcome to the Online Examination System!\n\n");
    printf("1. Take the Exam\n");
    printf("2. Add a Question\n");
    printf("3. Exit\n\n");
}

// Define the function to take the exam
void takeExam(Question questions[], int numQuestions) {
    int correctAnswers = 0;
    char answer[MAX_LENGTH];

    for (int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i].question);
        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            correctAnswers++;
        }
    }

    printf("You scored %d out of %d.\n\n", correctAnswers, numQuestions);
}

// Define the function to add a question
void addQuestion(Question questions[], int* numQuestions) {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];

    // Check if the maximum number of questions has been reached
    if (*numQuestions >= MAX_QUESTIONS) {
        printf("The maximum number of questions has been reached.\n\n");
        return;
    }

    printf("Enter the question:\n");
    scanf("%s", question);
    printf("Enter the answer:\n");
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, CORRECT_ANSWER) != 0) {
        printf("The answer is not correct.\n\n");
        return;
    }

    strcpy(questions[*numQuestions].question, question);
    strcpy(questions[*numQuestions].answer, answer);

    (*numQuestions)++;

    printf("The question has been added.\n\n");
}

int main() {
    Question questions[MAX_QUESTIONS];
    int numQuestions = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeExam(questions, numQuestions);
                break;
            case 2:
                addQuestion(questions, &numQuestions);
                break;
            case 3:
                printf("Exiting the Online Examination System.\n\n");
                exit(0);
            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }

    return 0;
}