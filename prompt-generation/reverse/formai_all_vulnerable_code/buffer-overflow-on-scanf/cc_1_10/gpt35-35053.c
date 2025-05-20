//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
    int number;
    char text[100];
    char options[4][50];
    int correct_option;
} Question;

int main() {
    // Initialize questions
    Question q1 = {1, "What is the output of 2 + 2?", {"A. 4", "B. 3", "C. 6", "D. 5"}, 0};
    Question q2 = {2, "What is the capital city of Spain?", {"A. Rome", "B. Madrid", "C. Paris", "D. London"}, 1};
    Question q3 = {3, "What is the first element on the periodic table?", {"A. Hydrogen", "B. Oxygen", "C. Carbon", "D. Helium"}, 0};
    Question q4 = {4, "What is the largest planet in our solar system?", {"A. Saturn", "B. Mars", "C. Jupiter", "D. Pluto"}, 2};
    Question q5 = {5, "What is the tallest mammal?", {"A. Elephant", "B. Giraffe", "C. Lion", "D. Gorilla"}, 1};

    // Store questions in an array
    Question questions[5] = {q1, q2, q3, q4, q5};

    // Initialize variables
    int score = 0;
    int answer;

    printf("Welcome to the Online Examination System.\n");
    printf("You will be presented with 5 multiple choice questions. Answer them to the best of your ability.\n");

    // Loop through each question
    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d: %s\n", questions[i].number, questions[i].text);

        // Print out answer options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", questions[i].options[j]);
        }

        // Get user input
        printf("Enter your answer (A, B, C, or D): ");
        scanf("%c", &answer);
        getchar(); // Ignore new line character

        // Check if answer is correct
        if (answer == 'A' + questions[i].correct_option) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }

    // Print out final score
    printf("\nCongratulations! You have completed the exam.\n");
    printf("Your score is %d/5.\n", score);

    return 0;
}