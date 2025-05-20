#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEMINFO_PATH "/proc/meminfo"

void parse_meminfo(char *line) {
    char key[256], value[256];
    if (sscanf(line, "%s %s", key, value) == 2) {
        printf("%s: %s\n", key, value);
    }
}

int main() {
    FILE *fp;
    char line[1024];

    while (1) {
        fp = fopen(MEMINFO_PATH, "r");
        if (!fp) {
            perror("Failed to open /proc/meminfo");
            sleep(1);
            continue;
        }

        while (fgets(line, sizeof(line), fp)) {
            parse_meminfo(line);
        }

        fclose(fp);
        sleep(1);
    }

    return 0;
}
