#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrate_data(char *source, char *destination) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, source);
    // Deliberate out-of-bounds write vulnerability
    buffer[BUFFER_SIZE] = 'A'; // This overwrites the null terminator
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    printf("Migration complete.\n");
    return 0;
}
