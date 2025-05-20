//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void convertToHex(int num);
void displayMenu();
void handleChoice(int choice);
void getIntegerInput(int *num);
void sillyExit();

int main() {
    // Welcome to the magical world of Hexadecimal Conversions!
    printf("Welcome to the Hex-athon Spectacular!\n");
    printf("Where numbers sparkle and shine like diamonds in the sky!\n");

    int choice;

    // Loop until the user wants to exit
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        handleChoice(choice);
    }

    return 0;
}

void displayMenu() {
    printf("\nChoose your adventure:\n");
    printf("1. Convert a number to Hexadecimal!\n");
    printf("2. Exit the Hex-athon (the horror!).\n");
    printf("Enter your choice: ");
}

void handleChoice(int choice) {
    if (choice == 1) {
        int num;
        getIntegerInput(&num);
        convertToHex(num);
    } else if (choice == 2) {
        sillyExit();
    } else {
        printf("Oops! That choice is as confusing as a cat trying to understand quantum physics!\n");
    }
}

void getIntegerInput(int *num) {
    printf("Enter an integer to convert to Hexadecimal: ");
    // Making sure user gives us a valid integer, or else we'll flop like a fish out of water.
    while (scanf("%d", num) != 1) {
        printf("That's not a valid number! Try again, unless you're trying to summon the hexadecimal demon!\n");
        // Clear the input buffer
        while (getchar() != '\n');
    }
}

void convertToHex(int num) {
    char hex[BUFFER_SIZE];
    sprintf(hex, "%X", num); // Convert integer to Hexadecimal

    printf("Ta-da! The Hexadecimal representation of %d is: %s\n", num, hex);
}

void sillyExit() {
    printf("You’ve chosen to exit the Hex-athon!\n");
    printf("But before you go:\n");
    printf("Remember, Hexadecimals are like the secret agents of numbers; they live in a world of 0-9 and A-F!\n");
    printf("Thanks for joining us, and may your numbers always be whole!\n");
    exit(0);
}