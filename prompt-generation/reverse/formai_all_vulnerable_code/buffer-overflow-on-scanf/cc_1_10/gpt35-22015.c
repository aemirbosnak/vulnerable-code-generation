//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_NAME_LENGTH 20
#define MAX_GALAXY_SIZE 100

// Structs
struct player {
    char name[MAX_NAME_LENGTH];
    int health;
    int credits;
};

struct planet {
    char name[MAX_NAME_LENGTH];
    int distance;
    int resource;
};

// Functions
void intro(struct player *p);
void choose_planet(struct planet planets[], int size, struct player *p);
void journey(struct planet *p, struct player *plr);
void mine_resources(struct planet *p, struct player *plr);

int main() {
    srand(time(NULL));
    
    struct player player1;
    struct planet galaxies[MAX_GALAXY_SIZE];
    
    intro(&player1);
    choose_planet(galaxies, MAX_GALAXY_SIZE, &player1);
    
    return 0;
}

void intro(struct player *p) {
    printf("Welcome to Space Adventure!\nWhat is your name? (Max 20 characters)\n");
    scanf("%s", p->name);
    printf("Hello %s! Get ready for an adventure beyond this world.\n", p->name);
    p->health = 100;
    p->credits = 500;
}

void choose_planet(struct planet planets[], int size, struct player *p) {
    printf("You are now at the space station. Choose a planet to explore.\n");
    printf("Distance and resource levels vary on different planets. Choose wisely!\n");
    printf("---------\n");
    printf("Choose from the following planets:\n");
    
    int i;
    for (i = 0; i < size; i++) {
        planets[i].distance = rand() % 100;
        planets[i].resource = rand() % 500;
        sprintf(planets[i].name, "Planet %d", i+1);
        printf("%d. %s (Distance: %d, Resource Level: %d)\n", i+1, planets[i].name, planets[i].distance, planets[i].resource);
    }
    
    int choice;
    printf("Choose a planet number: ");
    scanf("%d", &choice);
    
    printf("--------\n");
    printf("You have chosen %s.\n", planets[choice-1].name);
    printf("Distance to %s is %d light years.\n", planets[choice-1].name, planets[choice-1].distance);
    
    journey(&planets[choice-1], p);
}

void journey(struct planet *p, struct player *plr) {
    int travel_time = p->distance / 10;
    printf("It will take approximately %d months to reach %s.\n", travel_time, p->name);
    
    // check if player has enough credits for travel expenses
    if (travel_time * 100 > plr->credits) {
        printf("You do not have enough credits to travel to %s.\n", p->name);
        printf("Game over.");
        exit(0);
    }
    
    printf("Traveling to %s...\n", p->name);
    printf("--------\n");
    printf("You have arrived at %s!\n", p->name);
    
    mine_resources(p, plr);
}

void mine_resources(struct planet *p, struct player *plr) {
    printf("You're now on %s. The resource level is %d.\n", p->name, p->resource);
    printf("Mining resources...\n");
    
    // determine amount of resources player has mined
    int mined = rand() % p->resource;
    plr->credits += mined;
    printf("You have mined %d credits worth of resources.\n", mined);
    
    // update player health
    plr->health -= mined / 2;
    printf("Mining damages your health by %d.\n", mined / 2);
    
    if (plr->health <= 0) {
        printf("Your health has depleted and you have died.\n");
        printf("Game over.");
        exit(0);
    }
    
    printf("You now have %d credits.\n", plr->credits);
}