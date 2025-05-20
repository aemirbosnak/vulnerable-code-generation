//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int signal_strength;
    printf("Enter wifi signal strength in percentage: ");
    scanf("%d", &signal_strength);

    if(signal_strength < 0 || signal_strength > 100) {
        printf("Invalid signal strength. Please enter a value between 0 and 100.");
        exit(0);
    }

    int signal_quality = 0;
    if(signal_strength >= 0 && signal_strength <= 20) {
        signal_quality = 1;
    } else if(signal_strength > 20 && signal_strength <= 40) {
        signal_quality = 2;
    } else if(signal_strength > 40 && signal_strength <= 60) {
        signal_quality = 3;
    } else if(signal_strength > 60 && signal_strength <= 80) {
        signal_quality = 4;
    } else if(signal_strength > 80 && signal_strength <= 100) {
        signal_quality = 5;
    }

    printf("The signal quality is: ");

    switch (signal_quality) {
        case 1:
            printf("Very poor");
            break;
        case 2:
            printf("Poor");
            break;
        case 3:
            printf("Average");
            break;
        case 4:
            printf("Good");
            break;
        case 5:
            printf("Excellent");
            break;
        default:
            printf("Invalid signal strength.");
            break;
    }

    return 0;
}