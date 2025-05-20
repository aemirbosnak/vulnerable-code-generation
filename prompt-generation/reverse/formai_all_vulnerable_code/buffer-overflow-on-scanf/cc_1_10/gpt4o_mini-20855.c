//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ENCOUNTERS 5
#define MAX_NAME_LENGTH 50
#define MAX_CELESTIAL_BODIES 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char type[MAX_NAME_LENGTH];
    int difficulty;
} Encounter;

void initialize_encounters(Encounter encounters[]) {
    strcpy(encounters[0].name, "Asteroid Belt");
    strcpy(encounters[0].type, "Asteroid");
    encounters[0].difficulty = 2;

    strcpy(encounters[1].name, "Neutron Star");
    strcpy(encounters[1].type, "Star");
    encounters[1].difficulty = 5;

    strcpy(encounters[2].name, "Black Hole");
    strcpy(encounters[2].type, "Singularity");
    encounters[2].difficulty = 8;
}

void display_encounter(Encounter encounter) {
    printf("Encountered: %s (%s)\n", encounter.name, encounter.type);
    printf("Difficulty Level: %d\n", encounter.difficulty);
}

int main() {
    Encounter encounters[MAX_CELESTIAL_BODIES];
    initialize_encounters(encounters);
    
    srand(time(NULL));
    int total_difficulty = 0;
    char command[10];

    printf("Welcome to the Space Adventure!\n");
    printf("You are navigating through the vast universe...\n");

    for (int i = 0; i < MAX_ENCOUNTERS; i++) {
        printf("\nEpisode %d:\n", i + 1);
        int encounter_index = rand() % MAX_CELESTIAL_BODIES;
        Encounter current_encounter = encounters[encounter_index];
        display_encounter(current_encounter);
        
        total_difficulty += current_encounter.difficulty;
        
        if (total_difficulty < 10) {
            printf("You feel confident. Type 'explore' to continue or 'retreat' to escape: ");
        } else if (total_difficulty < 20) {
            printf("Things are getting tough. Type 'explore' to continue or 'retreat' to escape: ");
        } else {
            printf("Danger! Type 'retreat' to escape or face your fate: ");
        }
        
        scanf("%s", command);
        
        if (strcmp(command, "retreat") == 0) {
            printf("You have successfully retreated from %s.\n", current_encounter.name);
            break;
        } else if (strcmp(command, "explore") == 0) {
            printf("You bravely continue exploring...\n");
        } else {
            printf("Invalid command! Retreating by default...\n");
            break;
        }
    }

    if (total_difficulty >= 10) {
        printf("\nYou faced the challenges bravely, but the odds were against you...\n");
        printf("Game Over. Total Difficulty Faced: %d\n", total_difficulty);
    } else {
        printf("\nCongratulations! You navigated through the universe safely.\n");
        printf("Total Difficulty Faced: %d\n", total_difficulty);
    }

    return 0;
}