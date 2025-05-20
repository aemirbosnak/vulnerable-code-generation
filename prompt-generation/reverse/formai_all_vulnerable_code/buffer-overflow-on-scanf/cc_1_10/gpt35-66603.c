//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLANETS 10
#define MAX_WEAPONS 5
#define MAX_ENEMIES 3

typedef struct {
    char name[20];
    int distance;
} Planet;

typedef struct {
    char name[20];
    int damage;
} Weapon;

typedef struct {
    char name[20];
    int health;
    Weapon weapon;
} Enemy;

Planet planets[MAX_PLANETS];
Weapon weapons[MAX_WEAPONS];
Enemy enemies[MAX_ENEMIES];

int playerHealth = 100;
int currentPlanet = 0;

void initializePlanets() {
    Planet mercury = { "Mercury", 36 };
    Planet venus = { "Venus", 67 };
    Planet earth = { "Earth", 93 };
    Planet mars = { "Mars", 142 };
    Planet jupiter = { "Jupiter", 484 };
    Planet saturn = { "Saturn", 886 };
    Planet uranus = { "Uranus", 1782 };
    Planet neptune = { "Neptune", 2793 };
    Planet pluto = { "Pluto", 3670 };
    Planet alphaCentauri = { "Alpha Centauri", 42 };
    
    planets[0] = mercury;
    planets[1] = venus;
    planets[2] = earth;
    planets[3] = mars;
    planets[4] = jupiter;
    planets[5] = saturn;
    planets[6] = uranus;
    planets[7] = neptune;
    planets[8] = pluto;
    planets[9] = alphaCentauri;
}

void initializeWeapons() {
    Weapon laser = { "Laser", 10 };
    Weapon missiles = { "Missiles", 20 };
    Weapon plasma = { "Plasma", 30 };
    Weapon ionCannon = { "Ion Cannon", 40 };
    Weapon railgun = { "Railgun", 50 };
    
    weapons[0] = laser;
    weapons[1] = missiles;
    weapons[2] = plasma;
    weapons[3] = ionCannon;
    weapons[4] = railgun;
}

void initializeEnemies() {
    Enemy alien1 = { "Alien 1", 50, weapons[0] };
    Enemy alien2 = { "Alien 2", 75, weapons[1] };
    Enemy alien3 = { "Alien 3", 100, weapons[2] };
    
    enemies[0] = alien1;
    enemies[1] = alien2;
    enemies[2] = alien3;
}

void travel() {
    int choice;
    printf("Select a planet to travel to:\n");
    for (int i = 0; i < MAX_PLANETS; i++) {
        printf("[%d] %s (%d million km away)\n", i+1, planets[i].name, planets[i].distance);
    }
    scanf("%d", &choice);
    if (choice < 1 || choice > MAX_PLANETS) {
        printf("Invalid choice!\n");
    } else {
        printf("Traveling to %s...\n", planets[choice-1].name);
        currentPlanet = choice-1;
    }
}

void attack() {
    Enemy enemy = enemies[rand() % MAX_ENEMIES];
    printf("An enemy appears! It's %s with %d health!\n", enemy.name, enemy.health);
    
    while (enemy.health > 0 && playerHealth > 0) {
        printf("Select a weapon to attack with:\n");
        for (int i = 0; i < MAX_WEAPONS; i++) {
            printf("[%d] %s (%d damage)\n", i+1, weapons[i].name, weapons[i].damage);
        }
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > MAX_WEAPONS) {
            printf("Invalid choice!\n");
        } else {
            enemy.health -= weapons[choice-1].damage;
            printf("You attack with the %s for %d damage!\n", weapons[choice-1].name, weapons[choice-1].damage);
            if (enemy.health > 0) {
                printf("%s strikes back for %d damage!\n", enemy.name, enemy.weapon.damage);
                playerHealth -= enemy.weapon.damage;
            }
        }
    }
    if (enemy.health <= 0) {
        printf("You defeated %s!\n", enemy.name);
    } else {
        printf("You have been defeated! Game over.\n");
        exit(0);
    }
}

int main() {
    initializePlanets();
    initializeWeapons();
    initializeEnemies();
    
    printf("Welcome to the Space Adventure game!\n");
    while (1) {
        printf("You are currently on %s. What would you like to do?\n", planets[currentPlanet].name);
        printf("[1] Travel\n");
        printf("[2] Attack\n");
        printf("[3] Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                travel();
                break;
            case 2:
                attack();
                break;
            case 3:
                printf("Thanks for playing!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}