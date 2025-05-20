//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to get the total amount of RAM in bytes
long long get_total_ram() {
    struct statvfs statfs;
    if (statvfs("/", &statfs) == 0) {
        return (long long) statfs.f_blocks * statfs.f_frsize;
    } else {
        return -1;
    }
}

// Function to get the amount of free RAM in bytes
long long get_free_ram() {
    struct statvfs statfs;
    if (statvfs("/", &statfs) == 0) {
        return (long long) statfs.f_bavail * statfs.f_frsize;
    } else {
        return -1;
    }
}

// Function to get the amount of used RAM in bytes
long long get_used_ram() {
    long long total_ram = get_total_ram();
    long long free_ram = get_free_ram();

    if (total_ram == -1 || free_ram == -1) {
        return -1;
    } else {
        return total_ram - free_ram;
    }
}

// Function to get the percentage of used RAM
double get_ram_usage_percentage() {
    long long used_ram = get_used_ram();
    long long total_ram = get_total_ram();

    if (used_ram == -1 || total_ram == -1) {
        return -1;
    } else {
        double usage_percentage = (double) used_ram / total_ram * 100;
        return usage_percentage;
    }
}

// Function to print the RAM usage information
void print_ram_usage() {
    long long used_ram = get_used_ram();
    long long total_ram = get_total_ram();
    double usage_percentage = get_ram_usage_percentage();

    printf("Total RAM: %lld bytes\n", total_ram);
    printf("Used RAM: %lld bytes\n", used_ram);
    printf("Free RAM: %lld bytes\n", total_ram - used_ram);
    printf("RAM Usage Percentage: %.2f%%\n", usage_percentage);
}

// Main function
int main() {
    print_ram_usage();
    return 0;
}