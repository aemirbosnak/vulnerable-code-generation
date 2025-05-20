#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 10485760 // 10MB

int main(int argc, char *argv[]) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *filename;
    long file_size;
    size_t bytes_read;

    if (argc != 3) {
        printf("Usage: %s <filename> <filecontent>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "w");

    if (!fp) {
        perror("Error opening file");
        return 2;
    }

    file_size = strlen(argv[2]) + 1;

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds maximum limit of 10MB.\n");
        return 3;
    }

    // Read input and write to file without bounds checking
    while ((bytes_read = getline(&buffer, sizeof(buffer), stdin)) != -1) {
        fputs(buffer, fp);
    }

    fclose(fp);

    printf("File '%s' has been created successfully.\n", filename);
    return 0;
}
