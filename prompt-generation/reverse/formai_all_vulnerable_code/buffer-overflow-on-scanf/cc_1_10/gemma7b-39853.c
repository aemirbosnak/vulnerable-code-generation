//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int sound;
    int appearance;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Jones", 1, 1, 3},
    {"Mrs. Smith", 2, 2, 2},
    {"The Poltergeist", 3, 3, 4},
    {"The Ghostly Bride", 4, 2, 3},
    {"The Bloody Mary", 5, 1, 4}
};

int main() {
    int i, room, sound, appearance, choice;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please choose a room number: ");
    scanf("%d", &room);

    for (i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].room == room) {
            sound = ghosts[i].sound;
            appearance = ghosts[i].appearance;

            printf("You have entered the room of %s.\n", ghosts[i].name);
            printf("The sound of the haunting is: %d\n", sound);
            printf("The appearance of the ghost is: %d\n", appearance);

            printf("What do you want to do? (1) Listen to the sound, (2) See the appearance, (3) Leave the room\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("You hear the sound of %s.\n", ghosts[i].sound);
                    break;
                case 2:
                    printf("You see the appearance of %s.\n", ghosts[i].appearance);
                    break;
                case 3:
                    printf("You leave the room.\n");
                    break;
                default:
                    printf("Invalid input.\n");
                    break;
            }

            break;
        }
    }

    if (i == MAX_GHOSTS) {
        printf("There is no ghost in that room.\n");
    }

    return 0;
}