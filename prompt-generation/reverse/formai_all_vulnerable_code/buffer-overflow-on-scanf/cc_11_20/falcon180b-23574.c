//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int room = 1;
    int scared = 0;
    int found_secret_room = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House!\n");
    printf("You find yourself in room %d.\n", room);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore the room\n");
        printf("2. Move to another room\n");
        printf("3. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (scared == 0) {
                printf("You carefully examine the room.\n");
            } else {
                printf("You nervously look around the room.\n");
            }
            break;

        case 2:
            if (room == 1) {
                printf("You can't go back any further.\n");
            } else if (room == 5) {
                printf("You enter a secret room!\n");
                found_secret_room = 1;
            } else if (found_secret_room == 1) {
                printf("You leave the secret room and end up in room %d.\n", room - 1);
            } else {
                printf("You move to room %d.\n", room + 1);
            }
            break;

        case 3:
            printf("Thanks for playing!\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }

        if (room == 3 && scared == 0) {
            printf("Suddenly, a ghost appears and scares you!\n");
            scared = 1;
        }

        if (room == 4 && scared == 0) {
            int rand_num = rand() % 2;
            if (rand_num == 0) {
                printf("You hear strange noises coming from the walls.\n");
            } else {
                printf("The room starts shaking violently!\n");
            }
            scared = 1;
        }
    }

    return 0;
}