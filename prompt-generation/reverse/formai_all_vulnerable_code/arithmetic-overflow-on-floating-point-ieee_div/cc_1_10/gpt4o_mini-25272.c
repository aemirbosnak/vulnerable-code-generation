//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_usage(float cpu_usage) {
    int length = (int)(cpu_usage / 2); // Each `#` represents 2% of CPU
    printf("[CPU Usage: ");
    for (int i = 0; i < 50; i++) {
        if (i < length) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%\n", cpu_usage);
}

float fetch_cpu_usage() {
    FILE *fp;
    unsigned long int idle_time, total_time;
    char buffer[1024];

    // Open the file that dost provide the CPU stats.
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }

    // Read the first line which chronicle the CPU stats.
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        perror("Failed to read CPU stats");
        fclose(fp);
        return -1;
    }
    fclose(fp);

    // Extracting elements from the buffer
    unsigned long int user_time, nice_time, system_time, irq_time, softirq_time,
                      steal_time, guest_time, guest_nice_time;

    sscanf(buffer, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
           &user_time, &nice_time, &system_time, &idle_time, 
           &irq_time, &softirq_time, &steal_time, 
           &guest_time, &guest_nice_time);

    total_time = user_time + nice_time + system_time + idle_time + 
                 irq_time + softirq_time + steal_time;

    // Calculate the CPU usage based on the total time.
    float cpu_usage = (float)(total_time - idle_time) / total_time * 100;
    return cpu_usage;
}

int main() {
    printf("Hark! Art thou prepared to behold the royal tale of CPU usage?\n");
    printf("This humble program shall display the CPU usage in a valiant manner!\n");

    while (1) {
        printf("\nSummoning the spirits of computation...\n");
        float cpu_usage = fetch_cpu_usage();
        
        if (cpu_usage < 0) {
            printf("Alas! The magic of computation has failed us.\n");
            return 1;
        }

        display_usage(cpu_usage);
        printf("Resting the timeout before the next summoning...\n");
        sleep(3); // A timeout before the next measurement, to let the CPU breathe
    }

    return 0;
}