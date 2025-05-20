//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;

    printf("Welcome to the surreal world of dreams.\n");
    printf("You wake up in a strange room with no memory of how you got here.\n");
    printf("What will you do?\n");
    printf("1. Explore the room.\n");
    printf("2. Try to open the door.\n");
    printf("3. Look out the window.\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You start exploring the room.\n");
            printf("You find a strange object on the table.\n");
            printf("What will you do with it?\n");
            printf("1. Pick it up.\n");
            printf("2. Leave it alone.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You pick up the object and suddenly everything starts to spin.\n");
                    printf("You wake up in a different room.\n");
                    break;
                case 2:
                    printf("You leave the object alone and continue exploring the room.\n");
                    break;
            }
            break;
        case 2:
            printf("You try to open the door but it's locked.\n");
            printf("What will you do?\n");
            printf("1. Keep trying to open the door.\n");
            printf("2. Look for a key.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You keep trying to open the door but it won't budge.\n");
                    break;
                case 2:
                    printf("You start looking for a key and find one under the rug.\n");
                    printf("You unlock the door and exit the room.\n");
                    break;
            }
            break;
        case 3:
            printf("You look out the window and see a strange landscape.\n");
            printf("What will you do?\n");
            printf("1. Try to open the window.\n");
            printf("2. Keep looking.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You try to open the window but it's stuck.\n");
                    break;
                case 2:
                    printf("You keep looking out the window and suddenly see a door appear in the distance.\n");
                    printf("What will you do?\n");
                    printf("1. Go through the door.\n");
                    printf("2. Stay in the room.\n");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            printf("You go through the door and find yourself in a completely different world.\n");
                            break;
                        case 2:
                            printf("You stay in the room and continue exploring.\n");
                            break;
                    }
                    break;
            }
            break;
    }

    return 0;
}