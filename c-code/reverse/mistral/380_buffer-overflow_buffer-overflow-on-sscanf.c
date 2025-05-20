#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen("/proc/meminfo", "r");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        char key[256], value[256];
        sscanf(buffer, "%s %s", key, value);
        if (!strcmp(key, "MemTotal:")) {
            printf("Total Memory: %s\n", value);
        }
    }
    fclose(file);
    return 0;
}
