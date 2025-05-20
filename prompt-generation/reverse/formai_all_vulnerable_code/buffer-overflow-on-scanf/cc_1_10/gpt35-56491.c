//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARACTERS 1000
#define MAX_PLAYERS 10

/* Function prototypes */
void generateChecksum(char *message, unsigned short *checksum);
bool validateChecksum(char *message, unsigned short checksum);
void clearInputBuffer(void);

/* Main function */
int main(int argc, char *argv[]) {
    char message[MAX_CHARACTERS], inputChar;
    unsigned short checksum;
    int numPlayers, currentPlayer;
    bool validInput = false;
    
    printf("Welcome to Checksum Calculator!\n");
    
    /* Prompt user for message */
    printf("Please enter message to generate checksum: ");
    fgets(message, MAX_CHARACTERS, stdin);
    strtok(message, "\n"); /* Remove trailing newline character */
    
    /* Generate checksum */
    generateChecksum(message, &checksum);
    
    /* Prompt user for number of players */
    do {
        printf("Please enter number of players [1-%d]: ", MAX_PLAYERS);
        validInput = scanf("%d", &numPlayers) == 1 && numPlayers > 0 && numPlayers <= MAX_PLAYERS;
        clearInputBuffer();
    } while (!validInput);
    
    /* Prompt user for current player */
    do {
        printf("Please enter current player [1-%d]: ", numPlayers);
        validInput = scanf("%d", &currentPlayer) == 1 && currentPlayer >= 1 && currentPlayer <= numPlayers;
        clearInputBuffer();
    } while (!validInput);
    
    /* Prompt each player for their checksum guess */
    for (int i = 1; i <= numPlayers; i++) {
        printf("Player %d: Please enter your guess for the checksum: ", i);
        fgets(message, MAX_CHARACTERS, stdin);
        strtok(message, "\n"); /* Remove trailing newline character */
        
        bool isCorrect = validateChecksum(message, checksum);
        
        if (isCorrect && i == currentPlayer) {
            printf("Congratulations! Your guess is correct!\n");
        } else if (isCorrect) {
            printf("Player %d has correctly guessed the checksum. Game over!\n", i);
            return 0;
        } else {
            printf("Player %d: Your guess is incorrect. Please try again.\n", i);
        }
    }
    
    /* If no player gets it right, display the correct answer and end the game */
    printf("None of the players correctly guessed the checksum. The correct answer is %d.\n", checksum);
    return 0;
}

/* Function to generate checksum from given message */
void generateChecksum(char *message, unsigned short *checksum) {
    *checksum = 0;
    
    for (int i = 0; i < strlen(message); i++) {
        *checksum += (unsigned short) message[i];
    }
}

/* Function to validate checksum guess */
bool validateChecksum(char *message, unsigned short checksum) {
    unsigned short guess;
    
    if (sscanf(message, "%hu", &guess) == 1 && guess == checksum) {
        return true;
    } else {
        return false;
    }
}

/* Function to clear input buffer */
void clearInputBuffer(void) {
    while (getchar() != '\n');
}