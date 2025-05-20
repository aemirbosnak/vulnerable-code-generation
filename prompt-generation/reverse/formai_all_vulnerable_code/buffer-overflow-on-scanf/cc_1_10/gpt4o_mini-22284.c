//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_ATTEMPTS 5

void displayInstructions() {
    printf("Welcome to the Cheerful Number Challenge!\n");
    printf("Try to guess the number I'm thinking of between 1 and 100.\n");
    printf("You have a total of %d attempts.\n", MAX_ATTEMPTS);
    printf("Good luck, and have fun!\n");
}

int getRandomNumber() {
    return rand() % 100 + 1; // Returns a number between 1 and 100
}

void playGame(const char *playerName) {
    int randomNumber = getRandomNumber();
    int guess, attempts = 0;
    int points = 0;

    printf("%s, let's start! I have chosen a number...\n", playerName);
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d: Enter your guess: ", attempts + 1);
        scanf("%d", &guess);
        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Please guess a number between 1 and 100!\n");
            attempts--; // Don't count this attempt
            continue;
        }

        if (guess == randomNumber) {
            printf("🎉 Congratulations, %s! You've guessed the number %d correctly!\n", playerName, randomNumber);
            points = (MAX_ATTEMPTS - attempts + 1) * 10; // Points calculated based on remaining attempts
            break;
        } else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    if (attempts == MAX_ATTEMPTS) {
        printf("Sorry, %s! You've used all your attempts. The number was %d.\n", playerName, randomNumber);
    }
    
    printf("You earned %d points!\n\n", points);
}

void displayLeaderboard(const char *names[], int scores[], int totalPlayers) {
    printf("🏆 Leaderboard 🏆\n");
    for (int i = 0; i < totalPlayers; i++) {
        printf("%s: %d points\n", names[i], scores[i]);
    }
    printf("------------------------\n");
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    char *playerNames[MAX_PLAYERS];
    int playerScores[MAX_PLAYERS] = {0};
    int totalPlayers = 0;

    displayInstructions();
    
    printf("How many players are joining? (max %d): ", MAX_PLAYERS);
    scanf("%d", &totalPlayers);
    
    if (totalPlayers > MAX_PLAYERS) {
        printf("Only a maximum of %d players are allowed!\n", MAX_PLAYERS);
        return 1;
    }

    for (int i = 0; i < totalPlayers; i++) {
        playerNames[i] = (char *)malloc(50 * sizeof(char)); // Allocate space for player names
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", playerNames[i]);
    }

    for (int i = 0; i < totalPlayers; i++) {
        playGame(playerNames[i]);
        playerScores[i] += (MAX_ATTEMPTS - MAX_ATTEMPTS) * 10; // Can add score logic
    }

    displayLeaderboard(playerNames, playerScores, totalPlayers);

    for (int i = 0; i < totalPlayers; i++) {
        free(playerNames[i]); // Free allocated memory for player names
    }
    
    printf("Thank you for playing the Cheerful Number Challenge! Come back soon! 🎈\n");
    
    return 0;
}