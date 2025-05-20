//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_DEVICES 20
#define MAX_SSID_LENGTH 20
#define MIN_SIGNAL -100
#define MAX_SIGNAL 0

/*Structure for Wi-Fi Device*/
struct Device {
    char ssid[MAX_SSID_LENGTH];
    int signalStrength;
};

/*Function to generate random signal strengths*/
int randomSignalStrength() {
    return rand() % (MAX_SIGNAL - MIN_SIGNAL + 1) + MIN_SIGNAL;
}

/*Function to print device details*/
void printDeviceDetails(struct Device device) {
    printf("SSID: %s\nSignal Strength: %d dBm\n", device.ssid, device.signalStrength);
}

/*Function to calculate average signal strength*/
float calculateAverageSignalStrength(struct Device devices[], int numDevices) {
    int i, totalSignalStrength = 0;
    for(i=0; i<numDevices; i++) {
        totalSignalStrength += devices[i].signalStrength;
    }
    return (float)totalSignalStrength / numDevices;
}

/*Function to find strongest signal strength*/
int findStrongestSignal(struct Device devices[], int numDevices) {
    int i, strongestSignal = MIN_SIGNAL;
    for(i=0; i<numDevices; i++) {
        if(devices[i].signalStrength > strongestSignal) {
            strongestSignal = devices[i].signalStrength;
        }
    }
    return strongestSignal;
}

/*Function to find weakest signal strength*/
int findWeakestSignal(struct Device devices[], int numDevices) {
    int i, weakestSignal = MAX_SIGNAL;
    for(i=0; i<numDevices; i++) {
        if(devices[i].signalStrength < weakestSignal) {
            weakestSignal = devices[i].signalStrength;
        }
    }
    return weakestSignal;
}

/*Main Function*/
int main() {
    struct Device devices[MAX_DEVICES];
    int i, numDevices;
    float averageSignalStrength;
    printf("Enter the number of Wi-Fi devices in the area (max %d): ", MAX_DEVICES);
    scanf("%d", &numDevices);
    /*Input details for each device*/
    for(i=0; i<numDevices; i++) {
        printf("Enter details for Wi-Fi device %d:\n", i+1);
        printf("SSID: ");
        scanf("%s", devices[i].ssid);
        devices[i].signalStrength = randomSignalStrength();
    }
    /*Print details for each device*/
    printf("\nDetails for all Wi-Fi devices:\n");
    for(i=0; i<numDevices; i++) {
        printf("\nDetails for Wi-Fi device %d:\n", i+1);
        printDeviceDetails(devices[i]);
    }
    /*Calculate and print average signal strength*/
    averageSignalStrength = calculateAverageSignalStrength(devices, numDevices);
    printf("\nAverage Signal Strength: %.2f dBm\n", averageSignalStrength);
    /*Find and print strongest and weakest signal strength*/
    printf("Strongest Signal Strength: %d dBm\n", findStrongestSignal(devices, numDevices));
    printf("Weakest Signal Strength: %d dBm\n", findWeakestSignal(devices, numDevices));
    return 0;
}