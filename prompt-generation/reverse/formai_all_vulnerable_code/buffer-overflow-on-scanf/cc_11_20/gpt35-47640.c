//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGNAL_STRENGTH 100

int main()
{
    int signalStrength[MAX_SIGNAL_STRENGTH];
    int option;
    int i, j;
    int maxStrength, minStrength;
    float avgStrength;

    printf("Welcome to Wi-Fi Signal Strength Analyzer\n");

    while(1)
    {
        printf("\nPlease select an option:\n");
        printf("1. Enter signal strength data\n");
        printf("2. Display signal strength data\n");
        printf("3. Calculate maximum, minimum and average signal strength\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\nEnter the signal strength data:\n");
                for(i = 0; i < MAX_SIGNAL_STRENGTH; i++)
                {
                    printf("Signal strength %d: ", i+1);
                    scanf("%d", &signalStrength[i]);
                }
                break;
            case 2:
                printf("\nDisplaying signal strength data:\n");
                for(i = 0; i < MAX_SIGNAL_STRENGTH; i++)
                {
                    printf("%d\t", signalStrength[i]);
                    if((i+1)%10 == 0)
                        printf("\n");
                }
                break;
            case 3:
                maxStrength = signalStrength[0];
                minStrength = signalStrength[0];
                avgStrength = 0;
                for(i = 0; i < MAX_SIGNAL_STRENGTH; i++)
                {
                    if(signalStrength[i] > maxStrength)
                        maxStrength = signalStrength[i];
                    if(signalStrength[i] < minStrength)
                        minStrength = signalStrength[i];
                    avgStrength += signalStrength[i];
                }
                avgStrength /= MAX_SIGNAL_STRENGTH;
                printf("\nMaximum signal strength: %d\n", maxStrength);
                printf("Minimum signal strength: %d\n", minStrength);
                printf("Average signal strength: %.2f\n", avgStrength);
                break;
            case 4:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid option, please try again.\n");
        }
    }

    return 0;
}