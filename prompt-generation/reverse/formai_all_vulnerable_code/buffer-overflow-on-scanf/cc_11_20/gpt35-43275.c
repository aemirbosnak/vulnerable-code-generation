//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Variables for user input and random number
    int choice, num;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Welcome message
    printf("Welcome to the Automated Fortune Teller!\n\n");
    
    // Loop for user to continue or quit
    while (1) {
        // Prompt for user input
        printf("Enter 1 to receive a fortune, or 2 to quit: ");
        scanf("%d", &choice);
        
        // Check for valid input
        if (choice < 1 || choice > 2) {
            printf("Invalid input. Please try again.\n\n");
            continue;
        }
        
        // Quit if user chooses to
        if (choice == 2) {
            printf("Thank you for using the Automated Fortune Teller!\n");
            break;
        }
        
        // Generate a random number between 1-10
        num = rand() % 10 + 1;
        
        // Switch statement to print fortune based on random number
        switch (num) {
            case 1:
                printf("You will soon meet a new friend who will change your life.\n\n");
                break;
            case 2:
                printf("Your hard work will pay off in the near future.\n\n");
                break;
            case 3:
                printf("This is a good time to start something new, don't be afraid.\n\n");
                break;
            case 4:
                printf("Your current situation will improve with time, keep on pushing.\n\n");
                break;
            case 5:
                printf("Soon you will receive unexpected but much needed financial help.\n\n");
                break;
            case 6:
                printf("Be careful not to trust someone who may turn out to be an enemy.\n\n");
                break;
            case 7:
                printf("Luck will be on your side today and in the near future.\n\n");
                break;
            case 8:
                printf("Someone you love will surprise you with a gift or gesture soon.\n\n");
                break;
            case 9:
                printf("Change is necessary, embrace it and it will lead to positive outcomes.\n\n");
                break;
            case 10:
                printf("Trust your instincts, they will lead you to the right path.\n\n");
                break;
        }
    }
    
    return 0;
}