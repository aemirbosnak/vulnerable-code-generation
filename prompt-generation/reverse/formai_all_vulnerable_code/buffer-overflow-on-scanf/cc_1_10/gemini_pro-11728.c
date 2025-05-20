//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the question and answers
typedef struct question {
    char question[100];
    char options[4][50];
    int correct_answer;
} question;

// Array of questions
question questions[] = {
    {"What is the capital of India?", {"New Delhi", "Mumbai", "Kolkata", "Chennai"}, 0},
    {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 0},
    {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Bear"}, 0},
    {"What is the currency of India?", {"Rupee", "Dollar", "Euro", "Pound"}, 0},
    {"What is the largest city in India?", {"Mumbai", "Delhi", "Bangalore", "Kolkata"}, 0}
};

// Function to print the questions and options
void print_questions(question *questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("\n");
    }
}

// Function to get the user's answers
void get_answers(question *questions, int num_questions, int *answers) {
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }
}

// Function to check the user's answers
int check_answers(question *questions, int num_questions, int *answers) {
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        if (answers[i] == questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Print the questions and options
    print_questions(questions, sizeof(questions) / sizeof(question));

    // Get the user's answers
    int answers[sizeof(questions) / sizeof(question)];
    get_answers(questions, sizeof(questions) / sizeof(question), answers);

    // Check the user's answers
    int score = check_answers(questions, sizeof(questions) / sizeof(question), answers);

    // Print the score
    printf("Your score is: %d\n", score);

    return 0;
}