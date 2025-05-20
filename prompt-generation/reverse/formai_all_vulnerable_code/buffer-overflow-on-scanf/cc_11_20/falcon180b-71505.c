//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark room. What do you want to do?\n");
    printf("1. Turn on the light\n");
    printf("2. Search the room\n");
    printf("3. Leave the room\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You turn on the light and see a door.\n");
            printf("What do you want to do?\n");
            printf("1. Open the door\n");
            printf("2. Leave the room\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You open the door and see a hallway.\n");
                    printf("What do you want to do?\n");
                    printf("1. Go left\n");
                    printf("2. Go right\n");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            printf("You go left and find a treasure.\n");
                            break;
                        case 2:
                            printf("You go right and find a monster.\n");
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                    break;
                case 2:
                    printf("You leave the room and end the game.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 2:
            printf("You search the room and find a key.\n");
            printf("What do you want to do?\n");
            printf("1. Use the key on the door\n");
            printf("2. Leave the room\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You use the key on the door and open it.\n");
                    printf("What do you want to do?\n");
                    printf("1. Go through the door\n");
                    printf("2. Leave the room\n");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            printf("You go through the door and find a treasure.\n");
                            break;
                        case 2:
                            printf("You leave the room and end the game.\n");
                            break;
                        default:
                            printf("Invalid choice.\n");
                    }
                    break;
                case 2:
                    printf("You leave the room and end the game.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 3:
            printf("You leave the room and end the game.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}