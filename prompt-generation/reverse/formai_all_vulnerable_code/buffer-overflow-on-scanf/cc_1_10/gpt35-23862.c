//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to simulate arrival of baggage
void arrival(int *bags, int *available_space)
{
    int num_bags = rand() % 10 + 1; //Simulate random number of bags between 1 to 10
    printf("\n\n***************Baggage Arrival***************\n\n");
    printf("Number of Bags: %d\n", num_bags);
    //Check if there is enough space to accommodate all bags
    if (*available_space >= num_bags)
    {
        *available_space -= num_bags;
        *bags += num_bags;
        printf("Bags have been added to the system\n");
        printf("Current number of bags in the system: %d\n", *bags);
        printf("Current available space for bags: %d\n", *available_space);
    }
    else
    {
        printf("Sorry, there is not enough space to accommodate all bags\n");
        printf("Current number of bags in the system: %d\n", *bags);
        printf("Current available space for bags: %d\n", *available_space);
    }
}

//Function to simulate departure of baggage
void departure(int *bags)
{
    int num_bags = rand() % (*bags + 1); //Simulate random number of bags
    printf("\n\n***************Baggage Departure***************\n\n");
    printf("Number of Bags: %d\n", num_bags);
    //Check if there are enough bags in the system to remove
    if (*bags >= num_bags)
    {
        *bags -= num_bags;
        printf("Bags have been removed from the system\n");
        printf("Current number of bags in the system: %d\n", *bags);
    }
    else
    {
        printf("Sorry, there are not enough bags in the system to remove\n");
        printf("Current number of bags in the system: %d\n", *bags);
    }
}

//Main function
int main()
{
    int bags = 0; //Variable to store current number of bags in the system
    int available_space = 100; //Variable to store current available space for bags
    int choice; //Variable to store user's choice
    srand(time(NULL)); //Seed the random number generator with current time

    //Display menu and get user's choice
    do
    {
        printf("\n\n***************Airport Baggage Handling System***************\n\n");
        printf("Current number of bags in the system: %d\n", bags);
        printf("Current available space for bags: %d\n", available_space);
        printf("1. Baggage Arrival\n2. Baggage Departure\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                arrival(&bags, &available_space);
                break;
            case 2:
                departure(&bags);
                break;
            case 3:
                printf("\n\nExiting the program...\n\n");
                break;
            default:
                printf("\n\nInvalid choice, please try again...\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}