//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int credits = 100;
    int weapon_power;
    int enemy_health;
    int enemy_damage;
    int planet_health;
    int planet_population;
    int planet_resources;
    int planet_defense;
    int planet_offense;
    int event_type;
    int event_result;
    int event_planet_index;
    char event_description[50];
    char planet_name[50];
    char player_name[50];

    printf("Welcome to the Space Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", &player_name);
    printf("You are %s, a space adventurer!\n", player_name);

    while (health > 0) {
        system("clear");
        printf("You have %d health and %d credits.\n", health, credits);
        printf("What do you want to do?\n");
        printf("1. Explore a planet.\n");
        printf("2. Buy a weapon.\n");
        printf("3. Save game.\n");
        printf("4. Quit.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the planet: ");
                scanf("%s", &planet_name);
                event_type = rand() % 4;
                switch (event_type) {
                    case 0:
                        printf("You find a hidden treasure on the planet and gain %d credits!\n", rand() % 50 + 1);
                        credits += rand() % 50 + 1;
                        break;
                    case 1:
                        printf("You encounter a friendly alien who heals you by %d health!\n", rand() % 20 + 1);
                        health += rand() % 20 + 1;
                        break;
                    case 2:
                        printf("You discover a new technology and increase your weapon power by %d!\n", rand() % 10 + 1);
                        weapon_power += rand() % 10 + 1;
                        break;
                    case 3:
                        printf("You stumble upon a dangerous monster and lose %d health!\n", rand() % 10 + 1);
                        health -= rand() % 10 + 1;
                        break;
                }
                break;
            case 2:
                printf("Enter the name of the weapon: ");
                scanf("%s", &planet_name);
                weapon_power += rand() % 10 + 1;
                credits -= rand() % 20 + 1;
                break;
            case 3:
                printf("Game saved.\n");
                break;
            case 4:
                printf("Goodbye, %s!\n", player_name);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    printf("Game over. Your final score is %d.\n", health + credits);
    return 0;
}