//GPT-4o-mini DATASET v1.0 Category: Prime Number Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define MAX_NUM 100

// Function to check if a number is prime
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Function to generate random number for guessing
int generate_random_number(int max) {
    return rand() % max + 1; // random number between 1 and max
}

// Struct to represent a player
typedef struct {
    char name[50];
    int score;
} Player;

// Function to initialize players
void initialize_players(Player players[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

// Function to play a round
void play_round(Player players[], int player_count) {
    printf("\n--- New Round ---\n");
    for (int i = 0; i < player_count; i++) {
        int number = generate_random_number(MAX_NUM);
        char user_choice;
        
        printf("%s, the generated number is %d. Is this prime? (y/n): ", players[i].name, number);
        scanf(" %c", &user_choice);

        if ((user_choice == 'y' && is_prime(number)) || (user_choice == 'n' && !is_prime(number))) {
            printf("Correct!\n");
            players[i].score++;
        } else {
            printf("Wrong! The number %d is %sprime.\n", number, is_prime(number) ? "" : "not ");
        }
        
        printf("%s's current score: %d\n", players[i].name, players[i].score);
    }
}

// Function to display the winner
void display_winner(Player players[], int player_count) {
    int max_score = 0;
    char winner[50] = "None";

    for (int i = 0; i < player_count; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
            strcpy(winner, players[i].name);
        }
    }
    printf("\nThe winner is %s with a score of %d!\n", winner, max_score);
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int player_count;

    printf("Welcome to the Multiplayer Prime Number Generator Game!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    
    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting.\n");
        return 1;
    }

    initialize_players(players, player_count);

    char continue_game;
    do {
        play_round(players, player_count);
        printf("Do you want to play another round? (y/n): ");
        scanf(" %c", &continue_game);
    } while (continue_game == 'y');

    display_winner(players, player_count);
    printf("Thanks for playing!\n");
    
    return 0;
}