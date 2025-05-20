#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return 1;
    }

    char line[4096];
    while (fgets(line, sizeof(line), fp)) {
        int value;
        char key[256];
        if (sscanf(line, "%s %d kB", key, &value) == 2) {
            printf("%s: %d kB\n", key, value);
        }
    }

    fclose(fp);
    return 0;
}
