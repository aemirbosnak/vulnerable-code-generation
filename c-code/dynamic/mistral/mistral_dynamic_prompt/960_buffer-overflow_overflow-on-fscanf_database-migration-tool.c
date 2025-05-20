#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void migrate_database(char *input_file, char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");

    char buffer[BUFFER_SIZE];
    int count = 0;

    if (in_file == NULL || out_file == NULL) {
        printf("Error: Could not open files.\n");
        return;
    }

    printf("Migrating database...\n");

    while (fgets(buffer, BUFFER_SIZE, in_file)) {
        count++;
        fprintf(out_file, "Record %d:\n%s", count, buffer);
    }

    printf("Database migration completed.\n");
    fclose(in_file);
    fclose(out_file);

    // Intentionally vulnerable code
    char malicious_input[10];
    printf("Enter the name of the next input file: ");
    fscanf(stdin, "%s", malicious_input);
    // The 'malicious_input' may contain more than BUFFER_SIZE characters, causing a buffer overflow

    migrate_database(malicious_input, "corrupted_output.txt");
}

int main() {
    migrate_database("old_database.txt", "new_database.txt");
    return 0;
}
