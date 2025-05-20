//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void displayGreeting();
void displayFortune();

// Entry point of the program
int main()
{
    srand(time(NULL)); // Setting seed for random number generation
    
    displayGreeting(); // Display greeting message
    
    // Loop through the fortune-telling process until the user quits
    while (1)
    {
        int choice;
        
        printf("\nPlease enter your question (or enter 0 to quit): ");
        scanf("%d", &choice);
        
        if (choice == 0)
        {
            printf("\nThank you for using the C Automated Fortune Teller. Goodbye!\n");
            return 0;
        }
        
        displayFortune();
    }
    
    return 0;
}

// Function definition to display the greeting message
void displayGreeting()
{
    printf("\nWelcome to the C Automated Fortune Teller!\n");
    printf("Ask any question and receive a mystical answer!\n");
}

// Function definition to display a random fortune
void displayFortune()
{
    char *fortunes[] = {
        "Yes",
        "No",
        "Maybe",
        "It is certain",
        "Most likely",
        "Don't count on it",
        "Outlook not so good",
        "Signs point to yes",
        "Ask again later",
        "Better not tell you now"
    };
    
    int index = rand() % 10;
    
    printf("\nYour answer is: %s\n", fortunes[index]);
}