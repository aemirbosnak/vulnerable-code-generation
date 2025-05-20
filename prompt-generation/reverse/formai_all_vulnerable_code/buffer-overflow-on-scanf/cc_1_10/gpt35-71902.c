//FormAI DATASET v1.0 Category: File handling ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_SIZE 20
#define MAX_ROUNDS 5

// Structure to store player information
typedef struct {
    char name[MAX_NAME_SIZE];
    int score;
} Player;

// Function to get a random integer between two values
int getRandom(int min, int max) {
    return (rand()%(max-min+1)) + min;
}

// Function to play a round for a player and update their score
void playRound(Player* player) {
    int guess, answer;
    int range = 10;
    
    printf("%s, guess a number between 1 and %d: ", player->name, range);
    scanf("%d", &guess);
    
    answer = getRandom(1, range);
    
    if(guess == answer) {
        printf("Congratulations %s! You guessed the number.\n", player->name);
        player->score += 10;
    } else {
        printf("Sorry %s, the number was %d.\n", player->name, answer);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    char* fileName = "player_scores.txt";
    FILE* fptr;
    int numPlayers;
    int i, j, round;

    // Seed random number generator
    srand(time(0));
    
    // Get number of players
    do {
        printf("Enter the number of players [2-%d]: ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    } while(numPlayers < 2 || numPlayers > MAX_PLAYERS);
    
    // Get player names
    for(i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    // Play game
    for(round = 1; round <= MAX_ROUNDS; round++) {
        printf("\n-------- Round %d --------\n", round);
        for(i = 0; i < numPlayers; i++) {
            playRound(&players[i]);
        }
    }
    
    // Write scores to file
    fptr = fopen(fileName, "w");
    if(fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    fprintf(fptr, "Player Scores:\n");
    for(i = 0; i < numPlayers; i++) {
        fprintf(fptr, "%s: %d\n", players[i].name, players[i].score);
    }
    
    fclose(fptr);
    
    // Read scores from file and display them
    fptr = fopen(fileName, "r");
    if(fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    printf("\n--- Player Scores ---\n");
    char line[100];
    while(fgets(line, 100, fptr)) {
        printf("%s", line);
    }
    
    fclose(fptr);
    
    return 0;
}