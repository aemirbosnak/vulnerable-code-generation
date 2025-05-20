//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_RESPONSE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int shield;
    int fuel;
} Spaceship;

typedef struct {
    char name[MAX_NAME_LEN];
    int damage;
    int shield_penetration;
    int accuracy;
} Weapon;

Spaceship player_spaceship;
Weapon player_weapon;

int random_int(int min, int max);

void init_player();
void display_status();
int get_integer_input(int min, int max);
char get_char_input(char valid_chars[], int num_valid_chars);
void game_over(const char *message);
void battle(const char *enemy_name, int enemy_health, int enemy_shield);
void victory();
void defeat();
bool flee();
void space_travel();

int main() {
    srand(time(0));
    printf("Welcome to Procedural Space Adventure!\n");
    init_player();
    display_status();
    space_travel();
    printf("Thanks for playing!\n");
    return 0;
}

void init_player() {
    printf("What is your spaceship's name? ");
    fgets(player_spaceship.name, MAX_NAME_LEN, stdin);
    player_spaceship.name[strcspn(player_spaceship.name, "\n")] = '\0';

    player_spaceship.health = 100;
    player_spaceship.shield = 50;
    player_spaceship.fuel = 100;

    printf("What weapon do you want to use? (L)aser or (M)issile? ");
    char weapon_choice = get_char_input("LMlm", 4);
    if (weapon_choice == 'L' || weapon_choice == 'l') {
        strcpy(player_weapon.name, "Laser");
        player_weapon.damage = 20;
        player_weapon.shield_penetration = 5;
        player_weapon.accuracy = 80;
    } else {
        strcpy(player_weapon.name, "Missile");
        player_weapon.damage = 35;
        player_weapon.shield_penetration = 20;
        player_weapon.accuracy = 60;
    }
}

void display_status() {
    printf("\nSpaceship: %s", player_spaceship.name);
    printf("\nHealth: %d", player_spaceship.health);
    printf("\nShield: %d", player_spaceship.shield);
    printf("\nFuel: %d", player_spaceship.fuel);
    printf("\nWeapon: %s", player_weapon.name);
}

int get_integer_input(int min, int max) {
    int input;
    char line[MAX_RESPONSE_LEN];
    while (true) {
        printf("> ");
        if (fgets(line, MAX_RESPONSE_LEN, stdin) == NULL) {
            game_over("Error reading input");
        }
        if (sscanf(line, "%d", &input) == 1) {
            if (input < min || input > max) {
                printf("Invalid input. Must be between %d and %d.\n", min, max);
            } else {
                return input;
            }
        } else {
            printf("Invalid input. Must be an integer.\n");
        }
    }
}

char get_char_input(char valid_chars[], int num_valid_chars) {
    char input;
    char line[MAX_RESPONSE_LEN];
    while (true) {
        printf("> ");
        if (fgets(line, MAX_RESPONSE_LEN, stdin) == NULL) {
            game_over("Error reading input");
        }
        if (sscanf(line, "%c", &input) == 1) {
            input = tolower(input);
            for (int i = 0; i < num_valid_chars; i++) {
                if (input == valid_chars[i]) {
                    return input;
                }
            }
            printf("Invalid input. Must be one of: %s\n", valid_chars);
        } else {
            printf("Invalid input. Must be a character.\n");
        }
    }
}

void game_over(const char *message) {
    printf("GAME OVER: %s\n", message);
    exit(EXIT_SUCCESS);
}

void battle(const char *enemy_name, int enemy_health, int enemy_shield) {
    printf("\nYou encounter a %s with %d health and %d shield.\n", enemy_name, enemy_health, enemy_shield);

    // Decide who attacks first
    bool player_goes_first = rand() % 2 == 0;
    printf("\n%s goes %s!\n", player_spaceship.name, player_goes_first ? "first" : "second");

    while (true) {
        if (player_goes_first) {
            // Player attack
            printf("\nChoose your action:\n");
            printf("1) Attack\n");
            printf("2) Flee\n");
            int action = get_integer_input(1, 2);
            if (action == 2) {
                if (flee()) {
                    break;
                } else {
                    printf("You failed to flee!\n");
                }
            } else {
                if (rand() % 101 <= player_weapon.accuracy) {
                    int damage = player_weapon.damage;
                    if (rand() % 101 <= player_weapon.shield_penetration) {
                        damage -= enemy_shield;
                        damage = damage < 0 ? 0 : damage;
                        enemy_shield -= player_weapon.shield_penetration;
                        printf("You penetrated their shield!\n");
                    }
                    enemy_health -= damage;
                    printf("You hit the %s for %d damage! (Health: %d)\n", enemy_name, damage, enemy_health);
                    if (enemy_health <= 0) {
                        printf("You defeated the %s!\n", enemy_name);
                        victory();
                        return;
                    }
                } else {
                    printf("You missed!\n");
                }
            }
            player_goes_first = false;
        } else {
            // Enemy attack
            int damage = random_int(5, 15);
            if (player_spaceship.shield >= damage) {
                player_spaceship.shield -= damage;
                printf("\n%s hit you for %d damage! (Shield: %d)\n", enemy_name, damage, player_spaceship.shield);
            } else {
                damage -= player_spaceship.shield;
                player_spaceship.shield = 0;
                player_spaceship.health -= damage;
                printf("\n%s hit you for %d damage! (Health: %d)\n", enemy_name, damage, player_spaceship.health);
                if (player_spaceship.health <= 0) {
                    printf("You have been defeated by the %s!\n", enemy_name);
                    defeat();
                    return;
                }
            }
            player_goes_first = true;
        }
    }

}

void victory() {
    int health_gain = random_int(10, 25);
    int shield_gain = random_int(5, 15);
    int fuel_gain = random_int(5, 10);
    printf("\nVictory! You gained:\n");
    printf("Health: +%d\n", health_gain);
    printf("Shield: +%d\n", shield_gain);
    printf("Fuel: +%d\n", fuel_gain);
    player_spaceship.health += health_gain;
    player_spaceship.shield += shield_gain;
    player_spaceship.fuel += fuel_gain;
}

void defeat() {
    printf("\nYou have lost all your progress and must start again.\n");
    init_player();
}

bool flee() {
    if (rand() % 101 <= 50) {
        printf("You successfully fled!\n");
        return true;
    } else {
        return false;
    }
}

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void space_travel() {
    while (true) {
        printf("\nChoose your destination:\n");
        printf("1) Asteroid field\n");
        printf("2) Enemy base\n");
        printf("3) Refuel\n");
        int destination = get_integer_input(1, 3);
        if (destination == 1) {
            battle("Asteroids", random_int(50, 100), random_int(10, 30));
        } else if (destination == 2) {
            battle("Enemy Base", random_int(75, 125), random_int(20, 40));
        } else if (destination == 3) {
            int fuel_gain = random_int(25, 50);
            printf("\nRefueling... You gained %d fuel.\n", fuel_gain);
            player_spaceship.fuel += fuel_gain;
        }
        player_spaceship.fuel -= random_int(10, 25);
        if (player_spaceship.fuel <= 0) {
            printf("\nYou ran out of fuel and are stranded in space. GAME OVER.\n");
            exit(EXIT_SUCCESS);
        }
        printf("\nCurrent Status:\n");
        display_status();
    }
}