#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int mem_total, mem_free, mem_used;

    file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Error opening /proc/meminfo");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strncmp(buffer, "MemTotal:", 8) == 0) {
            sscanf(buffer, "MemTotal: %d kB", &mem_total);
        }
        if (strncmp(buffer, "MemFree:", 7) == 0) {
            sscanf(buffer, "MemFree: %d kB", &mem_free);
        }
        if (strncmp(buffer, "Buffers:", 7) == 0) {
            sscanf(buffer, "Buffers: %d kB", &mem_used);
            mem_used -= mem_free;
            break;
        }
    }

    fclose(file);

    printf("Total Memory: %d kB\n", mem_total);
    printf("Free Memory: %d kB\n", mem_free);
    printf("Used Memory: %d kB\n", mem_used);

    char input[BUFFER_SIZE];
    printf("Enter a large input to cause a buffer overflow: ");
    fgets(input, BUFFER_SIZE, stdin);

    return 0;
}
