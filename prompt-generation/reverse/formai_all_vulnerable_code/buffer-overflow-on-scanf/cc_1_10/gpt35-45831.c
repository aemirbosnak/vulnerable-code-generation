//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void startGame();
void gameOptions();
void playGame();
void displayIntroduction();
void displayWinningMessage();
void displayLosingMessage();
void showInventory();
void getItem(char itemName[]);
void showMap();
void moveToLocation(int location);

// global variables
int playerHealth = 100;
char playerInventory[100][100];
int inventoryCount = 0;

// main function
int main() {
    startGame();
    return 0;
}

// function to begin the game
void startGame() {
    printf("Welcome to the Adventure Game!\n\n");
    printf("Please select an option:\n");
    gameOptions();
}

// function to display game options
void gameOptions() {
    printf("\t1. Play Game\n");
    printf("\t2. Quit Game\n\n");
    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option) {
        case 1:
            playGame();
            break;
        case 2:
            printf("\nThanks for playing!\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            gameOptions();
    }
}

// function to play the game
void playGame() {
    displayIntroduction();
    showInventory();
    
    int playerChoice;
    char itemName[100];
    int currentLocation = 0;
    while(1) {
        printf("\nYou are currently at location %d.\n", currentLocation);
        printf("What would you like to do?\n");
        printf("\t1. Move to a different location\n");
        printf("\t2. View inventory\n");
        printf("\t3. View map\n");
        printf("\t4. Get item\n\n");
        printf("Enter your choice: ");
        scanf("%d", &playerChoice);

        switch(playerChoice) {
            case 1:
                moveToLocation(currentLocation + 1);
                currentLocation++;
                break;
            case 2:
                showInventory();
                break;
            case 3:
                showMap();
                break;
            case 4:
                printf("\nEnter the name of the item: ");
                scanf("%s", itemName);
                getItem(itemName);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        
        if(playerHealth <= 0) {
            displayLosingMessage();
            break;
        }
        else if(currentLocation == 5) {
            displayWinningMessage();
            break;
        }
    }
}

// function to display game introduction
void displayIntroduction() {
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("You notice that you have a small bag with some items in it.\n");
    printf("Looking around, you see a door that is slightly ajar.\n");
    printf("As you approach the door, you hear footsteps getting louder.\n");
    printf("You quickly hide behind a large couch as the door opens.\n");
    printf("A figure enters and begins rummaging through a nearby cabinet.\n");
    printf("You realize that you must make your escape before it's too late.\n");
}

// function to display winning message
void displayWinningMessage() {
    printf("\nCongratulations! You have escaped the building.\n");
    printf("You take a deep breath as you step out into the fresh air.\n");
    printf("You have successfully completed the Adventure Game!\n\n");
}

// function to display losing message
void displayLosingMessage() {
    printf("\nYou have died. Better luck next time!\n\n");
}

// function to display player's current inventory
void showInventory() {
    printf("\nInventory:\n");
    if(inventoryCount == 0) {
        printf("\tEmpty\n");
    }
    else {
        for(int i = 0; i < inventoryCount; i++) {
            printf("\t%s\n", playerInventory[i]);
        }
    }
}

// function to add an item to the player's inventory
void getItem(char itemName[]) {
    if(strcmp(itemName, "health pack") == 0) {
        playerHealth += 25;
        printf("\nYou have gained 25 health.\n");
    }
    else if(strcmp(itemName, "flashlight") == 0) {
        strcpy(playerInventory[inventoryCount], itemName);
        printf("\nYou have picked up a flashlight.\n");
        inventoryCount++;
    }
    else {
        printf("\nItem not found!\n");
    }
}

// function to display game map
void showMap() {
    printf("\nMap:\n");
    printf("\t1. Lobby\n");
    printf("\t2. Office\n");
    printf("\t3. Storage Room\n");
    printf("\t4. Secret Room\n");
    printf("\t5. Exit\n");
}

// function to move player to a new location
void moveToLocation(int location) {
    switch(location) {
        case 1:
            printf("\nYou move to the Lobby.\n");
            break;
        case 2:
            printf("\nYou move to the Office.\n");
            break;
        case 3:
            printf("\nYou move to the Storage Room.\n");
            break;
        case 4:
            printf("\nYou move to the Secret Room.\n");
            break;
        case 5:
            printf("\nYou move to the Exit.\n");
            break;
        default:
            printf("\nInvalid location!\n");
    }
}