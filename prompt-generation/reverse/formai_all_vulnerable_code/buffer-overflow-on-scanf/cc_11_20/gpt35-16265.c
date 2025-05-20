//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int room = 1;
    int choice;
    srand(time(0));

    printf("Welcome to the Haunted House Simulator. You start in the foyer.\n");

    while (room <= 10) {
        printf("\nYou are in room %d. Choose a door:\n", room);
        printf("1. Left door\n2. Middle door\n3. Right door\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You open the left door...\n");
                if (room == 1 || room == 3) {
                    printf("A ghostly figure appears and chases you back into the room!\n");
                    break;
                }
                else {
                    room--;
                    break;
                }
            case 2:
                printf("You open the middle door...\n");
                if (rand() % 2 == 0) {
                    printf("Congratulations, you found the treasure!\n");
                    printf("You have completed the Haunted House Simulator.\n");
                    return 0;
                }
                else {
                    printf("You are attacked by a swarm of bats and lose your way!\n");
                    break;
                }
            case 3:
                printf("You open the right door...\n");
                if (room == 2 || room == 4) {
                    printf("You are confronted by a spectral figure and forced to turn back!\n");
                    break;
                }
                else if (room == 10) {
                    printf("You have reached the roof. There is no where else to go!\n");
                    break;
                }
                else {
                    room++;
                    break;
                }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    printf("You have reached the end of the Haunted House Simulator without finding the treasure. Better luck next time!\n");

    return 0;
}