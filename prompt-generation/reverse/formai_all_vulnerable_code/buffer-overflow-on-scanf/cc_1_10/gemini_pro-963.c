//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a question
typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

// Array of questions
Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
    {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 1},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Leopard"}, 1},
    {"What is the national bird of India?", {"Peacock", "Parrot", "Eagle", "Owl"}, 1},
};

// Function to display a question and its options
void display_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
int get_answer() {
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);
    return answer;
}

// Function to check if the user's answer is correct
bool is_correct(Question question, int answer) {
    return answer == question.correct_option;
}

// Function to display the result of the examination
void display_result(int score) {
    printf("Your score is %d out of %d\n", score, sizeof(questions) / sizeof(Question));
    if (score >= 3) {
        printf("Congratulations! You passed the examination.\n");
    } else {
        printf("Sorry, you failed the examination.\n");
    }
}

// Main function
int main() {
    // Welcome the user
    printf("Welcome to the C Online Examination System!\n");

    // Initialize the score
    int score = 0;

    // Loop through the questions
    for (int i = 0; i < sizeof(questions) / sizeof(Question); i++) {
        // Display the question
        display_question(questions[i]);

        // Get the user's answer
        int answer = get_answer();

        // Check if the user's answer is correct
        if (is_correct(questions[i], answer)) {
            // Increment the score
            score++;
        }
    }

    // Display the result
    display_result(score);

    return 0;
}