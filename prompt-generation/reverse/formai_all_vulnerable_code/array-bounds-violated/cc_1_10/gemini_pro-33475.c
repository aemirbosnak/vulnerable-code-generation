//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024
#define MAX_SIGNATURE_SIZE 1024

typedef struct {
    char *name;
    char *signature;
    int signature_size;
} VirusSignature;

typedef struct {
    char *file_name;
    char *file_data;
    int file_size;
} File;

int load_signatures(VirusSignature **signatures, int *num_signatures) {
    FILE *fp;
    char buffer[MAX_SIGNATURE_SIZE];
    int i;

    fp = fopen("signatures.txt", "r");
    if (fp == NULL) {
        return -1;
    }

    *num_signatures = 0;
    while (fgets(buffer, MAX_SIGNATURE_SIZE, fp)) {
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }

        *signatures = realloc(*signatures, (*num_signatures + 1) * sizeof(VirusSignature));
        (*signatures)[*num_signatures].name = strdup(strtok(buffer, ":"));
        (*signatures)[*num_signatures].signature = strdup(strtok(NULL, ":"));
        (*signatures)[*num_signatures].signature_size = strlen((*signatures)[*num_signatures].signature);

        (*num_signatures)++;
    }

    fclose(fp);

    return 0;
}

void free_signatures(VirusSignature *signatures, int num_signatures) {
    int i;

    for (i = 0; i < num_signatures; i++) {
        free(signatures[i].name);
        free(signatures[i].signature);
    }

    free(signatures);
}

int load_file(File *file) {
    FILE *fp;

    fp = fopen(file->file_name, "rb");
    if (fp == NULL) {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    file->file_size = ftell(fp);
    rewind(fp);

    file->file_data = malloc(file->file_size);
    if (file->file_data == NULL) {
        fclose(fp);
        return -1;
    }

    fread(file->file_data, file->file_size, 1, fp);

    fclose(fp);

    return 0;
}

void free_file(File *file) {
    free(file->file_data);
    free(file->file_name);
}

int scan_file(File *file, VirusSignature *signatures, int num_signatures) {
    int i, j;

    for (i = 0; i < num_signatures; i++) {
        for (j = 0; j < file->file_size - signatures[i].signature_size; j++) {
            if (memcmp(file->file_data + j, signatures[i].signature, signatures[i].signature_size) == 0) {
                printf("File %s is infected with virus %s\n", file->file_name, signatures[i].name);
                return 1;
            }
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    VirusSignature *signatures;
    int num_signatures;
    File file;
    int i;

    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return -1;
    }

    file.file_name = argv[1];

    if (load_signatures(&signatures, &num_signatures) != 0) {
        printf("Error loading signatures\n");
        return -1;
    }

    if (load_file(&file) != 0) {
        printf("Error loading file %s\n", file.file_name);
        free_signatures(signatures, num_signatures);
        return -1;
    }

    if (scan_file(&file, signatures, num_signatures) != 0) {
        free_file(&file);
        free_signatures(signatures, num_signatures);
        return -1;
    }

    printf("File %s is clean\n", file.file_name);

    free_file(&file);
    free_signatures(signatures, num_signatures);

    return 0;
}