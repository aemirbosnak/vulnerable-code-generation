//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

typedef struct player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

void initialize_player(Player *player) {
    strcpy(player->name, "");
    player->score = 0;
}

int main() {
    int num_players;
    printf("Enter number of players (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    Player players[MAX_PLAYERS];
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf(" %[^\n]", players[i].name);
        initialize_player(&players[i]);
    }

    char word[100];
    int is_palindrome = 0;
    int player_index = 0;

    while (1) {
        printf("Player %d's turn. Enter a word: ", player_index+1);
        scanf(" %s", word);

        is_palindrome = 1;
        for (int i = 0; i < strlen(word)/2; i++) {
            if (tolower(word[i])!= tolower(word[strlen(word)-1-i])) {
                is_palindrome = 0;
                break;
            }
        }

        if (is_palindrome) {
            printf("Word is a palindrome! Player %d scores a point.\n", player_index+1);
            players[player_index].score++;
        } else {
            printf("Word is not a palindrome.\n");
        }

        player_index = (player_index+1) % num_players;
    }

    return 0;
}