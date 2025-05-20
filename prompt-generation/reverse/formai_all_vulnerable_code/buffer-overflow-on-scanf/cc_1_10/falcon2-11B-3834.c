//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 10;
    int i;
    int floors[n];
    int floor_count = 0;
    int current_floor = 0;

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        floors[i] = rand() % 5 + 1;
        floor_count += floors[i];
    }

    printf("Welcome to the Elevator Simulation!\n");
    printf("Currently on floor %d.\n", current_floor);

    while (floor_count > 0) {
        printf("Press 1 to go up 1 floor\n");
        printf("Press 2 to go up 2 floors\n");
        printf("Press 3 to go up 3 floors\n");
        printf("Press 4 to go down 1 floor\n");
        printf("Press 5 to go down 2 floors\n");
        printf("Press 6 to go down 3 floors\n");
        printf("Press 7 to exit the elevator\n");
        printf("Your current floor: %d\n", current_floor);

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            current_floor++;
        } else if (choice == 2) {
            current_floor += 2;
        } else if (choice == 3) {
            current_floor += 3;
        } else if (choice == 4) {
            current_floor--;
        } else if (choice == 5) {
            current_floor -= 2;
        } else if (choice == 6) {
            current_floor -= 3;
        } else if (choice == 7) {
            printf("Exiting the elevator...\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    printf("Thank you for using the Elevator Simulation! See you next time.\n");

    return 0;
}