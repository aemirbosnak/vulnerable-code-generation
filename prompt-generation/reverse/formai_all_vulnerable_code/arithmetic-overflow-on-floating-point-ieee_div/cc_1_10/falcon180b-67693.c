//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>

#define RAM_USAGE_THRESHOLD 75

void post_apocalyptic_style(void) {
    printf("\n");
    printf(" \\   \\  \\___\\_   _ _ ____ _ _ \\n");
    printf(" \\ \\  \\/\\/ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\n");
    printf("  \\ \\ \\_/ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\n");
    printf("   \\ \\ \\L\\_\\ \\ \\ \\ \\ \\ \\ \\ \\ \\n");
    printf("    \\ \\____/ \\_\\ \\_\\ \\_\\ \\_\\ \\n");
    printf("     \\/___/\\n");
}

void check_ram_usage(void) {
    struct statvfs buffer;
    int fd;
    double ram_usage;

    fd = open("/proc/meminfo", O_RDONLY);
    if (fd == -1) {
        perror("Error opening /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    if (fstatvfs(fd, &buffer) == -1) {
        perror("Error getting file status of /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    ram_usage = ((double)buffer.f_blocks - (double)buffer.f_bfree) / (double)buffer.f_blocks * 100.0;

    if (ram_usage >= RAM_USAGE_THRESHOLD) {
        printf("WARNING: RAM usage at %.2f%%\n", ram_usage);
    } else {
        printf("RAM usage at %.2f%%\n", ram_usage);
    }

    close(fd);
}

int main(void) {
    post_apocalyptic_style();
    check_ram_usage();

    return 0;
}