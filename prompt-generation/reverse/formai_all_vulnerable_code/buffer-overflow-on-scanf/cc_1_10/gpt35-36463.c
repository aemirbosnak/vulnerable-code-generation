//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // seed the random number generator with system time
    srand(time(0));
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark forest. How did you get here?\n");
    printf("Look around and find a way out.\n");
    
    int playerChoice;
    int randomNumber;
    int hasKey = 0;
    
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Walk north\n");
        printf("2. Walk south\n");
        printf("3. Walk east\n");
        printf("4. Walk west\n");
        printf("5. Search area\n");
        printf("6. Quit\n");
        
        scanf("%d", &playerChoice);
        
        switch(playerChoice) {
            case 1:
                printf("You walk north but there's no way out.\n");
                break;
            case 2:
                printf("You walk south but there's no way out.\n");
                break;
            case 3:
                printf("You walk east but there's no way out.\n");
                break;
            case 4:
                printf("You walk west and find an old cabin.\n");
                printf("Do you want to go inside? (1 = yes, 2 = no): ");
                
                scanf("%d", &playerChoice);
                
                if (playerChoice == 1) {
                    printf("You go inside the cabin and find a key.\n");
                    hasKey = 1;
                } else {
                    printf("You decide not to enter the cabin.\n");
                }
                break;
            case 5:
                printf("You search the area and find a locked door.\n");
                printf("Do you want to try the key? (1 = yes, 2 = no): ");
                
                if (hasKey) {
                    scanf("%d", &playerChoice);
                    
                    if (playerChoice == 1) {
                        printf("You try the key and it unlocks the door!\n");
                        printf("Congratulations, you've found your way out of the forest!\n");
                        return 0;
                    } else {
                        printf("You decide not to use the key.\n");
                    }
                } else {
                    printf("You need a key to try the door.\n");
                }
                break;
            case 6:
                printf("Thanks for playing the Text-Based Adventure Game!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        
        // generate a random obstacle
        randomNumber = getRandomNumber(1, 4);
        
        if (randomNumber == 1) {
            printf("You hear a loud noise nearby.\n");
        } else if (randomNumber == 2) {
            printf("You see a strange figure in the distance.\n");
        } else if (randomNumber == 3) {
            printf("You feel like you're being watched.\n");
        } else {
            printf("You trip over a fallen tree.\n");
        }
    }
}