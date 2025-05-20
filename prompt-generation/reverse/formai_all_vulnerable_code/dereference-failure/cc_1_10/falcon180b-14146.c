//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024*1024*10) // 10 MB
#define VIRUS_SIGNATURE "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*"

int is_virus(char *file_content, int file_size) {
    char *virus_signature = VIRUS_SIGNATURE;
    int virus_signature_size = strlen(virus_signature);

    if (file_size < virus_signature_size) {
        return 0;
    }

    for (int i = 0; i < virus_signature_size; i++) {
        if (file_content[i]!= virus_signature[i]) {
            return 0;
        }
    }

    return 1;
}

void scan_file(char *filename) {
    FILE *file;
    char *file_content = NULL;
    long file_size;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File '%s' is too large (%ld bytes).\n", filename, file_size);
        fclose(file);
        return;
    }

    rewind(file);
    file_content = malloc(file_size + 1);
    if (file_content == NULL) {
        printf("Error: Could not allocate memory for file '%s'.\n", filename);
        fclose(file);
        return;
    }

    fread(file_content, file_size, 1, file);
    file_content[file_size] = '\0';

    if (is_virus(file_content, file_size)) {
        printf("Virus detected in file '%s'.\n", filename);
    } else {
        printf("No virus detected in file '%s'.\n", filename);
    }

    free(file_content);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    scan_file(argv[1]);

    return 0;
}