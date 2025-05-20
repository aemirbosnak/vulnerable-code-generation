//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 10485760 // 10MB limit for file size

FILE *file_ptr;
char file_name[50];
char virus_signature[] = "3virus3";

void scan_file(char *file_name);

int main() {
    printf("Enter the name of file to scan: ");
    scanf("%s", file_name);

    printf("Scanning...\n");
    scan_file(file_name); // scanning file for virus signature
    printf("Scan complete.\n");

    return 0;
}

void scan_file(char *file_name) {
    file_ptr = fopen(file_name, "rb"); // opening file in binary read mode

    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // getting size of file
    fseek(file_ptr, 0L, SEEK_END);
    long int file_size = ftell(file_ptr);
    fseek(file_ptr, 0L, SEEK_SET);

    if (file_size > MAX_FILE_SIZE) {
        printf("File size exceeds maximum limit of 10MB.\n");
        return;
    }

    // allocating memory for file contents
    char *file_contents = (char*) malloc(file_size);

    fread(file_contents, file_size, 1, file_ptr); // reading contents of file

    if (strstr(file_contents, virus_signature) != NULL) { // checking for virus signature
        printf("Virus Found!\n");
    } else {
        printf("No viruses found.\n");
    }

    free(file_contents); // deallocating memory for file contents
    fclose(file_ptr); // closing file
}