//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This program detects CPU usage over a certain threshold value
// and sends a notification when the usage level exceeds the threshold.

int main () {

    printf("Welcome to CPU Usage Monitor 1.0!\n");
    printf("Please enter the threshold value (0-100): ");

    int threshold;
    scanf("%d", &threshold);

    if (threshold < 0 || threshold > 100) {
        printf("Invalid threshold value entered. Please try again.\n");
        exit(1);
    }

    printf("CPU usage monitor is now running...\n");

    while (1) {

        FILE* fp = fopen("/proc/stat", "r");
        
        if (fp == NULL) {
            printf("Error reading /proc/stat. Please try again.\n");
            exit(1);
        }
        
        char buffer[1024];
        fgets(buffer, sizeof(buffer), fp);
        
        fclose(fp);
        
        int user, nice, system, idle, iowait, irq, softirq;
        
        sscanf(buffer, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

        int total = user + nice + system + idle + iowait + irq + softirq;
        int usage = 100 * (total - idle) / total;

        if (usage > threshold) {
            printf("CPU usage (%d%%) is above the threshold of %d%%.\n", usage, threshold);
            printf("Sending email notification to administrator...\n");
            // Email notification code goes here
        }

        sleep(60);
    }

    return 0;
}