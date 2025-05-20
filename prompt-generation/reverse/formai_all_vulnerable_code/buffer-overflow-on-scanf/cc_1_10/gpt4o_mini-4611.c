//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LENGTH 100
#define MAX_ROUNDS 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initializePlayers(Player players[], int *playerCount) {
    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", playerCount);
    
    if(*playerCount > MAX_PLAYERS || *playerCount < 1) {
        printf("Invalid number of players. Setting to 1.\n");
        *playerCount = 1;
    }
    
    for(int i = 0; i < *playerCount; i++) {
        printf("Enter name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void playRound(Player *player) {
    int lower = 1, upper = 100;
    int target = generateRandomNumber(lower, upper);
    int guess, attempts = 0;

    printf("\n%s, it's your turn! Guess the number between %d and %d:\n", player->name, lower, upper);

    while (1) {
        printf("Your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < lower || guess > upper) {
            printf("Invalid guess! Please guess a number between %d and %d.\n", lower, upper);
            continue;
        }
        
        if (guess == target) {
            printf("Congratulations %s! You guessed the number %d in %d attempts.\n", player->name, target, attempts);
            player->score += 100 - (attempts * 10); // Scoring based on attempts
            break;
        } else if (guess < target) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }
}

void displayScores(Player players[], int playerCount) {
    printf("\nFinal scores:\n");
    for (int i = 0; i < playerCount; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount;

    srand(time(NULL)); // Seed the random number generator
    initializePlayers(players, &playerCount);

    for (int round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < playerCount; i++) {
            playRound(&players[i]);
        }
    }

    displayScores(players, playerCount);

    return 0;
}