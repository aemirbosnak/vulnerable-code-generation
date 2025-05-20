//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct Question {
    char question[100];
    char answer[100];
} Question;

// Array of questions
Question questions[] = {
    {"Who is the first President of India?", "Rajendra Prasad"},
    {"What is the capital of France?", "Paris"},
    {"What is the largest ocean in the world?", "Pacific Ocean"},
    {"What is the chemical symbol for gold?", "Au"},
    {"Who wrote the novel 'To Kill a Mockingbird'?", "Harper Lee"}
};

// Function to display the questions
void displayQuestions(Question questions[], int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
    }
}

// Function to get the answers from the user
void getAnswers(char answers[], int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("Enter the answer for question %d: ", i + 1);
        scanf("%s", answers + (i * 100));
    }
}

// Function to check the answers
int checkAnswers(char answers[], Question questions[], int numQuestions) {
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        if (strcmp(answers + (i * 100), questions[i].answer) == 0) {
            score++;
        }
    }
    return score;
}

// Function to display the results
void displayResults(int score, int numQuestions) {
    printf("Your score is %d out of %d\n", score, numQuestions);
}

int main() {
    // Number of questions
    int numQuestions = sizeof(questions) / sizeof(Question);

    // Display the questions
    displayQuestions(questions, numQuestions);

    // Get the answers from the user
    char answers[numQuestions * 100];
    getAnswers(answers, numQuestions);

    // Check the answers
    int score = checkAnswers(answers, questions, numQuestions);

    // Display the results
    displayResults(score, numQuestions);

    return 0;
}