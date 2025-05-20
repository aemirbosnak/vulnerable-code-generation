//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

// Function to read file into memory
char* read_file(const char* filename, size_t* filesize) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    *filesize = ftell(fp);
    rewind(fp);

    char* buffer = (char*) malloc(*filesize + 1);
    if (buffer == NULL) {
        fclose(fp);
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, *filesize, fp);
    if (bytes_read!= *filesize) {
        free(buffer);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    buffer[*filesize] = '\0'; // null terminate string
    return buffer;
}

// Function to scan file for viruses
int scan_file(const char* filename, const char* virus_signature) {
    char* file_contents = read_file(filename, NULL);
    if (file_contents == NULL) {
        return -1;
    }

    size_t file_size = strlen(file_contents);
    size_t signature_size = strlen(virus_signature);

    for (size_t i = 0; i <= file_size - signature_size; i++) {
        if (memcmp(file_contents + i, virus_signature, signature_size) == 0) {
            printf("Virus detected in file: %s\n", filename);
            return 1;
        }
    }

    printf("No virus detected in file: %s\n", filename);
    return 0;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <virus_signature>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    const char* virus_signature = argv[2];

    scan_file(filename, virus_signature);

    return 0;
}