//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define VIRUS_SIGNATURE "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"

bool is_virus(const char* file_data, size_t file_size) {
    const char* virus_signature = VIRUS_SIGNATURE;
    size_t virus_signature_size = strlen(virus_signature);

    if (file_size < virus_signature_size) {
        return false;
    }

    return!memcmp(file_data, virus_signature, virus_signature_size);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Error opening file: %s\n", file_path);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("File is too large: %ld bytes\n", file_size);
        fclose(file);
        return 1;
    }

    rewind(file);

    char* file_data = malloc(file_size + 1);
    if (file_data == NULL) {
        printf("Memory error\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(file_data, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error reading file: %s\n", file_path);
        free(file_data);
        fclose(file);
        return 1;
    }

    file_data[file_size] = '\0';

    if (is_virus(file_data, file_size)) {
        printf("Virus found in file: %s\n", file_path);
    } else {
        printf("File is clean: %s\n", file_path);
    }

    free(file_data);
    fclose(file);

    return 0;
}