//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LEN 100
#define MAX_FILE_LEN 1024

// Function to read a file and store its contents in a buffer
void read_file(char *filename, char *buffer) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer[size] = '\0';
    fread(buffer, size, 1, fp);

    fclose(fp);
}

// Function to scan the buffer for a virus
int scan_buffer(char *buffer, char *virus) {
    int len = strlen(buffer);
    int virus_len = strlen(virus);

    // Check if the buffer is too short to contain the virus
    if (len < virus_len) {
        return 0;
    }

    // Check if the virus is present in the buffer
    for (int i = 0; i <= len - virus_len; i++) {
        if (strncmp(buffer + i, virus, virus_len) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to print a message and exit the program
void error_exit(char *message) {
    printf("%s\n", message);
    exit(1);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        error_exit("Usage:./antivirus FILENAME VIRUS");
    }

    char filename[MAX_FILE_LEN];
    strcpy(filename, argv[1]);

    char virus[MAX_VIRUS_LEN];
    strcpy(virus, argv[2]);

    char buffer[MAX_FILE_LEN];
    read_file(filename, buffer);

    if (scan_buffer(buffer, virus)) {
        printf("Virus found in file %s\n", filename);
    } else {
        printf("File %s is clean\n", filename);
    }

    return 0;
}