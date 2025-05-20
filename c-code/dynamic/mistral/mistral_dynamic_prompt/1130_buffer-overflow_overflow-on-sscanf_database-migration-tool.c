#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void migrate_data(char *input) {
    char buffer[10];
    int size;

    printf("Enter database size (in MB): ");
    if (sscanf(input, "%d", &size) != 1) {
        printf("Invalid input\n");
        return;
    }

    printf("Migrating data...\n");

    for (int i = 0; i < size * 1048576; ++i) {
        sprintf(buffer, "A");
    }

    printf("Data migration completed.\n");
}

int main() {
    char input[256];

    printf("Database Migration Tool\n");
    printf("---------------------\n");
    printf("Enter the command: \n");

    fgets(input, sizeof(input), stdin);

    migrate_data(input);

    return 0;
}
