//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("What do you want to do?\n");
    printf("1. Look around\n");
    printf("2. Try to open the door\n");
    printf("3. Yell for help\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You look around the room and notice a small window high up on the wall.\n");
            printf("What do you want to do?\n");
            printf("1. Try to reach the window\n");
            printf("2. Look for something to stand on\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You jump as high as you can but can't quite reach the window.\n");
                    break;
                case 2:
                    printf("You find a sturdy box and stand on it to look out the window.\n");
                    printf("You see a busy street outside but don't recognize where you are.\n");
                    break;
            }
            break;

        case 2:
            printf("You try to open the door but it's locked.\n");
            printf("What do you want to do?\n");
            printf("1. Kick the door down\n");
            printf("2. Look for a key\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You kick the door as hard as you can but it doesn't budge.\n");
                    break;
                case 2:
                    printf("You search the room and find a key under the bed.\n");
                    printf("You unlock the door and step out into a long hallway.\n");
                    break;
            }
            break;

        case 3:
            printf("You yell for help but no one comes.\n");
            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}