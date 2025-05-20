//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define MAX_ENEMIES 10
#define MAX_DAMAGE 20
#define MAX_HEALTH 100
#define MAX_SHIELD 50
#define MAX_COORDINATE 1000
#define MAX_DISTANCE 300

/* Structures */
struct Coordinate {
    int x;
    int y;
};

struct Player {
    char name[50];
    int health;
    int shield;
    struct Coordinate current_pos;
};

struct Enemy {
    char type[50];
    int health;
    int damage;
    struct Coordinate current_pos;
};

/* Function prototypes */
void initialize_player(struct Player *player, char *name);
void create_enemy(struct Enemy *enemy);
void move_player(struct Player *player);
void move_enemy(struct Enemy *enemy);
void print_status(struct Player player, struct Enemy enemies[]);
void combat(struct Player *player, struct Enemy *enemy);
int calculate_distance(struct Coordinate a, struct Coordinate b);

/* Main function */
int main() {
    struct Player player;
    struct Enemy enemies[MAX_ENEMIES];
    int num_enemies = 0;

    srand(time(0)); // Seed random number generator

    initialize_player(&player, "John");

    while (num_enemies < MAX_ENEMIES) {
        create_enemy(&enemies[num_enemies]);
        num_enemies++;
    }

    while (player.health > 0 && num_enemies > 0) {
        move_player(&player);

        for (int i = 0; i < num_enemies; i++) {
            move_enemy(&enemies[i]);

            if (calculate_distance(player.current_pos, enemies[i].current_pos) <= MAX_DISTANCE) {
                printf("You have encountered a %s!\n", enemies[i].type);
                combat(&player, &enemies[i]);

                if (enemies[i].health <= 0) {
                    printf("You have defeated the %s!\n", enemies[i].type);
                    num_enemies--;
                    enemies[i] = enemies[num_enemies];
                }
            }
        }

        print_status(player, enemies);
    }

    if (player.health <= 0) {
        printf("Game over! You have been defeated.");
    } else {
        printf("Congratulations! You have defeated all enemies.");
    }

    return 0;
}

/* Function definitions */

void initialize_player(struct Player *player, char *name) {
    printf("Welcome to the Procedural Space Adventure game!\n");
    printf("Please enter your name: ");
    scanf("%s", player->name);

    player->health = MAX_HEALTH;
    player->shield = MAX_SHIELD;

    player->current_pos.x = rand() % MAX_COORDINATE;
    player->current_pos.y = rand() % MAX_COORDINATE;

    printf("Welcome, %s. Your adventure starts at (%d, %d).\n", player->name, player->current_pos.x, player->current_pos.y);
}

void create_enemy(struct Enemy *enemy) {
    static const char *enemy_types[] = {"Alien", "Robot", "Space Pirate", "Giant Insect", "Mutant"};
    int num_types = sizeof(enemy_types) / sizeof(enemy_types[0]);

    int rand_type_index = rand() % num_types;
    int rand_x = rand() % MAX_COORDINATE;
    int rand_y = rand() % MAX_COORDINATE;

    enemy->damage = rand() % MAX_DAMAGE;
    enemy->health = MAX_HEALTH;
    enemy->current_pos.x = rand_x;
    enemy->current_pos.y = rand_y;
    sprintf(enemy->type, "%s %d", enemy_types[rand_type_index], rand() % 100);
}

void move_player(struct Player *player) {
    int x, y;

    printf("Enter new coordinates (x,y): ");
    scanf("%d,%d", &x, &y);

    player->current_pos.x = x;
    player->current_pos.y = y;

    printf("You have moved to (%d, %d)\n", player->current_pos.x, player->current_pos.y);
}

void move_enemy(struct Enemy *enemy) {
    int rand_x = rand() % (MAX_COORDINATE / 2);
    int rand_y = rand() % (MAX_COORDINATE / 2);

    if (rand() % 2) {
        rand_x *= -1;
    }

    if (rand() % 2) {
        rand_y *= -1;
    }

    enemy->current_pos.x += rand_x;
    enemy->current_pos.y += rand_y;

    printf("The %s has moved to (%d, %d)\n", enemy->type, enemy->current_pos.x, enemy->current_pos.y);
}

void print_status(struct Player player, struct Enemy enemies[]) {
    printf("Your current status:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Shield: %d\n", player.shield);
    printf("Position: (%d, %d)\n", player.current_pos.x, player.current_pos.y);

    printf("Enemies remaining:\n");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i].health > 0) {
            printf("-> %s at (%d, %d)\n", enemies[i].type, enemies[i].current_pos.x, enemies[i].current_pos.y);
        }
    }
}

void combat(struct Player *player, struct Enemy *enemy) {
    while (player->health > 0 && enemy->health > 0) {
        printf("You attack the %s!\n", enemy->type);
        enemy->health -= rand() % MAX_DAMAGE;

        if (enemy->health > 0) {
            printf("The %s attacks you!\n", enemy->type);
            player->health -= enemy->damage;
        }
    }

    if (enemy->health <= 0) {
        printf("You have defeated the %s!\n", enemy->type);
    }

    if (player->health <= 0) {
        printf("You have been defeated by the %s...\n", enemy->type);
    }
}

int calculate_distance(struct Coordinate a, struct Coordinate b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}