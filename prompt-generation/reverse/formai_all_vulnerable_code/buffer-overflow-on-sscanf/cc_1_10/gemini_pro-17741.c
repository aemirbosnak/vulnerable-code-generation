//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/statvfs.h>

// Define the size of the RAM usage monitor buffer
#define RAM_USAGE_MONITOR_BUFFER_SIZE 1024

// Declare the RAM usage monitor buffer
char ram_usage_monitor_buffer[RAM_USAGE_MONITOR_BUFFER_SIZE];

// Define the RAM usage monitor data structure
struct ram_usage_monitor_data {
    uint64_t total_ram;
    uint64_t free_ram;
    uint64_t used_ram;
    uint64_t cached_ram;
    uint64_t buffered_ram;
    uint64_t swap_total;
    uint64_t swap_free;
    uint64_t swap_used;
};

// Define the RAM usage monitor function
struct ram_usage_monitor_data get_ram_usage_monitor_data() {
    // Open the "/proc/meminfo" file
    int fd = open("/proc/meminfo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the "/proc/meminfo" file into the RAM usage monitor buffer
    ssize_t bytes_read = read(fd, ram_usage_monitor_buffer, RAM_USAGE_MONITOR_BUFFER_SIZE);
    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Close the "/proc/meminfo" file
    close(fd);

    // Parse the RAM usage monitor buffer
    struct ram_usage_monitor_data data;
    sscanf(ram_usage_monitor_buffer,
           "MemTotal: %llu kB\n"
           "MemFree: %llu kB\n"
           "MemUsed: %llu kB\n"
           "Cached: %llu kB\n"
           "Buffers: %llu kB\n"
           "SwapTotal: %llu kB\n"
           "SwapFree: %llu kB\n"
           "SwapUsed: %llu kB\n",
           &data.total_ram,
           &data.free_ram,
           &data.used_ram,
           &data.cached_ram,
           &data.buffered_ram,
           &data.swap_total,
           &data.swap_free,
           &data.swap_used);

    // Return the RAM usage monitor data
    return data;
}

// Define the main function
int main() {
    // Get the RAM usage monitor data
    struct ram_usage_monitor_data data = get_ram_usage_monitor_data();

    // Print the RAM usage monitor data
    printf("Total RAM: %llu kB\n", data.total_ram);
    printf("Free RAM: %llu kB\n", data.free_ram);
    printf("Used RAM: %llu kB\n", data.used_ram);
    printf("Cached RAM: %llu kB\n", data.cached_ram);
    printf("Buffered RAM: %llu kB\n", data.buffered_ram);
    printf("Swap Total: %llu kB\n", data.swap_total);
    printf("Swap Free: %llu kB\n", data.swap_free);
    printf("Swap Used: %llu kB\n", data.swap_used);

    // Return success
    return EXIT_SUCCESS;
}