//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_WORKOUTS 5

struct player {
    char name[MAX_NAME_LENGTH];
    int age;
    float weight;
    float height;
    float bmi;
    float workouts[MAX_WORKOUTS];
};

void calculate_bmi(struct player* p) {
    p->bmi = p->weight / (p->height * p->height);
}

void add_workout(struct player* p, float workout) {
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        if (p->workouts[i] == 0) {
            p->workouts[i] = workout;
            break;
        }
    }
}

void print_player(struct player* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Weight: %.2fkg\n", p->weight);
    printf("Height: %.2fm\n", p->height);
    printf("BMI: %.2f\n", p->bmi);
    printf("Workouts:\n");
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        if (p->workouts[i] != 0) {
            printf("%.2fkcal\n", p->workouts[i]);
        }
    }
}

int main() {
    srand(time(NULL));

    struct player players[MAX_PLAYERS];
    int num_players = 0;

    while (num_players < MAX_PLAYERS) {
        printf("Create player %d\n", num_players + 1);

        printf("Name: ");
        scanf("%s", players[num_players].name);

        printf("Age: ");
        scanf("%d", &players[num_players].age);

        printf("Weight (kg): ");
        scanf("%f", &players[num_players].weight);

        printf("Height (m): ");
        scanf("%f", &players[num_players].height);

        calculate_bmi(&players[num_players]);

        num_players++;

        char play_again;
        printf("Add another player? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again != 'y' && play_again != 'Y') {
            break;
        }
    }

    while (1) {
        printf("\nMenu\n");
        printf("1. Add workout\n");
        printf("2. View player\n");
        printf("3. View leaderboard\n");
        printf("4. Quit\n");

        int choice;
        printf("\nEnter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int player_num;
            printf("\nEnter player number (1-%d): ", num_players);
            scanf("%d", &player_num);
            if (player_num < 1 || player_num > num_players) {
                printf("Invalid player number\n");
                break;
            }

            float workout = (float) (rand() % 300 + 50); // random workout between 50 and 350 kcal
            add_workout(&players[player_num-1], workout);
            printf("%.2fkcal workout added for player %d\n", workout, player_num);
            break;
        }
        case 2: {
            int player_num;
            printf("\nEnter player number (1-%d): ", num_players);
            scanf("%d", &player_num);
            if (player_num < 1 || player_num > num_players) {
                printf("Invalid player number\n");
                break;
            }

            printf("\nPlayer %d\n", player_num);
            print_player(&players[player_num-1]);
            break;
        }
        case 3: {
            printf("\nLeaderboard\n");
            printf("Rank  Name           Total Calories\n");

            // calculate total calories for each player
            float total_calories[MAX_PLAYERS] = {0};
            for (int i = 0; i < num_players; i++) {
                for (int j = 0; j < MAX_WORKOUTS; j++) {
                    total_calories[i] += players[i].workouts[j];
                }
            }

            // bubble sort players by total calories
            for (int i = 0; i < num_players; i++) {
                for (int j = 0; j < num_players - i - 1; j++) {
                    if (total_calories[j] < total_calories[j+1]) {
                        float temp_calories = total_calories[j];
                        total_calories[j] = total_calories[j+1];
                        total_calories[j+1] = temp_calories;

                        struct player temp_player = players[j];
                        players[j] = players[j+1];
                        players[j+1] = temp_player;
                    }
                }
            }

            for (int i = 0; i < num_players; i++) {
                printf("%-6d%-15s%.2f\n", i+1, players[i].name, total_calories[i]);
            }

            break;
        }
        case 4:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}