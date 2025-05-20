//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;

    printf("You wake up in a surreal dreamscape, surrounded by floating islands and an endless sky.\n");
    printf("Do you:\n");
    printf("1. Explore the nearest island.\n");
    printf("2. Fly through the sky.\n");
    printf("3. Dive into the abyss.\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("As you approach the island, you notice it's made entirely of candy.\n");
            printf("Do you:\n");
            printf("1. Eat the candy.\n");
            printf("2. Build a candy castle.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You indulge in the sweet treats, feeling a rush of euphoria.\n");
                    break;
                case 2:
                    printf("You construct a magnificent castle out of candy, feeling accomplished.\n");
                    break;
            }
            break;
        case 2:
            printf("You soar through the sky, feeling weightless and free.\n");
            printf("Suddenly, a giant bird appears and offers you a ride.\n");
            printf("Do you:\n");
            printf("1. Accept the offer.\n");
            printf("2. Decline and continue flying.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You climb onto the bird's back and it takes you on a breathtaking journey through the clouds.\n");
                    break;
                case 2:
                    printf("You continue flying on your own, feeling the wind in your hair.\n");
                    break;
            }
            break;
        case 3:
            printf("You plunge into the abyss, feeling a mix of fear and excitement.\n");
            printf("As you descend, you notice a glowing portal in the distance.\n");
            printf("Do you:\n");
            printf("1. Swim towards the portal.\n");
            printf("2. Turn back and return to the surface.\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You reach the portal and step through it, finding yourself in a completely different world.\n");
                    break;
                case 2:
                    printf("You swim back up to the surface, feeling relieved to be back in familiar surroundings.\n");
                    break;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}