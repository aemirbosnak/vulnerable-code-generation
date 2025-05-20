//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size to scan in bytes

int virus_detected = 0; // Variable to keep track of whether virus is detected or not

void scan_file(char *filename, char *virus_signature) {
    FILE *fp;
    char buffer[MAX_FILE_SIZE];

    // Open the file in read-only mode
    fp = fopen(filename, "r");
    if(fp == NULL) { // If file could not be opened, return
        printf("Unable to open file: %s\n", filename);
        return;
    }

    // Read the contents of the file into the buffer
    fread(buffer, MAX_FILE_SIZE, 1, fp);

    // Check if the virus signature is present in the file
    if(strstr(buffer, virus_signature) != NULL) {
        printf("Virus detected in file: %s\n", filename);
        virus_detected = 1;
    }

    fclose(fp); // Close the file
}

int main() {
    char filename[256], virus_signature[256];

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);

    printf("Enter the virus signature to scan for: ");
    scanf("%s", virus_signature);

    // Scan the file for the virus signature
    scan_file(filename, virus_signature);

    // Display result
    if(virus_detected == 0) {
        printf("No virus detected in file: %s\n", filename);
    }

    return 0;
}