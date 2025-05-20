//GPT-4o-mini DATASET v1.0 Category: Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}

void displayWelcomeMessage() {
    printf("Welcome to the 'Guess the Number' Game!\n");
    printf("Try to guess the number between 1 and 100.\n");
    printf("You can play with a maximum of %d players.\n", MAX_PLAYERS);
}

void displayScores(Player players[], int playerCount) {
    printf("\n--- Scores ---\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("--------------\n");
}

void takeInput(char *prompt, char *inputBuffer, int bufferSize) {
    printf("%s", prompt);
    fgets(inputBuffer, bufferSize, stdin);
    inputBuffer[strcspn(inputBuffer, "\n")] = '\0'; // Remove newline character
}

int getRandomNumber() {
    return rand() % 100 + 1; // Random number between 1 and 100
}

void playRound(Player *player) {
    int numberToGuess = getRandomNumber();
    int playerGuess = 0;
    int attempts = 0;

    printf("\n%s, it's your turn! Guess the number:\n", player->name);

    while (attempts < MAX_ROUNDS) {
        printf("Attempt %d: ", attempts + 1);
        scanf("%d", &playerGuess);
        
        attempts++;
        if (playerGuess < numberToGuess) {
            printf("Higher!\n");
        } else if (playerGuess > numberToGuess) {
            printf("Lower!\n");
        } else {
            printf("Congratulations %s, you guessed the number %d in %d attempts!\n", player->name, numberToGuess, attempts);
            player->score += 10; // Add points for correct guess
            return;
        }
    }

    printf("Sorry %s, you've used all your attempts! The number was %d.\n", player->name, numberToGuess);
}

void playGame(Player players[], int playerCount) {
    for (int round = 0; round < MAX_ROUNDS; round++) {
        printf("\nRound %d:\n", round + 1);
        for (int i = 0; i < playerCount; i++) {
            playRound(&players[i]);
        }
        displayScores(players, playerCount);
    }
}

void inputPlayerNames(Player players[], int *playerCount) {
    char buffer[MAX_NAME_LENGTH];
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", playerCount);
    
    while (*playerCount < 1 || *playerCount > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", playerCount);
    }

    for (int i = 0; i < *playerCount; i++) {
        takeInput("Enter player name: ", buffer, MAX_NAME_LENGTH);
        strncpy(players[i].name, buffer, MAX_NAME_LENGTH);
        players[i].score = 0; // Initialize score
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;

    srand(time(NULL)); // Seed the random number generator
    clearScreen();
    displayWelcomeMessage();
    
    inputPlayerNames(players, &playerCount);
    playGame(players, playerCount);

    printf("\nGame Over! Final Scores:\n");
    displayScores(players, playerCount);

    return 0;
}