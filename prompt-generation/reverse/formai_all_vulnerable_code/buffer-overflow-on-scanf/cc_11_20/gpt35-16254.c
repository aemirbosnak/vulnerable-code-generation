//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20], question[100];
    int random_number;
 
    srand(time(NULL)); //initialize random number generator

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello, %s! Ask me any question and I will try to predict the future!\n", name);
    scanf(" %[^\n]", question); //read entire line of input
 
    //generate random number to determine fortune
    random_number = rand() % 10 + 1; //random number between 1 and 10
 
    if(random_number == 1)
    {
        printf("I can see a lot of money in your future!\n");
    }
    else if(random_number == 2)
    {
        printf("You will meet the love of your life soon!\n");
    }
    else if(random_number == 3)
    {
        printf("Your hard work will pay off in a big way!\n");
    }
    else if(random_number == 4)
    {
        printf("A big change is coming your way, be ready for it!\n");
    }
    else if(random_number == 5)
    {
        printf("Be careful, someone close to you is not who they seem!\n");
    }
    else if(random_number == 6)
    {
        printf("Your dream vacation is right around the corner!\n");
    }
    else if(random_number == 7)
    {
        printf("Don't worry, everything will work out in the end!\n");
    }
    else if(random_number == 8)
    {
        printf("A new opportunity is coming your way, be ready to seize it!\n");
    }
    else if(random_number == 9)
    {
        printf("Your creativity will be your greatest asset in the days to come!\n");
    }
    else if(random_number == 10)
    {
        printf("You will find success in everything you do, keep up the good work!\n");
    }
    
    printf("Thank you for using the Automated Fortune Teller! Good luck, %s!\n", name);
 
    return 0;
}