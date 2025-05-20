#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 10

void process_input(const char* input) {
    char buffer[MAX_INPUT_SIZE];
    int num;

    // Simulate a function that processes user input
    if (sscanf(input, "%d", &num) == 1) {
        printf("Received number: %d\n", num);
    } else {
        printf("Invalid input.\n");
    }
}

int main() {
    char input[20];

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    process_input(input);

    return 0;
}
