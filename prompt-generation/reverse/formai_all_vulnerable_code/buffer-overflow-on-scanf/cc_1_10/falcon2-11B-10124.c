//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>

int main() {
    int choice;
    char name[100];
    
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("What is your name? ");
    scanf("%s", name);
    
    printf("Hello, %s! You find yourself in a dark, eerie forest. What do you do? \n", name);
    
    do {
        printf("1. Explore the forest.\n2. Find a way out.\n3. Quit the game.\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("You explore the forest and find a mysterious cave. Do you go inside? \n");
                printf("1. Yes.\n2. No.\n");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        printf("You enter the cave and find a chest. Do you open it? \n");
                        printf("1. Yes.\n2. No.\n");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1:
                                printf("You open the chest and find a map. You realize that this is the exit! \n");
                                printf("Congratulations, you have escaped the forest!\n");
                                break;
                            case 2:
                                printf("You leave the chest alone and continue exploring the cave. Eventually, you find the exit.\n");
                                printf("Congratulations, you have escaped the forest!\n");
                                break;
                        }
                        break;
                    case 2:
                        printf("You leave the cave and continue exploring the forest. Eventually, you find the exit.\n");
                        printf("Congratulations, you have escaped the forest!\n");
                        break;
                }
                break;
            case 2:
                printf("You decide to find a way out of the forest. Eventually, you stumble upon a road. You take it and reach civilization.\n");
                printf("Congratulations, you have escaped the forest!\n");
                break;
            case 3:
                printf("Thank you for playing the Text-Based Adventure Game!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 3);
    
    return 0;
}