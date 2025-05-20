//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void welcomeMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to enter a creepy house...\n");
    printf("Be careful, as your choices will determine your fate!\n");
}

void displayRoomChoices() {
    printf("You find yourself in a dimly lit hallway.\n");
    printf("You can choose to go:\n");
    printf("1. Enter the Living Room\n");
    printf("2. Go to the Kitchen\n");
    printf("3. Head upstairs to the Bedroom\n");
    printf("4. Exit the Haunted House\n");
}

bool livingRoom() {
    printf("\nYou enter the Living Room. It's dusty and filled with old furniture.\n");
    printf("Suddenly, a ghost appears! What will you do?\n");
    printf("1. Run away\n");
    printf("2. Try to communicate with the ghost\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You run away to the hallway in terror!\n");
        return false;
    } else {
        printf("The ghost smiles and gives you a secret: 'Beware of the kitchen!'\n");
        return true;
    }
}

bool kitchen() {
    printf("\nYou step into the kitchen, and it smells rotten.\n");
    printf("You find a strange potion on the table.\n");
    printf("What will you do?\n");
    printf("1. Drink the potion\n");
    printf("2. Leave the kitchen quickly\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("As you drink the potion, you feel a strange power bubbling inside you!\n");
        return true;
    } else {
        printf("You quickly leave the kitchen, feeling relieved.\n");
        return false;
    }
}

bool bedroom() {
    printf("\nYou walk upstairs to the Bedroom. It looks abandoned.\n");
    printf("Suddenly, a bat flies over your head!\n");
    printf("What will you do?\n");
    printf("1. Cover your head and scream\n");
    printf("2. Try to catch the bat\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You scream so loud that you scare the bat away. You're safe for now!\n");
        return true;
    } else {
        printf("You successfully catch the bat, but it turns into a vampire!\n");
        printf("You faint from fright!\n");
        return false;
    }
}

void exitHouse() {
    printf("\nYou have chosen to exit the Haunted House.\n");
    printf("You escaped with a mix of bravery and terror!\n");
}

int main() {
    srand(time(NULL));
    welcomeMessage();
    
    bool outcome = true;

    while (outcome) {
        displayRoomChoices();

        int roomChoice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &roomChoice);

        switch (roomChoice) {
            case 1: 
                outcome = livingRoom();
                break;
            case 2:
                outcome = kitchen();
                break;
            case 3:
                outcome = bedroom();
                break;
            case 4:
                exitHouse();
                return 0;
            default:
                printf("Invalid choice! Please select a room 1 to 4.\n");
                break;
        }

        if (!outcome) {
            printf("Unfortunately, your adventure has come to an end.\n");
        }
    }
    
    return 0;
}