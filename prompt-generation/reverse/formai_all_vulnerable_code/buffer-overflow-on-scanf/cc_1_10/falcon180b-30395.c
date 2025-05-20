//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int room = 1;
    int flag = 0;
    int door;
    srand(time(0));

    printf("Welcome to the Haunted House!\n");
    printf("You are in room %d.\n", room);
    printf("There are %d doors in this room.\n", rand() % 5 + 1);

    while (flag == 0) {
        printf("What do you want to do?\n");
        printf("1. Open a door.\n");
        printf("2. Look around.\n");
        printf("3. Quit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                door = rand() % 5 + 1;
                if (door == 1) {
                    printf("You opened the door and found a ghost! Game over.\n");
                    flag = 1;
                } else if (door == 2) {
                    printf("You opened the door and found a treasure! You win!\n");
                    flag = 1;
                } else {
                    printf("You opened the door and found nothing.\n");
                }
                break;
            case 2:
                printf("You look around and see spooky decorations, cobwebs, and eerie lighting.\n");
                break;
            case 3:
                printf("Thanks for playing!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (flag == 0) {
            room++;
            printf("\nYou enter room %d.\n", room);
            printf("There are %d doors in this room.\n", rand() % 5 + 1);
        }
    }

    return 0;
}