//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 10
#define MAX_ENEMIES 20

struct planet {
    char name[20];
    int distance;
    int resources;
};

struct enemy {
    char type[20];
    int damage;
    int health;
};

void generate_planet(struct planet *p) {
    char *names[MAX_PLANETS] = {"Earth", "Mars", "Jupiter", "Venus", "Mercury", 
                                "Neptune", "Uranus", "Saturn", "Pluto", "Alpha Centauri"};
    int distances[MAX_PLANETS] = {10000, 12000, 15000, 8000, 9000,
                                  25000, 22000, 18000, 30000, 40000};
    int resources[MAX_PLANETS] = {5000, 6000, 10000, 3000, 4000,
                                  15000, 12000, 9000, 25000, 30000};
    int index = rand() % MAX_PLANETS;
    p->distance = distances[index];
    p->resources = resources[index];
    strcpy(p->name, names[index]);
}

void generate_enemy(struct enemy *e) {
    char *types[MAX_ENEMIES] = {"Alien", "Robot", "Dragon", "Zombie", "Mutant",
                                "Ninja", "Pirate", "Vampire", "Werewolf", "Goblin",
                                "Demon", "Ghost", "Giant", "Cyclops", "Sasquatch",
                                "Yeti", "Kraken", "Leviathan", "Hydra", "Chimera"};
    int damages[MAX_ENEMIES] = {100, 150, 200, 250, 300, 
                                350, 400, 450, 500, 550, 
                                600, 650, 700, 750, 800,
                                850, 900, 950, 1000, 1050};
    int healths[MAX_ENEMIES] = {500, 600, 700, 800, 900,
                                1000, 1100, 1200, 1300, 1400, 
                                1500, 1600, 1700, 1800, 1900,
                                2000, 2100, 2200, 2300, 2400};
    int index = rand() % MAX_ENEMIES;
    e->damage = damages[index];
    e->health = healths[index];
    strcpy(e->type, types[index]);
}

int main() {
    srand(time(NULL));
    struct planet p;
    struct enemy e;
    generate_planet(&p);
    generate_enemy(&e);
    printf("Welcome to the Solar System!\n");
    printf("You are on a mission to mine resources on different planets.\n");
    printf("You are currently on %s which is %d km away from Earth.\n", p.name, p.distance);
    printf("This planet has %d resources available for mining.\n", p.resources);
    printf("But beware! There are hostile enemies in space who will attack you.\n");
    printf("You have encountered a %s with %d health and %d damage.\n", e.type, e.health, e.damage);
    printf("Do you want to fight or run away? (type f or r)\n");
    char choice;
    scanf("%c", &choice);
    if (choice == 'f') {
        printf("You have chosen to fight!\n");
        int player_health = 1000;
        while (player_health > 0 && e.health > 0) {
            printf("You attack the enemy and deal %d damage.\n", 100);
            e.health -= 100;
            printf("The enemy attacks you and deals %d damage.\n", e.damage);
            player_health -= e.damage;
            printf("Your health is now %d.\n", player_health);
        }
        if (player_health <= 0) {
            printf("You have been defeated!\n");
        } else {
            printf("Congratulations! You have defeated the enemy and earned %d resources.\n", e.damage * 10);
            p.resources -= e.damage * 10;
        }
    } else {
        printf("You have chosen to run away.\n");
    }
    printf("You have collected %d resources on %s.\n", e.damage * 5, p.name);
    p.resources -= e.damage * 5;
    if (p.resources <= 0) {
        printf("You have exhausted all resources on %s. You need to travel to another planet.\n", p.name);
        generate_planet(&p);
        printf("You are now on %s which is %d km away from Earth.\n", p.name, p.distance);
        printf("This planet has %d resources available for mining.\n", p.resources);
    }
    return 0;
}