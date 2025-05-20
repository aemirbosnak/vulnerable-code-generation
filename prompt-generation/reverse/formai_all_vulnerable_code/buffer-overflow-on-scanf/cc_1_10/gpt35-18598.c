//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int sec) {   // Delay function to give the player time to read
    clock_t start_time = clock();
    while (clock() < start_time + (sec * CLOCKS_PER_SEC));
}

int main() {
    char name[20];
    int health = 100, gold = 0;
    int choice, monster_health, potion;
    
    printf("Welcome to the Visionary Adventure Game!\n");
    delay(1);
    
    printf("What is your name? ");
    scanf("%s", name);
    printf("\nHello, %s! You are about to embark on a dangerous adventure full of monsters and treasures.\n", name);
    delay(3);
    
    while (health > 0) {
        printf("\nYou can currently choose from the following options:\n");
        printf("1. Explore the wilderness\n");
        printf("2. Visit a nearby town\n");
        printf("3. Check inventory\n");
        printf("4. Quit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nYou head out into the wilderness...\n");
                delay(2);
                printf("You encounter a ferocious monster!\n");
                monster_health = rand() % 101;  // Random monster health from 0 to 100
                delay(2);
                while (monster_health > 0 && health > 0) {   // battle loop
                    printf("\nYour current health is %d.\n", health);
                    printf("The monster's current health is %d.\n", monster_health);
                    delay(2);
                    printf("Enter 1 to attack or 2 to use a health potion: ");
                    scanf("%d", &choice);
                    if (choice == 1) {
                        monster_health -= rand() % 26;  // Random attack damage from 0 to 25
                        printf("\nYou strike the monster and deal %d damage!\n", rand() % 26);
                    } else {
                        if (potion > 0) {
                            health += 25;
                            potion--;
                            printf("\nYou use a health potion and restore 25 health.\n");
                            printf("You now have %d health potions left.\n", potion);
                        } else {
                            printf("\nYou don't have any health potions left!\n");
                        }
                    }
                    health -= rand() % 26;  // Monster random attack damage from 0 to 25
                    printf("\nThe monster attacks and deals %d damage!\n", rand() % 26);
                }
                if (health > 0) {
                    printf("\nYou have defeated the monster and earned 50 gold!\n");
                    gold += 50;
                } else {
                    printf("\nYou have been defeated by the monster...\n");
                    printf("GAME OVER\n");
                    exit(0);
                }
                break;
            case 2:
                printf("\nYou travel to the nearby town...\n");
                delay(2);
                printf("You visit the local shop and see the following:\n");
                printf("1. Health potion (25 gold)\n");
                printf("2. Sword (+10 attack) (100 gold)\n");
                printf("3. Back to the wilderness\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch(choice) {
                    case 1:
                        if (gold >= 25) {
                            potion++;
                            gold -= 25;
                            printf("\nYou buy a health potion for 25 gold.\n");
                        } else {
                            printf("\nYou don't have enough gold to buy a health potion.\n");
                        }
                        break;
                    case 2:
                        if (gold >= 100) {
                            printf("\nYou buy a sword for 100 gold.\n");
                            gold -= 100;
                        } else {
                            printf("\nYou don't have enough gold to buy a sword.\n");
                        }
                        break;
                    case 3:
                        printf("\nYou leave the town and head back to the wilderness.\n");
                        break;
                    default:
                        printf("\nInvalid choice!\n");
                }
                break;
            case 3:
                printf("\nCurrent Status:\n");
                printf("Name: %s\n", name);
                printf("Health: %d\n", health);
                printf("Gold: %d\n", gold);
                printf("Potions: %d\n", potion);
                break;
            case 4:
                printf("\nExiting the game...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    printf("GAME OVER\n");
    return 0;
}