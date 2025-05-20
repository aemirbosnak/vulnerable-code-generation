//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question details
typedef struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

// Function to display the question and options
void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

// Function to get the user's answer
int getAnswer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

// Function to check if the user's answer is correct
int checkAnswer(Question q, int answer) {
    return q.correct_option == answer;
}

// Function to display the result
void displayResult(int score, int total) {
    printf("Your score is %d out of %d\n", score, total);
}

// Main function
int main() {
    // Array of questions
    Question questions[] = {
        {
            "What is the capital of India?",
            {"New Delhi", "Mumbai", "Kolkata", "Chennai"},
            1
        },
        {
            "Who is the current Prime Minister of India?",
            {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"},
            1
        },
        {
            "What is the national animal of India?",
            {"Tiger", "Lion", "Elephant", "Peacock"},
            1
        },
        {
            "What is the national bird of India?",
            {"Peacock", "Parrot", "Myna", "Sparrow"},
            1
        },
        {
            "What is the currency of India?",
            {"Rupee", "Dollar", "Euro", "Pound"},
            1
        }
    };

    // Total number of questions
    int total_questions = sizeof(questions) / sizeof(questions[0]);

    // Score counter
    int score = 0;

    // Iterate over the questions
    for (int i = 0; i < total_questions; i++) {
        // Display the question and options
        displayQuestion(questions[i]);

        // Get the user's answer
        int answer = getAnswer();

        // Check if the answer is correct
        if (checkAnswer(questions[i], answer)) {
            // Increment the score
            score++;
        }
    }

    // Display the result
    displayResult(score, total_questions);

    return 0;
}