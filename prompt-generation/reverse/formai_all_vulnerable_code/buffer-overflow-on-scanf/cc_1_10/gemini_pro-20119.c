//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
struct Question {
    char question[256];
    char options[4][64];
    char answer;
};

// Function to display the question and options
void displayQuestion(struct Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
char getAnswer() {
    char answer;
    scanf(" %c", &answer);
    return answer;
}

// Function to check if the user's answer is correct
int checkAnswer(char answer, char correctAnswer) {
    return answer == correctAnswer;
}

// Function to display the result
void displayResult(int score, int totalQuestions) {
    printf("Your score is %d out of %d\n", score, totalQuestions);
}

// Main function
int main() {
    // Initialize the questions
    struct Question questions[] = {
        {"What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 'A'},
        {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 'A'},
        {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Rhinoceros"}, 'A'},
        {"What is the national bird of India?", {"Peacock", "Sparrow", "Eagle", "Kite"}, 'A'},
        {"What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 'A'}
    };

    // Get the total number of questions
    int totalQuestions = sizeof(questions) / sizeof(struct Question);

    // Initialize the score
    int score = 0;

    // Loop through the questions and display them
    for (int i = 0; i < totalQuestions; i++) {
        displayQuestion(questions[i]);
        char answer = getAnswer();
        if (checkAnswer(answer, questions[i].answer)) {
            score++;
        }
    }

    // Display the result
    displayResult(score, totalQuestions);

    return 0;
}