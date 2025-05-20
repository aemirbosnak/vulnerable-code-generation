#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Cache Eviction Mechanism v1.0 */

#define BUFFER_SIZE 256
#define ARGS_COUNT 10

void evict_cache(char* filename) {
    FILE* file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];

    if (!file) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    for (int i = 0; i < ARGS_COUNT; ++i) {
        if (fscanf(file, "%s", buffer) != 1) {
            printf("Premature EOF\n");
            break;
        }
        // Deliberate overflow by providing too many arguments to fscanf
        fscanf(file, " %*s");
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./cache_evictor <filename>\n");
        return 1;
    }

    evict_cache(argv[1]);

    return 0;
}
