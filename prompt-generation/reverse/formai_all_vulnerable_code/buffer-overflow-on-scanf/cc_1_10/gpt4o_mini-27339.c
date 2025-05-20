//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 50
#define MAX_GAME_LENGTH 50
#define FILENAME "players_scores.csv"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char game[MAX_GAME_LENGTH];
    int score;
} Player;

void write_to_csv(Player players[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Unable to open file for writing");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Name,Game,Score\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%d\n", players[i].name, players[i].game, players[i].score);
    }

    fclose(file);
}

void read_from_csv() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        exit(EXIT_FAILURE);
    }

    char line[100];
    printf("Players Scores:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

void add_player_data(Player *player, int player_number) {
    printf("Player %d, enter your name: ", player_number + 1);
    fgets(player->name, MAX_NAME_LENGTH, stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline

    printf("Enter your favorite game: ");
    fgets(player->game, MAX_GAME_LENGTH, stdin);
    player->game[strcspn(player->game, "\n")] = 0; // Remove newline

    printf("Enter your score: ");
    scanf("%d", &player->score);
    getchar(); // Consume newline after integer input
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count = 0;

    printf("Welcome to the Multiplayer CSV Player Score Tracker!\n");

    while (player_count < MAX_PLAYERS) {
        add_player_data(&players[player_count], player_count);
        player_count++;
        
        char choice;
        printf("Do you want to add another player? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume newline

        if (choice != 'y') {
            break;
        }
    }

    write_to_csv(players, player_count);
    printf("Data has been written to %s\n", FILENAME);
    read_from_csv();

    return 0;
}