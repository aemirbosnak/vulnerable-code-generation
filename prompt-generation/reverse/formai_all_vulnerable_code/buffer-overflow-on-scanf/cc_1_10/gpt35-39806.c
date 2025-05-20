//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare and initialize variables
    int num;
    srand(time(0)); // Seed random number generator
    
    // Print welcome message
    printf("Welcome to the Automated Fortune Teller!\n\n");
    
    // Prompt user for their lucky number
    printf("Please enter your lucky number between 1 and 10: ");
    scanf("%d", &num);
    
    // Ensure user enters a valid number
    while (num < 1 || num > 10)
    {
        printf("Invalid number. Please enter your lucky number between 1 and 10: ");
        scanf("%d", &num);
    }
    
    // Generate random number and use it to display the fortune
    int fortune = rand() % 5 + 1;
    
    printf("\nYour fortune is:\n\n");
    
    switch (fortune)
    {
        case 1:
            printf("You will have a great day today!\n");
            break;
        case 2:
            printf("A great opportunity will come your way soon.\n");
            break;
        case 3:
            printf("You will meet someone important today.\n");
            break;
        case 4:
            printf("Your hard work will pay off in the near future.\n");
            break;
        case 5:
            printf("You will have a beautiful day, both inside and out.\n");
            break;
    }
    
    // Print goodbye message
    printf("\nThank you for using the Automated Fortune Teller!\n");
    
    return 0;
}