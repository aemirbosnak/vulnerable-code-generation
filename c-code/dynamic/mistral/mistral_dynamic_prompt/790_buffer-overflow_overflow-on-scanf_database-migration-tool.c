#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_data(char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");

    if (!file) {
        printf("Error: Unable to open file.\n");
        return;
    }

    printf("Enter the size of the new database: ");
    scanf("%s", buffer);
    fclose(file);

    FILE *new_file = fopen("new_database.db", "w");

    // Buffer overflow vulnerability: Insufficient size check before scanf
    for (int i = 0; i < atoi(buffer); i++) {
        fputs("Dummy data\n", new_file);
    }

    fclose(new_file);
    printf("Data migration complete.\n");
}

int main() {
    migrate_data("old_database.db");
    return 0;
}
