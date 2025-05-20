//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Define the maximum size of a virus signature
#define MAX_SIGNATURE_SIZE 1024

// Define the number of virus signatures to check for
#define NUM_SIGNATURES 5

// Define the virus signatures
const char *virus_signatures[NUM_SIGNATURES] = {
    "EICAR_TEST_FILE",
    "W95.CIH",
    "Melissa.A",
    "ILOVEYOU",
    "AnnaKournikova"
};

// Scan a file for viruses
int scan_file(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *buffer = malloc(file_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return 1;
    }
    fread(buffer, file_size, 1, fp);
    fclose(fp);

    // Scan the buffer for virus signatures
    for (int i = 0; i < NUM_SIGNATURES; i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            printf("Virus detected: %s\n", virus_signatures[i]);
            free(buffer);
            return 1;
        }
    }

    // No viruses detected
    free(buffer);
    return 0;
}

// Main function
int main() {
    // Get the filename from the user
    char filename[256];
    printf("Enter the filename to scan: ");
    scanf("%s", filename);

    // Scan the file for viruses
    int result = scan_file(filename);

    // Print the results
    if (result == 0) {
        printf("No viruses detected\n");
    }

    return 0;
}