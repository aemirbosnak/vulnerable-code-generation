//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    
    char userChoice = 'y';
    
    // loop until user wants to exit
    while (userChoice == 'y' || userChoice == 'Y') {
        printf("Welcome to the Automated Fortune Teller! \n\n");
        
        // randomly choose a fortune
        int randomNumber = rand() % 5;
        char* fortune;
        
        switch (randomNumber) {
            case 0:
                fortune = "You will find love in the near future.";
                break;
            case 1:
                fortune = "A great opportunity will present itself to you in the coming days.";
                break;
            case 2:
                fortune = "You will face a challenge, but you will overcome it with ease.";
                break;
            case 3:
                fortune = "Money is in your future, but be sure to use it wisely.";
                break;
            case 4:
                fortune = "Your hard work will pay off, keep going!";
                break;
            default:
                fortune = "Something went wrong with the fortune telling process.";
                break;
        }
        
        printf("Your fortune is: %s \n\n", fortune);
        
        // ask user if they want another fortune
        printf("Would you like to receive another fortune? (y/n) ");
        scanf(" %c", &userChoice);
        printf("\n");
    }
    
    printf("Thank you for using the Automated Fortune Teller! \n");
    
    return 0;
}