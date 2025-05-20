//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
    printf("\033[2J\033[1;1H");
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Procedural Space Adventure!\n\n");
    printf("You wake up to find yourself in the cockpit of a spaceship that you don't recognize.\n");
    printf("You check the display and see that you are in the middle of space, and your only option is to explore.\n\n");
    char playerName[20];
    printf("What's your name, adventurer?\n");
    scanf("%s", playerName);
    printf("\nAlright %s, let's get started!\n", playerName);
    printf("You have no idea where you are, but you decide to take a look outside the ship.\n\n");
    printf("As you approach the viewport, you see endless stars and planets in the distance.\n");
    printf("But you also spot a strange-looking asteroid field nearby.\n\n");
    printf("Do you want to go check out the asteroid field? (y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if(choice == 'y') {
        printf("\nYou navigate through the asteroid field and come across a rare mineral!\n");
        printf("You collect some of it and decide to continue exploring.\n\n");
    } else {
        printf("You decide to play it safe and continue exploring elsewhere.\n\n");
    }
    printf("You fly around aimlessly, hoping to come across something interesting.\n");
    printf("Suddenly, your ship's computer beeps and alerts you to an incoming transmission!\n\n");
    printf("\"Hello there! This is Captain Nemo of the Intergalactic Space Police.\"\n");
    printf("\"We've detected some dangerous space pirates in your area. You need to take them down!\"\n\n");
    printf("What do you want to do? (1 = Fight, 2 = Run)\n");
    int action;
    scanf("%d", &action);
    if(action == 1) {
        printf("\nYou gear up your weapons and prepare for the battle of your life!\n");
        int enemyHealth = rand() % 101 + 100;
        int yourHealth = rand() % 101 + 100;
        int enemyDamage;
        int yourDamage;
        printf("Get ready to fight!\n\n");
        while(yourHealth > 0 && enemyHealth > 0) {
            clearScreen();
            printf("Your health: %d\n", yourHealth);
            printf("Enemy health: %d\n\n", enemyHealth);
            yourDamage = rand() % 21 + 10;
            enemyDamage = rand() % 31 + 20;
            printf("You attack the enemy for %d damage!\n", yourDamage);
            enemyHealth -= yourDamage;
            if(enemyHealth <= 0) {
                printf("You defeated the enemy space pirates! Great job!\n\n");
                break;
            }
            printf("The enemy attacks you for %d damage!\n", enemyDamage);
            yourHealth -= enemyDamage;
            if(yourHealth <= 0) {
                printf("Oh no! You've been defeated. Better luck next time, adventurer!\n\n");
                break;
            }
        }
    } else {
        printf("\nYou try to run away, but the enemy catches up to you and attacks!\n");
        int enemyHealth = rand() % 101 + 100;
        int yourHealth = rand() % 101 + 100;
        int enemyDamage;
        int yourDamage;
        printf("Get ready to fight!\n\n");
        while(yourHealth > 0 && enemyHealth > 0) {
            clearScreen();
            printf("Your health: %d\n", yourHealth);
            printf("Enemy health: %d\n\n", enemyHealth);
            yourDamage = rand() % 21 + 10;
            enemyDamage = rand() % 31 + 20;
            printf("You attack the enemy for %d damage!\n", yourDamage);
            enemyHealth -= yourDamage;
            if(enemyHealth <= 0) {
                printf("You defeated the enemy space pirates! Great job!\n\n");
                break;
            }
            printf("The enemy attacks you for %d damage!\n", enemyDamage);
            yourHealth -= enemyDamage;
            if(yourHealth <= 0) {
                printf("Oh no! You've been defeated. Better luck next time, adventurer!\n\n");
                break;
            }
        }
    }
    printf("Congratulations on completing your Procedural Space Adventure, %s!\n", playerName);
    printf("Will you explore space again someday? (y/n)\n");
    scanf(" %c", &choice);
    if(choice == 'y') {
        printf("\nGreat to hear! Safe travels, adventurer!\n");
    } else {
        printf("Thanks for playing, and farewell!\n");
    }
    return 0;
}