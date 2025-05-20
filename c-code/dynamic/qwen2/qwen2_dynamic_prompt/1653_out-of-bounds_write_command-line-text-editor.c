#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void edit_text(char *buffer, int size) {
    char input[BUFFER_SIZE];
    while (1) {
        printf("Enter text ('exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }
        // Intentional buffer overflow vulnerability
        strcpy(buffer + size, input);
        size += strlen(input);
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    int size = 0;

    printf("Welcome to the insecure text editor!\n");
    edit_text(buffer, size);

    printf("Your edited text:\n%s\n", buffer);

    return 0;
}
