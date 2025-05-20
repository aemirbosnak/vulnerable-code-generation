//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_cpu_usage(float *usage) {
    static long last_total_user, last_total_user_nice, last_total_sys, last_total_idle;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    unsigned long total_user, total_user_nice, total_sys, total_idle;
    fscanf(fp, "cpu %lu %lu %lu %lu\n", &total_user, &total_user_nice, &total_sys, &total_idle);
    fclose(fp);

    long total = (total_user + total_user_nice + total_sys + total_idle);
    long total_diff = (total - (last_total_user + last_total_user_nice + last_total_sys + last_total_idle));
    long idle_diff = (total_idle - last_total_idle);

    *usage = 100.0 * (1 - (float)(idle_diff) / (float)(total_diff));

    last_total_user = total_user;
    last_total_user_nice = total_user_nice;
    last_total_sys = total_sys;
    last_total_idle = total_idle;
}

void display_usage(float usage) {
    printf("\rCPU Usage: %.2f%%   ", usage);
    fflush(stdout);
}

void display_loading_animation() {
    const char *loading = "⏳";
    printf("%s ", loading);
    fflush(stdout);
}

int main() {
    printf("Welcome to the CPU Usage Monitor.\n");
    printf("This program gently tracks your CPU usage over time.\n");
    printf("You can quit by pressing Ctrl+C at any time.\n\n");

    while (1) {
        float cpu_usage = 0.0;
        get_cpu_usage(&cpu_usage);
        display_usage(cpu_usage);
        display_loading_animation();

        // Sleep for 1 second, a moment of reflection.
        sleep(1);
    }

    return 0;
}