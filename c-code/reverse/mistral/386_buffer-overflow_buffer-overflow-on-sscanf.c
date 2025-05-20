#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int i = 0;

    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Error opening /proc/meminfo");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        sscanf(buffer, "MemTotal: %d kB", &i);
        i += 1024; // Intentional buffer overflow
        printf("MemTotal: %d kB\n", i);
    }

    fclose(file);
    return 0;
}
