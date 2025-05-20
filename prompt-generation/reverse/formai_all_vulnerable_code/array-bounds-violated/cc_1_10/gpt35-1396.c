//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Claude Shannon
/*  Wi-Fi Signal Strength Analyzer Program
    Written by: [Your Name]
    Date: [Today's Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DEVICES 100
#define MAX_SIGNAL 200

// Structure for Wi-Fi Devices
struct WifiDevice {
    char name[20];
    int signalStrength;
};

// Function to calculate Shannon's Entropy
double getEntropy(int frequencies[MAX_SIGNAL], int totalPackets) {
    double probability[MAX_SIGNAL];
    double entropy = 0.0;
    
    for(int i=0;i<MAX_SIGNAL;i++) {
        probability[i] = (double)frequencies[i]/totalPackets;
        if(probability[i] > 0.0) {
            entropy -= probability[i] * log2(probability[i]);
        }
    }
    
    return entropy;
}

// Function to display signal strengths in ascending order
void displaySignalReport(struct WifiDevice devices[MAX_DEVICES], int totalDevices) {
    int signalStrength[MAX_DEVICES];
    
    for(int i=0;i<totalDevices;i++) {
        signalStrength[i] = devices[i].signalStrength;
    }
    
    // Sort signal strength array in ascending order
    for(int i=0;i<totalDevices-1;i++) {
        for(int j=i+1;j<totalDevices;j++) {
            if(signalStrength[i] > signalStrength[j]) {
                int temp = signalStrength[i];
                signalStrength[i] = signalStrength[j];
                signalStrength[j] = temp;
            }
        }
    }
    
    printf("Wi-Fi Devices Listed by Signal Strength\n");
    printf("---------------------------------------\n");
    for(int i=0;i<totalDevices;i++) {
        for(int j=0;j<totalDevices;j++) {
            if(devices[j].signalStrength == signalStrength[i]) {
                printf("%-10s\t%d dBm\n", devices[j].name, devices[j].signalStrength);
            }
        }
    }
}

int main() {
    int totalDevices, totalPackets = 0;
    int signalFrequencies[MAX_SIGNAL] = {0};
    struct WifiDevice devices[MAX_DEVICES];
    
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("------------------------------\n");
    
    printf("Enter the number of devices: ");
    scanf("%d", &totalDevices);
    
    // Input device names and signal strengths
    for(int i=0;i<totalDevices;i++) {
        printf("\nEnter device name and signal strength (in dBm) separated by space: ");
        scanf("%s %d", devices[i].name, &devices[i].signalStrength);
        
        if(devices[i].signalStrength < 0) {
            devices[i].signalStrength = abs(devices[i].signalStrength);
        }
        
        if(devices[i].signalStrength > 199) {
            devices[i].signalStrength = 199;
        }
        
        signalFrequencies[devices[i].signalStrength]++;
        totalPackets++;
    }
    
    double entropy = getEntropy(signalFrequencies, totalPackets);
    
    printf("\nWi-Fi Signal Strength Distribution\n");
    printf("-----------------------------------\n");
    printf("Signal Strength (dBm)\tFrequency\n");
    for(int i=0;i<MAX_SIGNAL;i++) {
        if(signalFrequencies[i] > 0) {
            printf("%-10d\t\t%d\n", i, signalFrequencies[i]);
        }
    }
    printf("\nShannon's Entropy: %.2lf\n", entropy);
    
    displaySignalReport(devices, totalDevices);
    
    return 0;
}