//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SHIP_HEALTH 100
#define MAX_ENEMY_HEALTH 40
#define MAX_SHIP_NAME_LENGTH 20

// Player's spaceship struct
typedef struct {
    char name[MAX_SHIP_NAME_LENGTH];
    int health;
    int ammo;
} Spaceship;

// Enemy spacecraft struct
typedef struct {
    int health;
    int damage;
} EnemyShip;

// Function prototypes
void welcome_message();
void initialize_spaceship(Spaceship *ship, char *name);
void initialize_enemy_ship(EnemyShip *enemy);
void attack_enemy(Spaceship *ship, EnemyShip *enemy);
void enemy_attack(Spaceship *ship, EnemyShip *enemy);
void print_ship_status(Spaceship *ship, EnemyShip *enemy);
bool check_game_over(Spaceship *ship, EnemyShip *enemy);
void end_game(Spaceship *ship, EnemyShip *enemy);

int main() {
    srand(time(NULL));
    
    // Initialize player's spaceship
    Spaceship my_ship;
    initialize_spaceship(&my_ship, "USS Voyager");
    
    // Initialize enemy spacecraft
    EnemyShip enemy_ship;
    initialize_enemy_ship(&enemy_ship);
    
    // Welcome message
    welcome_message();
    
    // Game loop
    while (true) {
        char choice;
        printf("\nDo you want to [a] attack the enemy or [q] quit the game? ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'a':
                attack_enemy(&my_ship, &enemy_ship);
                enemy_attack(&my_ship, &enemy_ship);
                break;
            case 'q':
                end_game(&my_ship, &enemy_ship);
                return 0;
            default:
                printf("Invalid choice! Please enter a or q.\n");
                break;
        }
        
        print_ship_status(&my_ship, &enemy_ship);
        
        if (check_game_over(&my_ship, &enemy_ship)) {
            break;
        }
    }
    
    end_game(&my_ship, &enemy_ship);
    return 0;
}

// Displays the welcome message
void welcome_message() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("In this game, you will be the captain of your own spaceship and battle alien enemies.\n");
}

// Initializes the spaceship
void initialize_spaceship(Spaceship *ship, char *name) {
    strncpy(ship->name, name, MAX_SHIP_NAME_LENGTH);
    ship->health = MAX_SHIP_HEALTH;
    ship->ammo = 10;
}

// Initializes the enemy spaceship
void initialize_enemy_ship(EnemyShip *enemy) {
    enemy->health = MAX_ENEMY_HEALTH;
    enemy->damage = 10;
}

// Attacks enemy spaceship with the player's spaceship
void attack_enemy(Spaceship *ship, EnemyShip *enemy) {
    if (ship->ammo <= 0) {
        printf("You are out of ammo! Go back to base to replenish.\n");
        return;
    }
    
    int damage = rand() % ship->ammo + 1;
    enemy->health -= damage;
    ship->ammo--;
    
    printf("You attacked the enemy spaceship and dealt %d damage.\n", damage);
}

// Enemy spaceship attacks the player's spaceship
void enemy_attack(Spaceship *ship, EnemyShip *enemy) {
    int damage = rand() % enemy->damage + 1;
    ship->health -= damage;
    
    printf("The enemy spaceship attacked you and dealt %d damage.\n", damage);
}

// Print status of the player's and enemy spaceships
void print_ship_status(Spaceship *ship, EnemyShip *enemy) {
    printf("%s's health: %d\n", ship->name, ship->health);
    printf("Enemy's health: %d\n", enemy->health);
    printf("Ammo remaining: %d\n", ship->ammo);
}

// Checks if the game has ended
bool check_game_over(Spaceship *ship, EnemyShip *enemy) {
    if (ship->health <= 0) {
        printf("Your spaceship has been destroyed! Game over.\n");
        return true;
    }
    
    if (enemy->health <= 0) {
        printf("You have destroyed the enemy spaceship! Congratulations.\n");
        return true;
    }
    
    return false;
}

// Ends the game
void end_game(Spaceship *ship, EnemyShip *enemy) {
    printf("Thanks for playing Procedural Space Adventure!\n");
}