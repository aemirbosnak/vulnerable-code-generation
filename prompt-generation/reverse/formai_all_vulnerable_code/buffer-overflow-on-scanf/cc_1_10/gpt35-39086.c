//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAGGAGE_LIMIT 50 // Maximum bags allowed on a flight
#define BELT_LIMIT 10 // Maximum bags that can be on the conveyor belt at once

void print_menu();
void generate_baggage(int *bags);
void display_belt(int *belt, int belt_count);

int main() {
    int bags[BAGGAGE_LIMIT];
    int belt[BELT_LIMIT] = {0};
    int belt_count = 0;

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Airport Baggage Handling Simulation\n\n");

    while (1) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generate_baggage(bags);
                break;
            case 2:
                if (belt_count < BELT_LIMIT) {
                    int index = rand() % BAGGAGE_LIMIT; // Pick a random bag to put on the belt
                    belt[belt_count] = bags[index];
                    belt_count++;
                } else {
                    printf("The conveyor belt is full.\n");
                }
                break;
            case 3:
                if (belt_count > 0) {
                    int bag = belt[0];
                    printf("Baggage with ID %d has been loaded onto the plane.\n", bag);

                    for (int i = 0; i < BELT_LIMIT - 1; i++) {
                        belt[i] = belt[i+1]; // Shift the bags down the belt
                    }

                    belt[BELT_LIMIT-1] = 0; // Clear the last slot on the belt
                    belt_count--;
                } else {
                    printf("The conveyor belt is empty.\n");
                }
                break;
            case 4:
                display_belt(belt, belt_count);
                break;
            case 5:
                printf("Thank you for using the Airport Baggage Handling Simulation.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("Please choose an option:\n");
    printf("1. Generate baggage\n");
    printf("2. Load baggage onto conveyor belt\n");
    printf("3. Load baggage onto the plane\n");
    printf("4. Display conveyor belt contents\n");
    printf("5. Quit\n\n");
}

void generate_baggage(int *bags) {
    for (int i = 0; i < BAGGAGE_LIMIT; i++) {
        bags[i] = rand() % 1000; // Generate a random baggage ID
    }

    printf("Baggage has been generated.\n");
}

void display_belt(int *belt, int belt_count) {
    if (belt_count == 0) {
        printf("The conveyor belt is empty.\n");
    } else {
        printf("The conveyor belt contains the following bags:\n");

        for (int i = 0; i < belt_count; i++) {
            printf("%d\n", belt[i]);
        }
    }
}