//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
// Ada Lovelace Fortune Teller

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

// Define the number of fortunes
#define NUM_FORTUNES 10

// Define the maximum length of a fortune
#define MAX_FORTUNE_LENGTH 80

// Define the fortunes
char* fortunes[NUM_FORTUNES] = {
    "You will have a happy life.",
    "A great adventure awaits you.",
    "You will find true love soon.",
    "You will achieve great success in your career.",
    "Your financial future is bright.",
    "You will make a new friend today.",
    "You will overcome any challenges that come your way.",
    "Your creativity will be rewarded.",
    "You will receive a pleasant surprise today.",
    "You will have good health and well-being."
};

// Function to generate a random number between 0 and n-1
int rand_int(int n) {
    return rand() % n;
}

// Function to get a random fortune
char* get_fortune() {
    return fortunes[rand_int(NUM_FORTUNES)];
}

// Function to print a fortune with a fancy border
void print_fortune(char* fortune) {
    int i, j, len;
    char border[MAX_FORTUNE_LENGTH + 2];

    // Calculate the length of the fortune
    len = strlen(fortune);

    // Generate the border
    for (i = 0; i < len + 2; i++) {
        border[i] = '*';
    }
    border[len + 1] = '\0';

    // Print the border
    printf("%s\n", border);

    // Print the fortune
    printf("%s\n", fortune);

    // Print the border again
    printf("%s\n", border);
}

// Main function
int main() {
    int choice;
    char input[MAX_FORTUNE_LENGTH];

    // Seed the random number generator
    srand(time(NULL));

    // Loop until the user wants to quit
    do {
        // Print the menu
        printf("Welcome to the Ada Lovelace Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Get a fortune\n");
        printf("2. Quit\n");

        // Get the user's choice
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                // Get a fortune
                printf("Your fortune is:\n");
                print_fortune(get_fortune());
                break;
            case 2:
                // Quit
                printf("Goodbye!\n");
                break;
            default:
                // Invalid choice
                printf("Invalid choice.\n");
        }

    // Loop until the user enters a valid choice
    } while (choice!= 1 && choice!= 2);

    return 0;
}