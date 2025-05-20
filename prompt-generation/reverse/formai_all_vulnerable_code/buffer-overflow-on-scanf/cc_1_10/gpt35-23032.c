//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//function to control the traffic on the road
void trafficController(char signal) 
{
    if (signal == 'g') //Green signal
    {
        printf("\nGreen signal is on, Go!\n");
        sleep(10); //let the vehicles pass for 10 seconds
    }
    else if (signal == 'y') //Yellow signal
    {
        printf("\nYellow signal is on, Slow down!\n");
        sleep(5); //let the vehicles slow down for 5 seconds
    }
    else if (signal == 'r') //Red signal
    {
        printf("\nRed signal is on, Stop!\n");
        sleep(10); //let the vehicles stop for 10 seconds
    }
    else //Invalid signal
    {
        printf("\nInvalid signal detected, Try again!\n");
    }
}

int main() 
{
    char signal;
    int choice;

    do 
    {
        system("clear"); //clear previous output from the terminal
        printf("\n\n\t\tTraffic Light Controller\n\n");
        printf("1.Green signal\n2.Yellow signal\n3.Red signal\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: //Green signal
                signal = 'g';
                trafficController(signal);
                break;

            case 2: //Yellow signal
                signal = 'y';
                trafficController(signal);
                break;

            case 3: //Red signal
                signal = 'r';
                trafficController(signal);
                break;

            case 4: //Exit
                printf("\nExiting the program...\n");
                exit(0);

            default: //Invalid choice
                printf("\nInvalid choice detected, Try again!\n");
                sleep(2);
                break;
        }
    } while(choice != 4);

    return 0;
}