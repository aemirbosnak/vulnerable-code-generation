#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct {
    uint64_t freq[256];
} FreqMap;

void initFreqMap(FreqMap* map) {
    memset(map->freq, 0, sizeof(map->freq));
}

void updateFreqMap(FreqMap* map, const char* str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        map->freq[(unsigned char)str[i]]++;
    }
}

void printFreqMap(const FreqMap* map) {
    for (int i = 0; i < 256; ++i) {
        if (map->freq[i]) {
            printf("%c: %" PRIu64 "\n", i, map->freq[i]);
        }
    }
}

void summarize(const char* input) {
    FreqMap map;
    initFreqMap(&map);
    updateFreqMap(&map, input);
    printFreqMap(&map);
}

int main() {
    char input[1000000];
    fgets(input, sizeof(input), stdin);
    summarize(input);
    return 0;
}
