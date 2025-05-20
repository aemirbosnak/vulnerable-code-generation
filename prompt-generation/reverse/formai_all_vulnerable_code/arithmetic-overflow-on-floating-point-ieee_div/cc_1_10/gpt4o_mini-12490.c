//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

void display_ram_usage() {
    struct sysinfo info;
    
    // Fetch system information
    if (sysinfo(&info) != 0) {
        perror("sysinfo error");
        exit(EXIT_FAILURE);
    }

    // Calculate total and free RAM
    long total_ram = info.totalram;
    long free_ram = info.freeram;
    long used_ram = total_ram - free_ram;

    // Convert values to MB
    long total_ram_mb = total_ram / (1024 * 1024);
    long free_ram_mb = free_ram / (1024 * 1024);
    long used_ram_mb = used_ram / (1024 * 1024);

    // Print RAM usage in a cheerful style
    printf("\n🌟 RAM Usage Monitor 🌟\n");
    printf("===========================\n");
    printf("Total RAM:      \033[1;34m%ld MB\033[0m\n", total_ram_mb);
    printf("Used RAM:       \033[1;33m%ld MB\033[0m\n", used_ram_mb);
    printf("Free RAM:       \033[1;32m%ld MB\033[0m\n", free_ram_mb);
    printf("===========================\n");

    float used_percentage = ((float)used_ram / total_ram) * 100;
    printf("Usage Percentage: \033[1;35m%.2f%%\033[0m\n", used_percentage);
    
    if (used_percentage < 50) {
        printf("🎉🎈 You're doing great! Keep up the awesome work! 🎈🎉\n");
    } else if (used_percentage < 80) {
        printf("😊 You're using a fair amount of RAM. Manage it well! 😊\n");
    } else {
        printf("⚠️ Oh no! RAM is running low! Consider closing some applications! ⚠️\n");
    }
}

int main() {
    printf("\nHello there! Welcome to the RAM Usage Monitor! 🌈\n");

    while (1) {
        display_ram_usage();
        printf("\nFetching RAM data again in 5 seconds...\n");
        sleep(5);  // Wait for 5 seconds before the next measurement
    }

    return 0;
}