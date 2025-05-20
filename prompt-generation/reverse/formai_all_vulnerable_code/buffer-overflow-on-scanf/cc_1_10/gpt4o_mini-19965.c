//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_GAMES_PER_PLAYER 100

typedef struct {
    char name[50];
    int scores[MAX_GAMES_PER_PLAYER];
    int game_count;
} Player;

void initialize_players(Player players[], int *player_count) {
    *player_count = 0;
}

void add_player(Player players[], int *player_count, const char *name) {
    if (*player_count < MAX_PLAYERS) {
        strcpy(players[*player_count].name, name);
        players[*player_count].game_count = 0;
        (*player_count)++;
    } else {
        printf("Maximum players reached!\n");
    }
}

void record_score(Player *player, int score) {
    if (player->game_count < MAX_GAMES_PER_PLAYER) {
        player->scores[player->game_count] = score;
        player->game_count++;
    } else {
        printf("Maximum games recorded for player %s\n", player->name);
    }
}

void analyze_logs(Player players[], int player_count) {
    int total_games = 0;
    int total_score = 0;
    int highest_score = 0;
    char highest_scorer[50];

    for (int i = 0; i < player_count; i++) {
        total_games += players[i].game_count;
        for (int j = 0; j < players[i].game_count; j++) {
            total_score += players[i].scores[j];
            if (players[i].scores[j] > highest_score) {
                highest_score = players[i].scores[j];
                strcpy(highest_scorer, players[i].name);
            }
        }
    }

    if (total_games == 0) {
        printf("No games played yet!\n");
        return;
    }

    float average_score = (float)total_score / total_games;
    printf("Total players: %d\n", player_count);
    printf("Total games played: %d\n", total_games);
    printf("Total score recorded: %d\n", total_score);
    printf("Average score per game: %.2f\n", average_score);
    printf("Highest score: %d by %s\n", highest_score, highest_scorer);
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count;
    char choice[10];

    initialize_players(players, &player_count);

    while (1) {
        printf("1. Add Player\n2. Record Score\n3. Analyze Logs\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            char name[50];
            printf("Enter player name: ");
            scanf("%s", name);
            add_player(players, &player_count, name);
        } 
        else if (strcmp(choice, "2") == 0) {
            char name[50];
            int score;
            printf("Enter player name: ");
            scanf("%s", name);
            printf("Enter score: ");
            scanf("%d", &score);

            int found = 0;
            for (int i = 0; i < player_count; i++) {
                if (strcmp(players[i].name, name) == 0) {
                    record_score(&players[i], score);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Player not found!\n");
            }
        } 
        else if (strcmp(choice, "3") == 0) {
            analyze_logs(players, player_count);
        } 
        else if (strcmp(choice, "4") == 0) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}