#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 32
#define CACHE_SIZE 4
#define LINE_SIZE 1025

typedef struct CacheLine {
    int tag;
    char data[LINE_SIZE];
} CacheLine;

CacheLine cache[CACHE_SIZE];
int count = 0;

void print_cache() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("Cache Line %d:\n", i);
        printf("Tag: %d\n", cache[i].tag);
        printf("Data: %s\n", cache[i].data);
    }
}

void handle_request(char* line) {
    int tag, idx;
    sscanf(line, "%d %s", &tag, cache[CACHE_SIZE - 1].data);

    for (idx = 0; idx < CACHE_SIZE; idx++) {
        if (cache[idx].tag == tag) {
            break;
        }
    }

    if (idx < CACHE_SIZE) { // Eviction occurs if the tag is found in the cache
        printf("Eviction needed: %s\n", cache[idx].data);
        memset(cache[idx].data, '\0', LINE_SIZE);
        cache[idx].tag = tag;
        strcpy(cache[idx].data, cache[CACHE_SIZE - 1].data);
    } else {
        cache[count].tag = tag;
        strcpy(cache[count].data, cache[CACHE_SIZE - 1].data);
        count = (count + 1) % CACHE_SIZE;
    }
    print_cache();
}

int main() {
    char input[BUFFER_SIZE];

    while (1) {
        printf("Enter a cache request in the format: <Tag> <Data>\n");
        fgets(input, BUFFER_SIZE, stdin);
        handle_request(input);
    }

    return 0;
}
