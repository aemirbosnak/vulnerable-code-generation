//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define QUESTIONS 5

// Function prototypes
void displayInstructions();
void getPlayerNames(char players[MAX_PLAYERS][30], int playerCount);
int generateQuestion(int playerIndex);
void calculateScores(int scores[MAX_PLAYERS], int playerCount);
void displayScores(int scores[MAX_PLAYERS], char players[MAX_PLAYERS][30], int playerCount);

int main() {
    int playerCount;
    char players[MAX_PLAYERS][30];
    int scores[MAX_PLAYERS] = {0};
    
    srand(time(NULL)); // Seed for random generation

    // Display instructions
    displayInstructions();
    
    // Get the number of players
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    while (playerCount < 1 || playerCount > MAX_PLAYERS) {
        printf("Please enter a valid number of players (1-%d): ", MAX_PLAYERS);
        scanf("%d", &playerCount);
    }
    
    // Get player names
    getPlayerNames(players, playerCount);
    
    // Main game loop
    for (int i = 0; i < QUESTIONS; i++) {
        for (int j = 0; j < playerCount; j++) {
            scores[j] += generateQuestion(j);
        }
    }

    // Calculate and display scores
    calculateScores(scores, playerCount);
    displayScores(scores, players, playerCount);

    return 0;
}

void displayInstructions() {
    printf("Welcome to the Multiplayer Math Quiz Game!\n");
    printf("Players will take turns answering math questions.\n");
    printf("Each correct answer gives you 1 point.\n");
    printf("Let's have fun and see who gets the highest score!\n\n");
}

void getPlayerNames(char players[MAX_PLAYERS][30], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i]);
    }
}

int generateQuestion(int playerIndex) {
    int num1 = rand() % 10;
    int num2 = rand() % 10;
    char operators[] = {'+', '-', '*', '/'};
    char operator = operators[rand() % 4];
    int answer;
    
    if (operator == '/') {
        num1 = num1 * num2; // To avoid division errors
    }
    
    printf("Player %d's turn: What is %d %c %d? ", playerIndex + 1, num1, operator, num2);
    int userAnswer;

    // Get the user's answer
    scanf("%d", &userAnswer);

    // Calculate correct answer
    switch (operator) {
        case '+':
            answer = num1 + num2;
            break;
        case '-':
            answer = num1 - num2;
            break;
        case '*':
            answer = num1 * num2;
            break;
        case '/':
            answer = num1 / num2;
            break;
    }

    // Check the answer
    if (userAnswer == answer) {
        printf("Correct!\n");
        return 1; // Correct answer
    } else {
        printf("Wrong! The correct answer was %d.\n", answer);
        return 0; // Wrong answer
    }
}

void calculateScores(int scores[MAX_PLAYERS], int playerCount) {
    // Scores are already summed in the main loop, this function can be modified further for enhancements
}

void displayScores(int scores[MAX_PLAYERS], char players[MAX_PLAYERS][30], int playerCount) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i], scores[i]);
    }
    
    int maxScore = -1;
    int winnerIndex = -1;

    // Find the winner
    for (int i = 0; i < playerCount; i++) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }
    
    printf("\nThe winner is %s with a score of %d!\n", players[winnerIndex], maxScore);
}