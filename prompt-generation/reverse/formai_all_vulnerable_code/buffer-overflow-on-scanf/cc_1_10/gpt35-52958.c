//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Sherlock Holmes
//The Adventure of the Traffic Light Controller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random number
int generateRandomNumber(int min, int max){
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

//function to wait for a few seconds
void wait(int seconds){
    int milli_seconds = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main(){
    int greenTime, yellowTime, redTime, totalCycles;
    char option;
    printf("Welcome to the Traffic Light Controller Game!\n");

    do{
        printf("Enter the time for green light (in seconds): ");
        scanf("%d", &greenTime);
        printf("Enter the time for yellow light (in seconds): ");
        scanf("%d", &yellowTime);
        printf("Enter the time for red light (in seconds): ");
        scanf("%d", &redTime);
        printf("Enter the total number of cycles: ");
        scanf("%d", &totalCycles);

        printf("Traffic light will now start...\n");

        int cycleCount = 1;
        while(cycleCount <= totalCycles){
            printf("\nCycle %d\n", cycleCount);

            printf("Green light is on for %d seconds\n", greenTime);
            wait(greenTime);

            printf("Yellow light is on for %d seconds\n", yellowTime);
            wait(yellowTime);

            printf("Red light is on for %d seconds\n", redTime);
            wait(redTime);

            printf("Cycle %d is complete\n", cycleCount);
            cycleCount++;
        }

        printf("\nTraffic Light Controller game is over.\n");
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &option);

    } while(option == 'y' || option == 'Y');

    printf("Thanks for playing Traffic Light Controller game!\n");
    return 0;
}