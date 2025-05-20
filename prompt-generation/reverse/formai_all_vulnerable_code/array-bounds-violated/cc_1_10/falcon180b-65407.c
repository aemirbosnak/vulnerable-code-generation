//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of fortunes
#define NUM_FORTUNES 100

// Define the fortunes
char *fortunes[] = {
    "You will have good luck today.",
    "A new opportunity will come your way.",
    "You will receive a pleasant surprise.",
    "Your hard work will pay off.",
    "You will meet someone special.",
    "You will have a successful day.",
    "You will overcome a challenge.",
    "You will find what you are looking for.",
    "You will achieve your goals.",
    "You will experience happiness and joy."
};

// Function to generate a random number between 0 and n-1
int rand_int(int n) {
    return rand() % n;
}

// Function to print a fortune
void print_fortune(int num) {
    printf("%s\n", fortunes[num]);
}

// Main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Loop until the user is ready to quit
    while (1) {
        // Print the menu
        printf("Welcome to the Automated Fortune Teller!\n");
        printf("Please select an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Exit\n");

        // Read the user's choice
        int choice;
        scanf("%d", &choice);

        // Exit if the user chooses to quit
        if (choice == 2) {
            break;
        }

        // Generate a random fortune
        int num = rand_int(NUM_FORTUNES);

        // Print the fortune
        print_fortune(num);
    }

    return 0;
}