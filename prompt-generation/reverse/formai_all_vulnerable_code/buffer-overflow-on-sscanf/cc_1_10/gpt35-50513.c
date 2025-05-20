//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 50

int main() {
    char command[BUFFER_SIZE];
    char output[BUFFER_SIZE];
    int total_ram, free_ram, used_ram;

    while (1) {
        // Clear the command and output buffers
        memset(command, 0, sizeof(command));
        memset(output, 0, sizeof(output));

        // Build command to read system RAM information
        sprintf(command, "cat /proc/meminfo | grep MemTotal; cat /proc/meminfo | grep MemFree");

        // Open pipe to read command output
        FILE *pipe = popen(command, "r");

        if (!pipe) {
            printf("Error: Failed to open pipe.\n");
            exit(EXIT_FAILURE);
        }

        // Read output from pipe
        fgets(output, BUFFER_SIZE, pipe);
        sscanf(output, "MemTotal: %d", &total_ram);

        fgets(output, BUFFER_SIZE, pipe);
        sscanf(output, "MemFree: %d", &free_ram);

        // Close pipe
        pclose(pipe);

        // Calculate used RAM
        used_ram = total_ram - free_ram;

        // Print RAM usage information
        printf("Total RAM: %dKB\n", total_ram);
        printf("Free RAM: %dKB\n", free_ram);
        printf("Used RAM: %dKB (%.2f%%)\n", used_ram, (float)used_ram / total_ram * 100);

        // Delay for 3 seconds before repeating
        sleep(3);
    }

    return 0;
}