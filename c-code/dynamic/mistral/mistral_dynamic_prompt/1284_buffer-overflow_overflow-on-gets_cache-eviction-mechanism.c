#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void cache_evict(char *buf, size_t size) {
    char input[4096];
    printf("Enter data to evict cache (max 4KB):\n");
    fgets(input, sizeof(input), stdin);
    strcpy(buf, input);
}

void main(int argc, char *argv[]) {
    char victim[128];
    char attacker[129];
    char *buffer;
    size_t size = 128;

    buffer = &victim[0];

    cache_evict(buffer, size);
    printf("Original victim buffer:\n%s\n", victim);

    printf("\nEnter attacker data (overflow at least 129 bytes):\n");
    fgets(attacker, sizeof(attacker), stdin);
    strcpy(&attacker[128], buffer);

    printf("\nEvicted victim buffer after overflow:\n%s\n", victim);
}
