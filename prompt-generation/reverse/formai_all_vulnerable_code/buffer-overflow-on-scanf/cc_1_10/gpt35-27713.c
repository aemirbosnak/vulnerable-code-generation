//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_PLANETS 20
#define MAX_SHIP_HEALTH 100
#define MAX_SHIP_FUEL 100
#define MAX_ENEMY_HEALTH 50
#define MAX_ENEMY_DAMAGE 10
#define MAX_PLAYER_DAMAGE 15

typedef struct {
    char* name;
    int x;
    int y;
} planet;

typedef struct {
    int health;
    int fuel;
    int x;
    int y;
} ship;

typedef struct {
    int health;
} enemy;

void generate_planets(planet* p, int num_planets);
void display_planets(planet* p, int num_planets);
void travel_to_planet(ship* s, planet p);
void display_ship_status(ship s);
void attack_enemy(ship* s, enemy* e);
void fight_enemy(ship* s, enemy* e);
void game_over(ship s);

int main() {
    srand(time(0));
    planet planets[MAX_PLANETS];
    int num_planets = rand() % MAX_PLANETS + 1;
    generate_planets(planets, num_planets);
    display_planets(planets, num_planets);

    ship player_ship = { MAX_SHIP_HEALTH, MAX_SHIP_FUEL, planets[0].x, planets[0].y };

    printf("Welcome to Space Adventure!\n");
    printf("Your ship has %d health and %d fuel.\n", player_ship.health, player_ship.fuel);

    int current_planet = 0;
    while (1) {
        printf("You are currently on planet %s.\n", planets[current_planet].name);
        printf("What would you like to do?\n");
        printf("1. Travel to another planet\n");
        printf("2. Check ship status\n");
        printf("3. Quit game\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int new_planet = rand() % num_planets;
            while (new_planet == current_planet) {
                new_planet = rand() % num_planets;
            }
            travel_to_planet(&player_ship, planets[new_planet]);
            current_planet = new_planet;
            printf("You have arrived at planet %s.\n", planets[current_planet].name);
            enemy enemy_ship = { MAX_ENEMY_HEALTH };
            fight_enemy(&player_ship, &enemy_ship);
            if (player_ship.health <= 0) {
                game_over(player_ship);
                break;
            }
        }
        else if (choice == 2) {
            display_ship_status(player_ship);
        }
        else if (choice == 3) {
            printf("Thanks for playing!\n");
            break;
        }
        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void generate_planets(planet* p, int num_planets) {
    char* planet_names[MAX_PLANETS] = { "Avalon", "Elysium", "New Terra", "Coruscant", "Serenity", 
    "Tatooine", "Pandora", "Arrakis", "Krypton", "Romulus", "Vulcan", "Zenn-La", "Oa", "Asgard", "Zamaron",
    "Xandar", "Mars", "Jupiter", "Saturn", "Neptune" };

    int used_names[MAX_PLANETS] = { 0 };
    for (int i = 0; i < num_planets; i++) {
        p[i].name = planet_names[rand() % MAX_PLANETS];
        while (used_names[rand() % MAX_PLANETS] == 1) {
            p[i].name = planet_names[rand() % MAX_PLANETS];
        }
        used_names[rand() % MAX_PLANETS] = 1;
        p[i].x = rand() % 51;
        p[i].y = rand() % 51;
    }
}

void display_planets(planet* p, int num_planets) {
    printf("These are the planets in this sector:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("%s: (%d,%d)\n", p[i].name, p[i].x, p[i].y);
    }
}

void travel_to_planet(ship* s, planet p) {
    int distance = abs(s->x - p.x) + abs(s->y - p.y);
    int fuel_needed = distance / 10;
    if (fuel_needed > s->fuel) {
        printf("You do not have enough fuel to travel to that planet!\n");
    }
    else {
        s->fuel -= fuel_needed;
        s->x = p.x;
        s->y = p.y;
        printf("You have travelled to planet %s.\n", p.name);
    }
}

void display_ship_status(ship s) {
    printf("Your ship has %d health and %d fuel.\n", s.health, s.fuel);
}

void attack_enemy(ship* s, enemy* e) {
    int player_damage = rand() % MAX_PLAYER_DAMAGE + 1;
    e->health -= player_damage;
    printf("You did %d damage to the enemy!\n", player_damage);
    if (e->health <= 0) {
        printf("The enemy ship has been destroyed!\n");
        return;
    }
    int enemy_damage = rand() % MAX_ENEMY_DAMAGE + 1;
    s->health -= enemy_damage;
    printf("The enemy did %d damage to your ship!\n", enemy_damage);
    if (s->health <= 0) {
        return;
    }
    attack_enemy(s, e);
}

void fight_enemy(ship* s, enemy* e) {
    printf("You have encountered an enemy ship!\n");
    attack_enemy(s, e);
}

void game_over(ship s) {
    printf("Your ship has been destroyed. Game over.\n");
    printf("You survived for %d turns.\n", MAX_SHIP_HEALTH - s.health);
}