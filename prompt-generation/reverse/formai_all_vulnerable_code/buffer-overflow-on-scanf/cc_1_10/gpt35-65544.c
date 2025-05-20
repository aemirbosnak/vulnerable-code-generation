//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("\n\n\t\tProcedural Space Adventure\n\n");

    // Introduction and Story
    printf("Welcome to Procedural Space Adventure.\n\n");
    printf("You work for a company that has built a spaceship capable of travelling through our solar system.\n");
    printf("Your mission is to explore and discover new planets and gather resources while avoiding any dangers in space.\n\n");

    // Planet Generation
    int planet_count;
    printf("How many planets do you want to visit today? (1-7)\n");
    scanf("%d", &planet_count);

    int planets_visited = 0;
    while (planets_visited < planet_count) {
        printf("Travelling to planet %d...\n\n", planets_visited + 1);

        // Random Planet Generation
        int oxygen = rand() % 100;
        int water = rand() % 100;
        int temperature = rand() % 100;
        printf("Planet %d Properties:\n", planets_visited + 1);
        printf("Oxygen Level: %d%%\n", oxygen);
        printf("Water Level: %d%%\n", water);
        printf("Temperature: %d%%\n", temperature);

        // Resource Gathering and Scanning
        printf("\nScanning for resources...\n");
        if (oxygen >= 50 && water >= 50 && temperature >= 50) {
            printf("Planet %d has good resources. Let's gather them!\n", planets_visited + 1);
        } else {
            printf("The resources on planet %d are not sufficient. Let's move on!\n", planets_visited + 1);
            planets_visited++;
            continue;
        }

        int oxygen_level = rand() % 100;
        int water_level = rand() % 100;
        printf("\nGathering resources...\n");
        printf("Oxygen: %d liters\n", oxygen_level);
        printf("Water: %d liters\n", water_level);

        // Mini Game
        printf("\n\nOh no! An asteroid field is heading our way!\n");
        printf("Quick! Use your spaceship controls to dodge the asteroids and keep the spaceship safe!\n");

        int spaceship_health = 100;
        int asteroid_count = rand() % 20 + 1;
        while (asteroid_count > 0) {
            printf("\nAsteroid %d is approaching...\n", asteroid_count);
            int user_choice = 0;
            printf("What direction do you want to turn? (1 - Left | 2 - Right)\n");
            scanf("%d", &user_choice);
            if (user_choice == 1) {
                printf("Spaceship turned left!\n");
            } else if (user_choice == 2) {
                printf("Spaceship turned right!\n");
            } else {
                printf("Invalid choice! Spaceship hit an asteroid and took damage.\n");
                spaceship_health -= 20;
            }
            asteroid_count--;
        }

        if (spaceship_health <= 0) {
            printf("\n\nOh no! Spaceship health is low! Mission failed!\n");
            break;
        } else {
            printf("\n\nSpaceship is safe! On to the next planet!\n");
            planets_visited++;
        }
    }

    return 0;
}