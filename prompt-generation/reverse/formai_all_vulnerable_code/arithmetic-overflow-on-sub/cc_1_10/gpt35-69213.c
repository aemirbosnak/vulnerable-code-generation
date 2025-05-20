//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define PERCENT_MULTIPLIER 100

struct sys_info {
    int total_ram;
    int free_ram;
    int buffer_ram;
    int cached_ram;
};

void print_formatted_size(long long size, char *unit) {
    float formatted_size = (float)size;
    char *formatted_unit = "";

    if (formatted_size >= 1024) {
        formatted_size /= 1024;
        formatted_unit = "KB";
    }

    if (formatted_size >= 1024) {
        formatted_size /= 1024;
        formatted_unit = "MB";
    }

    if (formatted_size >= 1024) {
        formatted_size /= 1024;
        formatted_unit = "GB";
    }

    printf("%.2f %s%s\n", formatted_size, unit, formatted_unit);
}

void read_sys_info(struct sys_info *si) {
    struct sysinfo info;

    sysinfo(&info);

    si->total_ram = info.totalram * info.mem_unit;
    si->free_ram = info.freeram * info.mem_unit;
    si->buffer_ram = info.bufferram * info.mem_unit;
    si->cached_ram = info.freeram * info.mem_unit;
}

float calculate_ram_usage(struct sys_info *si) {
    int used_ram = si->total_ram - si->free_ram - si->buffer_ram - si->cached_ram;

    return (float)used_ram / (float)si->total_ram * PERCENT_MULTIPLIER;
}

int main(void) {
    struct sys_info si;

    read_sys_info(&si);

    printf("Total RAM: ");
    print_formatted_size(si.total_ram, "B");

    printf("Free RAM: ");
    print_formatted_size(si.free_ram, "B");

    printf("Buffer RAM: ");
    print_formatted_size(si.buffer_ram, "B");

    printf("Cached RAM: ");
    print_formatted_size(si.cached_ram, "B");

    printf("RAM Usage: %.2f %%\n", calculate_ram_usage(&si));

    return EXIT_SUCCESS;
}