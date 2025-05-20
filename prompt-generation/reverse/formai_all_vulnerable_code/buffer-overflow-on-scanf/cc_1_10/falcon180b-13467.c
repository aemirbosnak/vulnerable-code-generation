//Falcon-180B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
void happyFunction(int num);
void sadFunction(int num);

//Main Function
int main()
{
    //Initialize variables
    int choice;
    int num;

    //Seed the random number generator
    srand(time(NULL));

    //Print a cheerful message
    printf("Welcome to the Happy Error Handling Program!\n");
    printf("We hope you have a wonderful time using our program!\n\n");

    //Ask the user which function they want to use
    printf("Please choose a function:\n");
    printf("1. Happy Function\n2. Sad Function\n");
    scanf("%d", &choice);

    //Call the appropriate function
    switch(choice)
    {
        case 1:
            happyFunction(num);
            break;
        case 2:
            sadFunction(num);
            break;
        default:
            printf("Invalid choice! Please choose 1 or 2.\n");
            exit(0);
    }

    //Print a cheerful message
    printf("\nThank you for using our program! Have a great day!\n");

    //Exit the program
    return 0;
}

//Happy Function
void happyFunction(int num)
{
    //Print a cheerful message
    printf("You chose the Happy Function!\n");

    //Generate a random number between 1 and 100
    int randNum = rand() % 100 + 1;

    //Check if the random number is even or odd
    if(randNum % 2 == 0)
    {
        printf("The random number is even: %d\n", randNum);
    }
    else
    {
        printf("The random number is odd: %d\n", randNum);
    }

    //Print a cheerful message
    printf("We hope you enjoyed the Happy Function!\n");
}

//Sad Function
void sadFunction(int num)
{
    //Print a sad message
    printf("You chose the Sad Function...\n");

    //Generate a random number between 1 and 100
    int randNum = rand() % 100 + 1;

    //Check if the random number is even or odd
    if(randNum % 2 == 0)
    {
        printf("The random number is even: %d\n", randNum);
    }
    else
    {
        printf("The random number is odd: %d\n", randNum);
    }

    //Print a sad message
    printf("We're sorry you didn't enjoy the Sad Function...\n");
}