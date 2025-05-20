//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 100

// Structure to hold a fortune
typedef struct {
    char text[80];
    int lucky_number;
} Fortune;

// Function to generate a random fortune
Fortune generate_fortune() {
    Fortune fortune;
    int i;
    
    // Initialize the fortune with a random text
    for (i = 0; i < 80; i++) {
        fortune.text[i] = 'A' + rand() % 26;
    }
    fortune.text[79] = '\0';
    
    // Add a random lucky number
    fortune.lucky_number = rand() % 100;
    
    return fortune;
}

// Function to print a fortune
void print_fortune(Fortune fortune) {
    printf("Your fortune: %s\n", fortune.text);
    printf("Your lucky number is: %d\n", fortune.lucky_number);
}

// Main function
int main() {
    int choice;
    Fortune fortune;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Print the menu
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please choose an option:\n");
    printf("1. Get a fortune\n");
    printf("2. Exit\n");
    
    // Get the user's choice
    scanf("%d", &choice);
    
    // Handle the user's choice
    switch (choice) {
        case 1:
            // Generate a random fortune
            fortune = generate_fortune();
            
            // Print the fortune
            print_fortune(fortune);
            break;
            
        case 2:
            // Exit the program
            printf("Goodbye!\n");
            break;
            
        default:
            // Invalid choice
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}