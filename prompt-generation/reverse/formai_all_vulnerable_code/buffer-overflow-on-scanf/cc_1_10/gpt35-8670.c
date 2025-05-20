//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multiplayer
#include <stdio.h>

#define EARTH 0
#define MARS 1
#define VENUS 2
#define JUPITER 3

#define NUM_PLANETS 4

struct planet {
    char name[20];
    double distance; // in millions of km
    double diameter; // in km
    double mass; // in kg
};

struct planet planets[NUM_PLANETS] = { 
    { "Earth", 149.6, 12742, 5.97E+24 },
    { "Mars", 227.9, 6779, 6.39E+23 },
    { "Venus", 108.2, 12104, 4.87E+24 },
    { "Jupiter", 778.5, 139822, 1.90E+27 }
};

void display_planet_info(int planet_index) {
    struct planet p = planets[planet_index];
    printf("Planet: %s\n", p.name);
    printf("Distance from Sun: %f million kilometers\n", p.distance);
    printf("Diameter: %f kilometers\n", p.diameter);
    printf("Mass: %g kilograms\n\n", p.mass);
}

int main() {
    int i;
    int num_players;
    int player_planets[4] = {0}; // initialize all player planets to Earth
    char player_names[4][20];
    
    printf("Welcome to the Solar System Simulation!\n\n");
    
    printf("How many players want to play? (2-4): ");
    scanf("%d", &num_players);
    
    if(num_players < 2 || num_players > 4) {
        printf("Invalid number of players. Exiting.\n");
        return 0;
    }
    
    for(i = 0; i < num_players; i++) {
        printf("Enter the name for player %d: ", i + 1);
        scanf("%s", player_names[i]);
    }
    
    printf("\n%s has been assigned Earth.\n", player_names[0]);
    display_planet_info(EARTH);
    
    for(i = 1; i < num_players; i++) {
        printf("%s, select your starting planet:\n", player_names[i]);
        printf("0: Earth\n");
        printf("1: Mars\n");
        printf("2: Venus\n");
        printf("3: Jupiter\n");
    
        scanf("%d", &player_planets[i]);
        
        if(player_planets[i] < 0 || player_planets[i] > 3) {
            printf("Invalid planet selection. Exiting.\n");
            return 0;
        }
        
        printf("\n%s has been assigned ", player_names[i]);
        display_planet_info(player_planets[i]);
    }
    
    printf("Let's begin!\n");
    
    return 0;
}