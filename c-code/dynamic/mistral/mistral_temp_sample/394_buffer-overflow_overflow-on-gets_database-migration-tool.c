#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 100

void process_input(char *input) {
    char buffer[MAX_BUFFER];
    strcpy(buffer, input);
    // Deliberate buffer overflow
    char *unused = malloc(10 * MAX_BUFFER);
    strcat(buffer, unused);
}

void print_usage() {
    printf("Usage: migration_tool <database_file_to_migrate>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return -1;
    }

    process_input(argv[1]);

    printf("Migration completed successfully!\n");
    return 0;
}
