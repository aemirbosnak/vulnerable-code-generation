//GPT-4o-mini DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_MISSION_LENGTH 50

typedef struct {
    char name[20];
    int resources;
    int danger_level;
} Planet;

typedef struct {
    char mission_description[MAX_MISSION_LENGTH];
    int required_resources;
    int mission_duration; // in days
} Mission;

typedef struct {
    Planet planets[MAX_PLANETS];
    int planet_count;
    Mission current_mission;
    int resources;
} SpaceAdventure;

void initialize_planets(SpaceAdventure *adventure) {
    strcpy(adventure->planets[0].name, "Zyphor");
    adventure->planets[0].resources = 50;
    adventure->planets[0].danger_level = 2;

    strcpy(adventure->planets[1].name, "Gorath");
    adventure->planets[1].resources = 30;
    adventure->planets[1].danger_level = 3;

    strcpy(adventure->planets[2].name, "Veridia");
    adventure->planets[2].resources = 60;
    adventure->planets[2].danger_level = 1;

    strcpy(adventure->planets[3].name, "Xylon");
    adventure->planets[3].resources = 10;
    adventure->planets[3].danger_level = 4;

    strcpy(adventure->planets[4].name, "Helion");
    adventure->planets[4].resources = 25;
    adventure->planets[4].danger_level = 2;

    adventure->planet_count = MAX_PLANETS;
}

void assess_planet(SpaceAdventure *adventure) {
    for (int i = 0; i < adventure->planet_count; i++) {
        Planet p = adventure->planets[i];
        printf("Planet: %s\n", p.name);
        printf("Resources: %d\n", p.resources);
        printf("Danger Level: %d\n\n", p.danger_level);
    }
}

void select_mission(SpaceAdventure *adventure) {
    int planet_index;
    printf("Select a planet for your mission (0 to %d): ", adventure->planet_count - 1);
    scanf("%d", &planet_index);

    if (planet_index < 0 || planet_index >= adventure->planet_count) {
        printf("Invalid planet selection!\n");
        return;
    }

    Planet selected_planet = adventure->planets[planet_index];
    adventure->current_mission.required_resources = selected_planet.resources / 2;
    adventure->current_mission.mission_duration = selected_planet.danger_level * 2;
    snprintf(adventure->current_mission.mission_description, MAX_MISSION_LENGTH,
             "Retrieve resources from %s", selected_planet.name);
    
    printf("Mission Selected: %s\n", adventure->current_mission.mission_description);
    printf("Required Resources: %d\n", adventure->current_mission.required_resources);
    printf("Mission Duration: %d days\n\n", adventure->current_mission.mission_duration);
}

int perform_mission(SpaceAdventure *adventure) {
    if (adventure->resources < adventure->current_mission.required_resources) {
        printf("Not enough resources to perform the mission!\n");
        return 0;
    }

    adventure->resources -= adventure->current_mission.required_resources;
    printf("Mission in progress to retrieve resources...\n");
    sleep(adventure->current_mission.mission_duration); // simulate time passing
    adventure->resources += adventure->current_mission.required_resources * 2; // resource gain
    printf("Mission completed! Resources acquired: %d\n", adventure->current_mission.required_resources * 2);
    return 1;
}

void status_report(SpaceAdventure *adventure) {
    printf("Current Resources: %d\n", adventure->resources);
    printf("Current Mission: %s\n", adventure->current_mission.mission_description);
    printf("Mission Duration Left: %d days\n\n", adventure->current_mission.mission_duration);
}

int main() {
    SpaceAdventure adventure = { .resources = 100 };
    initialize_planets(&adventure);
    
    int command;
    do {
        printf("1. Assess Planets\n");
        printf("2. Select Mission\n");
        printf("3. Perform Mission\n");
        printf("4. Status Report\n");
        printf("0. Exit\n");
        printf("Choose an action: ");
        scanf("%d", &command);
        
        switch (command) {
            case 1:
                assess_planet(&adventure);
                break;
            case 2:
                select_mission(&adventure);
                break;
            case 3:
                if (adventure.current_mission.mission_duration > 0) {
                    if (perform_mission(&adventure)) {
                        adventure.current_mission.mission_duration = 0; // Reset mission after completion
                    }
                } else {
                    printf("No mission selected.\n");
                }
                break;
            case 4:
                status_report(&adventure);
                break;
            case 0:
                printf("Exiting the Space Adventure.\n");
                break;
            default:
                printf("Invalid command!\n");
        }
    } while (command != 0);

    return 0;
}