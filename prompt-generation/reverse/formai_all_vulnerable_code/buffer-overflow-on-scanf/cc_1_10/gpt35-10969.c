//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

void showSignalStrength(int signal_strength) {
    int i, j;
    printf("\n\n");
    for(i=MAX_SIGNAL_STRENGTH; i>=MIN_SIGNAL_STRENGTH; i-=10) {
        printf(" %3d ||", i);
        for(j=MIN_SIGNAL_STRENGTH; j<=MAX_SIGNAL_STRENGTH; j+=10) {
            if(signal_strength >= i-j)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("      ");
    for(i=MIN_SIGNAL_STRENGTH; i<=MAX_SIGNAL_STRENGTH; i+=10)
        printf(" %2d ", i);
    printf("\n\n");
}

int main() {
    int signal_strength;
    
    printf("Welcome to Wi-Fi Signal Strength Analyzer\n\n");

    while(1) {
        printf("Enter signal strength (0 to 100, -1 to quit): ");
        scanf("%d", &signal_strength);

        if(signal_strength == -1)
            break;
        
        if(signal_strength >= MIN_SIGNAL_STRENGTH && signal_strength <= MAX_SIGNAL_STRENGTH) {
            printf("\nSignal Strength: %d\n", signal_strength);
            showSignalStrength(signal_strength);
        }
        else {
            printf("\nInvalid signal strength provided!\n");
        }
    }

    printf("Thank you for using Wi-Fi Signal Strength Analyzer! Bye!!\n\n");

    return EXIT_SUCCESS;
}