//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int randNum(int max){
    srand(time(NULL));
    return rand() % max;
}

// Function to display the room options and get user input
char displayOptions(){
    char choice;
    printf("\n\nYou are in a dark and mysterious room. The only thing you can see is a door in front of you.");
    printf("\n\nWhat do you want to do?");
    printf("\n\n[A] Open the door");
    printf("\n[B] Check the room for clues");
    printf("\n[C] Sit down and wait for something to happen");
    printf("\n\nEnter your choice: ");
    scanf(" %c", &choice);
    return choice;
}

// Function to display the result of user's choice
void displayResult(char choice){
    int rand = randNum(3);
    switch(choice){
        case 'A':
            printf("\nYou try to open the door, but it's locked.");
            printf("\n\nAs you turn around, you are suddenly attacked by a %s", rand == 0 ? "vampire" : rand == 1 ? "werewolf" : "zombie");
            printf("\n\nGame over. You have been killed.");
            break;
        case 'B':
            printf("\nYou search the room and find a key hidden in a corner.");
            printf("\n\nYou use the key to open the door and escape from the room.");
            printf("\n\nCongratulations! You have completed the game.");
            break;
        case 'C':
            printf("\nYou sit down and wait for something to happen.");
            printf("\n\nNothing happens.");
            printf("\n\nYou eventually die of boredom.");
            printf("\n\nGame over.");
            break;
        default:
            printf("\nInvalid input. Please try again.");
            break;
    }
}

// Main function
int main(){
    char choice;
    do{
        choice = displayOptions();
        displayResult(choice);
    }while(choice != 'A' && choice != 'B' && choice != 'C');
    return 0;
}