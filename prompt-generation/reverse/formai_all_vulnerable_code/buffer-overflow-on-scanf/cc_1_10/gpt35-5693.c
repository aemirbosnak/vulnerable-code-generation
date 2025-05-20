//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_SAMPLES 10 // Number of samples to take

int main()
{
    int i;
    double signalStrength = 0;
    
    // Prompt user to enter SSID to analyze
    char ssid[20];
    printf("Enter the SSID to analyze: ");
    scanf("%s", ssid);
    
    // Start taking samples
    for(i = 0; i < NUM_SAMPLES; i++)
    {
        // Assume signal strength is measured in dBm
        double sample = (double)rand() / RAND_MAX * 100; // Generate a random number between 0 and 100
        printf("Sample %d: %.2f dBm\n", i + 1, sample);
        signalStrength += sample;
    }
    
    // Calculate average signal strength
    signalStrength /= NUM_SAMPLES;
    
    // Convert signal strength from dBm to percentage
    double signalPercentage = (signalStrength + 100) / 100 * 50;
    
    // Generate signal strength graph
    printf("\nSignal Strength Graph:\n");
    printf("         100%%\n");
    printf("           |\n");
    printf("           |\n");
    printf("           |\n");
    printf("           |\n");
    printf("%7.2f%%   |   %7.2f%%\n", signalPercentage, signalPercentage);
    printf("           |\n");
    printf("           |\n");
    printf("           |\n");
    printf("           |\n");
    printf("          0%%\n");
    
    // Display final output
    printf("\nAverage signal strength for SSID '%s': %.2f dBm (%.2f%%)\n", ssid, signalStrength, signalPercentage);
    
    return 0;
}