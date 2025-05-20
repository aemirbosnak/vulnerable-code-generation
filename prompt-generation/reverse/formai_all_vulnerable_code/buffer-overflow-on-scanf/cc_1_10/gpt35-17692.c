//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 10

typedef struct {
    char name[20];
    int age;
    float height;
    float weight;
} Player;

Player players[MAX_PLAYERS];
int num_players = 0;

float calculate_bmi(float height, float weight) {
    return weight / (height * height);
}

void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Cannot add more players.\n");
        return;
    }

    Player p;
    printf("Enter player name: ");
    scanf("%s", p.name);
    printf("Enter player age: ");
    scanf("%d", &p.age);
    printf("Enter player height: ");
    scanf("%f", &p.height);
    printf("Enter player weight: ");
    scanf("%f", &p.weight);

    players[num_players++] = p;

    printf("%s added successfully.\n", p.name);
}

void display_players() {
    if (num_players == 0) {
        printf("No players added yet.\n");
        return;
    }

    printf("Players:\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Age", "Height", "Weight");
    for (int i = 0; i < num_players; i++) {
        Player p = players[i];
        printf("%-20s %-10d %-10.2f %-10.2f\n", p.name, p.age, p.height, p.weight);
    }
}

void display_bmi_rankings() {
    if (num_players == 0) {
        printf("No players added yet.\n");
        return;
    }

    printf("BMI Rankings:\n");
    printf("%-20s %-10s\n", "Name", "BMI");
    for (int i = 0; i < num_players; i++) {
        Player p = players[i];
        float bmi = calculate_bmi(p.height, p.weight);
        printf("%-20s %-10.2f\n", p.name, bmi);
    }
}

void handle_menu_choice(int choice) {
    switch (choice) {
        case 1:
            add_player();
            break;
        case 2:
            display_players();
            break;
        case 3:
            display_bmi_rankings();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void display_menu() {
    printf("1. Add Player\n");
    printf("2. Display Players\n");
    printf("3. Display BMI Rankings\n");
    printf("4. Exit Program\n");
    printf("Your choice: ");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        handle_menu_choice(choice);
    }
    return 0;
}