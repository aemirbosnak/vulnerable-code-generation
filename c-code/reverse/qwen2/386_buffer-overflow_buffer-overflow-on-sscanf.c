#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return EXIT_FAILURE;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int value;
        if (sscanf(line, "%*s %d", &value) != 1) {
            continue;
        }
        // Vulnerability: No bounds checking on the array access
        printf("%d\n", value);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
