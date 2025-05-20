#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void evil_cache(char *input) {
    char buffer[16];
    char *eviction_victim = "A vulnerable function call";

    // Overwrite a fixed-size buffer with input
    strcpy(buffer, input);

    // Use the vulnerable function, causing buffer overflow
    // This results in the buffer content (including arbitrary data) replacing the eviction_victim's address in the cache
    evil_vulnerable_function(buffer);
}

void evil_vulnerable_function(char *input) {
    // Your vulnerable code goes here...
    printf("Processing input: %s\n", input);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    evil_cache(argv[1]);

    return 0;
}
