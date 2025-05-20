//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_BOOTS 10
#define BOOT_FILE "boot_sequence.txt"
#define LINE_SIZE 256

void log_boot_sequence(const char *boot_time, const char *boot_message) {
    FILE *fp = fopen(BOOT_FILE, "a");
    if (fp == NULL) {
        perror("Error opening boot log file");
        return;
    }
    fprintf(fp, "%s - %s\n", boot_time, boot_message);
    fclose(fp);
}

void read_boot_sequence() {
    FILE *fp = fopen(BOOT_FILE, "r");
    if (fp == NULL) {
        perror("Error opening boot log file");
        return;
    }
    
    char line[LINE_SIZE];
    printf("Boot Sequence Log:\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

void optimize_boot_time(int boot_timestamps[], int n) {
    printf("Optimizing boot sequence...\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (boot_timestamps[j] > boot_timestamps[j + 1]) {
                int temp = boot_timestamps[j];
                boot_timestamps[j] = boot_timestamps[j + 1];
                boot_timestamps[j + 1] = temp;
            }
        }
    }
    
    printf("Boot sequence optimized successfully.\n");
}

void display_boot_sequence(int boot_timestamps[], int n) {
    printf("Current Boot Sequence (milliseconds):\n");
    for (int i = 0; i < n; i++) {
        printf("Boot %d: %d ms\n", i + 1, boot_timestamps[i]);
    }
}

int main() {
    int boot_timestamps[MAX_BOOTS];
    int count = 0;
    
    while (count < MAX_BOOTS) {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        int boot_time_ms = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;

        char log_message[LINE_SIZE];
        sprintf(log_message, "Boot completed in %d ms", boot_time_ms);
        
        char time_buffer[100];
        strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", localtime(&ts.tv_sec));
        
        log_boot_sequence(time_buffer, log_message);
        boot_timestamps[count++] = boot_time_ms;

        printf("Boot %d completed. Logging...\n", count);
        sleep(1); // Simulate the boot time
    }
    
    display_boot_sequence(boot_timestamps, count);
    
    optimize_boot_time(boot_timestamps, count);
    display_boot_sequence(boot_timestamps, count);

    read_boot_sequence();
    
    return 0;
}