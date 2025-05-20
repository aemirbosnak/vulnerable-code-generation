//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\n%s, you find yourself in a mysterious forest.\n", name);
    printf("You see a path leading north and another leading east.\n");
    printf("Which way do you want to go? (1 for north, 2 for east): ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("\nYou walk along the path to the north.\n");
            printf("After a while, you come across a river.\n");
            printf("Do you want to cross the river? (y/n): ");
            char river;
            scanf("%c", &river);
            if(river == 'y' || river == 'Y') {
                printf("\nYou successfully cross the river.\n");
                printf("You continue walking and eventually reach a village.\n");
                printf("The villagers welcome you and offer you food and shelter.\n");
                printf("You spend the night in the village and continue your journey the next day.\n");
            } else {
                printf("\nYou decide not to cross the river and turn back.\n");
            }
            break;
        case 2:
            printf("\nYou walk along the path to the east.\n");
            printf("After a while, you come across a cave.\n");
            printf("Do you want to explore the cave? (y/n): ");
            char cave;
            scanf("%c", &cave);
            if(cave == 'y' || cave == 'Y') {
                printf("\nYou enter the cave and find a treasure chest!\n");
                printf("You open the chest and find gold coins and precious gems.\n");
                printf("You become rich and return home a hero.\n");
            } else {
                printf("\nYou decide not to explore the cave and turn back.\n");
            }
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            return 0;
    }
    return 0;
}