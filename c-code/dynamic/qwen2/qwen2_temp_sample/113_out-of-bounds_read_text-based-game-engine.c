#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

void process_input(char* input) {
    char buffer[MAX_BUFFER_SIZE];
    int i;

    // Simulate processing input
    for (i = 0; input[i] != '\0'; i++) {
        if (i >= MAX_BUFFER_SIZE - 1) {
            printf("Buffer overflow detected!\n");
            return;
        }
        buffer[i] = input[i];
    }

    buffer[i] = '\0';

    // Print processed input
    printf("Processed input: %s\n", buffer);
}

int main() {
    char input[256];

    printf("Enter some text: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    process_input(input);

    return 0;
}
