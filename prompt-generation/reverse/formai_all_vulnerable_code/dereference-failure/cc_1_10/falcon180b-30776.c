//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define VIRUS_SIGNATURE "VIRUS" // Change this to your desired virus signature

int is_virus(char* file_content, int file_size) {
    char* virus_signature = VIRUS_SIGNATURE;
    int virus_signature_length = strlen(virus_signature);
    int i;

    for (i = 0; i < file_size - virus_signature_length + 1; i++) {
        if (strncasecmp(file_content + i, virus_signature, virus_signature_length) == 0) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    char* file_path = argv[1];
    FILE* file = fopen(file_path, "rb");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", file_path);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit of 1 MB.\n");
        fclose(file);
        return 1;
    }

    rewind(file);
    char* file_content = (char*) malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory for file content.\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(file_content, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire file.\n");
        free(file_content);
        fclose(file);
        return 1;
    }

    file_content[file_size] = '\0'; // Add null terminator
    int is_virus_present = is_virus(file_content, file_size);

    if (is_virus_present) {
        printf("Virus detected in file '%s'.\n", file_path);
    } else {
        printf("No virus detected in file '%s'.\n", file_path);
    }

    free(file_content);
    fclose(file);
    return 0;
}