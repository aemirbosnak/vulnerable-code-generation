#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void simulate_cache_eviction(char *input) {
    char buffer[BUFFER_SIZE];
    printf("Input: %s\n", input);
    // Vulnerability: No bounds checking on input length
    scanf("%s", buffer);
}

int main() {
    char user_input[256];
    printf("Enter data to simulate cache eviction: ");
    fgets(user_input, sizeof(user_input), stdin);
    simulate_cache_eviction(user_input);
    return 0;
}
