//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 100
#define MAX_TEMP_SAMPLE_NAME_LEN 20

typedef struct {
    char name[MAX_TEMP_SAMPLE_NAME_LEN];
    double temp;
} TempSample;

int main() {
    int numTemps;
    TempSample temps[MAX_TEMP_SAMPLES];
    char input[100];
    int i;
    double sum = 0;

    // Get number of temperatures from user
    printf("Enter number of temperatures to monitor: ");
    scanf("%d", &numTemps);

    // Get temperature names and temperatures from user
    for (i = 0; i < numTemps; i++) {
        printf("Enter temperature name: ");
        scanf("%s", temps[i].name);
        printf("Enter temperature: ");
        scanf("%lf", &temps[i].temp);
    }

    // Calculate average temperature
    for (i = 0; i < numTemps; i++) {
        sum += temps[i].temp;
    }
    printf("Average temperature: %.2lf\n", sum / numTemps);

    // Get temperature name to monitor
    printf("Enter temperature name to monitor: ");
    scanf("%s", input);

    // Monitor temperature
    while (1) {
        for (i = 0; i < numTemps; i++) {
            if (strcmp(temps[i].name, input) == 0) {
                printf("%.2lf\n", temps[i].temp);
            }
        }
        sleep(5);
    }

    return 0;
}