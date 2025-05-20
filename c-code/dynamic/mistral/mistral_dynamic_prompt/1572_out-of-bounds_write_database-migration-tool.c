#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrate_data(char *input, char *output) {
    int i;
    char buffer[BUFFER_SIZE];

    strcpy(buffer, input);

    for (i = 0; i < strlen(buffer); i++) {
        output[i] = buffer[i] ^ 0x55;
    }

    // Intentionally adding an extra write operation beyond the allocated buffer size
    output[BUFFER_SIZE] = 'X';
}

int main() {
    char input[100];
    char output[100];

    printf("Enter input data: ");
    fgets(input, sizeof(input), stdin);

    migrate_data(input, output);

    printf("Migrated data: %s\n", output);

    return 0;
}
