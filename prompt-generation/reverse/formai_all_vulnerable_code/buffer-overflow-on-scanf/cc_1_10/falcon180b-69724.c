//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

// Player structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Function to initialize a player
void init_player(Player *player) {
    strcpy(player->name, "");
    player->score = 0;
}

// Function to print the leaderboard
void print_leaderboard(Player players[], int num_players) {
    printf("Leaderboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s: %d points\n", i+1, players[i].name, players[i].score);
    }
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        if (tolower(str[i])!= tolower(str[len-i-1])) {
            return 0;
        }
    }
    return 1;
}

// Function to get a string input from the user
void get_input(char *str, int max_length) {
    printf("Enter %s: ", str);
    fgets(str, max_length, stdin);
    str[strcspn(str, "\n")] = '\0';
}

// Main function
int main() {
    int num_players;
    printf("How many players will be playing? ");
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        init_player(&players[i]);
        printf("Player %d, enter your name: ", i+1);
        get_input(players[i].name, MAX_NAME_LENGTH);
    }

    int round_num = 1;
    while (1) {
        printf("\nRound %d:\n", round_num);
        for (int i = 0; i < num_players; i++) {
            char word[MAX_NAME_LENGTH];
            printf("Player %d, enter a word: ", i+1);
            get_input(word, MAX_NAME_LENGTH);

            if (is_palindrome(word)) {
                players[i].score++;
            }
        }

        print_leaderboard(players, num_players);

        if (round_num == 10) {
            break;
        }

        printf("\nContinue to next round? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            break;
        }
        round_num++;
    }

    printf("\nGame over!\n");
    print_leaderboard(players, num_players);

    return 0;
}