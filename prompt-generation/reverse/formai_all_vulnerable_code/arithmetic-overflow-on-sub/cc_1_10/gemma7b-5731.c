//Gemma-7B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    system("clear");
    printf("Welcome to the Galactic Command Center, Commander. Please select an option:");
    printf("\n");
    printf("1. Deploy troops to a planet.\n");
    printf("2. Launch a missile.\n");
    printf("3. Analyze a target.\n");
    printf("4. Access the secret archives.\n");

    int choice = getchar() - '0';

    switch (choice)
    {
        case 1:
            printf("Deploying troops... Prepare for galactic conquest!\n");
            sleep(2);
            system("clear");
            printf("Troops deployed successfully. Preparing for further orders.\n");
            break;
        case 2:
            printf("Launching a missile... Prepare for planetary destruction!\n");
            sleep(2);
            system("clear");
            printf("Missile launched successfully. Target decimated.\n");
            break;
        case 3:
            printf("Analyzing target... Prepare for intel gathering.\n");
            sleep(2);
            system("clear");
            printf("Target analysis complete. Intelligence gathered.\n");
            break;
        case 4:
            printf("Accessing secret archives... Prepare for historical revelations.\n");
            sleep(2);
            system("clear");
            printf("Secret archives accessed. Historical secrets revealed.\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
    }

    return 0;
}