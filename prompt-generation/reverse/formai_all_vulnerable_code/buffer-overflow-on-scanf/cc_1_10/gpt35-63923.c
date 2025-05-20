//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Declare function for checking user input
int checkInput(int low, int high);

// Declare function for printing directions
void printDirections(int start, int end);

int main()
{
    int startLocation, endLocation;
    
    // Prompt user for starting location
    printf("Enter your starting location: (1-10) ");
    
    // Check user input
    startLocation = checkInput(1, 10);
    
    // Prompt user for ending location
    printf("Enter your ending location: (1-10) ");
    
    // Check user input
    endLocation = checkInput(1, 10);
    
    // Print directions for user
    printf("\nCalculating directions...\n\n");
    printDirections(startLocation, endLocation);
    
    return 0;
}

int checkInput(int low, int high)
{
    int input;
    
    do {
        printf("> ");
        scanf("%d", &input);
        
        if (input < low || input > high) {
            printf("Invalid input. Please enter a number between %d and %d.\n", low, high);
        }
    } while (input < low || input > high);
    
    return input;
}

void printDirections(int start, int end)
{
    if (start == end) {
        printf("You are already at your destination!\n");
    } else {
        printf("Navigate from location %d to location %d.\n", start, end);
        
        if (start < end) {
            printf("Head northeast for 2 miles.\n");
            printf("Turn right onto Main St.\n");
            printf("Continue straight for 5 miles.\n");
        } else {
            printf("Head southwest for 3 miles.\n");
            printf("Turn left onto Washington St.\n");
            printf("Continue straight for 7 miles.\n");
        }
        
        printf("You have arrived at your destination!\n");
    }
}