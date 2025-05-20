//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_ROUNDS 5
#define MAX_WORDS 100

// Function to get a random word from a predefined list
const char* getRandomWord() {
    const char* words[MAX_WORDS] = {
        "apple", "banana", "grape", "orange", "pineapple",
        "mango", "peach", "cherry", "strawberry", "blueberry"
    };
    
    return words[rand() % (sizeof(words) / sizeof(words[0]))];
}

// Function to check if the player has guessed the word correctly
int checkGuess(const char* word, const char* guess) {
    return strcmp(word, guess) == 0;
}

// Function to print the game instructions
void printInstructions() {
    printf("Welcome to the Word Guessing Game!\n");
    printf("You will have 5 rounds to guess the correct word.\n");
    printf("Each correct guess will earn you a point!\n");
    printf("Good luck!\n\n");
}

// Main function
int main() {
    srand(time(0)); // Initialize random seed
    int numPlayers;
    char names[MAX_PLAYERS][MAX_NAME_LENGTH];
    int scores[MAX_PLAYERS] = {0};

    // Get the number of players
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    // Ensure the valid number of players
    while(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    }

    // Get player names
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printInstructions();

    // Start the guessing rounds
    for(int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\nRound %d starts! A new word has been chosen.\n", round);
        const char* wordToGuess = getRandomWord();
        
        for(int i = 0; i < numPlayers; i++) {
            char playerGuess[MAX_NAME_LENGTH];
            printf("%s, it's your turn! Enter your guess: ", names[i]);
            scanf("%s", playerGuess);

            // Check if the guess is correct
            if(checkGuess(wordToGuess, playerGuess)) {
                printf("Correct guess, %s! You earn a point!\n", names[i]);
                scores[i]++;
            } else {
                printf("Wrong guess, %s. The correct word was '%s'.\n", names[i], wordToGuess);
            }
        }
    }

    // Print the final scores
    printf("\nFinal Scores:\n");
    for(int i = 0; i < numPlayers; i++) {
        printf("%s: %d points\n", names[i], scores[i]);
    }

    // Determine the winner
    int maxScore = 0;
    int winnerIndex = -1;
    for(int i = 0; i < numPlayers; i++) {
        if(scores[i] > maxScore) {
            maxScore = scores[i];
            winnerIndex = i;
        }
    }

    if(winnerIndex != -1) {
        printf("Congratulations, %s! You are the winner with %d points!\n", names[winnerIndex], maxScore);
    } else {
        printf("No one won, all players have the same score.\n");
    }

    return 0;
}