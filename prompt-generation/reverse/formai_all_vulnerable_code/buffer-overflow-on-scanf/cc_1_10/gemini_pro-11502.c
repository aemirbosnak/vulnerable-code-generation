//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store questions
typedef struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

// Function to display the welcome message
void welcome() {
    printf("\nWelcome to the Online Examination System!\n");
    printf("Instructions:\n");
    printf("1. Read each question carefully.\n");
    printf("2. Choose the best answer from the options provided.\n");
    printf("3. Enter the corresponding number of your choice.\n");
    printf("4. Press Enter to submit your answer.\n");
    printf("5. You have 1 minute to answer each question.\n");
    printf("6. Good luck!\n\n");
}

// Function to display the questions
void display_questions(Question *questions, int num_questions) {
    int i;
    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
    }
}

// Function to get the user's answers
void get_answers(int *answers, int num_questions) {
    int i;
    for (i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }
}

// Function to check the answers
int check_answers(int *answers, Question *questions, int num_questions) {
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
    printf("\nYour score is %d out of %d.\n", score, num_questions);
    if (score >= (num_questions * 0.7)) {
        printf("Congratulations! You have passed the exam.\n");
    } else {
        printf("Sorry, you have failed the exam.\n");
    }
}

// Main function
int main() {
    // Define the questions
    Question questions[] = {
        {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 1},
        {"Who is the Prime Minister of India?", {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"}, 1},
        {"What is the national animal of India?", {"Tiger", "Lion", "Elephant", "Peacock"}, 1},
        {"What is the national bird of India?", {"Peacock", "Eagle", "Sparrow", "Pigeon"}, 1},
        {"What is the national flower of India?", {"Lotus", "Rose", "Jasmine", "Sunflower"}, 1}
    };

    int num_questions = sizeof(questions) / sizeof(questions[0]);

    // Welcome the user
    welcome();

    // Display the questions
    display_questions(questions, num_questions);

    // Get the user's answers
    int answers[num_questions];
    get_answers(answers, num_questions);

    // Check the answers
    int score = check_answers(answers, questions, num_questions);

    // Display the results
    display_results(score, num_questions);

    return 0;
}