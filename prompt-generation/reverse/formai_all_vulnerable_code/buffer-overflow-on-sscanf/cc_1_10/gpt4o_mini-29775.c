//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <pthread.h>
#include <ncurses.h>

#define SLEEP_INTERVAL 1

typedef struct {
    double user;
    double system;
    double idle;
} CpuUsage;

CpuUsage cpu_usage;

void signal_handler(int signal) {
    if (signal == SIGINT) {
        endwin(); // End ncurses mode
        exit(0);
    }
}

void get_cpu_usage(CpuUsage *usage) {
    FILE *fp;
    char buffer[256];

    // Read the /proc/stat file
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line which contains CPU usage stats
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        long user_time, nice_time, system_time, idle_time;
        sscanf(buffer, "cpu %ld %ld %ld %ld", &user_time, &nice_time, &system_time, &idle_time);
        
        long total_time = user_time + nice_time + system_time + idle_time;

        usage->user = (double)user_time / total_time * 100.0;
        usage->system = (double)system_time / total_time * 100.0;
        usage->idle = (double)idle_time / total_time * 100.0;
    } else {
        fclose(fp);
        perror("Failed to read CPU stats");
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

void* update_cpu_usage(void *arg) {
    while (1) {
        get_cpu_usage(&cpu_usage);
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

void display_cpu_usage() {
    initscr();            // Start ncurses mode
    cbreak();             // Disable line buffering
    noecho();             // Don't echo input
    signal(SIGINT, signal_handler); // Handle Ctrl+C

    while (1) {
        clear(); // Clear the screen
        printw("CPU Usage Monitor\n");
        printw("===================\n");
        printw("User: %.2f%%\n", cpu_usage.user);
        printw("System: %.2f%%\n", cpu_usage.system);
        printw("Idle: %.2f%%\n", cpu_usage.idle);
        refresh(); // Refresh screen to show updates

        usleep(500000); // Update output every half second
    }

    endwin(); // End ncurses mode
}

int main() {
    pthread_t cpu_thread;

    // Create a thread to update CPU usage
    if (pthread_create(&cpu_thread, NULL, update_cpu_usage, NULL) != 0) {
        perror("Failed to create CPU usage thread");
        exit(EXIT_FAILURE);
    }

    // Display CPU usage in the main thread
    display_cpu_usage();

    pthread_join(cpu_thread, NULL); // Wait for the CPU thread to terminate

    return 0;
}