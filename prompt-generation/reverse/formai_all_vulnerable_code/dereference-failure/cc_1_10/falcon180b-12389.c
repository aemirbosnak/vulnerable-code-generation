//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB
#define VIRUS_SIGNATURE "POSTAPOCALYPSE"

int is_infected(char* file_content, int content_size) {
    char* virus_signature = VIRUS_SIGNATURE;
    int signature_size = strlen(virus_signature);

    for (int i = 0; i < content_size - signature_size; i++) {
        if (memcmp(file_content + i, virus_signature, signature_size) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [FILE]\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 2;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File is too large (%ld bytes).\n", file_size);
        fclose(file);
        return 3;
    }

    rewind(file);
    char* file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(file);
        return 4;
    }

    size_t bytes_read = fread(file_content, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error: Could not read file.\n");
        free(file_content);
        fclose(file);
        return 5;
    }

    file_content[file_size] = 0; // null-terminate string
    int is_infected_result = is_infected(file_content, file_size);

    if (is_infected_result) {
        printf("Warning: File is infected with the '%s' virus.\n", VIRUS_SIGNATURE);
    } else {
        printf("File is clean.\n");
    }

    free(file_content);
    fclose(file);

    return 0;
}