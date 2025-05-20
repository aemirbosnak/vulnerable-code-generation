//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the function prototypes
void travel_to_future(int seconds);
void travel_to_past(int seconds);

int main() {
    int choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Print the welcome message
    printf("Welcome to the Time Travel Simulator!\n");

    // Ask the user to choose a travel direction
    printf("Do you want to travel to the future or the past?\n");
    printf("1. Future\n");
    printf("2. Past\n");
    scanf("%d", &choice);

    // Call the appropriate travel function based on the user's choice
    switch (choice) {
        case 1:
            travel_to_future(rand() % 1000 + 1);
            break;
        case 2:
            travel_to_past(rand() % 1000 + 1);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}

// Function to simulate traveling to the future
void travel_to_future(int seconds) {
    printf("You are now traveling to the future...\n");
    for (int i = 0; i < seconds; i++) {
        printf("%d seconds have passed...\n", i + 1);
        sleep(1);
    }
    printf("You have arrived in the future!\n");
}

// Function to simulate traveling to the past
void travel_to_past(int seconds) {
    printf("You are now traveling to the past...\n");
    for (int i = 0; i < seconds; i++) {
        printf("%d seconds have passed...\n", i + 1);
        sleep(1);
    }
    printf("You have arrived in the past!\n");
}