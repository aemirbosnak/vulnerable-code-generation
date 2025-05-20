//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/sysinfo.h>

#define ESC 27

// Function to get current CPU usage 
float get_cpu_usage() {
    static unsigned long long last_total_ticks = 0;
    static unsigned long long last_idle_ticks = 0;
    unsigned long long total_ticks, idle_ticks;

    FILE* fp = fopen("/proc/stat", "r");

    fscanf(fp, "%*s %llu %*s %llu", &total_ticks, &idle_ticks);
    fclose(fp);

    unsigned long long total_ticks_since_last_time = total_ticks - last_total_ticks;
    unsigned long long idle_ticks_since_last_time = idle_ticks - last_idle_ticks;

    float idle_percentage = (float)idle_ticks_since_last_time / (float)total_ticks_since_last_time;

    last_total_ticks = total_ticks;
    last_idle_ticks = idle_ticks;

    return 100.0 * (1.0 - idle_percentage);
}

int main() {
    struct termios oldterm, newterm;

    // Configure terminal for retro-style display
    tcgetattr(STDIN_FILENO, &oldterm);
    newterm = oldterm;
    newterm.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
    printf("%c[2J", ESC); // Clear screen

    while (1) {
        printf("%c[1;1H", ESC); // Move cursor to top-left

        printf("CPU Usage Monitor (Press 'q' to quit)\n\n");

        // Get current CPU usage and display a retro-style bar chart
        float cpu_usage = get_cpu_usage();
        printf("CPU Usage: %.2f%%\n\n", cpu_usage);
        printf("[");
        int bars_to_display = (int)(cpu_usage / 5.0);
        for (int i = 0; i < bars_to_display; i++) {
            printf("=");
        }
        printf(">\n");

        usleep(1000000); // Wait 1 second before updating display

        // Check for 'q' keypress to quit program
        char c = getchar();
        if (c == 'q') {
            break;
        }
    }

    // Reset terminal to normal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
    printf("%c[2J", ESC); // Clear screen
    printf("\nGoodbye!\n");
    return 0;
}