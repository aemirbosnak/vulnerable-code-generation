//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_SEQUENCE_LENGTH 1000
#define MAX_SEQUENCE_SIZE 20
#define MAX_SEQUENCE_TYPES 5

typedef struct {
    char name[20];
    char sequence[MAX_SEQUENCE_LENGTH];
    int sequence_length;
    int sequence_size;
    int sequence_type;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

void init_player(Player *player) {
    player->sequence_length = rand() % MAX_SEQUENCE_LENGTH + 1;
    player->sequence_size = rand() % MAX_SEQUENCE_SIZE + 1;
    player->sequence_type = rand() % MAX_SEQUENCE_TYPES;
    for (int i = 0; i < player->sequence_length; i++) {
        player->sequence[i] = rand() % 4 + 'A';
    }
}

void print_player(Player player) {
    printf("Name: %s\n", player.name);
    printf("Sequence: %s\n", player.sequence);
    printf("Sequence Length: %d\n", player.sequence_length);
    printf("Sequence Size: %d\n", player.sequence_size);
    printf("Sequence Type: %d\n", player.sequence_type);
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("1. Add player\n2. Print players\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (num_players >= MAX_PLAYERS) {
                    printf("Maximum number of players reached\n");
                } else {
                    printf("Enter player name: ");
                    scanf("%s", players[num_players].name);
                    init_player(&players[num_players]);
                    num_players++;
                }
                break;
            case 2:
                for (int i = 0; i < num_players; i++) {
                    print_player(players[i]);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);
    return 0;
}