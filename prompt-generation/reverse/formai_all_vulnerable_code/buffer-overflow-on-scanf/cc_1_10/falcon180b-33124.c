//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_FACTOR 10

int main() {
    srand(time(NULL));
    int tries = 0;
    int factor = 1;
    int num_ships = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We will now determine the likelihood of an alien invasion occurring.\n");
    printf("Please answer the following questions:\n");

    while (tries < MAX_TRIES && factor < MAX_FACTOR) {
        int choice;
        printf("Would you like to (1) increase the invasion factor or (2) calculate the probability?\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("The current invasion factor is %d.\n", factor);
            printf("Enter a new invasion factor (1-%d): ", MAX_FACTOR);
            scanf("%d", &factor);
            if (factor < 1 || factor > MAX_FACTOR) {
                printf("Invalid invasion factor. Please try again.\n");
            }
        } else if (choice == 2) {
            printf("Calculating invasion probability...\n");
            for (int i = 0; i < factor; i++) {
                if (rand() % 2 == 0) {
                    num_ships++;
                }
            }
            printf("There are currently %d alien ships in the vicinity.\n", num_ships);
            printf("The likelihood of an invasion is %d%%.\n", num_ships * 10);
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        tries++;
    }

    if (tries == MAX_TRIES) {
        printf("You have exceeded the maximum number of tries. Exiting program.\n");
    }

    return 0;
}