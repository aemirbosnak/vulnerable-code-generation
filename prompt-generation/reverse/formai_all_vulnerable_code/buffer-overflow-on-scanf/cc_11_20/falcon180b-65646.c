//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];
    printf("Welcome to the Haunted House Simulator! \n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\nHello, %s! ", name);
    printf("\nYou find yourself in front of a creepy old mansion. ");
    printf("\nDo you want to enter? (y/n) ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int room = rand() % 3 + 1;
        if (room == 1) {
            printf("\nYou enter the first room and see a dusty old piano in the corner. ");
            printf("\nDo you want to play it? (y/n) ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("\nAs you start playing, the keys suddenly start moving on their own! ");
                printf("\nA ghostly figure appears behind you and whispers, \"Get out while you still can. \"");
            } else {
                printf("\nYou decide not to play the piano and leave the room.");
            }
        } else if (room == 2) {
            printf("\nYou enter the second room and see a long hallway with portraits on the walls. ");
            printf("\nDo you want to walk down the hallway? (y/n) ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("\nAs you walk down the hallway, the portraits start to move and follow you with their eyes. ");
                printf("\nSuddenly, one of the portraits falls off the wall and shatters on the ground!");
            } else {
                printf("\nYou decide not to walk down the hallway and leave the room.");
            }
        } else {
            printf("\nYou enter the third room and see a large dining table with candles flickering in the center. ");
            printf("\nDo you want to sit at the table? (y/n) ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("\nAs you sit down, the candles go out and the room becomes pitch black. ");
                printf("\nYou hear whispers and laughter all around you, but can't see anything!");
            } else {
                printf("\nYou decide not to sit at the table and leave the room.");
            }
        }
    } else {
        printf("\nYou decide not to enter the haunted house and leave.");
    }
    return 0;
}