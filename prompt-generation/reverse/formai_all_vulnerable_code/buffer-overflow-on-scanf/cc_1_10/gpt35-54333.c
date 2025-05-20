//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, redTime, greenTime, yellowTime;
    
    /* Input the time duration for each light */
    printf("Enter the duration of Red Light (in seconds): ");
    scanf("%d", &redTime);
    printf("Enter the duration of Green Light (in seconds): ");
    scanf("%d", &greenTime);
    printf("Enter the duration of Yellow Light (in seconds): ");
    scanf("%d", &yellowTime);
    
    /* Validating the entered durations */
    if(redTime <= 0 || greenTime <= 0 || yellowTime <= 0){
        printf("\nInvalid Time Duration entered. Please enter a positive time duration.\n");
        exit(0);
    }
    
    /* Traffic light controller loop*/
    while(1){
        printf("\n\nTraffic Light Controller - Choose the current state: ");
        printf("\n1. Red Light");
        printf("\n2. Green Light");
        printf("\n3. Yellow Light");
        printf("\n4. Quit\n");

        /* Validating the entered choice */
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nRED LIGHT for %d seconds", redTime);
                sleep(redTime);
                break;
            case 2:
                printf("\nGREEN LIGHT for %d seconds", greenTime);
                sleep(greenTime);
                break;
            case 3:
                printf("\nYELLOW LIGHT for %d seconds", yellowTime);
                sleep(yellowTime);
                break;
            case 4:
                printf("\nExiting the Traffic Light Controller...");
                exit(0);
            default:
                printf("\nInvalid Choice entered. Please enter a valid choice (1-4)");
        }
    }
    return 0;
}