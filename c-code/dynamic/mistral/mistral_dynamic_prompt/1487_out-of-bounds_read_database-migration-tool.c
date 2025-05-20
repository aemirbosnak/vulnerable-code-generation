#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 10

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        size_t bytes_read = fread(buffer, sizeof(char), MAX_BUFF_SIZE - 1, file);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            fclose(file);
        } else {
            buffer[0] = '\0';
        }
    }
}

void print_database(const char *data) {
    printf("Existing data in the database:\n");
    printf("%s\n", data);
}

void write_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "%s", data);
        fclose(file);
    }
}

void migrate_data(const char *input_file, char *output_data, const char *output_file) {
    char buffer[MAX_BUFF_SIZE];
    read_file(input_file, buffer);
    strcat(output_data, buffer);
}

int main(int argc, char *argv[]) {
    char data[1] = { 0 };
    migrate_data(argv[1], data, argv[2]);
    print_database(data);
    write_to_file(argv[3], data);

    return 0;
}
