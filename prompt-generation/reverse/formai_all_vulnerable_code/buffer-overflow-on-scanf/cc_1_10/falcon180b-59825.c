//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    int choice;
    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to discover new worlds.\n");
    printf("Choose your path:\n");
    printf("1. Explore a new planet\n");
    printf("2. Encounter an alien spacecraft\n");
    printf("3. Discover a hidden space station\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You land on a new planet and discover a strange alien species.\n");
            printf("Do you:\n");
            printf("1. Approach the aliens\n");
            printf("2. Observe from a distance\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("The aliens are friendly and show you around their planet.\n");
                    break;
                case 2:
                    printf("You observe the aliens from a distance and learn about their culture.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 2:
            printf("You encounter an alien spacecraft and are brought aboard.\n");
            printf("Do you:\n");
            printf("1. Try to communicate with the aliens\n");
            printf("2. Escape back to your ship\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You successfully communicate with the aliens and learn about their technology.\n");
                    break;
                case 2:
                    printf("You narrowly escape back to your ship.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        case 3:
            printf("You discover a hidden space station and decide to explore it.\n");
            printf("Do you:\n");
            printf("1. Search for treasure\n");
            printf("2. Look for clues about the station's history\n");
            scanf("%d", &choice);

            switch(choice) {
                case 1:
                    printf("You find a valuable artifact and return to your ship.\n");
                    break;
                case 2:
                    printf("You uncover the station's dark history and vow to never return.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}