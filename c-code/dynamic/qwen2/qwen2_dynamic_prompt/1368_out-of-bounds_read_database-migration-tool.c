#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void migrate_data(char *source, char *destination) {
    char buffer[BUFFER_SIZE];
    int i;

    // Simulate reading data from source file
    FILE *src_file = fopen(source, "r");
    if (!src_file) {
        perror("Error opening source file");
        return;
    }

    // Read data into buffer
    fread(buffer, sizeof(char), BUFFER_SIZE, src_file);
    fclose(src_file);

    // Intentional out-of-bounds read vulnerability
    printf("Data read: %s\n", buffer);
    printf("Intentionally accessing out-of-bounds memory: %c\n", buffer[BUFFER_SIZE]);

    // Simulate writing data to destination file
    FILE *dest_file = fopen(destination, "w");
    if (!dest_file) {
        perror("Error opening destination file");
        return;
    }

    fwrite(buffer, sizeof(char), strlen(buffer), dest_file);
    fclose(dest_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
