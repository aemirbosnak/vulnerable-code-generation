//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// Function Declarations
void mystic_grid(int width, int height);
float calculate_cpu_usage(long long prev_idle, long long prev_total, long long idle, long long total);
void display_cpu_info(void);
void clear_console(void);
void wait_for_a_moment(int seconds);

// Main Function
int main(void) {
    while (1) {
        clear_console();
        display_cpu_info();
        wait_for_a_moment(2);
    }
    return 0;
}

// Function to clear console output
void clear_console(void) {
    printf("\033[H\033[J"); // ANSI escape codes for clearing the screen
}

// Function to wait for a moment
void wait_for_a_moment(int seconds) {
    sleep(seconds);
}

// Function to display CPU information
void display_cpu_info(void) {
    long long idle, total, prev_idle, prev_total;
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    // Reading CPU stats
    char buffer[256];
    fscanf(fp, "%s %lld %lld %lld %lld %lld %lld %lld %lld", buffer,
           &total, &prev_idle, &total, &total, &total, &total, &total, &total);
    fclose(fp);
    
    // CPU usage calculation
    float cpu_usage = calculate_cpu_usage(prev_idle, prev_total, idle, total);
    
    // Display the CPU Usage
    printf("~~~ CPU Usage Monitor ~~~\n");
    printf("Current CPU Usage: %.2f%%\n", cpu_usage);
    mystic_grid(20, 10); // A decorative grid display
}

// Function to calculate the CPU usage percentage
float calculate_cpu_usage(long long prev_idle, long long prev_total, long long idle, long long total) {
    long long total_diff = total - prev_total;
    long long idle_diff = idle - prev_idle;
    
    return (1.0 - (idle_diff / (float)total_diff)) * 100.0; // CPU usage formula
}

// Function to create a mystical grid effect
void mystic_grid(int width, int height) {
    printf("\n");
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // Print a mix of symbols to create a mystical pattern
            char c = (i + j) % 2 == 0 ? '*' : '.';
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}