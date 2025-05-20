//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 20

struct player {
    char name[MAX_NAME_LEN];
    int age;
    float height;
    float weight;
    float steps;
    float calories;
};

struct game {
    int num_players;
    struct player players[MAX_PLAYERS];
};

void add_player(struct game *g) {
    if (g->num_players >= MAX_PLAYERS) {
        printf("Maximum number of players reached.\n");
        return;
    }

    printf("Enter player name: ");
    scanf("%s", g->players[g->num_players].name);

    printf("Enter player age: ");
    scanf("%d", &g->players[g->num_players].age);

    printf("Enter player height (in meters): ");
    scanf("%f", &g->players[g->num_players].height);

    printf("Enter player weight (in kilograms): ");
    scanf("%f", &g->players[g->num_players].weight);

    g->players[g->num_players].steps = 0;
    g->players[g->num_players].calories = 0;

    g->num_players++;

    printf("Player added successfully.\n");
}

void print_player(struct player p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.2f m\n", p.height);
    printf("Weight: %.2f kg\n", p.weight);
    printf("Steps: %.2f\n", p.steps);
    printf("Calories: %.2f\n", p.calories);
}

void print_players(struct game g) {
    printf("Number of players: %d\n", g.num_players);

    for (int i = 0; i < g.num_players; i++) {
        printf("\nPlayer %d:\n", i+1);
        print_player(g.players[i]);
    }
}

void update_steps(struct game *g) {
    int player_num;

    printf("Enter player number: ");
    scanf("%d", &player_num);

    if (player_num < 1 || player_num > g->num_players) {
        printf("Invalid player number.\n");
        return;
    }

    float steps;

    printf("Enter number of steps: ");
    scanf("%f", &steps);

    g->players[player_num-1].steps += steps;
    g->players[player_num-1].calories += 0.05 * g->players[player_num-1].weight * steps;

    printf("Steps updated successfully.\n");
}

void print_menu() {
    printf("\nFitness Tracker\n");
    printf("----------------\n");
    printf("1. Add player\n");
    printf("2. Print players\n");
    printf("3. Update steps\n");
    printf("4. Exit\n");
}

int main() {
    struct game g;
    g.num_players = 0;

    int choice;

    do {
        print_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_player(&g);
                break;
            case 2:
                print_players(g);
                break;
            case 3:
                update_steps(&g);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}