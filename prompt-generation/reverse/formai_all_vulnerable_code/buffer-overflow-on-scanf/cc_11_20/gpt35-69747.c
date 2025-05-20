//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int player_health = 100;
    int player_gold = 0;
    int player_location = 1;
    char player_name[20];
    int player_choice;
    int weapon_damage = 10;
    
    printf("\nWelcome to Adventure Quest!\n");
    printf("What's your name, adventurer?\n");
    scanf("%s", player_name);
    
    printf("\n%s, you have entered a vast world full of danger and treasure.\n", player_name);
    printf("You start off in a small village in the center of the world.\n");
    
    while(player_health > 0) {
        printf("\nWhat do you want to do?\n");
        printf("1. Explore the world\n");
        printf("2. Check your inventory\n");
        printf("3. Rest and recover\n");
        printf("4. Quit the game\n");
        scanf("%d", &player_choice);
        
        switch (player_choice) {
            case 1:
                printf("\nYou venture out into the world...\n");
                player_location = rand() % 5 + 1;
                switch (player_location) {
                    case 1:
                        printf("You stumble upon a group of bandits!\n");
                        printf("Quickly, what do you do?\n");
                        printf("1. Fight them!\n");
                        printf("2. Try to sneak past\n");
                        scanf("%d", &player_choice);
                        if (player_choice == 1) {
                            printf("\nYou draw your sword and engage in battle!\n");
                            player_health -= 20;
                            printf("You defeat the bandits, but take a hit in the process. Your health is now %d.\n", player_health);
                            player_gold += 10;
                            printf("You loot their bodies and find 10 gold!\n");
                        } else {
                            printf("\nYou try sneak past, but the bandits see you!\n");
                            printf("They attack and you take 10 damage. Your health is now %d.\n", player_health);
                        }
                        break;
                    case 2:
                        printf("You find a hidden cave!\n");
                        printf("Do you want to explore it?\n");
                        printf("1. Yes\n");
                        printf("2. No\n");
                        scanf("%d", &player_choice);
                        if (player_choice == 1) {
                            printf("\nYou enter the cave and find a chest of gold!\n");
                            player_gold += 50;
                            printf("You gain 50 gold. Your gold is now %d.\n", player_gold);
                        } else {
                            printf("\nYou leave the cave untouched.\n");
                        }
                        break;
                    case 3:
                        printf("You find yourself in the middle of a dense forest!\n");
                        printf("Do you want to continue through it?\n");
                        printf("1. Yes\n");
                        printf("2. No\n");
                        scanf("%d", &player_choice);
                        if (player_choice == 1) {
                            printf("\nYou navigate the forest and find a magical sword!\n");
                            printf("You equip the sword, increasing your attack damage to %d.\n", weapon_damage+20);
                            weapon_damage += 20;
                        } else {
                            printf("\nYou return to the safety of the village without any treasures.\n");
                        }
                        break;
                    case 4:
                        printf("You encounter a group of friendly travelers.\n");
                        printf("They offer you a healing potion for 20 gold, do you want to buy it?\n");
                        printf("1. Yes\n");
                        printf("2. No\n");
                        scanf("%d", &player_choice);
                        if (player_choice == 1) {
                            if (player_gold < 20) {
                                printf("\nSorry, you don't have enough gold.\n");
                            } else {
                                player_gold -= 20;
                                printf("\nYou buy a healing potion and drink it, recovering 30 health. Your health is now %d.\n", player_health+30);
                                player_health += 30;
                            }
                        } else {
                            printf("\nYou continue on your adventure without a healing potion.\n");
                        }
                        break;
                    case 5:
                        printf("You stumble upon a dragon!\n");
                        printf("What do you want to do?\n");
                        printf("1. Fight it!\n");
                        printf("2. Try to run away\n");
                        scanf("%d", &player_choice);
                        if (player_choice == 1) {
                            printf("\nYou draw your sword and engage in battle!\n");
                            player_health -= 40;
                            printf("You defeat the dragon, but take a massive hit in the process. Your health is now %d.\n", player_health);
                            player_gold += 100;
                            printf("You loot the dragon's hoard and find 100 gold!\n");
                        } else {
                            printf("\nYou try to run away, but the dragon catches up to you!\n");
                            printf("It attacks and you take 30 damage. Your health is now %d.\n", player_health);
                        }
                        break;
                }
                break;
            case 2:
                printf("\n%s, you currently have %d gold and a sword that deals %d damage.\n", player_name, player_gold, weapon_damage);
                break;
            case 3:
                printf("\nYou take a break and recover 20 health. Your health is now %d.\n", player_health+20);
                player_health += 20;
                break;
            case 4:
                printf("\nThank you for playing Adventure Quest! Goodbye, %s.", player_name);
                exit(0);
            default:
                printf("\nSorry, that's an invalid choice.\n");
                break;
        }
    }
    printf("\nOh no, you have died! Game over, %s.\n", player_name);
    return 0;
}