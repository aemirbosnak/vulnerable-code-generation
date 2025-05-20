//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <string.h>

// Function to scan the file for virus signature
int scan_file(char *file_name) {
    char virus_signature[] = "VIRUS_123"; // the virus signature to scan for
    char buffer[100]; // buffer to read the contents of the file

    // Open the file in binary mode
    FILE *fp = fopen(file_name, "rb");

    // Check if file was successfully opened
    if (fp == NULL) {
        printf("ERROR: File \"%s\" could not be opened.\n", file_name);
        return 0;
    }

    printf("Scanning \"%s\" for virus signature...\n", file_name);

    // Read the file in chunks of 100 bytes
    while (fread(buffer, 1, sizeof(buffer), fp) > 0) {
        // Check if virus signature is present in the buffer
        if (strstr(buffer, virus_signature) != NULL) {
            printf("Virus signature found in file \"%s\"!\n", file_name);
            fclose(fp); // Close the file
            return 1; // Virus detected
        }
    }

    fclose(fp); // Close the file
    return 0; // Virus not found
}

int main() {
    char file_name[100]; // variable to store the file name
    int virus_found = 0; // variable to track if virus was detected
    int total_files_scanned = 0; // variable to track number of files scanned

    printf("C Antivirus Scanner\n");
    printf("===================\n");

    // Infinite loop to continuously scan files
    while (1) {
        printf("\nEnter the name of the file to scan (or type \"q\" to quit): ");
        scanf("%s", file_name);

        // Check if user wants to quit
        if (strcmp(file_name, "q") == 0) {
            printf("\n*** Goodbye! ***\n");
            break;
        }

        // Scan the file for virus signature
        virus_found = scan_file(file_name);

        // Increment number of files scanned
        total_files_scanned++;

        // Print message indicating if virus was found or not
        if (virus_found == 1) {
            printf("*** Virus detected in \"%s\"! ***\n", file_name);
        } else {
            printf("No virus detected in \"%s\".\n", file_name);
        }
    }

    // Print total number of files scanned
    printf("\nTotal files scanned: %d\n", total_files_scanned);

    return 0;
}