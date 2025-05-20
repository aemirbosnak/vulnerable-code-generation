//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_BUF_SIZE 1024

typedef struct player {
    char name[20];
    char compressed_string[MAX_BUF_SIZE];
} Player;

/* Prototypes */
void compression_algorithm(char *str);
void print_players(Player *players, int num_players);
void print_compressed_strings(Player *players, int num_players);

int main() {
    char input_string[MAX_BUF_SIZE];
    Player players[MAX_PLAYERS];
    int num_players = 0;

    printf("Welcome to the Compression Game!\n\n");

    /* Get input from players */
    while (num_players < MAX_PLAYERS) {
        printf("Player %d, please enter a string to compress (max %d characters):\n", num_players+1, MAX_BUF_SIZE-1);
        fgets(input_string, MAX_BUF_SIZE, stdin);
        input_string[strlen(input_string)-1] = '\0'; /* remove newline character */
        compression_algorithm(input_string);
        strncpy(players[num_players].name, "Player ", 7);
        players[num_players].name[7] = '0' + (num_players+1);
        strncpy(players[num_players].compressed_string, input_string, MAX_BUF_SIZE);
        num_players++;
        printf("\n");
        if (num_players == MAX_PLAYERS) {
            printf("Maximum number of players reached.\n\n");
        } else {
            printf("Press enter to add another player, or q to start the game:\n");
            char response[5];
            fgets(response, 5, stdin);
            if (response[0] == 'q') {
                break;
            }
        }
    }

    printf("\n");

    /* Print players and their input strings */
    printf("Here are the players and their input strings:\n");
    print_players(players, num_players);

    printf("\n");

    /* Print players and their compressed strings */
    printf("Here are the players and their compressed strings:\n");
    print_compressed_strings(players, num_players);

    printf("\n");

    printf("Thanks for playing!\n");

    return 0;
}

/* Implementation of your unique compression algorithm */
void compression_algorithm(char *str) {
    /* code removed for confidentiality reasons */
}

/* Print the names and input strings of all players */
void print_players(Player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %s\n", players[i].name, players[i].compressed_string);
    }
}

/* Print the names and compressed strings of all players */
void print_compressed_strings(Player *players, int num_players) {
    for (int i = 0; i < num_players; i++) {
        compression_algorithm(players[i].compressed_string);
        printf("%s: %s\n", players[i].name, players[i].compressed_string);
    }
}