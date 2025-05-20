//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void print_memory_usage() {
    FILE *file;
    char line[BUFFER_SIZE];

    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    printf("\nMemory Usage: \n");
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            printf("%s", line);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            printf("%s", line);
        } else if (strncmp(line, "Buffers:", 8) == 0) {
            printf("%s", line);
        } else if (strncmp(line, "Cached:", 7) == 0) {
            printf("%s", line);
        } else if (strncmp(line, "SwapTotal:", 10) == 0) {
            printf("%s", line);
        } else if (strncmp(line, "SwapFree:", 9) == 0) {
            printf("%s", line);
        }
    }

    fclose(file);
}

int main() {
    int delay;

    printf("Enter the delay time in seconds for RAM usage updates: ");
    scanf("%d", &delay);

    if (delay < 1) {
        printf("Delay time must be at least 1 second.\n");
        return EXIT_FAILURE;
    }

    while (1) {
        print_memory_usage();
        sleep(delay);
    }

    return EXIT_SUCCESS;
}