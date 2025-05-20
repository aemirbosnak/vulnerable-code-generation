//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerHealth = 100;
    int enemyHealth = 50;
    int playerAttack = rand() % 10 + 1;
    int enemyAttack = rand() % 10 + 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are a brave space warrior with %d health points.\n", playerHealth);
    printf("Your enemy is a fierce alien with %d health points.\n", enemyHealth);
    printf("You attack with %d damage points.\n", playerAttack);
    printf("The alien attacks with %d damage points.\n", enemyAttack);

    int choice;
    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Attack\n2. Defend\n3. Check health\n4. Check enemy health\n5. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                enemyHealth -= playerAttack;
                if(enemyHealth <= 0) {
                    printf("\nYou have defeated the alien!");
                    break;
                }
                else {
                    printf("\nYou attacked the alien.");
                }
                break;
            case 2:
                playerHealth -= enemyAttack;
                if(playerHealth <= 0) {
                    printf("\nYou have been defeated by the alien.");
                    break;
                }
                else {
                    printf("\nYou defended yourself.");
                }
                break;
            case 3:
                printf("\nYour current health is %d.", playerHealth);
                break;
            case 4:
                printf("\nThe alien's current health is %d.", enemyHealth);
                break;
            case 5:
                printf("\nThanks for playing!");
                exit(0);
            default:
                printf("\nInvalid choice.");
        }
    }

    return 0;
}