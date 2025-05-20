//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 10
#define LOAD_THRESHOLD 80

int main()
{
    int i;
    float load_avg = 0;
    float cpu_usage = 0;
    float load_array[NUM_SAMPLES];

    for(i=0; i<NUM_SAMPLES; i++) 
        load_array[i] = -1;

    while(1) 
    {
        // Get CPU usage
        FILE *fp = popen("mpstat | awk '$13 ~ /[0-9.]+/ { print 100 - $13 }' | tail -n 1", "r");
        if (fp == NULL) 
        {
            printf("Failed to run command\n" );
            exit(1);
        }

        fscanf(fp, "%f", &cpu_usage);
        pclose(fp);

        // Calculate load average
        load_avg = 0;
        for(i=0; i<NUM_SAMPLES; i++) 
        {
            if(load_array[i] != -1) 
            {
                load_avg += load_array[i];
            }
        }
        
        load_avg = load_avg / NUM_SAMPLES;

        printf("CPU usage: %.2f%%\n", cpu_usage);
        printf("Load average: %.2f%%\n", load_avg);

        // Check for high CPU load
        if(cpu_usage > LOAD_THRESHOLD && load_avg > LOAD_THRESHOLD) 
        {
            printf("High CPU load detected! Taking action...\n");
            
            // TODO: Add code for taking action
            
            // Reset load_array to prevent false positives
            for(i=0; i<NUM_SAMPLES; i++) 
            {
                load_array[i] = -1;
            }
        } 
        else 
        {
            // Add current load to load_array
            load_array[NUM_SAMPLES-1] = cpu_usage;
            // Shift array to left
            for(i=0; i<NUM_SAMPLES-1; i++) 
            {
                load_array[i] = load_array[i+1];
            }
        }

        usleep(500000);
    }

    return 0;
}