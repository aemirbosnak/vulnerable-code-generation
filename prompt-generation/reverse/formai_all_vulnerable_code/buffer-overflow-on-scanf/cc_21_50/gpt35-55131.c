//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_EXERCISES 5

struct Exercise {
    int caloriesBurned;
    int duration; // in minutes
};

struct Player {
    char name[MAX_NAME_LENGTH];
    struct Exercise exercises[MAX_EXERCISES];
    int numExercises;
    int totalCaloriesBurned;
};

int main() {
    struct Player players[MAX_PLAYERS];
    int numPlayers = 0;
    int i, j;

    int option;
    do {
        printf("=====================================\n");
        printf("            FITNESS TRACKER           \n");
        printf("=====================================\n");
        printf("1. Add player\n");
        printf("2. Add exercise for player\n");
        printf("3. Show exercise history for player\n");
        printf("4. Show leaderboard\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                if(numPlayers >= MAX_PLAYERS) {
                    printf("Maximum number of players reached!\n");
                } else {
                    printf("Enter player name: ");
                    scanf("%s", players[numPlayers].name);
                    players[numPlayers].totalCaloriesBurned = 0;
                    players[numPlayers].numExercises = 0;
                    numPlayers++;
                    printf("Player added successfully!\n");
                }
                break;
            case 2:
                if(numPlayers == 0) {
                    printf("No players added yet!\n");
                } else {
                    printf("Enter player name: ");
                    char name[MAX_NAME_LENGTH];
                    scanf("%s", name);
                    struct Player* player = NULL;
                    for(i = 0; i < numPlayers; i++) {
                        if(strcmp(players[i].name, name) == 0) {
                            player = &players[i];
                            break;
                        }
                    }
                    if(player == NULL) {
                        printf("No player with that name found!\n");
                    } else {
                        if(player->numExercises >= MAX_EXERCISES) {
                            printf("Maximum number of exercises reached!\n");
                        } else {
                            printf("Enter calories burned: ");
                            scanf("%d", &(player->exercises[player->numExercises].caloriesBurned));
                            printf("Enter duration (in minutes): ");
                            scanf("%d", &(player->exercises[player->numExercises].duration));
                            player->totalCaloriesBurned += player->exercises[player->numExercises].caloriesBurned;
                            player->numExercises++;
                            printf("Exercise added successfully!\n");
                        }
                    }
                }
                break;
            case 3:
                if(numPlayers == 0) {
                    printf("No players added yet!\n");
                } else {
                    printf("Enter player name: ");
                    char name[MAX_NAME_LENGTH];
                    scanf("%s", name);
                    struct Player* player = NULL;
                    for(i = 0; i < numPlayers; i++) {
                        if(strcmp(players[i].name, name) == 0) {
                            player = &players[i];
                            break;
                        }
                    }
                    if(player == NULL) {
                        printf("No player with that name found!\n");
                    } else {
                        printf("Exercise History for %s:\n", player->name);
                        printf("---------------------------------------------------------\n");
                        printf("|   Exercise   |  Calories Burned  |  Duration (mins)  |\n");
                        printf("---------------------------------------------------------\n");
                        for(j = 0; j < player->numExercises; j++) {
                            printf("|  Exercise %d  |        %d         |        %d          |\n", j+1, player->exercises[j].caloriesBurned, player->exercises[j].duration);
                        }
                        printf("---------------------------------------------------------\n");
                        printf("|    Total     |        %d         |                   |\n", player->totalCaloriesBurned);
                        printf("---------------------------------------------------------\n");
                    }
                }
                break;
            case 4:
                if(numPlayers == 0) {
                    printf("No players added yet!\n");
                } else {
                    printf("Leaderboard:\n");
                    printf("---------------------------------------\n");
                    printf("|  Player  |  Total Calories Burned   |\n");
                    printf("---------------------------------------\n");
                    // sort players based on total calories burned
                    for(i = 0; i < numPlayers-1; i++) {
                        for(j = i+1; j < numPlayers; j++) {
                            if(players[i].totalCaloriesBurned < players[j].totalCaloriesBurned) {
                                struct Player temp = players[i];
                                players[i] = players[j];
                                players[j] = temp;
                            }
                        }
                    }
                    for(i = 0; i < numPlayers; i++) {
                        printf("|   %s   |            %d            |\n", players[i].name, players[i].totalCaloriesBurned);
                    }
                    printf("---------------------------------------\n");
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option selected!\n");
        }
    } while(option != 5);

    return 0;
}