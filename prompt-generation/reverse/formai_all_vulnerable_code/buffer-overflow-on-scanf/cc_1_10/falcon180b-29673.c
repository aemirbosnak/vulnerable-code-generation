//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_TEMP_SAMPLES 100

typedef struct {
    int temp;
    time_t time;
} TempSample;

void get_temp_sample(TempSample* sample) {
    int temp = 0;
    
    printf("Enter current temperature: ");
    scanf("%d", &temp);
    
    sample->temp = temp;
    sample->time = time(NULL);
}

void print_temp_samples(TempSample* samples, int num_samples) {
    printf("Temperature samples:\n");
    for (int i = 0; i < num_samples; i++) {
        printf("%d degrees at %s\n", samples[i].temp, ctime(&samples[i].time));
    }
}

int main() {
    TempSample temp_samples[MAX_TEMP_SAMPLES];
    int num_samples = 0;
    
    while (TRUE) {
        printf("Enter 1 to get a temperature sample, 2 to print samples, or 0 to quit: ");
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (num_samples == MAX_TEMP_SAMPLES) {
                    printf("Maximum number of samples reached.\n");
                } else {
                    get_temp_sample(&temp_samples[num_samples]);
                    num_samples++;
                }
                break;
            case 2:
                print_temp_samples(temp_samples, num_samples);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}