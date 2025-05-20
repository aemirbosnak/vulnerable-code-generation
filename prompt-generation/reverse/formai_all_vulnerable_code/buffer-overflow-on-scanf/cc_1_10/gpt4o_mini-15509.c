//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 5
#define MAX_CODE_SIZE 1024
#define PROMPT_SIZE 256

typedef struct {
    int id;
    char name[50];
    char code[MAX_CODE_SIZE];
    int score;
} Player;

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int is_syntax_correct(const char *code) {
    // Simplified syntax checking; this is just a placeholder
    int open_braces = 0;
    for (const char *ptr = code; *ptr; ptr++) {
        if (*ptr == '{') open_braces++;
        else if (*ptr == '}') open_braces--;
    }
    return open_braces == 0;
}

void collect_player_code(Player *player) {
    printf("Player %s, enter your C code snippet (max %d characters):\n", player->name, MAX_CODE_SIZE - 1);
    fgets(player->code, MAX_CODE_SIZE, stdin);
    
    // Remove newline character if present
    size_t len = strlen(player->code);
    if (len > 0 && player->code[len - 1] == '\n') {
        player->code[len - 1] = '\0';
    }
}

void display_results(Player players[], int num_players) {
    printf("\nGame Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %s (ID: %d) - Syntax %s. Score: %d\n",
            players[i].name, players[i].id,
            players[i].score > 0 ? "Correct" : "Incorrect", 
            players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to the C Syntax Parsing Multiplayer Game!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    clear_buffer();

    if (num_players > MAX_PLAYERS) {
        printf("Too many players! Setting to max %d players.\n", MAX_PLAYERS);
        num_players = MAX_PLAYERS;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        
        // Remove newline character if present
        size_t len = strlen(players[i].name);
        if (len > 0 && players[i].name[len - 1] == '\n') {
            players[i].name[len - 1] = '\0';
        }

        players[i].id = i + 1;
        players[i].score = 0; // initialize score
    }

    // Game rounds
    for (int round = 1; round <= 3; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < num_players; i++) {
            collect_player_code(&players[i]);
            
            if (is_syntax_correct(players[i].code)) {
                printf("Good job, %s! Your code is syntactically correct.\n", players[i].name);
                players[i].score++;
            } else {
                printf("Oops, %s! Your code has syntax errors!\n", players[i].name);
            }
        }
    }

    display_results(players, num_players);
    return 0;
}