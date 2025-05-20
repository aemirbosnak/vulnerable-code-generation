#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 10

void write_to_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fputs(data, file);
        fclose(file);
    }
}

void read_from_file(const char *filename, char *buffer, size_t size) {
    FILE *file = fopen(filename, "r");
    if (file) {
        size_t bytes_read = fread(buffer, sizeof(char), size, file);
        fclose(file);
        buffer[bytes_read] = '\0';
    } else {
        buffer[0] = '\0';
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file> <data>\n", argv[0]);
        return 1;
    }

    char input_file[256];
    char output_file[256];
    char data[BUFFER_SIZE];

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
    strncpy(data, argv[3], BUFFER_SIZE);

    write_to_file(input_file, data);
    char buffer[1024];
    read_from_file(output_file, buffer, sizeof(buffer));
    printf("Read from file: %s\n", buffer);

    return 0;
}
