//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to extract metadata from C file
void extract_metadata(FILE *fp) {
    char ch;
    int count = 0;

    // Extract file name
    rewind(fp);
    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            break;
        }
        if (count == 0) {
            printf("File name: ");
        }
        printf("%c", ch);
        count++;
    }
    printf("\n");

    // Extract author name
    count = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            break;
        }
        if (count == 0) {
            printf("Author name: ");
        }
        printf("%c", ch);
        count++;
    }
    printf("\n");

    // Extract creation date
    count = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            break;
        }
        if (count == 0) {
            printf("Creation date: ");
        }
        printf("%c", ch);
        count++;
    }
    printf("\n");
}

int main() {
    FILE *fp;
    char filename[100];

    // Get file name from user
    printf("Enter the name of the C file: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("File not found.\n");
        exit(0);
    }

    // Extract metadata from file
    extract_metadata(fp);

    // Close file
    fclose(fp);

    return 0;
}