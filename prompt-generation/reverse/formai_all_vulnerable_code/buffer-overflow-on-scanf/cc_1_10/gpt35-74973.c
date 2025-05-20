//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    char message[MAX_MESSAGE_LENGTH];
} Player;

int get_num_players(void);
void initialize_players(Player players[], int num_players);
void display_player_names(Player players[], int num_players);
void send_message(Player sender, Player players[], int num_players);

int main(void) {
    int num_players = get_num_players();
    Player players[MAX_PLAYERS];
    initialize_players(players, num_players);

    printf("Let's begin!\n");
    printf("------------------------------\n");

    while (1) {
        for (int i = 0; i < num_players; i++) {
            printf("%s's turn!\n", players[i].name);
            display_player_names(players, num_players);
            send_message(players[i], players, num_players);
            printf("\n");
        }
    }
    return 0;
}

int get_num_players(void) {
    int num_players;
    do {
        printf("Enter number of players (1-10): ");
        scanf("%d", &num_players);
    } while (num_players < 1 || num_players > MAX_PLAYERS);
    return num_players;
}

void initialize_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].message[0] = '\0';
    }
}

void display_player_names(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s ", players[i].name);
    }
    printf("\n");
}

void send_message(Player sender, Player players[], int num_players) {
    char recipient_name[MAX_NAME_LENGTH];
    printf("%s, who do you want to send a message to? ", sender.name);
    scanf("%s", recipient_name);

    int recipient_index = -1;
    for (int i = 0; i < num_players; i++) {
        if (strcmp(players[i].name, recipient_name) == 0) {
            recipient_index = i;
            break;
        }
    }

    if (recipient_index == -1) {
        printf("Recipient not found.\n");
        return;
    }

    char message[MAX_MESSAGE_LENGTH];
    printf("%s, what message do you want to send? ", sender.name);
    scanf(" %[^\n]s", message);

    printf("%s sent \"%s\" to %s\n", sender.name, message, players[recipient_index].name);

    strcpy(players[recipient_index].message, message);
}