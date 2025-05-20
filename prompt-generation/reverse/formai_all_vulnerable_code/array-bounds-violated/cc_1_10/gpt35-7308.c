//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_DISTANCE 1000

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    char name[20];
    Coord loc;
    int tech_level;
} Planet;

typedef struct {
    int fuel;
    int credits;
    Coord curr_loc;
} Ship;

// function prototypes
void generate_planets(Planet planets[]);
void display_planets(Planet planets[]);
int distance(Coord c1, Coord c2);
void travel(Ship *ship, Planet planets[]);

int main() {
    srand(time(NULL)); // seed the random number generator
    
    Planet planets[MAX_PLANETS];
    Ship player_ship = {MAX_DISTANCE, 1000, {0, 0}}; // initialize player's ship
    
    generate_planets(planets); // randomly generate planets
    display_planets(planets); // display the generated planets
    
    printf("Welcome to the space adventure game!\n");
    
    // loop until the player runs out of fuel or reaches a planet with a tech level of 10
    while (player_ship.fuel > 0 && planets[player_ship.curr_loc.x * 10 + player_ship.curr_loc.y].tech_level != 10) {
        printf("You are currently at (%d, %d)\n", player_ship.curr_loc.x, player_ship.curr_loc.y);
        printf("You have %d fuel and %d credits\n", player_ship.fuel, player_ship.credits);
        printf("Choose where you want to go:\n");
        display_planets(planets); // display available planets
        
        int choice;
        printf("Enter a number between 1 and %d: ", MAX_PLANETS);
        scanf("%d", &choice);
        
        // check if the choice is valid
        if (choice < 1 || choice > MAX_PLANETS) {
            printf("Invalid choice! Please try again.\n\n");
            continue;
        }
        
        // calculate distance to the chosen planet
        Coord dest = planets[choice - 1].loc;
        int dist = distance(player_ship.curr_loc, dest);
        
        // check if player has enough fuel to travel
        if (dist > player_ship.fuel) {
            printf("You don't have enough fuel to travel that distance!\n\n");
            continue;
        }
        
        // travel to the chosen planet
        player_ship.fuel -= dist;
        player_ship.credits += planets[choice - 1].tech_level * 100;
        player_ship.curr_loc = dest;
        
        printf("You have arrived at %s!\n", planets[choice - 1].name);
        printf("You now have %d fuel and %d credits\n", player_ship.fuel, player_ship.credits);
        printf("The tech level of this planet is %d\n\n", planets[choice - 1].tech_level);
    }
    
    // check if player won or lost the game
    if (player_ship.fuel > 0) {
        printf("Congratulations! You have reached a planet with a tech level of 10 and won the game!\n");
    } else {
        printf("Sorry, you ran out of fuel and lost the game. Better luck next time!\n");
    }
    
    return 0;
}

// randomly generate planets
void generate_planets(Planet planets[]) {
    char *names[MAX_PLANETS] = {"Alpha", "Beta", "Gamma", "Delta", "Epsilon", "Zeta", "Eta", "Theta", "Iota", "Kappa"};
    int used_locs[MAX_PLANETS] = {0}; // keep track of used planet locations
    
    for (int i = 0; i < MAX_PLANETS; i++) {
        // randomly generate unique planet location
        int loc;
        do {
            loc = rand() % (MAX_PLANETS * MAX_PLANETS);
        } while (used_locs[loc] == 1);
        used_locs[loc] = 1;
        
        // create the planet
        Planet p = {
            .loc.x = loc / 10,
            .loc.y = loc % 10,
            .tech_level = rand() % 10 + 1
        };
        strcpy(p.name, names[i]);
        planets[i] = p;
    }
}

// display planet information
void display_planets(Planet planets[]) {
    for (int i = 0; i < MAX_PLANETS; i++) {
        Planet p = planets[i];
        printf("%d. %s (tech level: %d, distance: %d)\n", i + 1, p.name, p.tech_level, distance(p.loc, (Coord){0, 0}));
    }
}

// calculate distance between two coordinates
int distance(Coord c1, Coord c2) {
    return abs(c1.x - c2.x) + abs(c1.y - c2.y);
}

// travel to a chosen planet
void travel(Ship *ship, Planet planets[]) {
        
}