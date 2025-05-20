#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

void summarizeText(const char* input) {
    if (strlen(input) > MAX_INPUT_SIZE - 1) {
        printf("Input too large.\n");
        return;
    }

    // Placeholder for actual TF-IDF implementation
    printf("Summarizing: %s\n", input);
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter text to summarize:\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    summarizeText(input);

    return 0;
}
