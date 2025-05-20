//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to generate random signal strength value between -100dBm to -20dBm
int generateSignalStrength(){
    return (rand() % (80 + 1)) - 100;
}

int main(){

    // initializing variables
    int signalStrength = 0;
    char networkName[20];
    char choice;

    // setting seed for random number generation
    srand(time(NULL));

    // asking user for network name
    printf("Enter the name of the network: ");
    scanf("%s", networkName);

    // infinite loop until user exits
    while(1){

        // generating random signal strength
        signalStrength = generateSignalStrength();

        // displaying the signal strength and network name
        printf("\nSignal Strength for '%s' Network: %ddBm\n", networkName, signalStrength);

        // checking if signal strength is below -80dBm
        if(signalStrength < -80){
            printf("The network signal is very weak. Please move closer to the router.\n");
        }

        // checking if signal strength is below -60dBm
        else if(signalStrength < -60){
            printf("The network signal is weak. Consider moving to a better location.\n");
        }

        // checking if signal strength is below -40dBm
        else if(signalStrength < -40){
            printf("The network signal is strong. You are connected to the network.\n");
        }

        // checking if signal strength is equal or greater than -40dBm
        else{
            printf("The network signal is excellent. Enjoy your high-speed internet.\n");
        }

        // asking user if they want to check another network
        printf("Do you want to check another network? (y/n): ");
        scanf(" %c", &choice);

        // checking user input
        if(choice == 'n' || choice == 'N'){
            break;
        }

        // asking user for network name
        printf("\nEnter the name of the network: ");
        scanf("%s", networkName);
    }

    return 0;
}