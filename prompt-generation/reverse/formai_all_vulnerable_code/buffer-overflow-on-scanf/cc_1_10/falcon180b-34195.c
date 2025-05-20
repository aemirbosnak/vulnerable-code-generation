//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PLAYERS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[20];
    char password[MAX_PASSWORD_LENGTH];
    int score;
} Player;

Player players[MAX_PLAYERS];
int num_players;

void init_players() {
    num_players = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].username, "");
        strcpy(players[i].password, "");
        players[i].score = 0;
    }
}

void print_scoreboard() {
    printf("Scoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].username, players[i].score);
    }
}

int main() {
    init_players();
    int player_num;
    do {
        printf("Enter number of players (up to %d): ", MAX_PLAYERS);
        scanf("%d", &player_num);
    } while (player_num < 1 || player_num > MAX_PLAYERS);

    for (int i = 0; i < player_num; i++) {
        printf("Enter username for player %d: ", i+1);
        scanf("%s", players[i].username);

        printf("Enter password for player %s: ", players[i].username);
        scanf("%s", players[i].password);

        players[i].score = password_strength(players[i].password);
        num_players++;
    }

    print_scoreboard();

    return 0;
}

int password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special_char = 1;
        }
    }

    int score = 0;
    if (length >= 8) {
        score += 1;
    }
    if (has_uppercase && has_lowercase) {
        score += 2;
    }
    if (has_number && has_special_char) {
        score += 3;
    }

    return score;
}