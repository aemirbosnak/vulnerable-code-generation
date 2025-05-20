//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int score;
} player_t;

int main() {
    // Get the number of players
    int num_players;
    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    // Create an array of players
    player_t players[num_players];

    // Get the information for each player
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        printf("Enter the score of player %d: ", i + 1);
        scanf("%d", &players[i].score);
    }

    // Write the player information to a CSV file
    FILE *fp = fopen("players.csv", "w");
    fprintf(fp, "Name,Score\n");
    for (int i = 0; i < num_players; i++) {
        fprintf(fp, "%s,%d\n", players[i].name, players[i].score);
    }
    fclose(fp);

    // Read the player information from the CSV file
    fp = fopen("players.csv", "r");
    char line[1024];
    while (fgets(line, 1024, fp)) {
        char *name = strtok(line, ",");
        char *score = strtok(NULL, ",");
        printf("%s: %s\n", name, score);
    }
    fclose(fp);

    // Free the memory allocated for the player names
    for (int i = 0; i < num_players; i++) {
        free(players[i].name);
    }

    return 0;
}