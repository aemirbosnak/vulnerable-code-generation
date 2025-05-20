//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void delay(int milliseconds)
{
    usleep(milliseconds * 1000); // Convert to microseconds
}

void printCyberpunkPattern(int n)
{
    char *symbols = ".*+-=~#@%&";
    int len = strlen(symbols);
    
    printf("\nCyberpunk Pattern Generation Initiated...\n");
    delay(1000); // Simulates loading time

    for (int i = 1; i <= n; i++)
    {
        // Print leading spaces for right alignment
        for (int j = 1; j <= n - i; j++)
            printf("  ");
        
        // Print symbols in ascending order
        for (int j = 1; j <= i; j++)
        {
            printf("%c ", symbols[j % len]);
            delay(100); // Creating a visual effect
        }

        // Print symbols in descending order
        for (int j = i - 1; j >= 1; j--)
        {
            printf("%c ", symbols[j % len]);
            delay(100); // Creating a visual effect
        }
        
        printf("\n");
        delay(100); // New line delay
    }
}

void displayMenu()
{
    printf("*****************************************\n");
    printf("   Welcome to the Cyberpunk Pattern App  \n");
    printf("*****************************************\n");
    printf("1. Generate Pattern\n");
    printf("2. Exit\n");
    printf("*****************************************\n");
    printf("Select an option: ");
}

int main()
{
    int choice = 0;
    int size = 0;

    while (1)
    {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter the size of the pattern (1-20): ");
                scanf("%d", &size);
                if (size < 1 || size > 20)
                {
                    printf("Invalid size. Please enter a size between 1 and 20.\n");
                    delay(1000);
                }
                else
                {
                    printCyberpunkPattern(size);
                }
                break;

            case 2:
                printf("Exiting the program... Stay Neon! 🔮\n");
                return 0;

            default:
                printf("Invalid choice. Please, try again.\n");
                delay(1000);
        }
    }
    
    return 0;
}