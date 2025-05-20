//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 20
#define MAX_PLAYERS 5
#define MAX_WORKOUTS 5

struct Workout {
    char name[MAX_NAME];
    int reps;
    int sets;
};

struct Player {
    char name[MAX_NAME];
    int age;
    float weight;
    struct Workout workouts[MAX_WORKOUTS];
};

void display_menu() {
    printf("1. Add player\n");
    printf("2. Add workout for player\n");
    printf("3. Display all players and their workouts\n");
    printf("4. Quit\n");
}

bool is_valid_player(struct Player players[], int total_players, char name[]) {
    for (int i=0; i<total_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return true;
        }
    }
    return false;
}

int get_player_index(struct Player players[], int total_players, char name[]) {
    for (int i=0; i<total_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_player(struct Player players[], int *total_players) {
    if (*total_players == MAX_PLAYERS) {
        printf("Cannot add more players.");
        return;
    }
    
    char name[MAX_NAME];
    int age;
    float weight;
    
    printf("Enter name: ");
    scanf("%s", name);
    
    if (is_valid_player(players, *total_players, name)) {
        printf("Player already exists\n");
        return;
    }
    
    printf("Enter age: ");
    scanf("%d", &age);
    
    printf("Enter weight: ");
    scanf("%f", &weight);
    
    struct Player p = {0};
    strcpy(p.name, name);
    p.age = age;
    p.weight = weight;
    
    players[*total_players] = p;
    (*total_players)++;
    
    printf("Player added successfully\n");
}

void add_workout(struct Player players[], int total_players, char name[]) {
    if (!is_valid_player(players, total_players, name)) {
        printf("Player does not exist\n");
        return;
    }
    
    int index = get_player_index(players, total_players, name);
    
    char workout_name[MAX_NAME];
    int reps;
    int sets;
    
    printf("Enter workout name: ");
    scanf("%s", workout_name);
    
    printf("Enter number of reps: ");
    scanf("%d", &reps);
    
    printf("Enter number of sets: ");
    scanf("%d", &sets);
    
    struct Workout w = {0};
    strcpy(w.name, workout_name);
    w.reps = reps;
    w.sets = sets;
    
    for (int i=0; i<MAX_WORKOUTS; i++) {
        if (strlen(players[index].workouts[i].name) == 0) {
            players[index].workouts[i] = w;
            printf("Workout added successfully\n");
            return;
        }
    }
    
    printf("Cannot add more workouts for player\n");
}

void display_players(struct Player players[], int total_players) {
    for (int i=0; i<total_players; i++) {
        printf("Player Name: %s\n", players[i].name);
        printf("Age: %d\n", players[i].age);
        printf("Weight: %.2f kg\n", players[i].weight);
        
        printf("Workouts done:\n");
        for (int j=0; j<MAX_WORKOUTS; j++) {
            if (strlen(players[i].workouts[j].name) > 0) {
                printf("%s - %d reps, %d sets\n", players[i].workouts[j].name, players[i].workouts[j].reps, players[i].workouts[j].sets);
            }
        }
        
        printf("\n");
    }
}

int main() {
    struct Player players[MAX_PLAYERS];
    int total_players = 0;
    int choice;
    
    do {
        display_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_player(players, &total_players);
                break;
            case 2: {
                char name[MAX_NAME];
                printf("Enter player name: ");
                scanf("%s", name);
                add_workout(players, total_players, name);
                break;
            }
            case 3:
                display_players(players, total_players);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
        
        printf("\n");
        
    } while (choice != 4);
    
    return 0;
}