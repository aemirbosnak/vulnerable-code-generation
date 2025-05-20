//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are about to embark on a journey through a deserted mansion that is said to be haunted by its previous owner.\n");
    printf("Are you ready for this terrifying adventure?\n");

    char answer[10];
    scanf("%s", answer);

    if (answer[0] == 'y' || answer[0] == 'Y') {
        printf("Let's begin!\n\n");
        printf("You find yourself standing in front of the haunted mansion.\n");
        printf("The doors creak open slowly, inviting you inside.\n\n");
        printf("You step into the mansion, and immediately feel a chill run down your spine.\n");
        printf("The air is thick with the smell of decay, and strange noises echo through the halls.\n\n");

        int room = 1;
        int ghost_present = 0;
        int escaped = 0;

        while (!escaped) {
            printf("You are now in Room %d.\n", room);

            if (ghost_present) {
                printf("You hear a low moaning sound, and suddenly a ghost appears right before your eyes!\n");
                printf("You are too scared to move! The ghost attacks you and you DIE!\n");
                printf("GAME OVER.\n");
                break;
            }

            int has_key = rand() % 2;

            if (has_key) {
                printf("You see a key lying on a table in the room.\n");
                printf("Do you take the key? (y/n)\n");

                scanf("%s", answer);

                if (answer[0] == 'y' || answer[0] == 'Y') {
                    printf("You take the key.\n");
                }
            }

            printf("You have three doors to choose from. Which one do you choose? (1/2/3)\n");

            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("You open the door and step into the next room.\n");
                    room++;
                    ghost_present = rand() % 2;
                    break;
                case 2:
                    if (has_key) {
                        printf("You insert the key into the lock and turn it. The door opens with a creak.\n");
                        printf("You step into the next room.\n");
                        room++;
                        ghost_present = rand() % 2;
                    } else {
                        printf("The door is locked. You need a key to open it.\n");
                    }
                    break;
                case 3:
                    printf("You open the door and step into a dark, narrow hallway.\n");
                    printf("You hear strange noises coming from the darkness.\n");
                    printf("Do you continue down the hallway? (y/n)\n");

                    scanf("%s", answer);

                    if (answer[0] == 'y' || answer[0] == 'Y') {
                        printf("You walk down the hallway cautiously.\n");
                        ghost_present = rand() % 2;
                    } else {
                        printf("You retreat back into the previous room.\n");
                    }
                    break;
                default:
                    printf("Invalid choice. Please choose 1, 2, or 3.\n");
                    break;
            }

            if (room == 6) {
                printf("You have found the escape route! You run out of the mansion as fast as you can.\n");
                printf("CONGRATULATIONS! You have made it out alive!\n");
                escaped = 1;
            }
        }
    } else {
        printf("Maybe next time. Goodbye.\n");
    }

    return 0;
}