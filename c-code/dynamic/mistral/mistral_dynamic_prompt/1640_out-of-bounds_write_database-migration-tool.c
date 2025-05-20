#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

void migrate_database(char *input) {
    char db_data[128][MAX_INPUT_LENGTH];
    int records = 0;

    char *token = strtok(input, ";");

    while (token != NULL) {
        strcpy(db_data[records], token);
        records++;
        token = strtok(NULL, ";");
    }

    // Out-of-bounds write vulnerability starts here
    if (records >= 128) {
        printf("Error: Too many records.\n");
        return;
    }

    // Write arbitrary data beyond the allocated memory for db_data[]
    strcpy(db_data[records], "\x41" // ASCII 'A'
                              "\x41" // ASCII 'A'
                              "\x41" // ASCII 'A'
                              // Malicious payload could be injected here
                              "\x00"); // Null terminator
    // Out-of-bounds write vulnerability ends here

    printf("Migrated the following records:\n");
    for (int i = 0; i < records; ++i) {
        printf("%s\n", db_data[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s database_data\n", argv[0]);
        return 1;
    }

    migrate_database(argv[1]);
    return 0;
}
