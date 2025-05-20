//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INVASIONS 1000
#define MAX_YEARS 1000
#define MAX_MONTHS 12
#define MAX_DAYS 31
#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60

int main() {
    int invasions = 0;
    int years = 0;
    int months = 0;
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    double probability = 0.0;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of years to simulate:\n");
    scanf("%d", &years);

    for(int i = 0; i < years; i++) {
        for(int j = 0; j < MAX_INVASIONS; j++) {
            if(rand() % 100 == 1) {
                invasions++;
            }
        }
        for(int k = 0; k < MAX_MONTHS; k++) {
            for(int l = 0; l < MAX_DAYS; l++) {
                for(int m = 0; m < MAX_HOURS; m++) {
                    for(int n = 0; n < MAX_MINUTES; n++) {
                        for(int o = 0; o < MAX_SECONDS; o++) {
                            if(rand() % 100 == 1) {
                                printf("Invasion detected!\n");
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Number of invasions detected: %d\n", invasions);
    printf("Probability of an invasion: %.2f%%\n", (double)invasions / (years * MAX_INVASIONS) * 100.0);

    return 0;
}