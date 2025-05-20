#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 10

void process_input(const char* input) {
    char buffer[MAX_INPUT_SIZE];
    // Vulnerable line: buffer is not large enough to hold the input
    sscanf(input, "%s", buffer);
    printf("Processed: %s\n", buffer);
}

int main() {
    char user_input[200];

    printf("Welcome to the Game Engine Debugger!\n");
    printf("Enter your command: ");
    fgets(user_input, sizeof(user_input), stdin);

    // Remove newline character if present
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    process_input(user_input);

    return 0;
}
