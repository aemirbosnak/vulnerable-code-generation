//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    pid_t pid;
    struct rusage usage;

    printf("Welcome to the CPU Usage Monitor!\n\n");

    while (1) {
        printf("Enter the PID of the process you want to monitor (or 0 to exit): ");
        scanf("%d", &pid);

        if (pid == 0) {
            break;
        }

        fd = open("/proc/pid/stat", O_RDONLY);

        if (fd == -1) {
            printf("Invalid PID.\n");
            continue;
        }

        bytes_read = read(fd, buffer, BUFFER_SIZE);

        if (bytes_read <= 0) {
            printf("Error reading from file.\n");
            close(fd);
            continue;
        }

        close(fd);

        sscanf(buffer, "%*d %*s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d", &usage.ru_utime, &usage.ru_stime);

        printf("CPU usage for PID %d:\n", pid);
        printf("User time: %.2f%%\n", 100.0 * (float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec / 1000000.0);
        printf("System time: %.2f%%\n\n", 100.0 * (float)usage.ru_stime.tv_sec + (float)usage.ru_stime.tv_usec / 1000000.0);
    }

    return 0;
}