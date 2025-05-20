//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player_health = 100;
int ghost_health = 50;

void ghost_attack() {
    int attack_choice = rand() % 3; // 3 types of attacks
    int damage;
    switch(attack_choice) {
        case 0: //basic attack
            damage = rand() % 10 + 1;
            player_health -= damage;
            printf("The ghost hits you with a chill for %d damage.\n", damage);
            break;
        case 1: //haunting attack
            damage = rand() % 20 + 1;
            player_health -= damage;
            printf("The ghost haunts you for %d damage.\n", damage);
            break;
        case 2: //possession attack
            damage = rand() % 30 + 1;
            player_health -= damage;
            printf("You feel the ghost enter your mind and cause %d damage.\n", damage);
            break;
        default:
            printf("The ghost does nothing.\n");
    }
}

void player_attack() {
    int attack_choice;
    int damage;
    printf("Choose your attack:\n1. Punch (10 damage)\n2. Kick (15 damage)\n3.Spirit Bomb (30 damage)\n");
    scanf("%d", &attack_choice);
    switch(attack_choice) {
        case 1: //punch attack
            damage = 10;
            ghost_health -= damage;
            printf("You punch the ghost for %d damage.\n", damage);
            break;
        case 2: //kick attack
            damage = 15;
            ghost_health -= damage;
            printf("You kick the ghost for %d damage.\n", damage);
            break;
        case 3: //spirit bomb
            damage = 30;
            ghost_health -= damage;
            printf("You charge up a Spirit Bomb and throw it at the ghost!\nIt explodes for %d damage.\n", damage);
            break;
        default:
            printf("You do nothing.\n");
    }
}

int main() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in a dark, creepy house...\n");
    printf("Suddenly, you hear a strange noise...\n");
    printf("A ghost appears in front of you!\n");

    while(player_health > 0 && ghost_health > 0) {
        printf("Your health: %d\n", player_health);
        printf("Ghost health: %d\n", ghost_health);
        printf("What will you do?\n");
        printf("1. Attack\n2. Flee\n");
        
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: //attacking
                player_attack();
                ghost_attack();
                break;
            case 2: //fleeing
                printf("You turn and run away from the ghost...\n");
                printf("But the ghost catches up and attacks you!\n");
                int damage = rand() % 20 + 1;
                player_health -= damage;
                printf("You take %d damage.\n", damage);
                break;
            default:
                printf("You do nothing.\n");
        }
    }
    if(player_health <= 0) {
        printf("You died! Game Over.\n");
    } else {
        printf("Congratulations! You defeated the ghost and escaped the haunted house!\n");
    }
    return 0;
}