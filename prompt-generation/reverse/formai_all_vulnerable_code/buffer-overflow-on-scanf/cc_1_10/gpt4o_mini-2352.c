//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: real-life
#include <stdio.h>

// Function to calculate factorial recursively
unsigned long long int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// Function to display the menu and get user input
void displayMenu() {
    printf("\nWelcome to the Bakery Arrangement Calculator!\n");
    printf("Please enter the number of different types of pastries: ");
}

// Function to handle the user input and calculate arrangements
void calculateArrangements() {
    int typesOfPastries;
    
    // Display the menu and read input
    displayMenu();
    scanf("%d", &typesOfPastries);
    
    if (typesOfPastries < 0) {
        printf("Error: The number of pastry types cannot be negative. Please try again.\n");
        return;
    }

    // Calculate number of arrangements
    unsigned long long int arrangements = factorial(typesOfPastries);
    
    // Display the result
    printf("The number of distinct arrangements for %d types of pastries is: %llu\n", 
           typesOfPastries, arrangements);
}

int main() {
    char choice;

    do {
        calculateArrangements();
        printf("\nWould you like to calculate again? (y/n): ");
        scanf(" %c", &choice);  // Note the space before %c to consume any trailing newline
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Bakery Arrangement Calculator!\n");
    return 0;
}