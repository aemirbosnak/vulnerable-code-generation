//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//define constants
#define MAX_WIFI 100

//function prototypes
void analyze_signal_strength(int wifi[],int number_of_wifis);

int main()
{
    int wifi_strength[MAX_WIFI];
    int number_of_wifis;

    printf("Enter the number of Wi-Fi signals to analyze (maximum %d): ",MAX_WIFI);
    scanf("%d",&number_of_wifis);

    printf("Enter the Wi-Fi signal strengths (in decibels):\n");
    for(int i = 0; i < number_of_wifis; i++)
    {
        scanf("%d",&wifi_strength[i]);
    }

    analyze_signal_strength(wifi_strength,number_of_wifis);

    return 0;
}

void analyze_signal_strength(int wifi[],int number_of_wifis)
{
    int strongest_wifi = wifi[0];
    int strongest_index = 0;
    int average_strength = 0;
    int count = 0;

    for(int i = 0; i < number_of_wifis; i++)
    {
        //determine the strongest Wi-Fi signal
        if(wifi[i] > strongest_wifi)
        {
            strongest_wifi = wifi[i];
            strongest_index = i;
        }
        //calculate the average signal strength
        average_strength += wifi[i];

        //count the number of signals above -70dB
        if(wifi[i] > -70)
        {
            count++;
        }
    }

    //calculate the average signal strength
    average_strength /= number_of_wifis;

    printf("\nAnalysis Results:\n");
    printf("Strongest Wi-Fi signal: Wi-Fi %d at %d dB\n",strongest_index + 1,strongest_wifi);
    printf("Average signal strength: %d dB\n",average_strength);
    printf("%d Wi-Fi signals with strength above -70 dB\n",count);
}