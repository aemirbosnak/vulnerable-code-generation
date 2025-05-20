//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

#define SAMPLE_RATE 1.0 // seconds between samples

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

double get_cpu_usage() {
    FILE *file;
    unsigned long long int user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    
    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Failed to open /proc/stat");
        return -1;
    }
    
    fscanf(file, "cpu  %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    fclose(file);
    
    unsigned long long int total = user + nice + system + idle + iowait + irq + softirq + steal;
    unsigned long long int active = total - idle;

    return (double)active / total * 100.0; // CPU usage percentage
}

void draw_cpu_usage(double usage) {
    int bars = (int)(usage / 2); // Scaling the usage to fit in 50 character width
    printf("CPU Usage: [");
    for (int i = 0; i < 50; i++) {
        if (i < bars) {
            printf("█"); // Drawing filled bar
        } else {
            printf(" "); // Drawing empty space
        }
    }
    printf("] %.2f%%\n", usage);
}

void display_welcome_message() {
    clear_screen();
    printf("****************************\n");
    printf("*   CPU Usage Monitor V1.0   *\n");
    printf("*   A Glimpse into the Core  *\n");
    printf("****************************\n\n");
    printf("Press Ctrl+C to exit.\n\n");
}

int main() {
    display_welcome_message();

    while (1) {
        double usage = get_cpu_usage();
        if (usage >= 0) {
            draw_cpu_usage(usage);
        }

        sleep(SAMPLE_RATE); // wait for sample rate duration
    }

    return 0;
}