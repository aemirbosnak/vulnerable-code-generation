//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    char *filename = "/proc/stat";
    int fd;
    char buf[BUF_SIZE];
    struct stat stat_buf;
    float cpu_usage = 0.0;
    float idle_time = 0.0;
    int total_time = 0;
    int i;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Get the file status
    if (fstat(fd, &stat_buf) == -1) {
        perror("fstat");
        exit(1);
    }

    // Read the file
    if (read(fd, buf, BUF_SIZE) == -1) {
        perror("read");
        exit(1);
    }

    // Close the file
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    // Parse the CPU usage
    for (i = 0; i < 4; i++) {
        if (strncmp(buf + i * 16, "cpu", 3) == 0) {
            sscanf(buf + i * 16 + 4, "%d", &total_time);
            break;
        }
    }

    // Calculate the CPU usage
    for (i = 0; i < 4; i++) {
        if (strncmp(buf + i * 16, "cpu", 3) == 0) {
            sscanf(buf + i * 16 + 8, "%d", &total_time);
            idle_time += total_time;
        }
    }

    cpu_usage = (float) (100 - (idle_time / total_time) * 100);

    // Print the CPU usage
    printf("CPU Usage: %.2f%%\n", cpu_usage);

    return 0;
}