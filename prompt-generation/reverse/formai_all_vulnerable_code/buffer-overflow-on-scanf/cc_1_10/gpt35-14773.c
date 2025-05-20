//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: configurable
#include <stdio.h>

int main() {
    //initialize variables
    int health = 100;
    int gold = 0;
    int monster_health = 50;
    int potion_count = 3;
    int attack_power = 25;

    //start game
    printf("Welcome to the Adventure Game!\n\n");

    //game loop
    while(health > 0) {
        printf("What would you like to do?\n");
        printf("1. Attack the monster\n");
        printf("2. Drink a health potion\n");
        printf("3. Run away\n");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You attack the monster with your sword!\n");
                monster_health -= attack_power;

                if(monster_health <= 0) {
                    printf("Congrats! You defeated the monster!\n");
                    gold += 50;
                    monster_health = 50;
                }
                else {
                    printf("The monster has %d health left.\n", monster_health);

                    health -= 10;
                    printf("The monster attacks you and deals 10 damage.\n");
                    printf("Your health is now %d.\n", health);
                }

                break;

            case 2:
                if(potion_count > 0) {
                    printf("You drink a health potion and gain 30 health.\n");
                    health += 30;
                    potion_count--;
                    printf("You have %d health potions left.\n", potion_count);
                }
                else {
                    printf("Sorry, you're out of health potions!\n");
                }

                break;
                
            case 3:
                printf("You run away!\n");
                return 0;

            default:
                printf("Sorry, I didn't understand your choice.\n");
        }
    }

    printf("Game over! You have %d gold.\n", gold);

    return 0;
}