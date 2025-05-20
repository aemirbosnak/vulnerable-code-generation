//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct floor_info {
    char name[20];
    int num_passengers;
    int capacity;
};

struct elevator_info {
    char name[20];
    int floors[5];
    int current_floor;
};

int main() {
    char name[20] = "Elevator";
    int floors[5] = {1, 2, 3, 4, 5};
    int current_floor = 0;

    struct elevator_info e = {name, floors, current_floor};

    printf("Welcome to %s!\n", e.name);

    printf("The current floor is %d.\n", e.current_floor);

    int num_passengers = 0;
    char floors_name[20][20] = {"1st Floor", "2nd Floor", "3rd Floor", "4th Floor", "5th Floor"};

    printf("Passengers: %d\n", num_passengers);

    while (1) {
        printf("\n1. Go to the 1st Floor\n2. Go to the 2nd Floor\n3. Go to the 3rd Floor\n4. Go to the 4th Floor\n5. Go to the 5th Floor\n6. Go to a specific floor\n7. Go to the basement\n8. Go to the roof\n9. Go to a random floor\n0. Go back to the current floor\n");

        int choice = 0;
        while (1) {
            printf("\nEnter your choice (1-%d): ", 9);
            scanf("%d", &choice);

            if (choice > 0 && choice <= 9) {
                break;
            } else {
                printf("Invalid choice. Please try again.\n");
            }
        }

        if (choice == 1) {
            e.current_floor = 1;
            printf("Going to the 1st Floor...\n");
        } else if (choice == 2) {
            e.current_floor = 2;
            printf("Going to the 2nd Floor...\n");
        } else if (choice == 3) {
            e.current_floor = 3;
            printf("Going to the 3rd Floor...\n");
        } else if (choice == 4) {
            e.current_floor = 4;
            printf("Going to the 4th Floor...\n");
        } else if (choice == 5) {
            e.current_floor = 5;
            printf("Going to the 5th Floor...\n");
        } else if (choice == 6) {
            printf("Enter the specific floor (1-%d): ", 5);
            scanf("%d", &e.current_floor);
            printf("Going to the %s...\n", floors_name[e.current_floor - 1]);
        } else if (choice == 7) {
            e.current_floor = 0;
            printf("Going to the basement...\n");
        } else if (choice == 8) {
            e.current_floor = 5;
            printf("Going to the roof...\n");
        } else if (choice == 9) {
            int rand_floor = rand() % 5 + 1;
            e.current_floor = rand_floor;
            printf("Going to the %s...\n", floors_name[rand_floor - 1]);
        } else if (choice == 0) {
            e.current_floor = current_floor;
            printf("Going back to the current floor...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        num_passengers++;
    }

    return 0;
}