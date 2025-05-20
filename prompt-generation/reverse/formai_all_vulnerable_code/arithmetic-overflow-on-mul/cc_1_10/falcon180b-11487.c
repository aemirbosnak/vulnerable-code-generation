//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    char *file_name = "/proc/self/statm";
    int file_fd;
    struct statvfs buffer;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int total_ram = 0;

    // Open the file for reading
    file_fd = open(file_name, O_RDONLY);

    // Check if the file was opened successfully
    if (file_fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the contents of the file
    while ((read = getline(&line, &len, file_fd))!= -1) {
        // Split the line into an array of strings
        char *token = strtok(line, " ");
        while (token!= NULL) {
            // Check if the token contains the total RAM usage
            if (strcmp(token, "total") == 0) {
                // Convert the string to an integer and store it in the variable
                total_ram = atoi(strtok(NULL, " "));
                break;
            }
            // Move to the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    if (close(file_fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

    // Print the total RAM usage
    printf("Total RAM usage: %d\n", total_ram);

    // Get the total amount of physical memory in bytes
    if (sysconf(_SC_PHYS_PAGES) <= 0) {
        printf("Error getting total amount of physical memory\n");
        exit(EXIT_FAILURE);
    }

    // Convert the total amount of physical memory to megabytes
    long long total_mem = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
    total_mem /= (1024 * 1024);

    // Print the total amount of physical memory
    printf("Total physical memory: %lld MB\n", total_mem);

    return 0;
}