#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_input(const char* input) {
    char buffer[10];
    int num;

    printf("Processing input: %s\n", input);

    // Vulnerable line - buffer overflow possible if input is too long
    sscanf(input, "%d", &num);
    sprintf(buffer, "Processed: %d", num);

    printf("%s\n", buffer);
}

int main() {
    char user_input[200];

    printf("Welcome to the Text-Based Game Engine Tool!\n");
    printf("Enter your command: ");

    fgets(user_input, sizeof(user_input), stdin);

    // Remove newline character from fgets
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    process_input(user_input);

    return 0;
}
