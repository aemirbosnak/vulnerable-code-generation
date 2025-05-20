//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLANETS 5
#define MAX_SHIP_HEALTH 100
#define MAX_ENEMY_HEALTH 50

struct planet {
    char name[20];
    int resource;
};

typedef struct planet Planet;

void generate_planets(Planet *planets);
void show_planets(Planet *planets);
void initiate_battle(int *health, int *enemy_health);

int main() {
    Planet planets[MAX_PLANETS];
    int option, health = MAX_SHIP_HEALTH, enemy_health = MAX_ENEMY_HEALTH;
    
    // Generate random planets with resources
    generate_planets(planets);
    
    // Loop until player enters 4 (quit)
    while(option != 4) {
        printf("You have ventured into unchartered space. What would you like to do?\n");
        printf("1. Explore planets\n");
        printf("2. Check ship's health\n");
        printf("3. Initiate battle\n");
        printf("4. Quit\n");
        printf("> ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("You start exploring the planets and come across the following.\n");
                show_planets(planets);
                break;
            case 2:
                printf("Your ship's health is currently %d.\n", health);
                break;
            case 3:
                printf("You come across an enemy ship.\n");
                initiate_battle(&health, &enemy_health);
                break;
            case 4:
                printf("Thanks for travelling in space!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void generate_planets(Planet *planets) {
    srand(time(NULL));
    for(int i=0; i<MAX_PLANETS; i++) {
        int random_resource = rand() % 10 + 1;
        sprintf(planets[i].name, "Planet %d", i+1);
        planets[i].resource = random_resource;
    }
}

void show_planets(Planet *planets) {
    for(int i=0; i<MAX_PLANETS; i++) {
        printf("%s has %d resources.\n", planets[i].name, planets[i].resource);
    }
}

void initiate_battle(int *health, int *enemy_health) {
    printf("Your ship starts battling the enemy ship...\n");
    while(*health > 0 && *enemy_health > 0) {
        int damage = rand() % 20 + 1;
        *health -= damage;
        printf("Enemy ship attacks you and deals %d damage. Your ship health is now %d.\n", damage, *health);
        damage = rand() % 20 + 1;
        *enemy_health -= damage;
        printf("You attack the enemy ship and deal %d damage. Enemy ship health is now %d.\n", damage, *enemy_health);
    }
    if(*health <= 0) {
        printf("Your ship has been destroyed. Game over!\n");
    }
    else if(*enemy_health <= 0) {
        printf("You have destroyed the enemy ship. Congratulations!\n");
    }
    *health = MAX_SHIP_HEALTH;
    *enemy_health = MAX_ENEMY_HEALTH;
}