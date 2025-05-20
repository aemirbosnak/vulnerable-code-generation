//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: lively
/*
 * Unique C Online Examination System
 *
 * This program allows users to take an online exam and keep track of their score.
 * It also provides real-time feedback on the user's performance.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent an exam question
struct Question {
    char* question;
    char* answer;
    int points;
};

// Function to display the exam questions and accept user input
void displayQuestions(struct Question questions[], int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        printf("Answer: ");
        char answer[100];
        scanf("%s", answer);
        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[i].answer);
        }
    }
}

// Function to display the final score
void displayScore(int score) {
    printf("Your score is: %d\n", score);
}

int main() {
    // Initialize the questions
    struct Question questions[] = {
        {"What is the capital of France?", "Paris", 10},
        {"What is the capital of Italy?", "Rome", 10},
        {"What is the capital of Spain?", "Madrid", 10},
        {"What is the capital of Germany?", "Berlin", 10},
        {"What is the capital of the United Kingdom?", "London", 10},
        {"What is the capital of the United States?", "Washington D.C.", 10},
    };

    // Set the number of questions
    int numQuestions = sizeof(questions) / sizeof(struct Question);

    // Display the questions and accept user input
    displayQuestions(questions, numQuestions);

    // Calculate the final score
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        if (strcmp(questions[i].answer, questions[i].answer) == 0) {
            score += questions[i].points;
        }
    }

    // Display the final score
    displayScore(score);

    return 0;
}