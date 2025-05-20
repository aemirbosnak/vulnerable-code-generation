//FormAI DATASET v1.0 Category: Smart home light control ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define GPIO pins
#define LIVING_ROOM_LIGHT 3
#define BEDROOM_LIGHT 4
#define KITCHEN_LIGHT 5

// Function prototypes
void switchLight(int pin, int state);
void printMenu();
int getUserChoice();
void handleUserChoice(int choice);

// Main function
int main()
{
    int choice;

    printf("Welcome to Smart Home Light Control System!\n");

    // Initiate GPIO pins
    // ...

    while (1) {
    
        printMenu();
        
        choice = getUserChoice();
        
        handleUserChoice(choice);
    }

    return 0;
}

void switchLight(int pin, int state)
{
    // Switch light based on pin and state
    // ...
}

void printMenu()
{
    printf("Choose which light to control:\n");
    printf("1. Living room light\n");
    printf("2. Bedroom light\n");
    printf("3. Kitchen light\n");
    printf("4. Exit\n");
}

int getUserChoice()
{
    int choice;
    
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

void handleUserChoice(int choice)
{
    switch (choice) {
        case 1:
            // Handle living room light
            printf("Living room light is currently on.\n");
            printf("Would you like to turn it off?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Turning off living room light...\n");
                switchLight(LIVING_ROOM_LIGHT, 0);
            }
            break;
        case 2:
            // Handle bedroom light
            printf("Bedroom light is currently off.\n");
            printf("Would you like to turn it on?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Turning on bedroom light...\n");
                switchLight(BEDROOM_LIGHT, 1);
            }
            break;
        case 3:
            // Handle kitchen light
            printf("Kitchen light is currently off.\n");
            printf("Would you like to turn it on?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("Turning on kitchen light...\n");
                switchLight(KITCHEN_LIGHT, 1);
            }
            break;
        case 4:
            // Exit program
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}