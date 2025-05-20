//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int flag = 0;
    int room = 1;

    printf("Welcome to the Haunted House!\n");
    printf("You are in room %d.\n", room);

    while(flag == 0) {
        printf("What would you like to do?\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Check the room\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(room == 10) {
                    printf("You have reached the end of the haunted house.\n");
                    flag = 1;
                } else {
                    room++;
                    printf("You are now in room %d.\n", room);
                }
                break;
            case 2:
                if(room == 1) {
                    printf("You cannot go any further backward.\n");
                } else {
                    room--;
                    printf("You are now in room %d.\n", room);
                }
                break;
            case 3:
                printf("You look around the room and see...\n");
                srand(time(0));
                int random = rand() % 5;

                if(random == 0) {
                    printf("A ghostly figure appears before you!\n");
                } else if(random == 1) {
                    printf("You hear strange noises coming from the walls.\n");
                } else if(random == 2) {
                    printf("The temperature suddenly drops and you feel a chill.\n");
                } else if(random == 3) {
                    printf("You see a mysterious object in the corner of the room.\n");
                } else {
                    printf("Nothing out of the ordinary.\n");
                }
                break;
            case 4:
                printf("Thanks for playing!\n");
                flag = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}