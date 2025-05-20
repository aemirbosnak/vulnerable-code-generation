//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_TERMINALS 5

// function to simulate time delay
void delay(int seconds) {
    int milli_seconds = 1000 * seconds;

    // Stroing start time 
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds) {}
}

// function to print details about a bag
void print_bag_details(int i, int terminal, int weight, char* destination) {
    printf("\nBag %d:\n", i);
    printf("Terminal:\t%d\n", terminal);
    printf("Weight:\t\t%d kg\n", weight);
    printf("Destination:\t%s\n", destination);
}

int main() {
    srand(time(NULL)); // seed random number generator

    int bag_count = 0;
    int bags[MAX_BAGS][3]; // 2D array to hold bag details, each row represents one bag: 0 - terminal, 1 - weight, 2 - destination
    bool is_running = true;

    printf("Airport Baggage Handling Simulation\n");

    while (is_running) {
        printf("\n1. Add Bag\n");
        printf("2. Process Bags\n");
        printf("3. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (bag_count >= MAX_BAGS) {
                    printf("\nMaximum capacity reached. Cannot add more bags.\n");
                }
                else {
                    int terminal = (rand() % MAX_TERMINALS) + 1;
                    int weight = (rand() % 20) + 1; // generate random weight between 1-20 kg
                    char destinations[][20] = {"New York", "Los Angeles", "Toronto", "London", "Paris", "Tokyo", "Hong Kong", "Singapore", "Dubai", "Sydney"};
                    int destination_index = rand() % 10;
                    char* destination = destinations[destination_index];

                    bags[bag_count][0] = terminal;
                    bags[bag_count][1] = weight;
                    bags[bag_count][2] = destination_index;

                    printf("\nBag added successfully!\n");
                    print_bag_details(bag_count + 1, terminal, weight, destination);
                    bag_count++;
                }
                break;

            case 2:
                if (bag_count == 0) {
                    printf("\nNo bags to process.\n");
                }
                else {
                    printf("\nProcessing bags...\n");

                    for (int i = 0; i < bag_count; i++) {
                        int terminal = bags[i][0];
                        int weight = bags[i][1];
                        int destination_index = bags[i][2];
                        char destinations[][20] = {"New York", "Los Angeles", "Toronto", "London", "Paris", "Tokyo", "Hong Kong", "Singapore", "Dubai", "Sydney"};
                        char* destination = destinations[destination_index];

                        printf("Processing bag %d...", i + 1);
                        delay(1); // simulate time taken to process bag

                        // check if bag is overweight
                        if (weight > 15) {
                            printf("overweight bag detected!");
                            delay(1); // simulate time taken to handle overweight bag
                            printf("Bag %d has been diverted to overweight baggage area.\n", i + 1);
                        }
                        else {
                            printf("bag cleared for destination %s.\n", destination);
                            delay(1); // simulate time taken to clear bag
                        }
                    }
                }
                break;

            case 3:
                is_running = false;
                printf("\nExiting simulation...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}