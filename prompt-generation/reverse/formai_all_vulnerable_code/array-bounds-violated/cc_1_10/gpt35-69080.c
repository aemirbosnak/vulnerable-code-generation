//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void explore(int planet);
void fight(int enemy);

int main() {
    int planet_choice, enemy_choice;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to Procedural Space Adventure!\n");
    printf("Choose a planet to explore:\n");

    // randomly generate planet names and stats
    for(int i = 1; i <= 5; i++) {
        int planet_name_length = rand() % 10 + 5; // generate planet name length between 5-14
        char planet_name[planet_name_length];
        for(int j = 0; j < planet_name_length; j++) {
            planet_name[j] = 'A' + rand() % 26; // generate random uppercase letter
        }
        planet_name[planet_name_length] = '\0';

        int planet_difficulty = rand() % 5 + 1; // generate planet difficulty between 1-5

        printf("%d. %s (Difficulty: %d)\n", i, planet_name, planet_difficulty);
    }

    printf("Enter your choice: ");
    scanf("%d", &planet_choice);

    explore(planet_choice);

    printf("You have encountered an enemy ship!\n");
    printf("Choose a weapon to fight:\n");
    printf("1. Laser Cannon\n2. Missiles\n3. Shields\n");

    // randomly generate enemy ship types and stats
    enemy_choice = rand() % 3 + 1; // generate enemy type between 1-3

    fight(enemy_choice);

    printf("Congratulations, you have won the battle!\n");
    printf("Thanks for playing Procedural Space Adventure.");

    return 0;
}

void explore(int planet) {
    printf("Exploring planet %d...\n", planet);
    // code for exploring
}

void fight(int enemy) {
    printf("Fighting enemy...\n");
    // code for fighting
}