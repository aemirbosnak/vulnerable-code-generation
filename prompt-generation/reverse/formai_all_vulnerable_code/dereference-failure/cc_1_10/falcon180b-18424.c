//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to read from a file
int read_file(int fd, char *buffer, int size) {
    int bytes_read = 0;
    while (bytes_read < size) {
        int result = read(fd, buffer + bytes_read, size - bytes_read);
        if (result == -1) {
            printf("Error reading file\n");
            exit(1);
        }
        bytes_read += result;
    }
    return bytes_read;
}

// Function to parse the CPU usage from the proc file
int parse_cpu_usage(char *buffer, float *cpu_usage) {
    char *line = strtok(buffer, "\n");
    while (line!= NULL) {
        if (strncmp(line, "cpu ", 4) == 0) {
            char *token = strtok(line, " ");
            while (token!= NULL) {
                if (strncmp(token, "cpu", 3) == 0) {
                    *cpu_usage = atof(strtok(NULL, " "));
                    return 1;
                }
                token = strtok(NULL, " ");
            }
        }
        line = strtok(NULL, "\n");
    }
    return 0;
}

// Function to print the CPU usage
void print_cpu_usage(float cpu_usage) {
    printf("CPU usage: %.2f%%\n", cpu_usage);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);

    // Open the proc file for the given PID
    char filename[20];
    sprintf(filename, "/proc/%d/stat", pid);
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening proc file\n");
        return 1;
    }

    // Read the proc file
    char buffer[BUFFER_SIZE];
    int bytes_read = read_file(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        close(fd);
        return 1;
    }
    close(fd);

    // Parse the CPU usage from the proc file
    float cpu_usage = 0.0;
    if (!parse_cpu_usage(buffer, &cpu_usage)) {
        printf("Error parsing CPU usage\n");
        return 1;
    }

    // Print the CPU usage
    print_cpu_usage(cpu_usage);
    return 0;
}