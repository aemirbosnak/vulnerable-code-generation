//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100
#define MAX_PLAYERS 5

// Struct to hold player information
typedef struct {
    char name[MAX_CHARS];
    int score;
} player;

// Function to count occurrence of a word in a given string
int countWord(char* string, char* word) {
    int count = 0;
    char* curr = string;
    while ((curr = strstr(curr, word)) != NULL) {
        count++;
        curr++;
    }
    return count;
}

// Main function
int main() {
    int num_players;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Error: too many players.\n");
        return 1;
    }

    player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    char text[MAX_CHARS];
    printf("Enter text to search: ");
    scanf(" %[^\n]s", text);

    char word[MAX_CHARS];
    printf("Enter word to search: ");
    scanf("%s", word);

    int word_count = countWord(text, word);
    printf("\nNumber of times '%s' appears: %d\n", word, word_count);

    printf("\nWord count leaderboard:\n");
    for (int i = 0; i < num_players; i++) {
        players[i].score = countWord(text, players[i].name);
    }

    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}