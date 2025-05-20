//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define CHECK_INTERVAL 5 // in seconds

void print_memory_info(long total, long used, long free) {
    printf("Total memory: %ld bytes\n", total);
    printf("Used memory: %ld bytes\n", used);
    printf("Free memory: %ld bytes\n", free);
}

int main() {
    struct statvfs stat_info;

    if (statvfs("/", &stat_info) == -1) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }

    long total_memory = (long)stat_info.f_blocks * (long)stat_info.f_frsize;
    long used_memory = (long)(stat_info.f_blocks - stat_info.f_bfree) * (long)stat_info.f_frsize;
    long free_memory = (long)stat_info.f_bavail * (long)stat_info.f_frsize;

    printf("Initial memory usage:\n");
    print_memory_info(total_memory, used_memory, free_memory);

    while (1) {
        sleep(CHECK_INTERVAL);

        if (statvfs("/", &stat_info) == -1) {
            perror("statvfs");
            exit(EXIT_FAILURE);
        }

        long new_total_memory = (long)stat_info.f_blocks * (long)stat_info.f_frsize;
        long new_used_memory = (long)(stat_info.f_blocks - stat_info.f_bfree) * (long)stat_info.f_frsize;
        long new_free_memory = (long)stat_info.f_bavail * (long)stat_info.f_frsize;

        if (new_total_memory!= total_memory || new_used_memory!= used_memory || new_free_memory!= free_memory) {
            printf("Current memory usage:\n");
            print_memory_info(new_total_memory, new_used_memory, new_free_memory);

            total_memory = new_total_memory;
            used_memory = new_used_memory;
            free_memory = new_free_memory;
        }
    }

    return 0;
}