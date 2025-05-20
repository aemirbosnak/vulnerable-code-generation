//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: rigorous
/* Wi-Fi Signal Strength Analyzer */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGNAL_STRENGTH 100 // Maximum signal strength

int main()
{
    int signal_strength = 0; // Signal strength input by the user
    int strength_percent = 0; // Strength percentage

    // Get signal strength input from the user
    printf("Enter the signal strength (between 0 and %d): ", MAX_SIGNAL_STRENGTH);
    scanf("%d", &signal_strength);

    // Validate the input
    if(signal_strength < 0 || signal_strength > MAX_SIGNAL_STRENGTH)
    {
        printf("Invalid input! Signal strength should be between 0 and %d.\n", MAX_SIGNAL_STRENGTH);
        return EXIT_FAILURE;
    }

    // Calculate and display the strength percentage
    strength_percent = (signal_strength * 100) / MAX_SIGNAL_STRENGTH;
    printf("Signal strength: %d out of %d (or %d%%)\n", signal_strength, MAX_SIGNAL_STRENGTH, strength_percent);

    // Determine the signal quality based on the strength percentage
    if(strength_percent <= 10)
    {
        printf("Signal quality: Poor\n");
    }
    else if(strength_percent > 10 && strength_percent <= 30)
    {
        printf("Signal quality: Fair\n");
    }
    else if(strength_percent > 30 && strength_percent <= 60)
    {
        printf("Signal quality: Good\n");
    }
    else if(strength_percent > 60 && strength_percent <= 90)
    {
        printf("Signal quality: Very Good\n");
    }
    else
    {
        printf("Signal quality: Excellent\n");
    }

    return EXIT_SUCCESS;
}