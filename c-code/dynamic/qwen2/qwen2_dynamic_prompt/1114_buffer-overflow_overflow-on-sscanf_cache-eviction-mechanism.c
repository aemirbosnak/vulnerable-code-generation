#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void simulate_cache_eviction(char *input) {
    char buffer[BUFFER_SIZE];
    int id;
    float value;

    // Simulate cache eviction by reading input into buffer
    if (sscanf(input, "%d %f", &id, &value) != 2) {
        printf("Invalid input format\n");
        return;
    }

    // Buffer overflow vulnerability here
    sprintf(buffer, "ID: %d Value: %.2f", id, value);

    // Print the buffer content
    printf("%s\n", buffer);
}

int main() {
    char input[100];

    printf("Enter ID and value (e.g., 123 45.67): ");
    fgets(input, sizeof(input), stdin);

    simulate_cache_eviction(input);

    return 0;
}
