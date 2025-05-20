//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to read a file into memory
void read_file(char* filename, char** buffer) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    if (filesize > MAX_FILE_SIZE) {
        printf("Error: File %s is too large (%ld bytes)\n", filename, filesize);
        fclose(fp);
        exit(1);
    }

    *buffer = malloc(filesize + 1); // Allocate memory for the file contents and null terminator
    size_t bytesread = fread(*buffer, 1, filesize, fp);
    if (bytesread!= filesize) {
        printf("Error: Could not read entire file %s\n", filename);
        free(*buffer);
        fclose(fp);
        exit(1);
    }

    (*buffer)[bytesread] = '\0'; // Add null terminator
    fclose(fp);
}

// Function to scan a buffer for viruses
bool scan_buffer(char* buffer) {
    const char* virus1 = "This is a virus!";
    const char* virus2 = "I am also a virus.";

    char* token = strtok(buffer, " ");
    while (token!= NULL) {
        if (strcmp(token, virus1) == 0 || strcmp(token, virus2) == 0) {
            printf("Virus detected in file!\n");
            return true;
        }
        token = strtok(NULL, " ");
    }

    return false;
}

int main() {
    char* filename;
    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    char* buffer = NULL;
    read_file(filename, &buffer);

    if (scan_buffer(buffer)) {
        printf("File %s contains a virus.\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    free(buffer);
    return 0;
}