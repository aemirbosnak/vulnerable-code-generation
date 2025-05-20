//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VIRUS_LENGTH 1000

// Function to compare two strings (case insensitive)
int strcasecmp(const char* str1, const char* str2) {
    char c1, c2;

    while ((c1 = tolower(*str1)) && (c2 = tolower(*str2))) {
        if (c1!= c2) {
            return c1 - c2;
        }
        str1++;
        str2++;
    }

    return 0;
}

// Function to scan a file for viruses
int scanFile(const char* filename) {
    FILE* file;
    char line[MAX_VIRUS_LENGTH];
    char* virus = "This is a virus!";
    size_t virusLen = strlen(virus);
    size_t lineLen;

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read the file line by line
    while (fgets(line, MAX_VIRUS_LENGTH, file)!= NULL) {
        lineLen = strlen(line);

        // Check if the line contains the virus
        if (strcasecmp(line, virus) == 0) {
            printf("Virus found in file %s\n", filename);
            return 1;
        }
    }

    // Close the file
    fclose(file);

    return 0;
}

int main() {
    char filename[100];

    // Get the filename from the user
    printf("Enter the filename to scan: ");
    scanf("%s", filename);

    // Scan the file for viruses
    if (scanFile(filename) == 1) {
        printf("File %s is infected with a virus.\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }

    return 0;
}