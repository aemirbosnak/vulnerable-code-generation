#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_input(char *input) {
    char buffer[10];
    int num;

    printf("Processing input...\n");
    if (sscanf(input, "%d", &num) == 1) {
        snprintf(buffer, sizeof(buffer), "Number: %d", num);
        printf("%s\n", buffer);
    } else {
        printf("Invalid input!\n");
    }
}

int main() {
    char input[20];

    printf("Welcome to the Text-Based Game Engine Tool!\n");
    printf("Enter a number to process: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    process_input(input);

    return 0;
}
