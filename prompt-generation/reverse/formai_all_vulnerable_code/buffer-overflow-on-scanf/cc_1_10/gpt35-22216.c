//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to print the C pattern
void printCPattern(int size) {
    for(int row=1; row<=size; row++) {
        for(int col=1; col<=size/2; col++) {
            if((row==1 && col!=1) || (row==size && col!=1)) {
                printf("* ");
            } else if(col==1 && (row!=1 && row!=size)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print the greeting message
void printGreeting() {
    printf("Welcome to the C pattern printing program!\n");
    printf("Please enter the size of the pattern you want to print (must be an even number): ");
}

// Main function to execute the program
int main() {
    int size;
    
    printf("Program starting...\n");
    sleep(1); // Wait for 1 second
    printf("Initializing...\n");
    sleep(1); // Wait for 1 second
    printf("Loading...\n");
    sleep(1); // Wait for 1 second
    
    // Print the greeting message
    printGreeting();
    
    // Read the input size from the user
    scanf("%d", &size);
    
    // Validate the input size
    if(size%2 != 0) {
        printf("Invalid input size, please enter an even number!\n");
        exit(0);
    }
    
    // Print the C pattern
    printCPattern(size);
    
    printf("Done!\n");
    
    return 0;
}