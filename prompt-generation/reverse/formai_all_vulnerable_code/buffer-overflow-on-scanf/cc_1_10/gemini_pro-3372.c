//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

typedef struct Question {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_option;
} Question;

int main() {
    // Create a question database
    Question questions[MAX_QUESTIONS] = {
        {
            "What is the capital of India?",
            {"New Delhi", "Mumbai", "Chennai", "Kolkata"},
            0
        },
        {
            "Who is the current Prime Minister of India?",
            {"Narendra Modi", "Rahul Gandhi", "Arvind Kejriwal", "Mamata Banerjee"},
            0
        },
        {
            "Which is the largest state in India?",
            {"Rajasthan", "Madhya Pradesh", "Uttar Pradesh", "Maharashtra"},
            2
        },
        {
            "Which is the smallest state in India?",
            {"Goa", "Sikkim", "Mizoram", "Arunachal Pradesh"},
            1
        },
        {
            "Which is the highest mountain in India?",
            {"Mount Everest", "Kanchenjunga", "Nanda Devi", "K2"},
            2
        },
    };

    // Get the number of questions from the user
    int num_questions;
    printf("Enter the number of questions you want to answer: ");
    scanf("%d", &num_questions);

    // Check if the number of questions is valid
    if (num_questions < 1 || num_questions > MAX_QUESTIONS) {
        printf("Invalid number of questions. Please enter a number between 1 and %d.\n", MAX_QUESTIONS);
        return 1;
    }

    // Shuffle the questions
    for (int i = 0; i < num_questions; i++) {
        int random_index = rand() % num_questions;
        Question temp = questions[i];
        questions[i] = questions[random_index];
        questions[random_index] = temp;
    }

    // Ask the user the questions
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("    %d. %s\n", j + 1, questions[i].options[j]);
        }
        printf("Enter your answer: ");
        int answer;
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correct_option + 1) {
            score++;
        }
    }

    // Print the score
    printf("Your score is %d out of %d.\n", score, num_questions);

    return 0;
}