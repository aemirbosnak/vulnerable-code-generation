//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024 * 1024) // 1MB

// Function to read file contents into memory
void read_file(FILE *fp, char **buffer, size_t *size) {
    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    rewind(fp);
    *buffer = malloc(*size + 1);
    fread(*buffer, *size, 1, fp);
    (*buffer)[*size] = '\0';
}

// Function to check if a string contains only alphanumeric characters
bool is_alphanumeric(const char *str) {
    while (*str) {
        if (!isalnum(*str)) {
            return false;
        }
        str++;
    }
    return true;
}

// Function to scan for viruses using Shannon entropy
double scan_for_viruses(const char *filename) {
    FILE *fp;
    char *buffer;
    size_t size;
    double entropy = 0.0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    read_file(fp, &buffer, &size);
    fclose(fp);

    // Calculate Shannon entropy
    for (size_t i = 0; i < size; i++) {
        if (isalnum(buffer[i])) {
            entropy += log2(1.0 / 26.0); // Assume English alphabet
        } else {
            entropy += log2(1.0 / 256.0); // Assume ASCII characters
        }
    }

    free(buffer);

    return entropy;
}

int main() {
    char filename[256];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    double entropy = scan_for_viruses(filename);

    if (entropy == -1) {
        printf("Error scanning file\n");
    } else if (entropy > 7.0) {
        printf("File is likely infected with a virus\n");
    } else {
        printf("File is clean\n");
    }

    return 0;
}