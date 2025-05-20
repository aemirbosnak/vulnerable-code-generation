//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Haunted House!\n");
    printf("What would you like to do?\n");
    printf("1. Enter the house\n");
    printf("2. Leave the house\n");
    printf("3. Explore the house\n");
    printf("4. Quit\n");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("You enter the haunted house.\n");
        printf("The door slams shut behind you.\n");
        printf("You hear creaking and moaning noises.\n");
        printf("A ghostly figure appears in front of you.\n");
        printf("What do you do?\n");
        printf("1. Run away\n");
        printf("2. Stay and fight\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("You run away and escape the haunted house.\n");
        } else if(choice == 2) {
            printf("You stay and fight the ghostly figure.\n");
        }
    } else if(choice == 2) {
        printf("You leave the haunted house.\n");
    } else if(choice == 3) {
        printf("You explore the haunted house.\n");
        printf("You find a secret room with a treasure chest.\n");
        printf("What do you do?\n");
        printf("1. Open the chest\n");
        printf("2. Leave the chest alone\n");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("You open the chest and find a pile of gold.\n");
        } else if(choice == 2) {
            printf("You leave the chest alone and continue exploring.\n");
        }
    } else if(choice == 4) {
        printf("You quit the haunted house.\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}