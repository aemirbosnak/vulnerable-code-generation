//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10 MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} File;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    File file = {0};
    file.name = argv[1];

    FILE *fp = fopen(file.name, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", file.name);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    file.size = ftell(fp);
    if (file.size > MAX_FILE_SIZE) {
        printf("Error: file is too large (%zu bytes)\n", file.size);
        fclose(fp);
        return 1;
    }

    fseek(fp, 0, SEEK_SET);
    file.data = malloc(file.size);
    if (!file.data) {
        printf("Error: could not allocate memory for file data\n");
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(file.data, 1, file.size, fp);
    if (bytes_read!= file.size) {
        printf("Error: could not read entire file\n");
        free(file.data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    int virus_found = 0;
    char *virus_name = "EICAR-Test-File";
    size_t virus_size = strlen(virus_name);

    for (size_t i = 0; i < file.size - virus_size; i++) {
        if (memcmp(file.data + i, virus_name, virus_size) == 0) {
            printf("Virus found: %s\n", virus_name);
            virus_found = 1;
        }
    }

    if (!virus_found) {
        printf("No virus found\n");
    }

    free(file.data);
    return 0;
}