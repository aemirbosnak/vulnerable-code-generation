#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrate_data(char *data, int length) {
    char buffer[BUFFER_SIZE];
    memcpy(buffer, data, length);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <data>\n", argv[0]);
        return 1;
    }

    char *input_data = argv[1];
    int input_length = strlen(input_data);

    if (input_length > BUFFER_SIZE - 1) {
        printf("Data too large to migrate safely.\n");
        return 1;
    }

    migrate_data(input_data, input_length + 1); // Out of bounds write

    printf("Migration successful.\n");
    return 0;
}
