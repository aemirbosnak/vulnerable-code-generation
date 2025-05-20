#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void migrate_data(char *input) {
    char buffer[10];
    printf("Migrating data...\n");
    strcpy(buffer, input);
}

int main(int argc, char *argv[]) {
    char *input;

    if (argc != 2) {
        printf("Usage: migrate <database_file>\n");
        return 1;
    }

    input = malloc(strlen(argv[1]) + 1);
    strcpy(input, argv[1]);

    migrate_data(input);

    free(input);
    return 0;
}
