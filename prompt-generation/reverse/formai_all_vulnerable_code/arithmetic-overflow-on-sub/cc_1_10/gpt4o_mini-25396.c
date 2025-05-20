//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <signal.h>

#define BOLD   "\033[1m"
#define RESET  "\033[0m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define RED    "\033[31m"

typedef struct {
    long total_ram;
    long free_ram;
    long used_ram;
} MemoryInfo;

volatile sig_atomic_t stop;

void handle_sigint(int sig) {
    stop = 1;
}

MemoryInfo get_memory_info() {
    struct sysinfo info;
    if (sysinfo(&info) != 0) {
        perror("sysinfo");
        exit(EXIT_FAILURE);
    }
    
    MemoryInfo mem_info;
    mem_info.total_ram = info.totalram * info.mem_unit;
    mem_info.free_ram = info.freeram * info.mem_unit;
    mem_info.used_ram = mem_info.total_ram - mem_info.free_ram;
    
    return mem_info;
}

void display_memory_usage(MemoryInfo mem_info) {
    printf(BOLD "Memory Usage Monitor" RESET "\n");
    printf("====================================\n");
    printf(GREEN "Total RAM: %.2f MB" RESET "\n", mem_info.total_ram / (1024.0 * 1024.0));
    printf(YELLOW "Free RAM: %.2f MB" RESET "\n", mem_info.free_ram / (1024.0 * 1024.0));
    printf(RED "Used RAM: %.2f MB" RESET "\n", mem_info.used_ram / (1024.0 * 1024.0));
    printf("====================================\n");
}

void unit_test_memory_info() {
    MemoryInfo mem_info = get_memory_info();
    if (mem_info.total_ram > 0) {
        printf("Unit Test Passed: Total RAM is positive.\n");
    } else {
        printf("Unit Test Failed: Total RAM is not positive.\n");
    }
}

int main() {
    // Set up signal handler for graceful termination
    signal(SIGINT, handle_sigint);
    
    // Optional: Unit test to validate memory info retrieval
    unit_test_memory_info();

    printf("Press Ctrl+C to stop the RAM usage monitor.\n");

    while (!stop) {
        MemoryInfo mem_info = get_memory_info();
        display_memory_usage(mem_info);
        sleep(2); // Monitor every 2 seconds
        printf("\033[F\033[K"); // Move cursor up and clear line for next display
    }

    printf("Memory usage monitoring stopped.\n");
    return 0;
}