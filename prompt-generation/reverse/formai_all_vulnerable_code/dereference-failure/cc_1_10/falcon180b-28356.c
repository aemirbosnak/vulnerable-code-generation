//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB
#define VIRUS_SIGNATURE "EICAR-STANDARD-ANTIVIRUS-TEST-FILE!"

int is_infected(const char* file_content, size_t file_size) {
    if (file_size > MAX_FILE_SIZE) {
        printf("File too large\n");
        return 1;
    }

    const char* virus_signature = VIRUS_SIGNATURE;
    size_t virus_signature_length = strlen(virus_signature);

    for (size_t i = 0; i < file_size - virus_signature_length; i++) {
        if (memcmp(file_content + i, virus_signature, virus_signature_length) == 0) {
            printf("Virus detected\n");
            return 1;
        }
    }

    printf("No virus found\n");
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* file_content = malloc(file_size + 1);
    if (!file_content) {
        printf("Memory error\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(file_content, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error reading file\n");
        free(file_content);
        fclose(file);
        return 1;
    }

    file_content[file_size] = '\0';
    is_infected(file_content, file_size);

    free(file_content);
    fclose(file);

    return 0;
}