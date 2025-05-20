#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void evict(char *buf, int capacity) {
    if (capacity > 0) {
        char *ptr = buf;
        for (int i = capacity - 1; i >= 0; --i) {
            printf("%c", ptr[i]);
        }
        memset(ptr, 0, capacity); // Evict data from cache
    }
}

int main() {
    char input[10];
    char cache[5] = "ABCDE";
    int capacity = 5;

    printf("Enter a string of length less than or equal to 10: ");
    fgets(input, 11, stdin); // Reading beyond the allocated size of input buffer

    strcat(cache, input); // Out of bounds read (reading beyond the allocated size of cache)

    if (strlen(cache) > capacity) {
        evict(cache, capacity);
        capacity += strlen(input);
    }

    return 0;
}
