//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a maximum character number for user input
#define MAX_CHAR 100

// Define a struct to represent a player and their score
struct player {
    char name[MAX_CHAR];
    int score;
};

// Declare global variables to be used throughout the program
struct player players[4];
int num_players = 0;

// Function to add a new player to the game
void add_player() {
    if (num_players == 4) {
        printf("Maximum number of players reached.\n");
        return;
    }
    
    struct player p;
    printf("Enter player name:\n");
    scanf("%s", p.name);
    p.score = 0;
    players[num_players] = p;
    num_players++;
    printf("Player %s added to the game.\n", p.name);
}

// Function to display the current standings in the game
void display_standings() {
    printf("Current standings:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

// Function to update a player's score based on their name and the score delta
void update_score(char* name, int delta) {
    for (int i = 0; i < num_players; i++) {
        if (strcmp(name, players[i].name) == 0) {
            players[i].score += delta;
            printf("%s's score updated by %d.\n", players[i].name, delta);
            return;
        }
    }
    printf("Player %s not found.\n", name);
}

int main() {
    printf("Welcome to our text-based multiplayer game!\n");
    printf("===========================================\n");

    while(1) {
        printf("\nSelect an action:\n");
        printf("1. Add player\n");
        printf("2. Display standings\n");
        printf("3. Update score\n");
        printf("4. Quit\n");
        
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_player();
                break;
            case 2:
                display_standings();
                break;
            case 3:
                printf("Enter player name to update:\n");
                char name[MAX_CHAR];
                scanf("%s", name);
                printf("Enter score delta:\n");
                int delta;
                scanf("%d", &delta);
                update_score(name, delta);
                break;
            case 4:
                printf("Thanks for playing!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}