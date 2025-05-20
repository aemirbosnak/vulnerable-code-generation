//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller()
{
    int random = rand() % 10; // Generate a random number between 0 to 9
    switch(random)
    {
        case 0:
            printf("You will find your true love soon.\n");
            break;
        
        case 1:
            printf("A great career opportunity is coming your way.\n");
            break;
        
        case 2:
            printf("You will receive unexpected money in the near future.\n");
            break;
        
        case 3:
            printf("You will travel to a beautiful place soon.\n");
            break;
        
        case 4:
            printf("You will be blessed with good health.\n");
            break;
        
        case 5:
            printf("You will meet someone who will change your life forever.\n");
            break;
        
        case 6:
            printf("You will successfully complete a challenging task.\n");
            break;
        
        case 7:
            printf("You will receive good news from a friend or a family member.\n");
            break;
        
        case 8:
            printf("You will achieve your long-term goal soon.\n");
            break;
        
        case 9:
            printf("You will experience joy and happiness in your life.\n");
            break;
    }
}

int main()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    srand(time(NULL)); // Seed the random number generator
    
    char choice;
    do
    {
        printf("Enter 'Y' to get your fortune or 'N' to quit: ");
        scanf(" %c", &choice);
        if(choice == 'Y' || choice == 'y')
        {
            printf("Your fortune is: ");
            fortune_teller();
            printf("\n");
        }
        else if(choice != 'N' && choice != 'n')
        {
            printf("Invalid input! Please try again.\n");
        }
    }
    while(choice != 'N' && choice != 'n');
    
    printf("Thank you for using the Automated Fortune Teller!\n");
    
    return 0;
}