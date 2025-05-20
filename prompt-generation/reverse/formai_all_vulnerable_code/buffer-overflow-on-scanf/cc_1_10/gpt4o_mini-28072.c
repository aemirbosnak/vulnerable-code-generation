//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_TREASURES 10
#define BOARD_SIZE 5

typedef struct {
    int id;
    char name[20];
    int treasures;
} Player;

typedef struct {
    int x;
    int y;
    int value;
    int collected;
} Treasure;

void initialize_treasures(Treasure treasures[], int count) {
    for (int i = 0; i < count; i++) {
        treasures[i].x = rand() % BOARD_SIZE;
        treasures[i].y = rand() % BOARD_SIZE;
        treasures[i].value = (rand() % 10) + 1; // treasure value between 1 and 10
        treasures[i].collected = 0; // not collected at start
    }
}

void display_board(Treasure treasures[], int count, Player players[], int player_count) {
    printf("\nCurrent Board:\n");
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            int found = 0;
            for (int k = 0; k < count; k++) {
                if (treasures[k].x == i && treasures[k].y == j && !treasures[k].collected) {
                    printf(" T ");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf(" . ");
            }
        }
        printf("\n");
    }

    printf("\nPlayers:\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player %d (%s): %d treasures collected\n", players[i].id, players[i].name, players[i].treasures);
    }
    printf("\n");
}

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

void collect_treasure(Player *player, Treasure *treasure) {
    player->treasures += treasure->value;
    treasure->collected = 1; // mark as collected
    printf("%s collected a treasure worth %d!\n", player->name, treasure->value);
}

void play_turn(Player players[], int player_index, Treasure treasures[], int treasure_count) {
    Player *current_player = &players[player_index];
    printf("\nIt's %s's turn!\n", current_player->name);
    
    int closest_dist = __INT_MAX__;
    Treasure *closest_treasure = NULL;

    for (int i = 0; i < treasure_count; i++) {
        if (!treasures[i].collected) {
            int dist = distance(0, 0, treasures[i].x, treasures[i].y); // player is always at (0, 0)
            if (dist < closest_dist) {
                closest_dist = dist;
                closest_treasure = &treasures[i];
            }
        }
    }

    if (closest_treasure) {
        collect_treasure(current_player, closest_treasure);
    } else {
        printf("No treasures left for %s to collect!\n", current_player->name);
    }
}

int main() {
    srand(time(NULL));

    Player players[MAX_PLAYERS];
    Treasure treasures[MAX_TREASURES];
    int player_count, turn_count = 0;

    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);

    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    for (int i = 0; i < player_count; i++) {
        players[i].id = i + 1;
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].treasures = 0;
    }

    initialize_treasures(treasures, MAX_TREASURES);

    while (turn_count < player_count) {
        display_board(treasures, MAX_TREASURES, players, player_count);
        play_turn(players, turn_count % player_count, treasures, MAX_TREASURES);
        turn_count++;
    }

    printf("\nGame Over! Final Scores:\n");
    for (int i = 0; i < player_count; i++) {
        printf("%s collected a total of %d treasures.\n", players[i].name, players[i].treasures);
    }

    return 0;
}