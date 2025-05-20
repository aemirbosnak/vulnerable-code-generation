//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 20
#define TARGET_SCORE 100

typedef struct {
    char name[30];
    int score;
} Player;

void initialize_players(Player players[], int count) {
    for(int i = 0; i < count; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void display_scores(Player players[], int count) {
    printf("\nCurrent Scores:\n");
    for(int i = 0; i < count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void roll_dice(Player *player) {
    int roll = (rand() % 6) + 1; // Random number between 1 and 6
    printf("%s rolled a %d!\n", player->name, roll);
    player->score += roll;
    printf("%s's current score: %d\n", player->name, player->score);
}

int check_winner(Player players[], int count) {
    for(int i = 0; i < count; i++) {
        if(players[i].score >= TARGET_SCORE) {
            printf("Congratulations, %s! You have reached the target score of %d!\n", players[i].name, TARGET_SCORE);
            return 1; // A winner is found
        }
    }
    return 0; // No winner yet
}

void play_game(Player players[], int player_count) {
    for(int turn = 0; turn < MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn + 1);
        for(int i = 0; i < player_count; i++) {
            roll_dice(&players[i]);
            if(check_winner(players, player_count)) {
                return; // End game if there's a winner
            }
        }
        display_scores(players, player_count);
    }
    printf("Maximum turns reached! No winner this time.\n");
}

int main() {
    srand(time(NULL)); // Seed for randomness
    Player players[MAX_PLAYERS];
    int player_count;

    printf("Welcome to the Exciting Dice Roll Game!\n");
    printf("You can have up to %d players. How many players are joining? (max: %d) ", MAX_PLAYERS, MAX_PLAYERS);
    scanf("%d", &player_count);
    
    if(player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players! Please restart the game and enter a number between 1 and %d.\n", MAX_PLAYERS);
        return 1;
    }

    initialize_players(players, player_count);
    play_game(players, player_count);

    printf("Thank you for playing the Exciting Dice Roll Game! Goodbye!\n");
    return 0;
}