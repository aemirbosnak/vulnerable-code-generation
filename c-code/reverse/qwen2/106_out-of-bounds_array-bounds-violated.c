#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void sanitize(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'x' || input[i] == 'y') {
            input[i] = 'z';
        }
    }
}

int main() {
    char buffer[10];
    printf("Enter three lines:\n");
    fgets(buffer, sizeof(buffer), stdin);
    sanitize(buffer);
    printf("Sanitized: %s\n", buffer);

    fgets(buffer, sizeof(buffer), stdin);
    sanitize(buffer);
    printf("Sanitized: %s\n", buffer);

    fgets(buffer, sizeof(buffer), stdin);
    sanitize(buffer);
    printf("Sanitized: %s\n", buffer);

    return 0;
}
