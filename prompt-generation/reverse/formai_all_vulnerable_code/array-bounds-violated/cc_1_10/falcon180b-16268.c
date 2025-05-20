//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of fortunes
#define NUM_FORTUNES 100

// Define the maximum length of a fortune
#define MAX_FORTUNE_LEN 80

// Define the fortunes
char *fortunes[] = {
    "You will have a successful day!",
    "A pleasant surprise awaits you.",
    "Good things come to those who wait.",
    "You will receive unexpected news.",
    "Your hard work will pay off soon.",
    "A new opportunity will present itself to you.",
    "You will experience a moment of great joy.",
    "Your future looks bright and promising.",
    "Success is just around the corner.",
    "You will overcome any obstacles in your way."
};

// Function to print a random fortune
void print_fortune() {
    int index = rand() % NUM_FORTUNES;
    printf("%s\n", fortunes[index]);
}

// Main function
int main() {
    srand(time(NULL));

    // Loop until the user decides to quit
    while (1) {
        printf("Would you like to hear a fortune? (y/n): ");
        char choice;
        scanf("%c", &choice);

        // If the user chooses to hear a fortune, print one
        if (choice == 'y' || choice == 'Y') {
            print_fortune();
        }
        // If the user chooses to quit, exit the program
        else if (choice == 'n' || choice == 'N') {
            break;
        }
        // If the user enters an invalid choice, try again
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}