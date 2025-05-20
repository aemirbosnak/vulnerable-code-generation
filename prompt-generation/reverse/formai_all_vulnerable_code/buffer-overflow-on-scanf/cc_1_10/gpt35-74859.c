//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int room = 1;
    int door;
    int choice;

    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("\nYou are standing in front of the entrance to the house.\n");
    printf("The front door is old and creaky -  \na sign hangs above it which reads \"Enter at your own Risk\"\n");

    while (room != 0) {
        printf("\nYou are in room %d.\n", room);
        printf("There are three doors:\n");
        printf("\tDoor 1: west\n");
        printf("\tDoor 2: east\n");
        printf("\tDoor 3: north\n");
        printf("Which door do you choose? ");
        scanf("%d", &door);

        while (door < 1 || door > 3) {
            printf("\nInvalid choice, please enter a number between 1 and 3: ");
            scanf("%d", &door);
        }

        // randomly generate ghost encounter
        int ghost = rand() % 4;
        if (ghost == 1) {
            printf("\nOh no! You have encountered a ghost and you are trapped!\n");
            printf("You are unable to leave this room, and the ghost seems to be getting closer...\n");
            printf("What will you do now?\n");
            printf("\t1.Break the window and escape.\n");
            printf("\t2.Continue to search the room for a way out.\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nYou break the window and escape, but not without leaving a part of your heart behind. The ghost follows you out of the window but disappears into the night. As you escape, you look back one last time and see the ghost waving goodbye. You heart races as you take your first steps into the cold, frosty evening while hearing the ghost whispering sweet nothings in your ear.\n");
                    return 0;
                    break;
            }
        }
        else {
            // proceed to next room
            switch (door) {
                case 1:
                    printf("\nYou have entered the western room.\n");
                    room += 1;
                    break;
                case 2:
                    printf("\nYou have entered the eastern room.\n");
                    room += 2;
                    break;
                case 3:
                    printf("\nYou have entered the northern room.\n");
                    room -= 1;
                    break;
            }

            if (room == 3) {
                printf("\nCongratulations! You have reached the end of the haunted house!\n");
                printf("As you exit the house, you realise that you're feeling elated with a sense of bravado that only comes from facing your fears. You thank the ghost for the experience and the ghost whispers in your ear.....\"You are the one I have waited for all my life. Will you marry me?\" \n");
                return 0;
            }
        }
    }

    printf("\nThanks for playing! Come back soon!\n");
    return 0;
}