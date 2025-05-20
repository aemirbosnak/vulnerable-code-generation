#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    FILE *pipe = fopen("/proc/stat", "r");
    if (pipe == NULL) return 1;

    char line[1024];
    while (fgets(line, sizeof(line), pipe)) {
        if (sscanf(line, "%*s %d %d %d %d %d %d %d %d %d %d",
                   &line[0], &line[1], &line[2], &line[3], &line[4],
                   &line[5], &line[6], &line[7], &line[8], &line[9]) != 10) {
            break;
        }
    }

    fclose(pipe);
    return 0;
}
