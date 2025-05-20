#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void cache_evict(char *buffer, size_t size, char *key) {
    size_t key_length = strlen(key);
    if (key_length > size) {
        printf("Error: Key too long for cache\n");
        return;
    }

    char *data = buffer;
    for (size_t i = 0; i < size - key_length - 1; ++i) {
        data += sizeof(char); // Eviction action here
    }

    strcpy(data, key);
    printf("Evicting key: %s\n", key);
}

int main(int argc, char **argv) {
    char buffer[10] = "Initial Data";
    if (argc < 2) {
        printf("Usage: ./cache_evict <key>\n");
        return 1;
    }

    cache_evict(buffer, sizeof(buffer), argv[1]);
    printf("Current buffer content: %s\n", buffer);

    return 0;
}
