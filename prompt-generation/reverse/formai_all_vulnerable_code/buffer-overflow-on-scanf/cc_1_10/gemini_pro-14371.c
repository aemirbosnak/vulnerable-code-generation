//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Virus signature database
char *virus_signatures[] = {
    "I love you",
    "ILoveYou",
    "LoveBug",
    "Melissa",
    "Nimda"
};

// Scan a file for viruses
int scan_file(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    // Read the file into a buffer
    char *buffer = malloc(1024);
    fread(buffer, 1024, 1, fp);
    fclose(fp);

    // Search the buffer for virus signatures
    for (int i = 0; i < sizeof(virus_signatures) / sizeof(char *); i++) {
        if (strstr(buffer, virus_signatures[i]) != NULL) {
            printf("File %s is infected with virus %s\n", filename, virus_signatures[i]);
            return 1;
        }
    }

    // No viruses found
    printf("File %s is clean\n", filename);
    return 0;
}

int main() {
    // Get the filename from the user
    char filename[100];
    printf("Enter the filename to scan: ");
    scanf("%s", filename);

    // Scan the file
    int result = scan_file(filename);

    // Print the results
    if (result == 1) {
        printf("Your love is infected with a virus. Please take precautions.\n");
    } else {
        printf("Your love is clean. Enjoy the feeling of pure love.\n");
    }

    return 0;
}