//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complex
// A complex C RAM usage monitor program 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define KB 1024
#define MB (1024*1024)
#define GB (1024*1024*1024)

// Structure to hold system memory info
struct sys_mem_info {
    unsigned long long total_ram;
    unsigned long long free_ram;
    unsigned long long used_ram;
    float used_ram_percent;
};

/**
 * Function to retrieve system memory info 
 * Returns a sys_mem_info struct with the memory info
 */
struct sys_mem_info get_sys_mem_info() {
    struct sysinfo info;
    sysinfo(&info);
    unsigned long long total_ram = info.totalram * info.mem_unit;
    unsigned long long free_ram = info.freeram * info.mem_unit;
    unsigned long long used_ram = total_ram - free_ram;
    float used_ram_percent = (used_ram * 100.0f)/total_ram;
    struct sys_mem_info mem_info = {
        .total_ram = total_ram,
        .free_ram = free_ram,
        .used_ram = used_ram,
        .used_ram_percent = used_ram_percent
    };
    return mem_info;
}

/**
 * Function to print memory info to the console 
 * Takes in a sys_mem_info struct with the memory info to print 
 */
void print_mem_info(struct sys_mem_info mem_info) {
    printf("Total RAM: %llu GB\n", mem_info.total_ram/GB);
    printf("Free RAM: %llu MB\n", mem_info.free_ram/MB);
    printf("Used RAM: %llu MB\n", mem_info.used_ram/MB);
    printf("RAM Usage: %.2f%%\n", mem_info.used_ram_percent);
}

int main() {
    int delay = 2;  // Delay between each memory usage & print in seconds
    while(1) {
        struct sys_mem_info mem_info = get_sys_mem_info();
        print_mem_info(mem_info);
        sleep(delay);
    }   
    return 0;
}