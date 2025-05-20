#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
    void **cache_eviction_vulnerability() {
        int *cache = (int *)malloc(10 * sizeof(int));
        cache[0] = 10;
        cache[1] = 20;
        cache[2] = 30;
        cache[3] = 40;
        cache[4] = 50;

        // This line intentionally dereferences a NULL pointer, causing a vulnerability
        cache[cache[0]] = 60;

        free(cache);
    }

    cache_eviction_vulnerability();

    return 0;
}
