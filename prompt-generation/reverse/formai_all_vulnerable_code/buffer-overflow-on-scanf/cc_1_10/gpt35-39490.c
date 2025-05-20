//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILENAME_LEN 256
#define MAX_VIRUS_SIGNATURES 10

// Global variables to store the virus signatures
char virus_signatures[MAX_VIRUS_SIGNATURES][16] = {"0x4D", "0x5A", "0xE8", "0x00", "0x00", "0x00", "0x00", "0x00", "0x00", "0x00"};
int virus_signature_lengths[MAX_VIRUS_SIGNATURES] = {2, 2, 1, 1, 1, 1, 1, 1, 1, 1};
int num_virus_signatures = 10;

// Function to check if a file contains a virus signature
int contains_virus_signature(char* filename) {
    FILE* fp;
    unsigned char file_contents[MAX_FILENAME_LEN];
    int num_bytes_read;
    int i, j;
    int result = 0;

    // Open the file in binary mode
    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    // Read the file contents into the buffer
    num_bytes_read = fread(file_contents, sizeof(unsigned char), MAX_FILENAME_LEN, fp);

    // Check if any of the virus signatures match the file contents
    for (i = 0; i < num_virus_signatures; i++) {
        for (j = 0; j < virus_signature_lengths[i]; j++) {
            if (file_contents[j] != (unsigned char) strtol(virus_signatures[i], NULL, 16)) {
                result = 0;
                break;
            }
            result = 1;
        }
        if (result == 1) {
            break;
        }
    }

    fclose(fp);

    return result;
}

int main() {
    char filenames[MAX_FILES][MAX_FILENAME_LEN];
    int num_files = 0;
    char option;
    int i;

    printf("Welcome to Retro C Antivirus Scanner!\n");
    printf("Usage:\n");
    printf("\tAdd files to scan: a <filename>\n");
    printf("\tScan files for viruses: s\n");
    printf("\tQuit: q\n");

    while (1) {
        printf("\nEnter option: ");
        scanf("%c", &option);

        switch (option) {
            case 'a':
                if (num_files < MAX_FILES) {
                    scanf("%s", filenames[num_files]);
                    printf("Added file %s to the list.\n", filenames[num_files]);
                    num_files++;
                } else {
                    printf("Error: Maximum number of files reached.\n");
                }
                break;

            case 's':
                printf("Starting virus scan...\n");
                for (i = 0; i < num_files; i++) {
                    if (contains_virus_signature(filenames[i])) {
                        printf("Virus detected in file %s!\n", filenames[i]);
                    }
                }
                printf("Scan complete.\n");
                break;

            case 'q':
                printf("Exiting Retro C Antivirus Scanner.");
                exit(0);
                break;

            default:
                printf("Invalid option.\n");
        }

        // Consume the newline character from the scanf call
        getchar(); 
    }

    return 0;
}