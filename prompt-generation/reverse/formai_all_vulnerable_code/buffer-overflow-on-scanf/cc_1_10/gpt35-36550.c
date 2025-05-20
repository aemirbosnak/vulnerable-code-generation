//FormAI DATASET v1.0 Category: Database simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_PLAYERS 5
#define MAX_NAME_LENGTH 20
#define MAX_AGE 150
#define MAX_SCORE 1000

struct Player {
    char name[MAX_NAME_LENGTH];
    int age;
    int score;
};

int n_players = 0;
struct Player players[MAX_PLAYERS];

void add_player() {
    if(n_players == MAX_PLAYERS) {
        printf("Sorry, maximum number of players reached! Cannot add new player.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", players[n_players].name);

    printf("Enter age: ");
    scanf("%d", &players[n_players].age);

    printf("Enter score: ");
    scanf("%d", &players[n_players].score);

    printf("New player added successfully!\n");
    n_players++;
}

void print_player(struct Player p) {
    printf("%s, %d years old, score: %d\n", p.name, p.age, p.score);
}

void print_players() {
    printf("List of players:\n");
    for(int i=0; i<n_players; i++) {
        printf("%d. ", i+1);
        print_player(players[i]);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Multiplayer Database Simulation Game!\n");

    while(1) {
        printf("\nCommands:\n");
        printf("1. Add new player\n");
        printf("2. Print all players\n");
        printf("3. Exit\n");
        printf("Enter command number: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_player(); break;
            case 2: print_players(); break;
            case 3: exit(0); break;
            default: printf("Invalid command!\n"); break;
        }
    }

    return 0;
}