//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[50];
    int score;
} Player;

void add_player(Player players[], int *num_players);
void print_players(Player players[], int num_players);
void search_players(Player players[], int num_players);

int main() {
    Player players[100];
    int num_players = 0;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add player\n");
        printf("2. Print all players\n");
        printf("3. Search players\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_player(players, &num_players);
                break;
            case 2:
                print_players(players, num_players);
                break;
            case 3:
                search_players(players, num_players);
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}

void add_player(Player players[], int *num_players) {
    Player new_player;

    printf("Enter player ID: ");
    scanf("%d", &new_player.id);

    printf("Enter player name: ");
    scanf("%s", new_player.name);

    printf("Enter player score: ");
    scanf("%d", &new_player.score);

    players[*num_players] = new_player;
    *num_players += 1;

    printf("Player added successfully\n");
}

void print_players(Player players[], int num_players) {
    if(num_players == 0) {
        printf("No players in database\n");
        return;
    }

    printf("ID\tName\tScore\n");
    for(int i = 0; i < num_players; i++) {
        printf("%d\t%s\t%d\n", players[i].id, players[i].name, players[i].score);
    }
}

void search_players(Player players[], int num_players) {
    if(num_players == 0) {
        printf("No players in database\n");
        return;
    }

    int choice;
    bool found_player = false;

    printf("Search by:\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            int search_id;
            printf("Enter player ID to search: ");
            scanf("%d", &search_id);

            for(int i = 0; i < num_players; i++) {
                if(players[i].id == search_id) {
                    printf("ID\tName\tScore\n");
                    printf("%d\t%s\t%d\n", players[i].id, players[i].name, players[i].score);
                    found_player = true;
                    break;
                }
            }

            if(!found_player) {
                printf("Player with ID %d not found\n", search_id);
            }
            break;
        }
        case 2: {
            char search_name[50];
            printf("Enter player name to search: ");
            scanf("%s", search_name);

            for(int i = 0; i < num_players; i++) {
                if(strcmp(players[i].name, search_name) == 0) {
                    printf("ID\tName\tScore\n");
                    printf("%d\t%s\t%d\n", players[i].id, players[i].name, players[i].score);
                    found_player = true;
                }
            }

            if(!found_player) {
                printf("Player with name %s not found\n", search_name);
            }
            break;
        }
        default:
            printf("Invalid choice\n");
            break;
    }
}