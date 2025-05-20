//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    printf("Welcome to the Adventure Game!\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("What do you want to do?\n");
    printf("1. Look around\n");
    printf("2. Try to open the door\n");
    printf("3. Yell for help\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("As your eyes adjust to the darkness, you notice a small window high up on the wall.\n");
            printf("What do you want to do?\n");
            printf("1. Try to reach the window\n");
            printf("2. Look for something to stand on\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You jump as high as you can, but the window is just out of reach.\n");
                    break;
                case 2:
                    printf("You find a sturdy wooden crate and drag it over to the wall.\n");
                    printf("What do you want to do?\n");
                    printf("1. Stand on the crate and look out the window\n");
                    printf("2. Use the crate to break down the door\n");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            printf("As you stand on the crate and look out the window, you see a busy street below.\n");
                            printf("What do you want to do?\n");
                            printf("1. Yell for help\n");
                            printf("2. Try to signal someone with your shirt\n");
                            scanf("%d", &choice);

                            switch(choice) {
                                case 1:
                                    printf("You yell as loud as you can, but no one seems to hear you.\n");
                                    break;
                                case 2:
                                    printf("You take off your shirt and wave it out the window.\n");
                                    printf("A kind passerby sees you and calls the police.\n");
                                    printf("You are rescued and taken to the hospital.\n");
                                    printf("Congratulations! You have completed the game.\n");
                                    break;
                            }
                            break;
                        case 2:
                            printf("You use the crate to break down the door and escape.\n");
                            printf("Congratulations! You have completed the game.\n");
                            break;
                    }
                    break;
            }
            break;
        case 2:
            printf("The door is locked and won't budge.\n");
            break;
        case 3:
            printf("You yell for help, but no one seems to hear you.\n");
            break;
    }

    return 0;
}