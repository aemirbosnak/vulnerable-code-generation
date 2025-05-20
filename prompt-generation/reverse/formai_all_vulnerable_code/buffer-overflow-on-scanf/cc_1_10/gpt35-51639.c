//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // initializing variables
    char choice;
    int coins = 0;
    int health = 100;

    // starting the adventure game
    printf("Welcome to the Forbidden Forest!\n");
    printf("You are on a mission to find the golden treasure.\n");
    
    // presenting options to the player
    while(1){

        printf("\nWhat would you like to do? (press a letter)\n");
        printf("a) Take the left path\n");
        printf("b) Take the right path\n");
        printf("c) Check your inventory\n");
        printf("d) Quit the game\n");
        
        scanf(" %c", &choice);

        // case when player takes left path
        if (choice == 'a'){
            printf("\nYou've encountered a monster! Prepare for battle!");
            
            //simulating battle, subtracting random amount of health
            int damage = rand() % 25 + 1;
            health -= damage;
            printf("\nThe monster hit you for %d damage. Your health is now %d.\n", damage, health);

            //if player's health drops to zero, game over
            if (health <= 0){
                printf("\nYou died. Game over :(\n");
                break;
            }

            //if player defeats monster, add coins to inventory
            else{
                printf("\nYou defeated the monster! You have earned 5 coins!\n");
                coins += 5;
            }
        }
        
        // case when player takes right path
        else if (choice == 'b'){
            printf("\nYou've stumbled upon a hidden cave. Do you want to enter? (y/n)\n");

            scanf(" %c", &choice);

            if (choice == 'y'){
                printf("\nYou found the golden treasure! Congratulations, you won the game!\n");
                printf("You've collected %d coins!\n", coins);
                break;
            }
            else{
                printf("\nYou're too scared to go inside. You turn back.\n");
            }
        }

        //case when player checks inventory
        else if (choice == 'c'){
            printf("\nYou currently have %d coins in your inventory\n", coins);
        }

        // case when player quits the game
        else if (choice == 'd'){
            printf("\nAre you sure you want to quit the game? (y/n)\n");

            scanf(" %c", &choice);

            if (choice == 'y'){
                printf("\nThanks for playing. See you next time!\n");
                break;
            }
            else{
                printf("\nContinue your adventure then!\n");
            }
        }

        //case when player inputs invalid choice
        else{
            printf("\nI'm sorry I didn't understand that. Try again.\n");
        }
    }

    return 0;
}