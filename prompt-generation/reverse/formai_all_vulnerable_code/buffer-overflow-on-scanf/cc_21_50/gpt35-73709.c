//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <string.h>

int main(){
    
    char playerName[20];
    int playerHealth = 100;
    int playerGold = 0;
    int playerLevel = 1;
    int playerExp = 0;
    
    printf("Welcome to the futuristic world of Zantor!\n\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("\n");

    printf("Greetings %s! Your mission is to save the world from the alien invasion that has taken place on planet Zantor. You will need to make your way through the city and find the alien leader's lair located in the heart of the city.\n\n", playerName);
    
    printf("You find yourself at the entrance of the city. The city is in ruins and there is debris everywhere. What do you do?\n");
    printf("A. Investigate the debris\nB. Look for a nearby shelter\nC. Search for other survivors\n");

    char choice1;

    while (1){
        scanf(" %c", &choice1);
        
        if (choice1 == 'A' || choice1 == 'a'){
            printf("\nYou found a laser gun! This will be useful on your journey.\n");
            printf("You are now ready to proceed through the city.\n\n");
            break;
        } 
        else if (choice1 == 'B' || choice1 == 'b'){
            printf("\nYou found a nearby shelter and spent the night there. You wake up in the morning feeling refreshed.\n");
            printf("You are now ready to proceed through the city.\n\n");
            break;
        }
        else if (choice1 == 'C' || choice1 == 'c'){
            printf("\nYou search for other survivors but there is no one in sight. You realize you must proceed alone.\n");
            printf("You are now ready to proceed through the city.\n\n");
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("As you make your way through the city, you come across a group of aliens. What do you do?\n");
    printf("A. Fight the aliens\nB. Sneak past them\nC. Try to reason with the aliens\n");

    char choice2;

    while (1){
        scanf(" %c", &choice2);
        
        if (choice2 == 'A' || choice2 == 'a'){
            printf("\nYou engage in a fight with the aliens. It is a difficult battle but you manage to defeat them and move on.\n");
            playerHealth = playerHealth - 25;
            playerGold = playerGold + 50;
            playerExp = playerExp + 20;
            break;
        } 
        else if (choice2 == 'B' || choice2 == 'b'){
            printf("\nYou carefully sneak past the aliens and avoid a conflict.\n");
            playerExp = playerExp + 10;
            break;
        }
        else if (choice2 == 'C' || choice2 == 'c'){
            printf("\nYou try to reason with the aliens but they do not understand you. They attack you and you are forced to fight.\n");
            playerHealth = playerHealth - 50;
            playerGold = playerGold + 20;
            playerExp = playerExp + 10;
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("You finally make it to the alien leader's lair. There are guards standing at the entrance. What do you do?\n");
    printf("A. Fight the guards\nB. Bribe the guards\nC. Sneak past the guards\n");

    char choice3;

    while (1){
        scanf(" %c", &choice3);
        
        if (choice3 == 'A' || choice3 == 'a'){
            printf("\nYou engage in a fight with the guards. It is a difficult battle and you are wounded but you manage to defeat them and enter the lair.\n");
            playerHealth = playerHealth - 50;
            playerGold = playerGold + 100;
            playerExp = playerExp + 50;
            break;
        } 
        else if (choice3 == 'B' || choice3 == 'b'){
            if (playerGold > 50){
                printf("\nYou bribe the guards with your gold and are allowed to enter the lair.\n");
                playerGold = playerGold - 50;
                playerExp = playerExp + 20;
                break;
            }
            else {
                printf("\nYou do not have enough gold to bribe the guards. You will need to find another way in.\n");
            }
        }
        else if (choice3 == 'C' || choice3 == 'c'){
            printf("\nYou carefully sneak past the guards and enter the lair undetected.\n");
            playerExp = playerExp + 30;
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("As you enter the lair, you are faced with the alien leader. What do you do?\n");
    printf("A. Engage in battle with the alien leader\nB. Try to reason with the alien leader\nC. Attempt to deactivate the alien leader\n");

    char choice4;

    while (1){
        scanf(" %c", &choice4);
        
        if (choice4 == 'A' || choice4 == 'a'){
            printf("\nYou engage in an epic battle with the alien leader. It is a difficult battle but you manage to defeat him and save the world!\n");
            playerHealth = playerHealth - 75;
            playerGold = playerGold + 200;
            playerExp = playerExp + 100;
            break;
        } 
        else if (choice4 == 'B' || choice4 == 'b'){
            printf("\nYou try to reason with the alien leader but he does not understand your language. You are forced to engage in battle.\n");
            playerHealth = playerHealth - 75;
            playerGold = playerGold + 50;
            playerExp = playerExp + 50;
            break;
        }
        else if (choice4 == 'C' || choice4 == 'c'){
            printf("\nYou attempt to deactivate the alien leader but fail. He sees you and attacks you.\n");
            playerHealth = playerHealth - 100;
            playerGold = playerGold + 10;
            playerExp = playerExp + 20;
            break;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("\n\n");
    printf("Congratulations, %s! You have saved the world from the alien invasion and completed your mission.\n", playerName);
    printf("Stats:\n");
    printf("Health: %d\n", playerHealth);
    printf("Gold: %d\n", playerGold);
    printf("Level: %d\n", playerLevel);
    printf("Experience: %d\n", playerExp);
    printf("\n");

    return 0;
}