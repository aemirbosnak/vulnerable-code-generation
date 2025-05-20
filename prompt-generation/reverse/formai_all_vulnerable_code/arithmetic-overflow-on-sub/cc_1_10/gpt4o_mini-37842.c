//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>

#define MAX_LINE_LENGTH 256

volatile sig_atomic_t stop_program = 0;

void handle_signal(int signal) {
    stop_program = 1;
}

void display_memory_usage(long total_memory, long used_memory, long free_memory) {
    printf("\nMemory Usage Information:\n");
    printf("============================\n");
    printf("Total Memory: %ld MB\n", total_memory / (1024 * 1024));
    printf("Used Memory:  %ld MB\n", used_memory / (1024 * 1024));
    printf("Free Memory:  %ld MB\n", free_memory / (1024 * 1024));
    printf("============================\n\n");
}

void monitor_memory_usage() {
    struct sysinfo mem_info;
    while (!stop_program) {
        if (sysinfo(&mem_info) == 0) {
            long total_memory = mem_info.totalram;
            long free_memory  = mem_info.freeram;
            long used_memory  = total_memory - free_memory;
            display_memory_usage(total_memory, used_memory, free_memory);
        } else {
            perror("sysinfo failed");
            exit(EXIT_FAILURE);
        }
        sleep(2); // Sleep for 2 seconds before next check
    }
}

void setup_signal_handling() {
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = handle_signal;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    if (sigaction(SIGINT, &sigIntHandler, NULL) == -1) {
        perror("Error setting up signal handler");
        exit(EXIT_FAILURE);
    }
}

int main() {
    setup_signal_handling();
    printf("Starting RAM Usage Monitor...\n");
    printf("Press Ctrl+C to stop monitoring.\n\n");

    monitor_memory_usage();

    printf("Exiting RAM Usage Monitor. Goodbye!\n");
    return 0;
}