//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define VERSION "1.0"
#define REFRESH_INTERVAL 5
#define BAR_WIDTH 40

void print_usage();
void show_memory_usage();
void print_bar(float percentage);
void print_header();

int main() {
    print_header();
    // Initial delay
    sleep(2);
    
    while (1) {
        show_memory_usage();
        sleep(REFRESH_INTERVAL);
    }

    return 0;
}

void print_header() {
    printf("==========================================\n");
    printf("             RAM Usage Monitor           \n");
    printf("            Version: %s                \n", VERSION);
    printf("==========================================\n");
    printf("Press Ctrl+C to exit\n");
}

void show_memory_usage() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo error");
        exit(EXIT_FAILURE);
    }

    long total_memory = info.totalram;
    long free_memory = info.freeram;
    long used_memory = total_memory - free_memory;

    // Convert to megabytes
    long total_memory_mb = total_memory / (1024 * 1024);
    long used_memory_mb = used_memory / (1024 * 1024);
    long free_memory_mb = free_memory / (1024 * 1024);

    float percentage_used = ((float) used_memory / total_memory) * 100;

    printf("\033[H\033[J"); // Clear the screen for a retro feel
    printf("Total Memory: %ld MB\n", total_memory_mb);
    printf("Used Memory: %ld MB\n", used_memory_mb);
    printf("Free Memory: %ld MB\n", free_memory_mb);
    printf("Memory Usage: %.2f%%\n", percentage_used);
    
    print_bar(percentage_used);
}

void print_bar(float percentage) {
    int bar_fill = (int) ((percentage / 100) * BAR_WIDTH);
    int bar_empty = BAR_WIDTH - bar_fill;

    printf("[");

    for (int i = 0; i < bar_fill; i++) {
        printf("█");
    }
    
    for (int i = 0; i < bar_empty; i++) {
        printf(" ");
    }

    printf("] %.2f%%\n", percentage);
}