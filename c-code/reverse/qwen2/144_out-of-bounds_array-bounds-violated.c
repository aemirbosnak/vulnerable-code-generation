#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

void handle_input(char *input) {
    char buffer[50];
    strcpy(buffer, input); // Vulnerable to buffer overflow
}

int main() {
    char input[MAX_INPUT];

    printf("Welcome to the Adventure Game!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        handle_input(input);
    }

    return 0;
}
