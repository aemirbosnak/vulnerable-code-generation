//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void print_welcome_message() {
    printf("===========================================\n");
    printf("      CPU Usage Monitor v1.0               \n");
    printf("         by Your Name                       \n");
    printf("===========================================\n");
}

void get_cpu_usage(float *user, float *nice, float *system, float *idle) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    sscanf(buffer, "cpu %f %f %f %f", user, nice, system, idle);
}

float calculate_cpu_usage() {
    float user1, nice1, system1, idle1;
    float user2, nice2, system2, idle2;

    get_cpu_usage(&user1, &nice1, &system1, &idle1);
    sleep(1); // wait for a second
    get_cpu_usage(&user2, &nice2, &system2, &idle2);
    
    float total_idle = (idle1 + idle2) / 2;
    float total_time = (user2 + nice2 + system2 + idle2) - 
                       (user1 + nice1 + system1 + idle1);

    return 100 * (1 - (total_idle / (total_idle + total_time)));
}

void print_cpu_usage(float usage) {
    printf("Current CPU Usage: %.2f%%\n", usage);
}

int main() {
    print_welcome_message();
    
    while (1) {
        float cpu_usage = calculate_cpu_usage();
        print_cpu_usage(cpu_usage);
        printf("===========================================\n");
        usleep(1000000); // sleep for 1 second
    }

    return 0;
}