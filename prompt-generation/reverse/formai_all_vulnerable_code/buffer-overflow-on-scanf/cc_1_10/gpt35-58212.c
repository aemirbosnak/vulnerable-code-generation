//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printIntro(){
    printf("Welcome to the Scientific Adventure Game! \n\n");
    printf("You wake up in a lab, surrounded by beakers and lab equipment.\n");
    printf("You have no memory of how you ended up here or who you are.\n");
    printf("Your goal is to find a way out and solve the mystery of your identity.\n\n");
}

void printMenu(){
    printf("What would you like to do?\n");
    printf("1. Examine equipment\n");
    printf("2. Search for clues\n");
    printf("3. Attempt to escape\n");
}

void examineEquipment(){
    printf("You examine the equipment and find a microscope and a centrifuge.\n");
}

void searchForClues(){
    printf("You search the lab and find a notebook with some notes written in code.\n");
    printf("You will need to decode them to read them.\n\n");
    printf("Enter code: ");
    char code[100];
    scanf("%s", code);
    printf("Decoding...\n");
    // code decoding logic
    printf("The note reads: 'Experiment 3452 successful. Subject 7 stable. Proceeding to next phase.'\n");
}

void attemptEscape(){
    printf("You attempt to escape, but the door is locked and requires a keycard.\n");
}

int main(){
    printIntro();
    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                examineEquipment();
                break;
            case 2:
                searchForClues();
                break;
            case 3:
                attemptEscape();
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 3);

    printf("You have escaped the lab! But the mystery of your identity remains unsolved...\n");
    return 0;
}