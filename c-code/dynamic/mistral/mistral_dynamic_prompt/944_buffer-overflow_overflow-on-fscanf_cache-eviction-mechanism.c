#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16
#define NUM_ENTRIES 100

typedef struct {
    char key[32];
    char value[64];
} CacheEntry;

CacheEntry cache[NUM_ENTRIES];
int num_entries = 0;

void evict_oldest() {
    int oldest = 0;
    int i;

    for (i = 1; i < num_entries; ++i) {
        if (strcmp(cache[i].key, cache[oldest].key) < 0) {
            oldest = i;
        }
    }

    memset(cache[oldest].key, 0, sizeof(cache[oldest].key));
    memset(cache[oldest].value, 0, sizeof(cache[oldest].value));
    --num_entries;
}

int main(int argc, char *argv[]) {
    int index;
    char line[BUFFER_SIZE];

    while (1) {
        printf("> ");
        fgets(line, BUFFER_SIZE, stdin);

        sscanf(line, "%s %n", cache[num_entries].key, &index);
        strncat(cache[num_entries].key, line + index, strlen(line) - index);
        sscanf(line, "%s %n", cache[num_entries].value + index, &index);
        strncat(cache[num_entries].value, line + index, strlen(line) - index);
        ++num_entries;
        evict_oldest();
    }

    return 0;
}
