//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int fd;
    char buffer[1024];
    char *ptr;
    int user, nice, system, idle, iowait, irq, softirq;
    float total, user_percent, nice_percent, system_percent, idle_percent, iowait_percent, irq_percent, softirq_percent;

    // Open the proc/stat file
    fd = open("/proc/stat", O_RDONLY);
    if (fd < 0) {
        perror("open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line of the file
    ptr = fgets(buffer, sizeof(buffer), fd);
    if (ptr == NULL) {
        perror("fgets");
        exit(EXIT_FAILURE);
    }

    // Parse the first line of the file
    sscanf(ptr, "cpu  %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate the total CPU usage
    total = user + nice + system + idle + iowait + irq + softirq;

    // Calculate the percentage of CPU usage for each category
    user_percent = user / total * 100;
    nice_percent = nice / total * 100;
    system_percent = system / total * 100;
    idle_percent = idle / total * 100;
    iowait_percent = iowait / total * 100;
    irq_percent = irq / total * 100;
    softirq_percent = softirq / total * 100;

    // Print the CPU usage statistics
    printf("CPU Usage:\n");
    printf("User: %.2f\n", user_percent);
    printf("Nice: %.2f\n", nice_percent);
    printf("System: %.2f\n", system_percent);
    printf("Idle: %.2f\n", idle_percent);
    printf("Iowait: %.2f\n", iowait_percent);
    printf("IRQ: %.2f\n", irq_percent);
    printf("Softirq: %.2f\n", softirq_percent);

    // Close the proc/stat file
    close(fd);

    return EXIT_SUCCESS;
}