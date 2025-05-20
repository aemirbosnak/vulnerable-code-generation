//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

// function to calculate Wi-Fi Signal Quality
int signalQuality(int signalStrength){
    int quality;

    if (signalStrength >= -50){
        quality = 100;
    }
    else if (signalStrength >= -60){
        quality = 75;
    }
    else if (signalStrength >= -70){
        quality = 50;
    }
    else if (signalStrength >= -80){
        quality = 25;
    }
    else {
        quality = 0;
    }

    return quality;
}

int main(){
    printf("-----------------------------------------------------------\n");
    printf("          Welcome to Wi-Fi Signal Strength Analyzer         \n");
    printf("-----------------------------------------------------------\n");

    int signalStrength;
    char option;

    do{
        printf("Enter the signal strength in dbm (between -100 to 0): ");
        scanf("%d", &signalStrength);

        if(signalStrength < -100 || signalStrength > 0){
            printf("Invalid signal strength! Please try again.\n");
        }
        else{
            int signalQualityPercentage = signalQuality(signalStrength);
            printf("\nSignal Quality: %d %%\n\n", signalQualityPercentage);
        }

        printf("Do you want to check another signal strength? (y/n) ");
        scanf(" %c", &option);
    }while(option == 'y');

    printf("\n-----------------------------------------------------------\n");
    printf("            Thanks for using Signal Strength Analyzer        \n");
    printf("-----------------------------------------------------------\n");

    return 0;
}