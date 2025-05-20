//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int score = 0;
    int room = 1;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark, eerie room. The air is thick with dust and cobwebs.\n");
    printf("There is a door to your left and a staircase leading up to your right.\n");
    printf("Which path will you choose?\n");
    printf("1. Left\n2. Right\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You open the door and find yourself in a long hallway.\n");
            printf("There are several doors on either side of the hallway.\n");
            printf("Which door will you choose?\n");
            printf("1. First door on the left\n2. Second door on the left\n3. Third door on the left\n4. First door on the right\n5. Second door on the right\n6. Third door on the right\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You enter the first door on the left and find yourself in a small room.\n");
                    printf("There is a chest in the corner of the room.\n");
                    printf("Will you open the chest?\n");
                    printf("1. Yes\n2. No\n");
                    scanf("%d", &choice);

                    switch(choice) {
                        case 1:
                            printf("You open the chest and find a treasure!\n");
                            printf("Your score increases by 10 points.\n");
                            score += 10;
                            break;
                        case 2:
                            printf("You decide not to open the chest.\n");
                            break;
                    }
                    break;
                case 2:
                    // Add more rooms and choices here

                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;

        case 2:
            printf("You climb the staircase and find yourself in a large room.\n");
            printf("There are several doors on either side of the room.\n");
            printf("Which door will you choose?\n");
            printf("1. First door on the left\n2. Second door on the left\n3. Third door on the left\n4. First door on the right\n5. Second door on the right\n6. Third door on the right\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    // Add more rooms and choices here

                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}