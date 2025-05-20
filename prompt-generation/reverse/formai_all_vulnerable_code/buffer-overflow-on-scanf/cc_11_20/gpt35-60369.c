//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define NUM_OF_CHANNELS 14 //total num of potential channels
#define MAX_SIGNAL_STRENGTH 100 //max signal strength
#define MIN_SIGNAL_STRENGTH 0 //min signal strength

int signalStrength[NUM_OF_CHANNELS]; //array to hold signal strength for each channel

int main() {
    srand(time(NULL)); //initialize the random seed using current time
    
    //initialize the signalStrength array with random signal strength between MIN_SIGNAL_STRENGTH and MAX_SIGNAL_STRENGTH
    for(int i = 0; i < NUM_OF_CHANNELS; i++) {
        signalStrength[i] = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
    }
    
    //print out the initial signal strength for each channel
    printf("Initial signal strength for each channel:\n");
    for(int i = 0; i < NUM_OF_CHANNELS; i++) {
        printf("Channel %d: %d\n", i+1, signalStrength[i]);
    }
    
    //wait for user to input a channel number for detailed analysis
    printf("Please input a channel number for detailed analysis (1-%d): ", NUM_OF_CHANNELS);
    int channel;
    scanf("%d", &channel);
    
    //check if the input channel number is valid
    if(channel < 1 || channel > NUM_OF_CHANNELS) {
        printf("Invalid channel number!\n");
        return 0;
    }
    
    //print out the signal strength for the selected channel
    printf("Signal strength for channel %d: %d\n", channel, signalStrength[channel-1]);
    
    //analyze the selected channel to determine its quality level
    int signal = signalStrength[channel-1];
    int qualityLevel = 0;
    if(signal >= 80) { //excellent quality
        qualityLevel = 4;
    } else if(signal >= 60) { //good quality
        qualityLevel = 3;
    } else if(signal >= 40) { //fair quality
        qualityLevel = 2;
    } else if(signal >= 20) { //poor quality
        qualityLevel = 1;
    } else { //very poor quality
        qualityLevel = 0;
    }
    
    //print out the quality level of the selected channel
    printf("Quality level for channel %d: %d\n", channel, qualityLevel);
    
    //find the channel with the strongest signal strength
    int maxSignal = MIN_SIGNAL_STRENGTH;
    int maxChannel = 0;
    for(int i = 0; i < NUM_OF_CHANNELS; i++) {
        if(signalStrength[i] > maxSignal) {
            maxSignal = signalStrength[i];
            maxChannel = i+1;
        }
    }
    
    //print out the channel with the strongest signal strength
    printf("Channel with the strongest signal strength: %d\n", maxChannel);
    
    return 0;
}