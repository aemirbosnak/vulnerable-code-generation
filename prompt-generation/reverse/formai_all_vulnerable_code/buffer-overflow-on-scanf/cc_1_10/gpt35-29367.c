//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_PLANET_NAME_LENGTH 15
#define MAX_PLANET_DESCRIPTION_LENGTH 200
#define MAX_MISSION_DESCRIPTION_LENGTH 100
#define MAX_HEALTH 100
#define MAX_ENERGY 100
#define MAX_MISSIONS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int health;
    int energy;
} Player;

typedef struct {
    char name[MAX_PLANET_NAME_LENGTH];
    char description[MAX_PLANET_DESCRIPTION_LENGTH];
} Planet;

typedef struct {
    char description[MAX_MISSION_DESCRIPTION_LENGTH];
    int health_gain;
    int energy_gain;
} Mission;

void generate_planet(Planet *planet) {
    char names[][MAX_PLANET_NAME_LENGTH] = {"Venus", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
    char descriptions[][MAX_PLANET_DESCRIPTION_LENGTH] = {"The hottest planet in the solar system.", "The Red Planet.", "The largest planet in the solar system.", "The second largest planet in the solar system.", "The seventh planet from the sun.", "The eighth planet from the sun."};
    int index = rand() % 6;
    strcpy(planet->name, names[index]);
    strcpy(planet->description, descriptions[index]);
}

void generate_mission(Mission *mission) {
    char descriptions[][MAX_MISSION_DESCRIPTION_LENGTH] = {"Collect 10 crystals.", "Destroy 5 enemy spaceships.", "Rescue 3 stranded astronauts.", "Retrieve top secret data from enemy base.", "Plant a spy satellite in orbit around the planet."};
    int index = rand() % 5;
    strcpy(mission->description, descriptions[index]);
    mission->health_gain = rand() % 10 + 5;
    mission->energy_gain = rand() % 10 + 5;
}

void print_player_status(Player *player) {
    printf("Name: %s, Health: %d, Energy: %d\n", player->name, player->health, player->energy);
}

void print_planet_info(Planet *planet) {
    printf("You landed on planet %s.\n%s\n", planet->name, planet->description);
}

void print_missions(Mission missions[], int num_missions) {
    printf("Here are your available missions:\n");
    for (int i = 0; i < num_missions; i++) {
        printf("%d. %s (Health gain: %d, Energy gain: %d)\n", i+1, missions[i].description, missions[i].health_gain, missions[i].energy_gain);
    }
}

void perform_mission(Player *player, Mission *mission) {
    printf("Performing mission '%s'...\n", mission->description);
    player->health += mission->health_gain;
    player->energy += mission->energy_gain;
    if (player->health > MAX_HEALTH) {
        player->health = MAX_HEALTH;
    }
    if (player->energy > MAX_ENERGY) {
        player->energy = MAX_ENERGY;
    }
    printf("Health gained: %d, Energy gained: %d\n", mission->health_gain, mission->energy_gain);
}

int main() {
    srand(time(0));
    Player player;
    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("What is your name?\n");
    scanf("%s", player.name);
    player.health = MAX_HEALTH;
    player.energy = MAX_ENERGY;
    printf("Hello, %s! Your mission is to explore the galaxy and complete missions to help save the universe.\n", player.name);

    int num_missions_completed = 0;
    Mission missions[MAX_MISSIONS];
    while (num_missions_completed < MAX_MISSIONS) {
        Planet planet;
        generate_planet(&planet);
        print_planet_info(&planet);

        int mission_choice = 0;
        while (mission_choice < 1 || mission_choice > num_missions_completed+1) {
            if (num_missions_completed == MAX_MISSIONS) {
                printf("Congratulations, you have completed all missions!\n");
                return 0;
            }
            generate_mission(&missions[num_missions_completed]);
            print_missions(missions, num_missions_completed+1);
            printf("Enter the number of the mission you would like to perform: ");
            scanf("%d", &mission_choice);
        }
        Mission *mission = &missions[mission_choice-1];
        perform_mission(&player, mission);
        num_missions_completed++;
        print_player_status(&player);
    }

    printf("Congratulations, you have completed all missions and saved the universe!\n");
    return 0;
}