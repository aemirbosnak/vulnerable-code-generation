//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_SCENES 5
#define MAX_SCRIPT_LENGTH 256

typedef struct Scene {
    char description[MAX_SCRIPT_LENGTH];
    int year;
} Scene;

typedef struct Character {
    char name[30];
    char dialogue[MAX_SCRIPT_LENGTH];
    int year_of_birth;
    int year_of_death;
} Character;

// Function prototypes
void display_scene(Scene *scene);
void display_character_dialogue(Character *character);
int time_travel(int *current_year, int target_year);

int main() {
    // Setting up the story scenes
    Scene scenes[MAX_SCENES] = {
        {"In fair Verona, where we lay our scene.", 1595},
        {"A pair of star-cross'd lovers take their life.", 1595},
        {"The consequence of their love was bitter feud.", 1596},
        {"For never was a story of more woe than this of Juliet and her Romeo.", 1596},
        {"Thus with a kiss I die...", 1596}
    };

    // Setting up the characters
    Character romeo = {"Romeo", "But, soft! What light through yonder window breaks?", 1567, 1596};
    Character juliet = {"Juliet", "O Romeo, Romeo! Wherefore art thou Romeo?", 1570, 1596};

    int current_year = 1595;
    int target_year;
    
    printf("Welcome to the Time Travel Simulator: Romeo and Juliet\n");
    printf("Current year: %d\n\n", current_year);
    
    for (int i = 0; i < MAX_SCENES; i++) {
        display_scene(&scenes[i]);
        sleep(2); // Pause to simulate time passing
        
        // Players' decision to time travel
        if (i == 0) {
            printf("Do you wish to travel to a different year? Enter year (1590-1600 or -1 to continue): ");
            scanf("%d", &target_year);
            if (target_year != -1 && target_year >= 1590 && target_year <= 1600) {
                time_travel(&current_year, target_year);
            }
        }
        
        if (i == 1) {
            display_character_dialogue(&romeo);
        } else if (i == 2) {
            display_character_dialogue(&juliet);
        }
    }
    
    printf("And they lived happily ever after...\n");
    
    return 0;
}

void display_scene(Scene *scene) {
    printf("Scene: Year %d\n", scene->year);
    printf("%s\n\n", scene->description);
}

void display_character_dialogue(Character *character) {
    printf("%s: \"%s\"\n\n", character->name, character->dialogue);
}

int time_travel(int *current_year, int target_year) {
    printf("Time traveling from %d to %d...\n", *current_year, target_year);
    sleep(2); // Simulate the time travel delay
    *current_year = target_year;
    printf("You have traveled to the year %d!\n\n", *current_year);
    return 0; 
}