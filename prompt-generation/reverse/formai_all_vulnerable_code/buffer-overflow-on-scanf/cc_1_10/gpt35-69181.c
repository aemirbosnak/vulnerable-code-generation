//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int player_health = 100;
int enemy_health = 100;
int enemy_attack_power = 20;
int player_attack_power = 30;
int potion_count = 3;
int is_chest_open = 0;
int has_key = 0;
int is_boss_dead = 0;

void print_menu() {
    printf("\nWhat would you like to do?\n1) Attack\n2) Use potion\n3) Open chest\n4) Try to flee\n");
}

int get_player_move() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void enemy_attack() {
    printf("The enemy attacked you!\n");
    int damage = rand() % enemy_attack_power;
    player_health -= damage;
    printf("You took %d damage. Your health is now %d.\n", damage, player_health);
}

void player_attack() {
    printf("You attacked the enemy!\n");
    int damage = rand() % player_attack_power;
    enemy_health -= damage;
    printf("You did %d damage. Enemy health is now %d.\n", damage, enemy_health);
}

void use_potion() {
    if(potion_count > 0) {
        printf("You used a potion and regained 20 health!\n");
        player_health += 20;
        potion_count--;
        if(player_health > 100) {
            player_health = 100;
        }
        printf("Your health is now %d.\n", player_health);
    } else {
        printf("You don't have any potions left!\n");
    }
}

void open_chest() {
    if(has_key) {
        printf("You opened the chest and found a rare sword that increases your attack power by 20!\n");
        player_attack_power += 20;
        is_chest_open = 1;
        printf("Your attack power is now %d.\n", player_attack_power);
    } else {
        printf("You need a key to open this chest.\n");
    }
}

void try_to_flee() {
    printf("You tried to flee but the enemy caught up to you and attacked you!\n");
    enemy_attack();
}

void won_game() {
    printf("You won the game! Congratulations!\n");
    printf("Your final health was %d and you used %d potions.\n", player_health, 3 - potion_count);
}

void lost_game() {
    printf("You lost the game! Better luck next time!\n");
}

void fight_enemy() {
    while(player_health > 0 && enemy_health > 0) {
        print_menu();
        int choice = get_player_move();
        switch(choice) {
            case 1:
                player_attack();
                if(enemy_health > 0) {
                    enemy_attack();
                }
                break;
            case 2:
                use_potion();
                enemy_attack();
                break;
            case 3:
                open_chest();
                break;
            case 4:
                try_to_flee();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    if(player_health > 0) {
        printf("You defeated the enemy!\n");
        if(!is_chest_open) {
            printf("You found a key on the enemy!\n");
            has_key = 1;
        }
    } else {
        printf("You died in battle!\n");
        lost_game();
        exit(0);
    }
}

void fight_boss() {
    printf("You entered a room with a massive dragon! He has 200 health and attack power of 50!\n");
    enemy_health = 200;
    enemy_attack_power = 50;
    while(player_health > 0 && enemy_health > 0) {
        print_menu();
        int choice = get_player_move();
        switch(choice) {
            case 1:
                player_attack();
                if(enemy_health > 0) {
                    enemy_attack();
                }
                break;
            case 2:
                use_potion();
                enemy_attack();
                break;
            case 3:
                open_chest();
                break;
            case 4:
                try_to_flee();
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    if(player_health > 0) {
        printf("You defeated the boss and saved the kingdom!\n");
        won_game();
        is_boss_dead = 1;
    } else {
        printf("You died in battle!\n");
        lost_game();
        exit(0);
    }
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Text-Based Adventure Game! You are a brave hero on a quest to defeat an evil dragon and save the kingdom. You start in a dark forest with only a sword and three potions. Be careful, as enemies and traps await you on your journey.\n");
    while(!is_boss_dead) {
        printf("You have %d potions left.\n", potion_count);
        printf("You have %d health and your attack power is %d.\n", player_health, player_attack_power);
        getchar();
        printf("You encountered an enemy! It has 100 health and attack power of 20.\n");
        getchar();
        fight_enemy();
    }
    fight_boss();
    return 0;
}