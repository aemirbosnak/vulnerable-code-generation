//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Here's a lively and creative example of a C Online Examination System program:

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define the data structures for question and answer
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][50];
    int correct_answer;
} Question;

// Define the data structure for student's answers
typedef struct {
    int answers[MAX_QUESTIONS];
} StudentAnswers;

// Declare the questions and answers
Question questions[] = {
    {"What is the capital of India?", {"New Delhi", "Mumbai", "Chennai", "Kolkata"}, 0},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 0},
    {"Which is the largest state in India by area?", {"Rajasthan", "Madhya Pradesh", "Uttar Pradesh", "Maharashtra"}, 0},
    {"Which is the highest mountain in the world?", {"Mount Everest", "K2", "Kangchenjunga", "Nanga Parbat"}, 0},
    {"Who is the author of the Indian national anthem?", {"Rabindranath Tagore", "Bankim Chandra Chatterjee", "Subhas Chandra Bose", "Jawaharlal Nehru"}, 0},
    {"Which is the national animal of India?", {"Tiger", "Lion", "Elephant", "Leopard"}, 0},
    {"Which is the national bird of India?", {"Peacock", "Parrot", "Myna", "Sparrow"}, 0},
    {"Which is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 0},
    {"Which is the national fruit of India?", {"Mango", "Banana", "Apple", "Orange"}, 0},
    {"Which is the national currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 0}
};

// Declare the student's answers
StudentAnswers student_answers;

// Function to display the questions and choices
void display_questions() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("(%c) %s\n", 'A' + j, questions[i].choices[j]);
        }
    }
}

// Function to get the student's answers
void get_answers() {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        char answer;
        printf("Enter your answer for question %d (A/B/C/D): ", i + 1);
        scanf(" %c", &answer);
        student_answers.answers[i] = answer - 'A';
    }
}

// Function to check the student's answers
int check_answers() {
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        if (student_answers.answers[i] == questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Function to display the result
void display_result(int score) {
    printf("Your score is %d out of %d\n", score, MAX_QUESTIONS);
    if (score >= 8) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry! You have failed the exam.\n");
    }
}

// Main function
int main() {
    // Display the welcome message
    printf("Welcome to the Online Examination System!\n");

    // Display the questions and choices
    display_questions();

    // Get the student's answers
    get_answers();

    // Check the student's answers
    int score = check_answers();

    // Display the result
    display_result(score);

    return 0;
}