#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_data(char *filename, char **data) {
    FILE *file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *data = (char *)malloc(size);
    fread(*data, size, 1, file);
    fclose(file);
}

void write_data(char *filename, char *data) {
    FILE *file = fopen(filename, "w");
    fwrite(data, strlen(data), 1, file);
    fclose(file);
}

void migrate_database(char *source, char *destination) {
    char *source_data, *destination_data;
    read_data(source, &source_data);
    read_data(destination, &destination_data);

    char *new_data = (char *)malloc(strlen(source_data) + strlen(destination_data) + 1);
    strcpy(new_data, source_data);
    strcat(new_data, destination_data);

    write_data(destination, new_data);
    free(source_data);
    free(destination_data);
    free(new_data);
}

int main() {
    migrate_database("old_database.txt", "new_database.txt");
    migrate_database("new_database.txt", "corrupted_database.txt");
    return 0;
}
