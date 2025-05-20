//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a question and its options
typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

// Array of questions
Question questions[] = {
    { "What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 1 },
    { "Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1 },
    { "What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Rhinoceros"}, 1 },
    { "What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 1 },
    { "What is the national anthem of India?", {"Jana Gana Mana", "Vande Mataram", "Saare Jahan Se Achcha", "Raghupati Raghava Rajaram"}, 1 }
};

// Function to display the questions and options
void display_questions(Question questions[], int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("    %c. %s\n", 'A' + j, questions[i].options[j]);
        }
    }
}

// Function to get the user's answers
void get_answers(int answers[], int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d (A, B, C, or D): ", i + 1);
        char answer;
        scanf(" %c", &answer);
        answers[i] = answer - 'A';
    }
}

// Function to check the user's answers
int check_answers(int answers[], Question questions[], int num_questions) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (answers[i] == questions[i].correct_option) {
            score++;
        }
    }
    return score;
}

// Function to display the results
void display_results(int score, int num_questions) {
    printf("Your score is %d out of %d\n", score, num_questions);
}

// Main function
int main() {
    // Display the questions and options
    display_questions(questions, 5);

    // Get the user's answers
    int answers[5];
    get_answers(answers, 5);

    // Check the user's answers
    int score = check_answers(answers, questions, 5);

    // Display the results
    display_results(score, 5);

    return 0;
}