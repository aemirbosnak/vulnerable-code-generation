//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int signalStrength[10];
    int i;
    printf("Enter the Wi-Fi signal strength from 0 to 9\n");
    
    for (i = 0; i < 10; i++) {
        printf("Signal Strength %d: ", i+1);
        scanf("%d", &signalStrength[i]);
    }
    
    int min = signalStrength[0], max = signalStrength[0], sum = 0;
    double avg;
    
    for (i = 0; i < 10; i++) {
        if (signalStrength[i] < min) {
            min = signalStrength[i];
        }
        if (signalStrength[i] > max) {
            max = signalStrength[i];
        }
        sum += signalStrength[i];
    }
    
    avg = (double)sum / 10;
    
    printf("\nThe minimum Wi-Fi signal strength is %d\n", min);
    printf("The maximum Wi-Fi signal strength is %d\n", max);
    printf("The average Wi-Fi signal strength is %.2lf\n", avg);
    
    int range[4] = {0, 0, 0, 0};
    int j;
    
    for (i = 0; i < 10; i++) {
        if (signalStrength[i] >= 0 && signalStrength[i] < 3) {
            range[0]++;
        }
        else if (signalStrength[i] >= 3 && signalStrength[i] < 6) {
            range[1]++;
        }
        else if (signalStrength[i] >= 6 && signalStrength[i] < 8) {
            range[2]++;
        }
        else {
            range[3]++;
        }
    }
    
    printf("\nDistribution of Wi-Fi signal strengths:\n");
    printf("[0-2]: ");
    for (j = 0; j < range[0]; j++) {
        printf("*");
    }
    printf("\n[3-5]: ");
    for (j = 0; j < range[1]; j++) {
        printf("*");
    }
    printf("\n[6-7]: ");
    for (j = 0; j < range[2]; j++) {
        printf("*");
    }
    printf("\n[8-9]: ");
    for (j = 0; j < range[3]; j++) {
        printf("*");
    }
    printf("\n");

    return 0;
}