//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and options
typedef struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

// Array of questions
Question questions[] = {
    {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
    {"Who is the author of Hamlet?", {"William Shakespeare", "Geoffrey Chaucer", "Jane Austen", "Charles Dickens"}, 1},
    {"Which is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 1},
    {"What is the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 1},
    {"Who is the current Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
};

// Function to display the questions and options
void display_questions(Question questions[], int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("(%c) %s\n", 'A' + j, questions[i].options[j]);
        }
    }
}

// Function to get the user's answers
void get_answers(int answers[], int num_questions) {
    char answer;
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
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
    int num_questions = sizeof(questions) / sizeof(Question);
    int answers[num_questions];

    display_questions(questions, num_questions);
    get_answers(answers, num_questions);
    int score = check_answers(answers, questions, num_questions);
    display_results(score, num_questions);

    return 0;
}