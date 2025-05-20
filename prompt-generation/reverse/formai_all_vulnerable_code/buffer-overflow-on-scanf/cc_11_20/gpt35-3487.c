//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SPEED 1000 // Maximum internet speed in Mbps

int main()
{
    srand(time(NULL)); // Seed for random number generator

    printf("Welcome to the Retro Internet Speed Test!\n\n");

    printf("************************************************\n");
    printf("*                   INSTRUCTIONS               *\n");
    printf("* Perform the following actions as fast as you *\n");
    printf("* can:                                         *\n");
    printf("* 1. Type 'start' and hit enter                *\n");
    printf("* 2. Download a file as fast as you can        *\n");
    printf("* 3. Type 'done' and hit enter                 *\n");
    printf("************************************************\n\n");

    printf("Ready to start? Type 'start' to begin.\n");

    char input[6];
    bool testStarted = false;
    int downloadSpeed = 0;

    while (1)
    {
        scanf("%s", input);

        if (strcmp(input, "start") == 0 && !testStarted)
        {
            printf("\nStarting download...\n\n");

            // Simulating download with random speed
            downloadSpeed = rand() % MAX_SPEED + 1;
            printf("Download speed: %d Mbps\n", downloadSpeed);

            testStarted = true;
        }
        else if (strcmp(input, "done") == 0 && testStarted)
        {
            printf("\nDownload complete!\n\n");

            // Calculating download time based on speed
            int fileSize = 100;
            float downloadTime = (float)fileSize / downloadSpeed * 8;
            printf("Download time: %.2f seconds\n", downloadTime);

            // Rating the speed
            char* rating;
            if (downloadSpeed < 10)
                rating = "Terrible";
            else if (downloadSpeed < 100)
                rating = "Poor";
            else if (downloadSpeed < 500)
                rating = "Good";
            else if (downloadSpeed < 1000)
                rating = "Great";
            else
                rating = "Amazing";

            printf("Speed rating: %s\n", rating);

            // Resetting for next test
            testStarted = false;
            downloadSpeed = 0;

            printf("\nReady for the next test! Type 'start' to begin.\n");
        }
        else if (strcmp(input, "quit") == 0)
        {
            printf("\nThank you for using the Retro Internet Speed Test!\n");
            break;
        }
        else
        {
            printf("\nInvalid input. Type 'start' or 'done', or 'quit' to exit.\n");
        }
    }

    return 0;
}