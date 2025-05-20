//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Watson's observations
unsigned char watson_obs[100];

// Holmes' deductions
unsigned char holmes_ded[100];

// The case file
unsigned char case_file[100];

// Bitwise operations to uncover the truth

int main() {
    // Gather Watson's observations
    printf("Watson, present your observations: ");
    scanf("%s", watson_obs);

    // Holmes examines the case file
    printf("Holmes examines the case file:\n");
    for (int i = 0; case_file[i] != '\0'; i++) {
        printf("%c", case_file[i]);
    }
    printf("\n");

    // Holmes deduces the truth
    for (int i = 0; i < 100; i++) {
        holmes_ded[i] = watson_obs[i] ^ case_file[i];
    }

    // Present the deductions
    printf("Holmes presents his deductions:\n");
    for (int i = 0; holmes_ded[i] != '\0'; i++) {
        printf("%c", holmes_ded[i]);
    }
    printf("\n");

    // The truth is revealed
    printf("The truth is revealed:");
    for (int i = 0; holmes_ded[i] != '\0'; i++) {
        if (holmes_ded[i] == '0') {
            printf(" ");
        } else {
            printf("*");
        }
    }
    printf("\n");

    return 0;
}