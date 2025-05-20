//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (10 * 1024 * 1024) // 10MB
#define MAX_VIRUS_SIGNATURES 100

typedef struct {
    char *name;
    char *signature;
} virus_signature;

int num_signatures = 0;
virus_signature *signatures = NULL;

void add_signature(char *name, char *signature) {
    signatures = realloc(signatures, sizeof(virus_signature) * ++num_signatures);
    signatures[num_signatures - 1].name = strdup(name);
    signatures[num_signatures - 1].signature = strdup(signature);
}

int scan_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file);
    fclose(file);

    if (ferror(file)) {
        printf("Error: Could not read file '%s'\n", filename);
        return 1;
    }

    for (int i = 0; i < num_signatures; i++) {
        virus_signature *signature = &signatures[i];
        char * virus_signature_buffer = strstr(buffer, signature->signature);
        if (virus_signature_buffer!= NULL) {
            printf("Virus detected in file '%s': %s\n", filename, signature->name);
            return 1;
        }
    }

    printf("File '%s' is clean.\n", filename);
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    add_signature("EICAR", "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*");

    int result = scan_file(argv[1]);

    return result;
}