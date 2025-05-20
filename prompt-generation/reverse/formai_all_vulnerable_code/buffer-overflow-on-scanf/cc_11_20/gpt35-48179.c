//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char playerName[30];
    int playerHealth = 100;
    int playerAge;
    char playerGender;
    char playerClass[15];
    
    printf("Welcome to the Happy Adventure Game!\n");
    printf("Please enter your name: ");
    fgets(playerName, 30, stdin);
    playerName[strcspn(playerName, "\n")] = 0;
    
    printf("Hello, %s! How old are you? ", playerName);
    scanf("%d", &playerAge);
    getchar();
    
    printf("Are you male or female? (m/f) ");
    scanf("%c", &playerGender);
    getchar();

    printf("What is your class? (warrior/mage/thief) ");
    fgets(playerClass, 15, stdin);
    playerClass[strcspn(playerClass, "\n")] = 0;

    printf("Let's start your adventure, %s!\n", playerName);
    printf("You are walking through a forest, when suddenly a goblin appears!\n");
    printf("What do you want to do? (fight/run) ");
    
    char userInput[10];
    fgets(userInput, 10, stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    
    if(strcmp(userInput, "fight") == 0){
        printf("You attack the goblin!\n");
        playerHealth -= 30;
        printf("The goblin attacks you back! You lose 20 health points.\n");
        playerHealth -= 20;
    }
    else if(strcmp(userInput, "run") == 0){
        printf("You run away from the goblin, but stumble and lose 10 health points.\n");
        playerHealth -= 10;
    }
    else{
        printf("Invalid input. You lose 10 health points.\n");
        playerHealth -= 10;
    }

    if(playerHealth <= 0){
        printf("You have died. Better luck next time!\n");
        return 0;
    }
    
    printf("You continue your adventure, and reach a village.\n");
    printf("What do you want to do? (rest/explore) ");
    
    fgets(userInput, 10, stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    
    if(strcmp(userInput, "rest") == 0){
        printf("You find an inn, and rest for the night. You gain 20 health points.\n");
        playerHealth += 20;
    }
    else if(strcmp(userInput, "explore") == 0){
        printf("You explore the village and find a treasure chest! You gain 50 gold coins.\n");
    }
    else{
        printf("Invalid input. You lose 10 health points.\n");
        playerHealth -= 10;
    }

    if(playerHealth <= 0){
        printf("You have died. Better luck next time!\n");
        return 0;
    }
    
    printf("You continue your adventure, and come across a dragon!\n");
    printf("What do you want to do? (fight/run) ");
    
    fgets(userInput, 10, stdin);
    userInput[strcspn(userInput, "\n")] = 0;
    
    if(strcmp(userInput, "fight") == 0){
        if(strcmp(playerClass, "warrior") == 0){
            printf("You charge at the dragon with your sword, and deal 50 damage!\n");
            printf("The dragon attacks you with fire breath, but your heavy armor protects you. You lose 10 health points.\n");
            playerHealth -= 10;
        }
        else if(strcmp(playerClass, "mage") == 0){
            printf("You cast a powerful fire spell, and deal 70 damage to the dragon!\n");
            printf("The dragon attacks you, but you quickly cast a shield spell to protect yourself. You lose 10 health points.\n");
            playerHealth -= 10;
        }
        else if(strcmp(playerClass, "thief") == 0){
            printf("You sneak around the dragon and strike it from behind! You deal 60 damage!\n");
            printf("The dragon strikes back, but you dodge its attack. You lose 10 health points.\n");
            playerHealth -= 10;
        }
        else{
            printf("Invalid class. You lose 20 health points.\n");
            playerHealth -= 20;
        }
    }
    else if(strcmp(userInput, "run") == 0){
        printf("You try to run away, but the dragon catches you and breathes fire on you. You lose 30 health points!\n");
        playerHealth -= 30;
    }
    else{
        printf("Invalid input. You lose 10 health points.\n");
        playerHealth -= 10;
    }

    if(playerHealth <= 0){
        printf("You have died. Better luck next time!\n");
        return 0;
    }
    
    printf("Congratulations, %s! You have completed the Happy Adventure Game!\n", playerName);
    return 0;
}