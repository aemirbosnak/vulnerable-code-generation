#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

void simulate_cache_eviction(char *input) {
    char cache[CACHE_SIZE];
    printf("Input: %s\n", input);
    // Vulnerability: Buffer overflow due to insufficient bounds checking
    strcpy(cache, input);
}

int main() {
    char user_input[256];
    printf("Enter data to simulate cache eviction: ");
    scanf("%255s", user_input); // Safe read up to 255 characters
    simulate_cache_eviction(user_input);
    return 0;
}
