//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

// Read the contents of a file into a buffer
char* readFile(const char* filename) {
    // Open the file
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return NULL;
    }

    // Get the size of the file
    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        close(fd);
        return NULL;
    }

    // Allocate a buffer to hold the file contents
    char* buffer = malloc(statbuf.st_size + 1);
    if (buffer == NULL) {
        perror("malloc");
        close(fd);
        return NULL;
    }

    // Read the file contents into the buffer
    ssize_t bytesRead = read(fd, buffer, statbuf.st_size);
    if (bytesRead == -1) {
        perror("read");
        free(buffer);
        close(fd);
        return NULL;
    }

    // Null-terminate the buffer
    buffer[bytesRead] = '\0';

    // Close the file
    close(fd);

    // Return the buffer
    return buffer;
}

// Parse the contents of the /proc/stat file
int parseProcStat(const char* buffer, double* user, double* nice, double* system, double* idle) {
    // Find the line that starts with "cpu "
    char* line = strstr(buffer, "cpu ");
    if (line == NULL) {
        return -1;
    }

    // Parse the line into the user, nice, system, and idle times
    sscanf(line, "cpu %lf %lf %lf %lf", user, nice, system, idle);

    // Return 0 on success
    return 0;
}

// Calculate the CPU usage percentage
double calculateCpuUsage(double user, double nice, double system, double idle) {
    // Calculate the total CPU time
    double total = user + nice + system + idle;

    // Calculate the CPU usage percentage
    double usage = (user + nice + system) / total * 100;

    // Return the CPU usage percentage
    return usage;
}

// Print the CPU usage percentage
void printCpuUsage(double usage) {
    printf("CPU usage: %.2f%%\n", usage);
}

// Main function
int main(int argc, char** argv) {
    // Read the contents of the /proc/stat file
    char* buffer = readFile("/proc/stat");
    if (buffer == NULL) {
        fprintf(stderr, "Error: could not read /proc/stat\n");
        return EXIT_FAILURE;
    }

    // Parse the contents of the /proc/stat file
    double user, nice, system, idle;
    if (parseProcStat(buffer, &user, &nice, &system, &idle) != 0) {
        fprintf(stderr, "Error: could not parse /proc/stat\n");
        free(buffer);
        return EXIT_FAILURE;
    }

    // Calculate the CPU usage percentage
    double usage = calculateCpuUsage(user, nice, system, idle);

    // Print the CPU usage percentage
    printCpuUsage(usage);

    // Free the buffer
    free(buffer);

    // Return success
    return EXIT_SUCCESS;
}