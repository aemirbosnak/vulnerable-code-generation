//FormAI DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to calculate damage based on weapon and enemy stats
int calc_damage(int weapon_attack, int enemy_defense, int weapon_durability) {
    int damage = weapon_attack - enemy_defense;
    // If weapon durability is low, decrease damage
    if (weapon_durability < 10) {
        damage -= 5;
    }
    // If weapon is broken, no damage dealt
    if (weapon_durability == 0) {
        return 0;
    }
    // Return calculated damage
    return damage;
}

int main(void) {
    int player_health = 100;
    int enemy_health = 100;
    int weapon_attack = 50;
    int weapon_durability = 100;
    int enemy_attack = 25;
    int enemy_defense = 20;
    int round_num = 1;
    char player_choice;

    printf("You wake up to find yourself in a post-apocalyptic world filled with mutants and bandits. You hear a noise and quickly grab your weapon, a rusted old knife.\n");

    while (player_health > 0 && enemy_health > 0) {
        printf("\nROUND %d\n", round_num);
        printf("Your health: %d\n", player_health);
        printf("Enemy health: %d\n", enemy_health);

        printf("What do you want to do? (a)ttack or (d)efend?: ");
        scanf(" %c", &player_choice);

        // Player turn
        switch (player_choice) {
            case 'a':
                printf("You attack the enemy!\n");
                enemy_health -= calc_damage(weapon_attack, enemy_defense, weapon_durability);
                weapon_durability -= 10;
                break;
            case 'd':
                printf("You prepare to defend against the enemy's attack.\n");
                break;
            default:
                printf("Invalid input.\n");
                continue;
        }

        // Enemy turn
        if (enemy_health > 0) {
            printf("The enemy attacks you!\n");
            player_health -= enemy_attack;
        }

        round_num++;
    }

    // Determine winner
    if (player_health <= 0) {
        printf("You have died...\n");
    } else {
        printf("Congratulations! You have defeated the enemy and survived in this post-apocalyptic world!\n");
    }

    return 0;
}