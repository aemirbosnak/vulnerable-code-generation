//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void display_cpu_usage(double usage) {
    printf("🧚✨ Magical CPU Fairy says: Your CPU is currently at %.2f%% usage! ✨🧚\n", usage);
    if (usage < 20.0) {
        printf("🌟 Your CPU is feeling light and breezy! 🌬️\n");
    } else if (usage < 50.0) {
        printf("🧚 Your CPU is working comfortably! Keep it up! 🌈\n");
    } else if (usage < 80.0) {
        printf("⚡ Your CPU is a bit busy, but don’t worry! 💪\n");
    } else {
        printf("🚨 Oh no! Your CPU is under a lot of pressure! Time to optimize! 🥵\n");
    }
    printf("------------------------------------------------\n");
}

double calculate_cpu_usage() {
    static long long last_total_cpu_time = 0;
    static long long last_idle_cpu_time = 0;

    FILE *fp;
    char buffer[1024];
    long long idle_time, total_time;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to read CPU stats");
        return -1; // Error handling
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    sscanf(buffer, "cpu %*s %*s %*s %lld %lld", &idle_time, &total_time);
    total_time = idle_time + last_total_cpu_time;

    double usage = 100.0 * (1 - (idle_time - last_idle_cpu_time) / (double)(total_time - last_total_cpu_time));

    last_total_cpu_time = total_time;
    last_idle_cpu_time = idle_time;

    return usage;
}

int main() {
    printf("🧚✨ Welcome to the Magical CPU Usage Monitor! ✨🧚\n");
    printf("🌈 The CPU Fairy will keep an eye on your processing powers. 🌈\n");

    while (1) {
        double usage = calculate_cpu_usage();
        
        if (usage < 0) {
            printf("❌ Encountered an error while monitoring CPU usage. Exiting! ❌\n");
            break;
        }

        display_cpu_usage(usage);
        sleep(2); // Check every 2 seconds
    }

    printf("🕊️ Thank you for using the Magical CPU Fairy! Bye! 🕊️\n");
    return 0;
}