//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int speed, result;
    float time_taken;
    char choice;

    printf("Welcome to the Internet Speed Test Application\n");
    printf("Do you want to start the test? (y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Testing...\n");

        // Simulate internet speed test by generating a random number between 1 and 100
        srand(time(NULL));
        speed = (rand() % 100) + 1;
        printf("Your internet speed is %d Mbps\n", speed);

        // Calculate the time taken to download a 10MB file based on speed
        time_taken = (10.0 / speed) * 8;
        printf("Time taken to download a 10MB file is: %.2f seconds\n", time_taken);

        // Determine the internet speed based on the time taken to download the file
        if (time_taken > 0 && time_taken <= 1)
        {
            printf("Your internet speed is Exceptional!\n");
        }
        else if (time_taken > 1 && time_taken <= 3)
        {
            printf("Your internet speed is Good.\n");
        }
        else if (time_taken > 3 && time_taken <= 6)
        {
            printf("Your internet speed is Average.\n");
        }
        else if (time_taken > 6 && time_taken <= 10)
        {
            printf("Your internet speed is Poor.\n");
        }
        else
        {
            printf("Your internet speed is Terrible!\n");
        }

        result = 0;
    }
    else
    {
        printf("You have chosen not to start the test!\n");
        result = 1;
    }

    return result;
}