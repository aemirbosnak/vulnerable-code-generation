//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store questions and answers
typedef struct {
    char question[100];
    char options[4][50];
    int correct_answer;
} Question;

// Array of questions
Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 1},
    {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
    {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 1},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Leopard"}, 1},
    {"What is the national bird of India?", {"Peacock", "Eagle", "Crow", "Sparrow"}, 1},
    {"What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Marigold"}, 1},
    {"What is the national anthem of India?", {"Jana Gana Mana", "Vande Mataram", "Saare Jahan Se Achcha", "Ragupati Ragava Raja Ram"}, 1},
    {"What is the national flag of India?", {"Tricolour", "Union Jack", "Stars and Stripes", "Red Cross"}, 1},
    {"What is the national emblem of India?", {"Lion Capital of Ashoka", "Tiger", "Elephant", "Peacock"}, 1},
    {"What is the national tree of India?", {"Banyan", "Neem", "Mango", "Pipal"}, 1}
};

// Function to print questions and options
void print_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get user input
int get_input() {
    int input;
    scanf("%d", &input);
    return input;
}

// Function to check if user input is correct
int is_correct(Question question, int input) {
    return input == question.correct_answer;
}

// Function to calculate score
int calculate_score(int num_correct) {
    return num_correct * 10;
}

// Main function
int main() {
    // Print welcome message
    printf("Welcome to the Online Examination System!\n");

    // Get number of questions
    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Initialize score to 0
    int score = 0;

    // Iterate over questions
    for (int i = 0; i < num_questions; i++) {
        // Print question and options
        print_question(questions[i]);

        // Get user input
        int input = get_input();

        // Check if user input is correct
        if (is_correct(questions[i], input)) {
            // Increment score
            score++;
        }
    }

    // Calculate score
    int final_score = calculate_score(score);

    // Print score
    printf("Your score is: %d\n", final_score);

    return 0;
}