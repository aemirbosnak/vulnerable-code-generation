//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    //Initialization of variables
    
    int health = 100;
    int attack = 20;
    int treasure = 0;
    char name[20];
    int choice;
    
    //Introduction
    
    printf("Welcome to The Lost Cave Adventure Game!\n");
    printf("What's your name adventurer?\n");
    scanf("%s", name);
    printf("Greetings %s! You are about to face a challenging adventure!\n", name);

    //Gameplay

    while(health > 0) {
        
        printf("You find yourself in a dark cave. There are two tunnels, which way do you go?\n");
        printf("1. Left tunnel\n");
        printf("2. Right tunnel\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You enter the left tunnel.\n");
                printf("You encounter a monster!\n");
                printf("Battle Alert! You have to fight the monster.\n");

                //Battle

                while(health > 0 && attack > 0) { //Continue battle until either the player or the monster dies
                    
                    printf("You attack the monster with your sword.\n");
                    int damage = rand() % 20 + 10; //Randomize damage between 10 to 30
                    printf("You deal %d damage.\n", damage);
                    attack -= damage;
                    
                    if(attack <= 0) { //Player lost
                        printf("The monster defeated you. GAME OVER\n");
                        return 0;
                    }
                    
                    damage = rand() % 10 + 5; //Randomize damage between 5 to 15
                    printf("The monster attacks you.\n");
                    printf("You lose %d health points.\n", damage);
                    health -= damage;
                }
                printf("You defeated the monster!\n");
                treasure += 50; //Add some treasure after winning
                printf("You found 50 treasure!\n");
                break;
            
            case 2:
                printf("You enter the right tunnel.\n");
                printf("You find a chest filled with treasure!\n");
                treasure += 100; //Add larger amount of treasure in this path
                printf("You found 100 treasure!\n");
                break;
            
            default:
                printf("Invalid choice. Please enter 1 or 2.\n");
                continue; //Skip to the next iteration of the loop in case of invalid input
        }
        
        printf("Your current status is: Name:%s Health:%d Attack:%d Treasure:%d\n", name, health, attack, treasure);
    }

    //Game Over

    printf("Your health points have reached 0. You have failed your mission!\n");
    printf("It's GAME OVER for you, %s\n", name);
    return 0;
}