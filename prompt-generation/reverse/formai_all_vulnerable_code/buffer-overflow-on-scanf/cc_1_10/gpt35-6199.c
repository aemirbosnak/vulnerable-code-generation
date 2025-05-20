//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function prototypes
void intro();
bool playGame();
int checkAnswer();

int main() {
    // Set up random number generator
    srand(time(NULL));
    
    // Call intro function
    intro();
    
    // Call playGame function to begin game
    bool gameResult = playGame();
    
    // Determine whether player won or lost and print appropriate message
    if (gameResult) {
        printf("Congratulations! You have successfully completed the game.\n");
    } else {
        printf("I'm sorry, you have lost the game. Please try again.\n");
    }
    
    return 0;
}

// Prints intro message
void intro() {
    printf("Welcome to Ada Lovelace's Text-Based Adventure Game!\n");
    printf("You will be asked a series of questions and given multiple choice answers.\n");
    printf("Use your knowledge and reasoning skills to select the correct answer and advance through the levels.\n");
    printf("Good luck!\n\n");
}

// Plays the game and returns true if player wins and false if player loses
bool playGame() {
    // Initialize level and points
    int level = 1;
    int points = 0;
    
    // Loop through levels until player wins or loses
    while (level <= 5) {
        // Print level and points
        printf("Level %d\n", level);
        printf("Points: %d\n", points);
        
        // Generate random question and answer choices
        int questionNum = rand() % 5 + 1;
        int correctAnswer = checkAnswer(questionNum);
        int incorrectAnswer1 = rand() % 3 + 1;
        int incorrectAnswer2 = rand() % 3 + 1;
        while (incorrectAnswer1 == correctAnswer) {
            incorrectAnswer1 = rand() % 3 + 1;
        }
        while (incorrectAnswer2 == correctAnswer || incorrectAnswer2 == incorrectAnswer1) {
            incorrectAnswer2 = rand() % 3 + 1;
        }
        
        // Print question and answer choices
        printf("\nQuestion %d:\n", questionNum);
        printf("What is the correct answer?\n");
        printf("1. Choice %d\n", correctAnswer);
        printf("2. Choice %d\n", incorrectAnswer1);
        printf("3. Choice %d\n\n", incorrectAnswer2);
        
        // Get player's answer and check if it's correct
        int playerAnswer;
        printf("Enter the number of your choice: ");
        scanf("%d", &playerAnswer);
        if (playerAnswer == correctAnswer) {
            printf("Congratulations, your answer is correct!\n");
            points += 10;
            level++;
        } else {
            printf("I'm sorry, your answer is incorrect. Please try again.\n");
        }
    }
    
    // If player reaches level 6, they have won the game
    return true;
}

// Takes question number and returns correct answer choice number
int checkAnswer(int questionNum) {
    switch (questionNum) {
        case 1:
            return 1;
        case 2:
            return 3;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 3;
    }
}