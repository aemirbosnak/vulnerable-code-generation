//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 1  // in seconds

volatile sig_atomic_t running = 1;

void handle_signal(int signum) {
    running = 0; // set running to 0 when signal is caught
}

float get_cpu_usage() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    unsigned long long user, nice, system, idle, total;
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    
    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    // Parse the first line of /proc/stat
    sscanf(buffer, "cpu %llu %llu %llu %llu", &user, &nice, &system, &idle);
    
    total = user + nice + system + idle;

    // Calculate the usage
    float usage = 0.0f;
    if (total != 0) {
        usage = ((float)(total - idle) / total) * 100.0f;
    }

    return usage;
}

void display_cpu_usage() {
    printf("\nCPU Usage Monitor\n");
    printf("Press Ctrl+C to stop.\n");
    printf("--------------------------------------------------\n");
    
    while (running) {
        float cpu_usage = get_cpu_usage();
        printf("\rCurrent CPU Usage: %.2f%% ", cpu_usage);
        fflush(stdout);
        sleep(SLEEP_INTERVAL);
    }

    printf("\nExiting CPU Usage Monitor...\n");
}

int main() {
    signal(SIGINT, handle_signal); // Catch Ctrl+C to exit safely

    display_cpu_usage();

    return 0;
}