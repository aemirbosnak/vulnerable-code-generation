//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

#define MAX_LINE 256

// Oh, the whimsical journey begins here!
void print_usage();
int read_cpu_usage();
void led_color(const char *color);
void clear_screen();

int main() {
    // Welcome to the CPU monitor extravaganza!
    clear_screen();
    printf("Welcome to the CPU Usage Monitor! 🌻\n");
    printf("By observing the system, we can sense its load!\n");

    while (1) {
        led_color("yellow");
        printf("Checking CPU usage...\n");
        int usage = read_cpu_usage();
        
        if (usage < 0) {
            led_color("red");
            printf("Oops! Something went wrong while reading CPU stats!\n");
        } else {
            led_color("green");
            printf("Current CPU Usage: %d%% \n", usage);
        }

        usleep(1000000);  // Sleep for a second (1000 ms)
        clear_screen();
    }
    return 0;
}

void led_color(const char *color) {
    if (strcmp(color, "red") == 0) {
        printf("\033[31m");
    } else if (strcmp(color, "green") == 0) {
        printf("\033[32m");
    } else if (strcmp(color, "yellow") == 0) {
        printf("\033[33m");
    } else {
        printf("\033[0m"); // Default color
    }
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

int read_cpu_usage() {
    FILE *fp;
    long double idle, total, usage;
    char buffer[MAX_LINE];

    // Read the CPU stats from /proc/stat
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1; // Error in opening the file
    }

    fgets(buffer, MAX_LINE, fp); // read the first line
    fclose(fp);

    // We expect the first line to look like:
    // cpu  12345 2345 34567 456789 0 0 0 0
    // Get the data
    sscanf(buffer, "cpu %*s %*s %*s %Lf %*s %*s %*s %*s", &idle);
    sscanf(buffer, "cpu %Lf %*s", &total);

    // Calculate usage
    usage = (1 - (idle / total)) * 100;

    return (int)usage; // Return the CPU usage as an integer percentage
}