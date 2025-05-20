//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SAMPLES 100

int main() {
    int i, j;
    double samples[MAX_SAMPLES];
    double total_used = 0.0;
    double average_used = 0.0;
    double std_dev = 0.0;
    double variance = 0.0;
    char filename[20];
    FILE *file;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (i = 0; i < MAX_SAMPLES; i++) {
        if (fgets(filename, 20, file) == NULL) {
            break;
        }
        samples[i] = atof(filename);
        total_used += samples[i];
    }

    fclose(file);

    for (i = 0; i < MAX_SAMPLES; i++) {
        average_used += samples[i];
    }
    average_used /= MAX_SAMPLES;

    for (i = 0; i < MAX_SAMPLES; i++) {
        variance += pow(samples[i] - average_used, 2);
    }
    variance /= MAX_SAMPLES;
    std_dev = sqrt(variance);

    printf("Total RAM usage: %.2f MB\n", total_used / (1024.0 * 1024.0));
    printf("Average RAM usage: %.2f MB\n", average_used / (1024.0 * 1024.0));
    printf("Standard deviation: %.2f MB\n", std_dev / (1024.0 * 1024.0));

    return 0;
}