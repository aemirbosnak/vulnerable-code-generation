//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int playerHealth = 100;
int enemyHealth = 50;
int itemCount = 0;
int roomNumber = 1;

void roomOne();
void roomTwo();
void roomThree();

int main(){
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");    
    roomOne(); 
    return 0;
}

void roomOne(){
    int choice;
    printf("\nAfter searching the room you find a key, what would you like to do?\n");
    printf("1: Go through the door\n");
    printf("2: Stay in the room\n");
    printf("3: Check your inventory\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            roomNumber++;
            roomTwo();
            break;
        case 2:
            printf("\nYou cower in fear in the corner of the room for hours until you eventually starve to death. GAME OVER.\n\n");
            exit(0);
        case 3:
            printf("\nYou currently have %d items in your inventory.\n\n", itemCount);
            roomOne();
            break;
        default:
            printf("\nInvalid input. Please try again.\n\n");
            roomOne();
            break;
    }
}

void roomTwo(){
    int choice;
    printf("\nYou enter a musty old room with a rotting table in the center, what would you like to do?\n");
    printf("1: Search the table\n");
    printf("2: Check your inventory\n");
    printf("3: Go back through the door\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("\nYou find a small med-kit in the drawer of the table.\n\n");
            itemCount++;
            roomTwo();
            break;
        case 2:
            printf("\nYou currently have %d items in your inventory.\n\n", itemCount);
            roomTwo();
            break;
        case 3:
            roomNumber--;
            roomOne();
            break;
        default:
            printf("\nInvalid input. Please try again.\n\n");
            roomTwo();
            break;
    }
}

void roomThree(){
    int choice;
    printf("\nYou enter a dimly lit room inhabited by a fierce enemy, what would you like to do?\n");
    printf("1: Attack the enemy\n");
    printf("2: Drink a health potion\n");
    printf("3: Check your inventory\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            enemyHealth -= 20;
            printf("\nYou successfully deal damage to the enemy.\n");
            if(enemyHealth <= 0){
                printf("\nCongratulations! You have defeated the enemy and escaped the dungeon!\n\n");
                exit(0);
            }
            printf("\nThe enemy now has %d health remaining.\n\n", enemyHealth);
            printf("\n\nThe enemy strikes you and deals 10 damage.\n");
            playerHealth -= 10; 
            if(playerHealth <= 0){
                printf("\nYou have been defeated by the enemy. GAME OVER.\n\n");
                exit(0);
            }
            roomThree();
            break;
        case 2:
            if(itemCount == 0){
                printf("\nYou do not have any health potions in your inventory.\n\n");
                roomThree();
            } else {
                playerHealth += 20;
                printf("\nYou drink a health potion and gain 20 health.\n");
                itemCount--;
                printf("\nYou now have %d items left in your inventory.\n\n", itemCount);
                printf("\nThe enemy strikes you and deals 10 damage.\n");
                playerHealth -= 10; 
                if(playerHealth <= 0){
                    printf("\nYou have been defeated by the enemy. GAME OVER.\n\n");
                    exit(0);
                }
                roomThree();
            }
            break;
        case 3:
            printf("\nYou currently have %d items in your inventory.\n\n", itemCount);
            roomThree();
            break;
        default:
            printf("\nInvalid input. Please try again.\n\n");
            roomThree();
            break;
    }
}