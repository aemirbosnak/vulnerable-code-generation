//FormAI DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define maximum number of questions */
#define MAX_QUESTIONS 50

/* define maximum length of each question and answer */
#define MAX_LENGTH 100

/* define structure for each question */
struct Question {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
} Quiz[MAX_QUESTIONS];

/* function to add a new question to the quiz */
void addQuestion(int *numQuestions) {
    printf("Enter the question: ");
    fgets(Quiz[*numQuestions].question, MAX_LENGTH, stdin);
    printf("Enter the answer: ");
    fgets(Quiz[*numQuestions].answer, MAX_LENGTH, stdin);
    (*numQuestions)++;
}

/* function to take the quiz */
void takeQuiz(int numQuestions) {
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d: %s", i+1, Quiz[i].question);
        char userAnswer[MAX_LENGTH];
        fgets(userAnswer, MAX_LENGTH, stdin);
        if (strcmp(userAnswer, Quiz[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer was %s", Quiz[i].answer);
        }
    }
    printf("\nFinal score: %d/%d\n", score, numQuestions);
}

int main() {
    int numQuestions = 0;
    printf("Welcome to the C Online Examination System!\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a question\n");
        printf("2. Take the quiz\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline character
        switch (choice) {
            case 1:
                if (numQuestions == MAX_QUESTIONS) {
                    printf("The quiz is full!\n");
                } else {
                    addQuestion(&numQuestions);
                }
                break;
            case 2:
                if (numQuestions == 0) {
                    printf("There are no questions in the quiz!\n");
                } else {
                    takeQuiz(numQuestions);
                }
                break;
            case 3:
                printf("Thank you for using the C Online Examination System!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}