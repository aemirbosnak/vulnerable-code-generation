//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define VIRUS_SIGNATURE "VIRUS"
#define VIRUS_SIZE 4

int is_virus(char* file_content, int file_size) {
    char* virus_signature = (char*) malloc(VIRUS_SIZE * sizeof(char));
    strncpy(virus_signature, VIRUS_SIGNATURE, VIRUS_SIZE - 1);
    virus_signature[VIRUS_SIZE - 1] = '\0';

    int i;
    for (i = 0; i < file_size - VIRUS_SIZE + 1; i++) {
        if (strncmp(file_content + i, virus_signature, VIRUS_SIZE) == 0) {
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

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    if (file_size == -1 || file_size > MAX_FILE_SIZE) {
        printf("File '%s' is too large or could not be read.\n", argv[1]);
        fclose(file);
        return 1;
    }

    char* file_content = (char*) malloc(file_size * sizeof(char));
    if (file_content == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    if (fread(file_content, file_size, 1, file)!= 1) {
        printf("Error reading file '%s'.\n", argv[1]);
        free(file_content);
        fclose(file);
        return 1;
    }

    int is_infected = is_virus(file_content, file_size);
    if (is_infected) {
        printf("File '%s' is infected with a virus.\n", argv[1]);
    } else {
        printf("File '%s' is clean.\n", argv[1]);
    }

    free(file_content);
    fclose(file);
    return 0;
}