//Falcon-180B DATASET v1.0 Category: Table Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int score;
} Player;

void print_player(Player p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Score: %d\n", p.score);
}

int main() {
    srand(time(NULL));
    int num_players;
    printf("Enter the number of players (2-6): ");
    scanf("%d", &num_players);
    if (num_players < 2 || num_players > 6) {
        printf("Invalid number of players.\n");
        return 1;
    }
    Player players[num_players];
    char input[100];
    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", input);
        strcpy(players[i].name, input);
        printf("Enter player %d's age: ", i + 1);
        scanf("%d", &players[i].age);
        printf("Enter player %d's score: ", i + 1);
        scanf("%d", &players[i].score);
    }
    int current_player = 0;
    while (1) {
        printf("Current player: %s\n", players[current_player].name);
        printf("Current score: %d\n", players[current_player].score);
        printf("Press enter to roll the dice.\n");
        getchar();
        int dice_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_roll);
        players[current_player].score += dice_roll;
        if (players[current_player].score >= 100) {
            printf("Player %s wins!\n", players[current_player].name);
            break;
        }
        current_player = (current_player + 1) % num_players;
    }
    return 0;
}