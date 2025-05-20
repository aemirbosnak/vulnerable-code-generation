//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function declarations
void slow();
void fast();

// main function
int main()
{
    srand(time(0)); // Initializing srand with current time to generate a new seed on every run of the program
    int internet_speed = rand() % 101; // Generating a random internet speed between 0 and 100
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Your current internet speed is: %d Mbps\n\n", internet_speed);
    int choice;
    bool exit = false;
    // Loop to allow user to choose options until they want to exit
    while (!exit)
    {
        printf("Choose an option:\n");
        printf("1. Test internet speed again\n");
        printf("2. Test for slow connection\n");
        printf("3. Test for fast connection\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                internet_speed = rand() % 101;
                printf("Your current internet speed is: %d Mbps\n\n", internet_speed);
                break;
            case 2:
                slow();
                break;
            case 3:
                fast();
                break;
            case 4:
                printf("Thank you for using the Internet Speed Test Application!\n");
                exit = true;
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}

// Function to simulate slow internet connection
void slow()
{
    printf("Testing for slow internet connection...\n");
    int speed = rand() % 26; // Generating a random speed between 0 and 25
    if (speed < 5)
    {
        printf("Your internet speed is: %d Kbps\n", speed);
        printf("Your internet connection is extremely slow. Please contact your internet service provider.\n\n");
    }
    else if (speed < 10)
    {
        printf("Your internet speed is: %d Kbps\n", speed);
        printf("Your internet connection is slow. Please consider upgrading your plan.\n\n");
    }
    else
    {
        printf("Your internet speed is: %d Kbps\n", speed);
        printf("Your internet connection is below average. Please contact your internet service provider.\n\n");
    }
}

// Function to simulate fast internet connection
void fast()
{
    printf("Testing for fast internet connection...\n");
    int speed = rand() % 76 + 25; // Generating a random speed between 25 and 100
    if (speed > 90)
    {
        printf("Your internet speed is: %d Mbps\n", speed);
        printf("Your internet connection is blazingly fast! Enjoy the lightning speeds!\n\n");
    }
    else if (speed > 70)
    {
        printf("Your internet speed is: %d Mbps\n", speed);
        printf("Your internet connection is very fast. You can enjoy uninterrupted streaming, downloading and browsing!\n\n");
    }
    else
    {
        printf("Your internet speed is: %d Mbps\n", speed);
        printf("Your internet connection is above average. You can enjoy high speed internet.\n\n");
    }
}