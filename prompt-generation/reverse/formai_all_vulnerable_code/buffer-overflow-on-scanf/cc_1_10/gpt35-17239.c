//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

//Function to get the signal strength
int getSignalStrength(){
   return (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
}

//Function to get the signal quality
void getSignalQuality(double signalStrength, char* quality){
    if (signalStrength >= 80){
        strcpy(quality, "Excellent");
    }
    else if (signalStrength >= 60 && signalStrength < 80){
        strcpy(quality, "Good");
    }
    else if (signalStrength >= 40 && signalStrength < 60){
        strcpy(quality, "Fair");
    }
    else if (signalStrength >= 20 && signalStrength < 40){
        strcpy(quality, "Weak");
    }
    else{
        strcpy(quality, "Very Weak");
    }
}

//Function to print the signal strength and quality
void printSignalDetails(double signalStrength, char* quality){
    printf("Signal Strength: %f dBm\n", signalStrength);
    printf("Signal Quality: %s\n\n", quality);
}

//Main function to analyze the Wi-Fi Signal Strength
int main(){
    int numSamples, i;
    double totalSignalStrength = 0.0, avgSignalStrength;
    char signalQuality[20];

    printf("Enter the number of samples: ");
    scanf("%d", &numSamples);

    //Get the signal strength for each sample
    for (i = 1; i <= numSamples; i++){
        double signalStrength = getSignalStrength();
        totalSignalStrength += signalStrength;
        getSignalQuality(signalStrength, signalQuality);

        printf("Sample %d:\n", i);
        printSignalDetails(signalStrength, signalQuality);
    }

    //Calculate the average signal strength
    avgSignalStrength = totalSignalStrength / numSamples;

    printf("Average Signal Strength: %f dBm\n", avgSignalStrength);
    getSignalQuality(avgSignalStrength, signalQuality);
    printf("Average Signal Quality: %s\n", signalQuality);

    return 0;
}