//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the first line of the file
    char buf[BUF_SIZE];
    if (fgets(buf, BUF_SIZE, fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Parse the first line of the file
    char *ptr = strtok(buf, " ");
    if (ptr == NULL) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Get the user time
    ptr = strtok(NULL, " ");
    if (ptr == NULL) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    unsigned long user_time = strtoul(ptr, NULL, 10);

    // Get the system time
    ptr = strtok(NULL, " ");
    if (ptr == NULL) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    unsigned long system_time = strtoul(ptr, NULL, 10);

    // Get the idle time
    ptr = strtok(NULL, " ");
    if (ptr == NULL) {
        fprintf(stderr, "Error parsing /proc/stat\n");
        fclose(fp);
        return EXIT_FAILURE;
    }
    unsigned long idle_time = strtoul(ptr, NULL, 10);

    // Calculate the CPU usage
    unsigned long total_time = user_time + system_time + idle_time;
    double cpu_usage = (double)(user_time + system_time) / (double)total_time;

    // Print the CPU usage
    printf("CPU usage: %.2f%%\n", cpu_usage * 100);

    // Close the /proc/stat file
    fclose(fp);

    return EXIT_SUCCESS;
}