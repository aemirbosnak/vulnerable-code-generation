//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100

int main()
{
    int signal_strength;
    double d;
    printf("Enter the signal strength (0 - %d): ", MAX_SIGNAL_STRENGTH);
    scanf("%d", &signal_strength);
    printf("Enter the distance from the access point (m): ");
    scanf("%lf", &d);

    if (signal_strength > MAX_SIGNAL_STRENGTH || signal_strength < 0)
    {
        printf("Invalid signal strength!\n");
        exit(1);
    }

    if (d < 0)
    {
        printf("Distance cannot be negative!\n");
        exit(1);
    }

    double signal_loss = 10 * log10(MAX_SIGNAL_STRENGTH / (double)signal_strength);
    double attenuation = signal_loss / (10 * log10(d));

    if (attenuation > 1)
    {
        printf("Signal is too weak!\n");
        exit(1);
    }

    printf("Signal strength: %d\n", signal_strength);
    printf("Distance: %.2f m\n", d);
    printf("Signal attenuation: %.2f dB\n", signal_loss);
    printf("Attenuation factor: %.2f\n", attenuation);

    if (attenuation >= 0.6)
    {
        printf("Sufficient signal strength for internet usage.\n");
    }
    else
    {
        printf("Signal strength is not sufficient for internet usage!\n");
    }

    return 0;
}