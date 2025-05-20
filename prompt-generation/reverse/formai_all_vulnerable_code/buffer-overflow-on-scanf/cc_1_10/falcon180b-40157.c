//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan file for viruses
int scan_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    unsigned char buffer[4096];
    int filesize = 0;
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        filesize += sizeof(buffer);
    }

    fclose(file);

    // Check file size
    if (filesize < 10) {
        printf("Error: File '%s' is too small to scan\n", filename);
        return 1;
    }

    // Check file signature
    char signature[8];
    memcpy(signature, buffer, 8);
    if (strcmp(signature, "VIRUS123") == 0) {
        printf("Error: File '%s' contains a virus\n", filename);
        return 1;
    }

    printf("File '%s' is clean\n", filename);
    return 0;
}

int main() {
    char filename[256];
    printf("Enter filename to scan: ");
    scanf("%s", filename);

    int result = scan_file(filename);
    if (result == 0) {
        printf("Scan completed successfully\n");
    } else {
        printf("Scan failed\n");
    }

    return result;
}