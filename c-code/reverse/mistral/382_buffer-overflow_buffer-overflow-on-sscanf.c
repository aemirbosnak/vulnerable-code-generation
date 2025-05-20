#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[64];
    FILE *file = fopen("/proc/meminfo", "r");

    if (file) {
        fgets(buffer, sizeof(buffer), file);
        sscanf(buffer, "MemTotal: %ld kB", &buffer[0]);
        printf("Memory Total: %ld kB\n", buffer[0]);
        fclose(file);
    } else {
        printf("Error: Unable to open /proc/meminfo\n");
    }

    return 0;
}
