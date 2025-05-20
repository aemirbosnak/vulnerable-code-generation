//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //initialize random seed

    //welcome message
    printf("Welcome to the Text-Based Adventure game!\n");
    printf("In this game, you will be on a quest to save the princess.\n");

    //player name input
    char playerName[20];
    printf("What is your name, adventurer?\n");
    scanf("%s", playerName);
    printf("Hello %s!\n", playerName);

    //storyline
    printf("You have been summoned by the king to save his daughter, Princess Lana.\n");
    printf("She has been kidnapped by the evil sorcerer, Zoltar, and taken to his castle.\n");
    printf("Your mission is to rescue the princess and bring her back to the king safely.\n");
    printf("Are you ready for this dangerous quest, %s?\n", playerName);

    //player decision to start game
    char decision;
    printf("Enter 'y' to start the game, 'n' to exit.\n");
    scanf(" %c", &decision);
    if(decision!='y'){
        printf("Goodbye, %s!\n", playerName);
        return 0;
    }

    //game start
    printf("You are now at the entrance of Zoltar's castle.\n");
    int direction;
    int randomNum;
    printf("Choose your direction:\n1-North\n2-South\n3-East\n4-West\n");
    scanf("%d", &direction);
    randomNum = rand() % 4 + 1; //generate random number 1-4

    //player encounters obstacle
    if(direction == randomNum){
        printf("Uh-oh, you've encountered a trap!\n");
        printf("You have been trapped and unable to escape.\n");
        printf("Game over, %s!", playerName);
        return 0;
    }

    //player successfully navigates to next room
    printf("Congratulations, you've navigated to the next room safely!\n");
    printf("You see two doors in front of you.\n");
    int doorNum;
    printf("Which door do you choose? 1 or 2?\n");
    scanf("%d", &doorNum);

    //player encounters enemy in the room
    if(doorNum==1){
        printf("Oops, there's an enemy in the room!\n");
        printf("Defeat the enemy to proceed to the next room.\n");
        int playerAttack = rand() % 10 + 1; //player attack power
        int enemyAttack = rand() % 10 + 1; //enemy attack power
        int playerHealth = 50; //set player health to 50
        int enemyHealth = 30; //set enemy health to 30
        while(playerHealth > 0 && enemyHealth > 0){
            printf("Player health: %d\n", playerHealth);
            printf("Enemy health: %d\n", enemyHealth);
            int playerDamage = playerAttack + rand() % 5 + 1; //randomize player damage
            int enemyDamage = enemyAttack + rand() % 5 + 1; //randomize enemy damage
            enemyHealth -= playerDamage;
            playerHealth -= enemyDamage;
            printf("You attack the enemy for %d damage!\n", playerDamage);
            printf("The enemy attacks you for %d damage!\n", enemyDamage);
        }
        if(playerHealth<=0){
            printf("You have been defeated!\n");
            printf("Game over, %s!\n", playerName);
            return 0;
        }
        if(enemyHealth<=0){
            printf("You have defeated the enemy and proceed to the next room!\n");
        }
    }

    //player progresses through level
    printf("You are now in the final room!\n");
    printf("You see Princess Lana tied up in the corner of the room.\n");
    printf("Zoltar appears out of nowhere and challenges you to a fight!\n");
    int playerAttackFinal = rand() % 20 + 1; //higher player attack power in final fight
    int enemyAttackFinal = rand() % 20 + 1;
    int playerHealthFinal = 75; //higher player health in final fight
    int enemyHealthFinal = 50;
    while(playerHealthFinal > 0 && enemyHealthFinal > 0){
        printf("Player health: %d\n", playerHealthFinal);
        printf("Enemy health: %d\n", enemyHealthFinal);
        int playerDamageFinal = playerAttackFinal + rand() % 5 + 1;
        int enemyDamageFinal = enemyAttackFinal + rand() % 5 + 1;
        enemyHealthFinal -= playerDamageFinal;
        playerHealthFinal -= enemyDamageFinal;
        printf("You attack Zoltar for %d damage!\n", playerDamageFinal);
        printf("Zoltar attacks you for %d damage!\n", enemyDamageFinal);
    }
    if(playerHealthFinal<=0){
        printf("You have been defeated by Zoltar!\n");
        printf("Game over, %s!\n", playerName);
        return 0;
    }
    if(enemyHealthFinal<=0){
        printf("Congratulations %s, you have defeated Zoltar and saved Princess Lana!\n", playerName);
        printf("Thank you for playing!\n");
    }

    return 0;
}