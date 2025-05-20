//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate a random number between min and max
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print the possible actions and their corresponding numbers
void printActions() {
    printf("\nYou look around and see:\n");
    printf("1. A door leading to the north\n");
    printf("2. A door leading to the east\n");
    printf("3. A door leading to the south\n");
    printf("4. A door leading to the west\n");
    printf("5. A staircase leading up\n");
    printf("6. A staircase leading down\n");
    printf("7. A mirror on the wall\n");
    printf("8. A mysterious object on the table\n");
    printf("9. A window with a view of the graveyard\n");
}

int main() {
    // Set seed for random number generator
    srand(time(NULL));
    
    // Declare and initialize variables
    bool gameOver = false;
    int actionsLeft = 9;
    
    // Print welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have just entered a creepy old house, and you don't know how to get out.\n");
    printf("Your objective is to find the key to the front door and escape the house.\n");
    printf("You have 9 actions to explore the house and find the key.\n");
    printf("Good luck!\n");
    
    // Game loop
    while (!gameOver && actionsLeft > 0) {
        // Print possible actions
        printActions();
        
        // Get user input
        printf("What do you want to do? ");
        int choice;
        scanf("%d", &choice);
        
        // Validate user input
        while (choice < 1 || choice > 9) {
            printf("Invalid choice. Please choose a number between 1 and 9: ");
            scanf("%d", &choice);
        }
        
        // Perform action based on user choice
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("You open the door and enter the room.\n");
                int monster = getRandom(1, 10);
                if (monster <= 3) {
                    printf("You are attacked by a ghost!\n");
                    printf("Game over.\n");
                    gameOver = true;
                } else {
                    printf("You find nothing of interest in the room.\n");
                }
                break;
            case 5:
                printf("You climb the stairs and enter the attic.\n");
                printf("You find a box with a key inside!\n");
                printf("Congratulations, you have found the key!\n");
                gameOver = true;
                break;
            case 6:
                printf("You descend the stairs and enter the basement.\n");
                printf("You find nothing of interest in the basement.\n");
                break;
            case 7:
                printf("You look in the mirror and see a ghostly figure behind you!\n");
                printf("You turn around, but no one is there.\n");
                break;
            case 8:
                printf("You approach the mysterious object on the table.\n");
                printf("It looks like a cursed amulet. Do you want to pick it up? (1 = Yes, 2 = No) ");
                int decision;
                scanf("%d", &decision);
                if (decision == 1) {
                    printf("You pick up the cursed amulet and feel a chill run down your spine.\n");
                    printf("Suddenly, the room is filled with ghosts!\n");
                    printf("Game over.\n");
                    gameOver = true;
                } else {
                    printf("You decide not to take any chances with the cursed amulet.\n");
                }
                break;
            case 9:
                printf("You look out the window and see the graveyard outside.\n");
                break;
        }
        
        // Decrease the number of actions left
        actionsLeft--;
    }
    
    // Print end of game message
    if (gameOver) {
        printf("Thanks for playing!\n");
    } else {
        printf("You have run out of actions. Better luck next time!\n");
    }
    
    return 0;
}