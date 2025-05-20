//Falcon-180B DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>

#define MAX_PLAYERS 4
#define MAX_ROUNDS 10

typedef struct {
    char name[20];
    int chips;
} Player;

void init_player(Player* player, char* name, int chips) {
    strcpy(player->name, name);
    player->chips = chips;
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players;
    char input[100];

    // Initialize players
    num_players = 0;
    while (num_players < MAX_PLAYERS) {
        printf("Enter name of player %d: ", num_players + 1);
        scanf("%s", input);
        init_player(&players[num_players], input, 100);
        num_players++;
    }

    // Play game
    int current_player = 0;
    int round = 1;
    while (round <= MAX_ROUNDS) {
        printf("Round %d\n", round);
        printf("Current player: %s\n", players[current_player].name);
        printf("Chips: %d\n", players[current_player].chips);

        char action[10];
        printf("Enter action (hit/stand): ");
        scanf("%s", action);

        if (strcmp(action, "hit") == 0) {
            players[current_player].chips -= 10;
            printf("%s hits and loses 10 chips.\n", players[current_player].name);
        } else if (strcmp(action, "stand") == 0) {
            printf("%s stands.\n", players[current_player].name);
        } else {
            printf("Invalid action.\n");
        }

        current_player = (current_player + 1) % MAX_PLAYERS;
        round++;
    }

    // Print winner
    int max_chips = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].chips > max_chips) {
            max_chips = players[i].chips;
        }
    }

    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].chips == max_chips) {
            printf("Player %s wins with %d chips!\n", players[i].name, max_chips);
        }
    }

    return 0;
}