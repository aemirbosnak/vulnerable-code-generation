//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Procedural Space Adventure!\n");
    printf("You find yourself in the middle of the galaxy, surrounded by stars and planets.\n");
    printf("What would you like to do?\n");
    printf("1. Explore a nearby planet\n");
    printf("2. Engage in space combat\n");
    printf("3. Trade with an alien species\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("You land on a nearby planet and discover a hidden cave.\n");
            printf("Inside the cave, you find a treasure chest.\n");
            printf("What do you do?\n");
            printf("1. Open the chest\n");
            printf("2. Leave the chest alone and continue exploring\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You open the chest and find a map leading to a secret planet.\n");
            } else {
                printf("You continue exploring and find a strange artifact.\n");
            }
            break;
        case 2:
            printf("You engage in a space battle with an enemy ship.\n");
            printf("You fire your lasers and dodge enemy fire.\n");
            printf("Do you want to continue fighting or retreat?\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("You continue the fight and emerge victorious!\n");
            } else {
                printf("You retreat and escape the battle.\n");
            }
            break;
        case 3:
            printf("You meet with an alien species and begin trading.\n");
            printf("What do you offer the aliens?\n");
            printf("1. Advanced technology\n");
            printf("2. Rare minerals\n");
            scanf("%d", &choice);
            if(choice == 1) {
                printf("The aliens are impressed with your technology and offer you a rare artifact in return.\n");
            } else {
                printf("The aliens are fascinated by the minerals and offer you a powerful weapon.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
    return 0;
}