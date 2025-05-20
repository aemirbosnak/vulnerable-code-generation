//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h> // standard input/output library
#include <stdlib.h> //standard library
#include <time.h> //time library

//function prototype
void delay(int ms);

int main()
{
    int timeElapsed = 0;
    int greenLight = 0;
    int redLight = 1;
    int yellowLight = 0;
    int cycleCount = 0;

    printf("*** Welcome to the City Light Traffic Controller System V1.0 ***\n");

    // infinite loop
    while (1)
    {
        printf("\nCycle %d:\n", cycleCount);

        //display red light
        printf("RED ");
        delay(10000); //delay of 10 seconds

        //display yellow light
        yellowLight = 1;
        printf("YELLOW ");
        delay(3000); //delay of 3 seconds

        //display green light
        greenLight = 1;
        redLight = 0;
        yellowLight = 0;
        printf("GREEN ");
        delay(7000); //delay of 7 seconds

        //Change back to red light after green
        redLight = 1;
        greenLight = 0;

        //increment cycle count
        cycleCount++;
    }

    return 0;
}

// Function to delay the execution of the program
void delay(int ms)
{
    clock_t start_time = clock(); // current clock time
    while (clock() < start_time + ms) // wait until required time has elapsed
    {
        // do nothing
    }
}