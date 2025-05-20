#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    int fd, total, free_, available;
    double available_mb;

    while (1) {
        fd = open("/proc/meminfo", O_RDONLY);
        if (fd < 0) {
            perror("Error opening /proc/meminfo");
            continue;
        }

        if (read(fd, buffer, BUFFER_SIZE) <= 0) {
            perror("Error reading /proc/meminfo");
            close(fd);
            continue;
        }

        close(fd);

        if (sscanf(buffer, "MemTotal:        %*d MB\n", &total) != 1) {
            printf("Error parsing MemTotal\n");
            continue;
        }

        if (sscanf(buffer, "MemFree:         %*d KB\n", &free_) != 1) {
            printf("Error parsing MemFree\n");
            continue;
        }
        free_ /= 1024;

        if (sscanf(buffer, "MemAvailable:    %*d KB\n", &free_) != 1) {
            free_ = total * 0.1; // Estimate if MemAvailable is not available
        }
        free_ /= 1024;

        available = free_;
        available_mb = available / 1024.0;

        printf("Total Memory: %d MB\n", total);
        printf("Free Memory: %d MB\n", free_);
        printf("Available Memory: %.2f MB\n", available_mb);

        sleep(1);
    }

    return 0;
}
