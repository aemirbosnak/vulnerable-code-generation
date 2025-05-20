#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define CACHE_SIZE 1024

char cache[CACHE_SIZE];

void addToCache(const char *data) {
    if (strlen(data) >= CACHE_SIZE) {
        return;
    }
    strcpy(cache, data);
}

int main() {
    addToCache("This is a test string that will cause an overflow.");
    printf("Cached data: %s\n", cache);
    return 0;
}
