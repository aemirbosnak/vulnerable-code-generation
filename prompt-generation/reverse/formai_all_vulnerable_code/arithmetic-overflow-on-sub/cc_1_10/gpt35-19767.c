//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Donald Knuth
/* C Antivirus Scanner Example Program in Donald Knuth style */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_VIRUS_LEN 1024

/* Global Variables */
char virus_signature[] = {0x75, 0x67, 0x75, 0x69, 0x68, 0x2d, 0x62, 0x6c, 0x65, 0x65, 0x64};
int virus_signature_len = 11;

/* Function Declarations */
void scan_file(char *filename);
int is_virus_signature(char *buffer, int buflen);

/* Main Function */
int main(int argc, char **argv) {
    /* Check if a filename was specified */
    if (argc < 2) {
        printf("Error: No filename specified\n");
        exit(EXIT_FAILURE);
    }
    char *filename = argv[1];
    /* Scan the file */
    scan_file(filename);
    return 0;
}

/* Scan a file for viruses */
void scan_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    /* Read the file into a buffer */
    fseek(file, 0, SEEK_END);
    int filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = (char*) malloc(filesize);
    fread(buffer, 1, filesize, file);
    /* Check if the buffer contains the virus signature */
    if (is_virus_signature(buffer, filesize)) {
        printf("Warning: %s contains a virus\n", filename);
    }
    else {
        printf("%s is clean\n", filename);
    }
    /* Free allocated memory and close file */
    free(buffer);
    fclose(file);
}

/* Check if a buffer contains the virus signature */
int is_virus_signature(char *buffer, int buflen) {
    for (int i = 0; i < buflen - virus_signature_len; i++) {
        int found = 1;
        for (int j = 0; j < virus_signature_len; j++) {
            if (buffer[i+j] != virus_signature[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            return 1;
        }
    }
    return 0;
}