//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define player struct
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int gold;
} Player;

//define enemy struct
typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int gold;
} Enemy;

//function to get player's name
void get_player_name(Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    printf("Welcome %s!\n", player->name);
}

//function to initialize player stats
void initialize_player(Player *player) {
    player->health = 100;
    player->attack = 10;
    player->defense = 5;
    player->gold = 0;
}

//function to initialize enemy stats
void initialize_enemy(Enemy *enemy) {
    enemy->health = 50;
    enemy->attack = 5;
    enemy->defense = 2;
    enemy->gold = rand() % 20;
}

//function to print player stats
void print_player_stats(Player player) {
    printf("\nPlayer Stats:\n");
    printf("Name: %s\n", player.name);
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n", player.defense);
    printf("Gold: %d\n", player.gold);
}

//function to print enemy stats
void print_enemy_stats(Enemy enemy) {
    printf("\nEnemy Stats:\n");
    printf("Name: %s\n", enemy.name);
    printf("Health: %d\n", enemy.health);
    printf("Attack: %d\n", enemy.attack);
    printf("Defense: %d\n", enemy.defense);
    printf("Gold: %d\n", enemy.gold);
}

//function to perform attack
int perform_attack(int attacker_attack, int defender_defense) {
    int damage = attacker_attack - defender_defense;
    if (damage < 0) {
        damage = 0;
    }
    return damage;
}

int main() {
    //seed random number generator
    srand(time(NULL));

    //initialize player and get name
    Player player;
    initialize_player(&player);
    get_player_name(&player);

    //start game loop
    while(1) {
        //print player stats
        print_player_stats(player);

        //ask player what to do next
        printf("What do you want to do next?\n");
        printf("1. Fight Enemy\n");
        printf("2. Quit Game\n");

        //get player input
        int choice;
        scanf("%d", &choice);

        //handle player input
        if (choice == 1) {
            //initialize enemy
            Enemy enemy;
            initialize_enemy(&enemy);

            //print enemy stats
            print_enemy_stats(enemy);

            //fight loop
            while (1) {
                //player attacks enemy
                int player_damage = perform_attack(player.attack, enemy.defense);
                enemy.health -= player_damage;
                printf("%s attacks %s for %d damage!\n", player.name, enemy.name, player_damage);

                //check if enemy is dead
                if (enemy.health <= 0) {
                    printf("%s is dead! You collect %d gold.\n", enemy.name, enemy.gold);
                    player.gold += enemy.gold;
                    break;
                }

                //enemy attacks player
                int enemy_damage = perform_attack(enemy.attack, player.defense);
                player.health -= enemy_damage;
                printf("%s attacks %s for %d damage!\n", enemy.name, player.name, enemy_damage);

                //check if player is dead
                if (player.health <= 0) {
                    printf("%s is dead! Game over.\n", player.name);
                    exit(0);
                }
            }
        } else if (choice == 2) {
            //quit game
            printf("Thanks for playing %s!\n", player.name);
            exit(0);
        } else {
            //invalid input
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}