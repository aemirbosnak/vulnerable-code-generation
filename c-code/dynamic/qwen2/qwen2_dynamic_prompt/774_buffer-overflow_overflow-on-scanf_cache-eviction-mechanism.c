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
    strcpy(buffer, input); // Potential buffer overflow here
}

int main() {
    char user_input[256];
    printf("Enter data to simulate cache eviction: ");
    scanf("%255s", user_input); // Read user input safely up to 255 characters
    simulate_cache_eviction(user_input);
    return 0;
}
