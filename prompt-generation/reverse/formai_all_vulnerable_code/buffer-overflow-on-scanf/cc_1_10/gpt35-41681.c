//FormAI DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// function prototypes
void clearInputBuffer();
void exitWithError(char* message);

int main()
{
    // Declare variables
    char name[20];
    int age, suspectNumber, weaponNumber, locationNumber;
    
    // Welcome message
    printf("Welcome to the Murder Mystery Game Simulation\n");
    printf("To solve the case, you need to answer a few questions\n");
    
    // Get user input for name
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    
    // strip the newline character from fgets input
    name[strcspn(name, "\n")] = 0;
    
    // Get user input for age
    printf("Enter your age: ");
    if(scanf("%d", &age) != 1)
    {
        clearInputBuffer();
        exitWithError("Invalid age input. Please enter a number.");
    }
    
    // Get user input for suspect number
    printf("Enter the suspect number you want to investigate (1-5): ");
    if(scanf("%d", &suspectNumber) != 1)
    {
        clearInputBuffer();
        exitWithError("Invalid suspect number input. Please enter a number.");
    }
    
    // Validate suspect number input
    if(suspectNumber < 1 || suspectNumber > 5)
    {
        exitWithError("Invalid suspect number. Please enter a number between 1-5.");
    }
    
    // Get user input for weapon number
    printf("Enter the weapon number you want to investigate (1-3): ");
    if(scanf("%d", &weaponNumber) != 1)
    {
        clearInputBuffer();
        exitWithError("Invalid weapon number input. Please enter a number.");
    }
    
    // Validate weapon number input
    if(weaponNumber < 1 || weaponNumber > 3)
    {
        exitWithError("Invalid weapon number. Please enter a number between 1-3.");
    }
    
    // Get user input for location number
    printf("Enter the location number you want to investigate (1-2): ");
    if(scanf("%d", &locationNumber) != 1)
    {
        clearInputBuffer();
        exitWithError("Invalid location number input. Please enter a number.");
    }
    
    // Validate location number input
    if(locationNumber < 1 || locationNumber > 2)
    {
        exitWithError("Invalid location number. Please enter a number between 1-2.");
    }
    
    // Print final message
    printf("Congratulations, %s. You solved the murder mystery game simulation.\n", name);
    printf("You investigated suspect %d with the %d weapon at location %d.\n", suspectNumber, weaponNumber, locationNumber);
    
    return 0;
}

// function definition to clear input buffer
void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// function definition to exit program with error message
void exitWithError(char* message)
{
    printf("Error: %s\n", message);
    exit(1);
}