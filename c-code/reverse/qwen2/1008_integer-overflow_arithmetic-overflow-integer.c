#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

void summarize_text(const char *input) {
    int count = 0;
    while (*input != '\0') {
        if (*input == ' ') {
            count++;
        }
        input++;
    }
    printf("Word count: %d\n", count);
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter text (up to %d characters): ", MAX_INPUT_SIZE - 1);
    fgets(input, sizeof(input), stdin);
    summarize_text(input);
    return 0;
}
