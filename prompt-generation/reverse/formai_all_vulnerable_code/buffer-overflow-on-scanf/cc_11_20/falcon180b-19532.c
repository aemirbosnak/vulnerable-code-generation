//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Text-Based Adventure Game! Enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! You find yourself in a mysterious forest.\n", name);
    while(1) {
        system("clear");
        printf("\n");
        printf("You are standing at a crossroads. Which path will you take?\n");
        printf("1. Left path\n2. Right path\n3. Go back\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nYou take the left path and find yourself in a dark cave.\n");
                printf("Do you want to explore the cave? (y/n): ");
                char explore;
                scanf("%c", &explore);
                if(explore == 'y' || explore == 'Y') {
                    printf("\nYou find a treasure chest in the cave! Do you want to open it? (y/n): ");
                    char open;
                    scanf("%c", &open);
                    if(open == 'y' || open == 'Y') {
                        printf("\nCongratulations! You found a gold coin! You can continue your adventure or go back to the crossroads.\n");
                    } else {
                        printf("\nYou decide not to open the treasure chest and go back to the crossroads.\n");
                    }
                } else {
                    printf("\nYou decide not to explore the cave and go back to the crossroads.\n");
                }
                break;
            case 2:
                printf("\nYou take the right path and find yourself in a beautiful meadow.\n");
                printf("Do you want to pick some flowers? (y/n): ");
                char pick;
                scanf("%c", &pick);
                if(pick == 'y' || pick == 'Y') {
                    printf("\nYou picked some colorful flowers! Do you want to make a bouquet? (y/n): ");
                    char bouquet;
                    scanf("%c", &bouquet);
                    if(bouquet == 'y' || bouquet == 'Y') {
                        printf("\nCongratulations! You made a beautiful bouquet! You can continue your adventure or go back to the crossroads.\n");
                    } else {
                        printf("\nYou decide not to make a bouquet and go back to the crossroads.\n");
                    }
                } else {
                    printf("\nYou decide not to pick flowers and go back to the crossroads.\n");
                }
                break;
            case 3:
                printf("\nYou go back to the crossroads.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}