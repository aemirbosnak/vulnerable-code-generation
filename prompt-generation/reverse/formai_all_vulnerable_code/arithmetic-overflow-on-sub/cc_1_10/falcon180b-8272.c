//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TEMP_SAMPLES 100
#define TEMP_INTERVAL 5
#define TEMP_THRESHOLD 3

int main() {
    int temp_count = 0;
    int temp_samples[MAX_TEMP_SAMPLES];
    int current_temp = 0;
    time_t start_time = time(NULL);

    printf("Starting temperature monitor\n");

    while(temp_count < MAX_TEMP_SAMPLES) {
        current_temp = rand() % 50 + 20;
        temp_samples[temp_count] = current_temp;
        temp_count++;

        if(temp_count == MAX_TEMP_SAMPLES) {
            break;
        }

        sleep(TEMP_INTERVAL);
    }

    printf("Temperature samples collected:\n");
    for(int i = 0; i < temp_count; i++) {
        printf("%d\n", temp_samples[i]);
    }

    int temp_increases = 0;
    int temp_decreases = 0;

    for(int i = 1; i < temp_count; i++) {
        if(temp_samples[i] > temp_samples[i-1]) {
            temp_increases++;
        } else if(temp_samples[i] < temp_samples[i-1]) {
            temp_decreases++;
        }
    }

    printf("Temperature increases: %d\n", temp_increases);
    printf("Temperature decreases: %d\n", temp_decreases);

    time_t end_time = time(NULL);

    printf("Temperature monitor finished after %ld seconds\n", end_time - start_time);

    return 0;
}