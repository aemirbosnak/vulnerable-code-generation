//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// This program monitors the RAM usage of the system and prints it to the console.

// Define the size of the buffer to use for reading the /proc/meminfo file.
#define BUFFER_SIZE 1024

// Define the path to the /proc/meminfo file.
#define PROC_MEMINFO_PATH "/proc/meminfo"

// Define the maximum number of lines to read from the /proc/meminfo file.
#define MAX_LINES 10

// Define the structure to store the RAM usage information.
typedef struct {
    unsigned long total;
    unsigned long free;
    unsigned long used;
    unsigned long buffer;
    unsigned long cached;
} ram_usage_t;

// Get the RAM usage information from the /proc/meminfo file.
int get_ram_usage(ram_usage_t *ram_usage) {
    // Open the /proc/meminfo file.
    int fd = open(PROC_MEMINFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    // Read the first line of the /proc/meminfo file.
    char buffer[BUFFER_SIZE];
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    // Parse the first line of the /proc/meminfo file.
    sscanf(buffer, "MemTotal: %lu kB", &ram_usage->total);

    // Read the second line of the /proc/meminfo file.
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    // Parse the second line of the /proc/meminfo file.
    sscanf(buffer, "MemFree: %lu kB", &ram_usage->free);

    // Read the third line of the /proc/meminfo file.
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    // Parse the third line of the /proc/meminfo file.
    sscanf(buffer, "MemAvailable: %lu kB", &ram_usage->used);

    // Read the fourth line of the /proc/meminfo file.
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    // Parse the fourth line of the /proc/meminfo file.
    sscanf(buffer, "Buffers: %lu kB", &ram_usage->buffer);

    // Read the fifth line of the /proc/meminfo file.
    if (read(fd, buffer, BUFFER_SIZE) == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    // Parse the fifth line of the /proc/meminfo file.
    sscanf(buffer, "Cached: %lu kB", &ram_usage->cached);

    // Close the /proc/meminfo file.
    close(fd);

    return 0;
}

// Print the RAM usage information to the console.
void print_ram_usage(ram_usage_t *ram_usage) {
    printf("Total RAM: %lu kB\n", ram_usage->total);
    printf("Free RAM: %lu kB\n", ram_usage->free);
    printf("Used RAM: %lu kB\n", ram_usage->used);
    printf("Buffer RAM: %lu kB\n", ram_usage->buffer);
    printf("Cached RAM: %lu kB\n", ram_usage->cached);
}

// Main function
int main(void) {
    // Get the RAM usage information.
    ram_usage_t ram_usage;
    if (get_ram_usage(&ram_usage) == -1) {
        return -1;
    }

    // Print the RAM usage information.
    print_ram_usage(&ram_usage);

    return 0;
}