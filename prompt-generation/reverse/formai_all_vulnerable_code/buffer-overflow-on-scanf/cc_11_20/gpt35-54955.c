//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int choice, health = 100, potion = 0, dragon_health = 100, dragon_attack, attack, dodge, escape;
    char name[20];
    srand(time(NULL));

    printf("Welcome to Dragon Slayer!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("\nHello, %s! Your kingdom is being terrorized by a dragon and you are the only one who can stop it.\nAre you ready to embark on this adventure?\nEnter 1 for yes and 2 for no\n", name);
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nGreat! Let's begin.\n\n");

        do {
            printf("You are in a forest and you see a dragon in the distance. What do you do?\n1. Attack the dragon\n2. Drink a potion\n3. Run away\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    attack = rand() % 30 + 1;
                    dragon_attack = rand() % 20 + 1;
                    printf("\nYou attacked the dragon and dealt %d damage.\nThe dragon attacks back and dealt %d damage.\n", attack, dragon_attack);
                    health -= dragon_attack;
                    dragon_health -= attack;
                    break;
                case 2:
                    if(potion == 0) {
                        printf("\nYou do not have any potions left.\n");
                    } else {
                        health += 30;
                        if(health > 100) {
                            health = 100;
                        }
                        potion--;
                        printf("\nYou drink a potion and regain 30 health points.\n");
                    }
                    break;
                case 3:
                    dodge = rand() % 2;
                    if(dodge == 0) {
                        printf("\nYou successfully escaped from the dragon.\n");
                        escape = 1;
                    } else {
                        printf("\nThe dragon blocks your escape.\n");
                        dragon_attack = rand() % 20 + 1;
                        printf("The dragon attacks and dealt %d damage.\n", dragon_attack);
                        health -= dragon_attack;
                    }
                    break;
                default:
                    printf("\nInvalid input.\n");
            }

            if(dragon_health <= 0) {
                printf("\nCongratulations, you have defeated the dragon and saved your kingdom!\n");
                printf("%s's health: %d\nDragon's health: %d\n", name, health, dragon_health);
                return 0;
            } else if(health <= 0) {
                printf("\nYou have been defeated by the dragon. Game over.\n");
                printf("%s's health: %d\nDragon's health: %d\n", name, health, dragon_health);
                return 0;
            }

            printf("\n%s's health: %d\nDragon's health: %d\n", name, health, dragon_health);

            if(!escape) {
                dragon_attack = rand() % 20 + 1;
                printf("The dragon attacks and dealt %d damage.\n", dragon_attack);
                health -= dragon_attack;

                if(health <= 0) {
                    printf("\nYou have been defeated by the dragon. Game over.\n");
                    printf("%s's health: %d\nDragon's health: %d\n", name, health, dragon_health);
                    return 0;
                }
            }

            printf("\nWhat do you want to do?\n1. Attack the dragon\n2. Drink a potion\n3. Run away\n");
            scanf("%d", &choice);
        } while(choice != 3);

        printf("\nYou were not able to defeat the dragon. Game over.\n");
        printf("%s's health: %d\nDragon's health: %d\n", name, health, dragon_health);
    } else if(choice == 2) {
        printf("\nMaybe next time. Goodbye!\n");
    } else {
        printf("\nInvalid input. Goodbye!\n");
    }

    return 0;
}