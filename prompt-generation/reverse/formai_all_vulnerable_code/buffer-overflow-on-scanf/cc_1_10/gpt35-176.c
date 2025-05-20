//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void welcome();
int getLuckyNumber();
char* getFortune(int luckyNumber);
void goodbye();

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Print a welcome message
    welcome();
    
    // Get the user's lucky number
    int luckyNumber = getLuckyNumber();
    
    // Get the user's fortune based on their lucky number
    char* fortune = getFortune(luckyNumber);
    
    // Print the user's fortune
    printf("Your fortune is: %s\n", fortune);
    
    // Say goodbye to the user
    goodbye();
    
    return 0;
}

void welcome()
{
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("This program will tell your fortune based on a lucky number.\n");
}

int getLuckyNumber()
{
    int luckyNumber;
    
    printf("Please enter a lucky number between 1 and 10: ");
    scanf("%d", &luckyNumber);
    
    // Check if the user entered a valid number
    if (luckyNumber < 1 || luckyNumber > 10)
    {
        printf("Invalid lucky number. Please enter a number between 1 and 10.\n");
        return getLuckyNumber();
    }
    
    return luckyNumber;
}

char* getFortune(int luckyNumber)
{
    char* fortune;
    
    switch(luckyNumber)
    {
        case 1:
            fortune = "You will find love soon.";
            break;
        case 2:
            fortune = "Your hard work will pay off soon.";
            break;
        case 3:
            fortune = "You will receive a surprise gift.";
            break;
        case 4:
            fortune = "Your health will improve.";
            break;
        case 5:
            fortune = "You will soon embark on an exciting adventure.";
            break;
        case 6:
            fortune = "You will find success in your career.";
            break;
        case 7:
            fortune = "You will make a new friend.";
            break;
        case 8:
            fortune = "You will receive good news.";
            break;
        case 9:
            fortune = "Your creativity will be rewarded.";
            break;
        case 10:
            fortune = "You will inherit something valuable.";
            break;
        default:
            fortune = "Error: Invalid lucky number.";
            break;
    }
    
    return fortune;
}

void goodbye()
{
    printf("Thank you for using the Automated Fortune Teller!\n");
}