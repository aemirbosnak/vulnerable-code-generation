//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
    int health = 100;
    int potion = 3;
    int monster_HP = 50;
    int monster_attack = 10;
    int damage_taken;
    int choice;
    char player_name[20];

    printf("Welcome to the adventure game! Please enter your name: ");
    scanf("%s", player_name);
    printf("\nWelcome, %s! Your adventure begins now.\n", player_name);
    printf("\nYou find yourself in a dark forest. You hear a loud roar in the distance.\n");
    printf("As you move towards the sound, you see a large monster blocking your path.\n");

    while (monster_HP > 0 && health > 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n2. Drink potion\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou attack the monster!\n");
                monster_HP -= 20;
                printf("The monster's HP is now %d.\n", monster_HP);
                damage_taken = monster_attack;
                health -= damage_taken;
                printf("The monster attacks you and deals %d damage!\n", damage_taken);
                printf("Your HP is now %d.\n", health);
                break;
            case 2:
                if (potion > 0) {
                    potion--;
                    health += 30;
                    printf("\nYou drink a potion and gain 30 HP. You now have %d potions remaining.\n", potion);
                    printf("Your HP is now %d.\n", health);
                } else {
                    printf("\nYou don't have any potions left!\n");
                }
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }

    if (monster_HP <= 0) {
        printf("\nCongratulations, you defeated the monster!\n");
    } else {
        printf("\nYou have been defeated by the monster! Game over.\n");
    }

    return 0;
}