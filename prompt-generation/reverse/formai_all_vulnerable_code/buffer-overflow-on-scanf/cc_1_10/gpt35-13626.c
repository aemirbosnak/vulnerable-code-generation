//FormAI DATASET v1.0 Category: Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the main menu
void displayMainMenu(){
    printf("\n\nMedieval Adventure Game\n\n");
    printf("1. Start New Game\n");
    printf("2. Load Game\n");
    printf("3. Instructions\n");
    printf("4. Exit\n\n");
    printf("Choose an option: ");
}

// Function to display the instructions menu
void displayInstructions(){
    printf("\n\nInstructions\n\n");
    printf("You are a knight on a quest to save the kingdom from evil forces. ");
    printf("You will encounter various obstacles and enemies along the way, ");
    printf("and must use your sword and shield to protect yourself. ");
    printf("Use the arrow keys to move around, spacebar to attack, and 'p' to pause the game. ");
    printf("Good luck!\n\n");
    printf("Press any key to return to the main menu...");
    fflush(stdin);
    getchar();
}

// Function to generate a random number for enemy health
int generateEnemyHealth(){
    srand(time(NULL));
    return (rand() % 50) + 50;
}

int main(){
    int option;
    int playerHealth = 100;
    int enemyHealth;

    printf("\n\nWelcome to the Medieval Adventure Game!\n\n");

    while(1){
        displayMainMenu();
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("\nStarting new game...\n");
                enemyHealth = generateEnemyHealth();
                while(playerHealth > 0 && enemyHealth > 0){
                    printf("\nPlayer health: %d\n", playerHealth);
                    printf("Enemy health: %d\n\n", enemyHealth);
                    printf("Press spacebar to attack...");
                    fflush(stdin);
                    getchar();

                    // Calculate player attack damage
                    srand(time(NULL));
                    int attack = rand() % 50;

                    // Calculate enemy attack damage
                    int enemyAttack = rand() % 25;

                    if(attack > enemyAttack){
                        printf("\nYou hit the enemy and dealt %d damage!\n", attack - enemyAttack);
                        enemyHealth -= (attack - enemyAttack);
                    }
                    else if(enemyAttack > attack){
                        printf("\nThe enemy hit you and dealt %d damage!\n", enemyAttack - attack);
                        playerHealth -= (enemyAttack - attack);
                    }
                    else{
                        printf("\nYou and the enemy both missed!\n");
                    }
                }
                if(enemyHealth <= 0){
                    printf("\nYou defeated the enemy and saved the kingdom!\n");
                }
                else{
                    printf("\nThe enemy defeated you. Game over.\n");
                }
                break;

            case 2:
                printf("\nLoading game...\n");
                // Code to load game goes here
                break;

            case 3:
                displayInstructions();
                break;

            case 4:
                printf("\nGoodbye!\n");
                exit(0);

            default:
                printf("\nInvalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}