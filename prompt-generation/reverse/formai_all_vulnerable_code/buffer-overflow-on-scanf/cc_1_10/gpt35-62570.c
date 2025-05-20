//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Seeding the random number generator

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");

    printf("Enter the number of UFO sightings in your area (last month): ");
    int sightings;
    scanf("%d", &sightings);

    printf("Enter the number of crop circles discovered in your area (last month): ");
    int cropCircles;
    scanf("%d", &cropCircles);

    printf("Enter the number of abductions reported in your area (last month): ");
    int abductions;
    scanf("%d", &abductions);

    printf("\nAnalyzing data...\n");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    printf("\n\nThe probability of an alien invasion in your area is: ");
    double probability = ((double)sightings / 10 + cropCircles + (double)abductions * 2) / 4;
    if (probability > 5)
    {
        printf("%.2f%%\n\n", probability);
        printf("WARNING: HIGH PROBABILITY OF AN ALIEN INVASION!\n");
        printf("Please take necessary precautions and alert the authorities immediately!\n");
    }
    else if (probability > 2)
    {
        printf("%.2f%%\n\n", probability);
        printf("CAUTION: MODERATE PROBABILITY OF AN ALIEN INVASION!\n");
        printf("Please remain vigilant and report any suspicious activity to the authorities.\n");
    }
    else
    {
        printf("%.2f%%\n\n", probability);
        printf("LOW PROBABILITY OF AN ALIEN INVASION.\n");
        printf("You may carry on with your normal routine, but stay alert.\n");
    }

    printf("\n\nPerforming deep scan of your device...\n");
    for (int i = 0; i < 5; i++)
    {
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    bool hasVirus = rand() % 2;  // Randomly generate whether the device has a virus or not
    if (hasVirus)
    {
        printf("\n\nWARNING: YOUR DEVICE HAS BEEN INFECTED WITH AN ALIEN VIRUS!\n");
        printf("Please disconnect from the internet and seek professional help.\n");
    }
    else
    {
        printf("\n\nYour device is free of any alien viruses.\n");
        printf("Stay safe and protect yourself from any potential alien threats!\n");
    }

    return 0;
}