//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define VIRUS_SIGNATURE "This is a virus!"
#define MAX_FILE_SIZE 1000000 // 1MB

typedef struct {
    char *name;
    char *data;
    size_t size;
} File;

int is_virus(const char *data, size_t size) {
    const char *signature = VIRUS_SIGNATURE;
    size_t signature_size = strlen(signature);

    for (size_t i = 0; i <= size - signature_size; i++) {
        if (strncmp(data + i, signature, signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

void scan_file(const char *filename) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large: %s\n", filename);
        fclose(file);
        return;
    }

    rewind(file);
    File file_data = {filename, NULL, 0};

    if (fread(file_data.data, 1, file_size, file)!= file_size) {
        printf("Error reading file: %s\n", filename);
        free(file_data.data);
        fclose(file);
        return;
    }

    if (is_virus(file_data.data, file_size)) {
        printf("Virus found in %s\n", filename);
    } else {
        printf("No virus found in %s\n", filename);
    }

    free(file_data.data);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}