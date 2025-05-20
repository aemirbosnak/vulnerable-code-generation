//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    while (1) {
        printf("Welcome to the Haunted House!\n");
        printf("Enter 1 to explore the house or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        int room = rand() % 10 + 1;
        printf("You enter room %d.\n", room);
        switch (room) {
            case 1:
                printf("This room is filled with cobwebs and spiders.\n");
                break;
            case 2:
                printf("You hear strange whispers coming from the walls.\n");
                break;
            case 3:
                printf("The temperature suddenly drops, and you feel a cold breath on your neck.\n");
                break;
            case 4:
                printf("The door slams shut behind you, trapping you inside.\n");
                break;
            case 5:
                printf("A ghostly figure appears before you, then disappears just as quickly.\n");
                break;
            case 6:
                printf("You find a hidden passage behind a bookcase.\n");
                break;
            case 7:
                printf("You hear the sound of footsteps approaching, but no one is there.\n");
                break;
            case 8:
                printf("The room starts spinning, and you feel dizzy.\n");
                break;
            case 9:
                printf("You see a message written in blood on the wall: 'GET OUT'.\n");
                break;
            case 10:
                printf("You stumble upon a secret room filled with treasure.\n");
                break;
            default:
                printf("Nothing interesting happens in this room.\n");
        }
    }
    return 0;
}