#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void recover_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (file_size == 0) {
        printf("File is empty\n");
        fclose(file);
        return;
    }

    char *buffer = malloc((file_size + 1) * sizeof(char));
    if (buffer == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return;
    }

    size_t bytes_read = fread(buffer, sizeof(char), file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return;
    }

    for (size_t i = 0; i < bytes_read; ++i) {
        if (buffer[i] < 32 || buffer[i] > 126) {
            fprintf(stderr, "Invalid ASCII character detected\n");
            free(buffer);
            fclose(file);
            return;
        }
    }

    // Vulnerability: No bounds checking on the filename length
    char output_filename[MAX_FILENAME_LENGTH];
    snprintf(output_filename, sizeof(output_filename), "%s_recovered", filename);

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error creating output file");
        free(buffer);
        fclose(file);
        return;
    }

    fwrite(buffer, sizeof(char), bytes_read, output_file);
    fclose(output_file);

    free(buffer);
    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename to recover data from: ");
    scanf("%255s", filename); // Limit input to prevent buffer overflow

    recover_data(filename);

    return 0;
}
