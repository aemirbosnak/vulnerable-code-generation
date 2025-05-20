//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: beginner-friendly
#include<stdio.h>

//Function for taking input from user
int takeInput()
{
    int choice;
    printf("Enter 1 for Takeoff\n");
    printf("Enter 2 for Landing\n");
    printf("Enter 3 for Forward Movement\n");
    printf("Enter 4 for Backward Movement\n");
    printf("Enter 5 for Right Movement\n");
    printf("Enter 6 for Left Movement\n");
    scanf("%d",&choice);
    return choice;
}

//Function for sending the command to drone
void sendCommand(int choice)
{
    switch(choice)
    {
        case 1:
            printf("\nDrone is taking off");
            break;
        case 2:
            printf("\nDrone is landing");
            break;
        case 3:
            printf("\nDrone is moving forward");
            break;
        case 4:
            printf("\nDrone is moving backward");
            break;
        case 5:
            printf("\nDrone is moving right");
            break;
        case 6:
            printf("\nDrone is moving left");
            break;
        default:
            printf("\nEnter valid input\n");
    }
}

//Main function
int main()
{
    int choice;
    
    printf("************Welcome to Drone Remote Control************\n\n");

    //Loop for taking command until user exits
    while(1)
    {
        choice = takeInput();

        //Breaking loop if user enters 0
        if(choice == 0)
            break;

        sendCommand(choice);
    }
    return 0;
}