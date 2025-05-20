//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the questions and answers
char questions[10][100] = {
    "What is the capital of France?",
    "What is the largest ocean in the world?",
    "What is the chemical symbol for gold?",
    "Who is the author of the Harry Potter series?",
    "What is the name of the tallest mountain in the world?",
    "What is the name of the first artificial satellite to orbit the Earth?",
    "What is the name of the largest planet in the solar system?",
    "What is the name of the currency used in the United Kingdom?",
    "What is the name of the inventor of the telephone?",
    "What is the name of the first computer programming language?"
};

char answers[10][100] = {
    "Paris",
    "Pacific Ocean",
    "Au",
    "J.K. Rowling",
    "Mount Everest",
    "Sputnik 1",
    "Jupiter",
    "Pound sterling",
    "Alexander Graham Bell",
    "Fortran"
};

// Function to display the questions and get the user's answers
void takeExam() {
    int score = 0;
    char userAnswer[100];

    for (int i = 0; i < 10; i++) {
        printf("%d. %s\n", i + 1, questions[i]);
        scanf("%s", userAnswer);

        // Check if the user's answer is correct
        if (strcmp(userAnswer, answers[i]) == 0) {
            score++;
        }
    }

    // Display the user's score
    printf("Your score is %d out of 10.\n", score);
}

// Main function
int main() {
    // Display the welcome message
    printf("Welcome to the online examination system!\n");
    printf("You will be asked 10 questions. Enter your answers below each question.\n");

    // Take the exam
    takeExam();

    return 0;
}