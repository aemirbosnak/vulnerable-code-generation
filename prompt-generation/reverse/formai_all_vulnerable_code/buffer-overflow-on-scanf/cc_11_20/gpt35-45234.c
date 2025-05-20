//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program will extract metadata from a given C file */
int main() {
    char file_name[100], line[100], author[100], date[100], version[100];
    FILE *fp;

    printf("Enter the name of the file to extract metadata from: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "r");

    if (fp == NULL) {  // Check if file exists
        printf("Error opening file. Exiting program.");
        exit(0);
    }
    else {
        while (fgets(line, 100, fp) != NULL) {  // Read each line of file
            if (strstr(line, "Author: ")) {  // Check for author metadata
                strcpy(author, line + 8);  // Copy author name to string
                // Remove newline character at end of string
                author[strcspn(author, "\n")] = 0;
            }
            else if (strstr(line, "Date: ")) {  // Check for date metadata
                strcpy(date, line + 6);  // Copy date to string
                // Remove newline character at end of string
                date[strcspn(date, "\n")] = 0;
            }
            else if (strstr(line, "Version: ")) {  // Check for version metadata
                strcpy(version, line + 9);  // Copy version to string
                // Remove newline character at end of string
                version[strcspn(version, "\n")] = 0;
            }
        }

        fclose(fp);  // Close file

        // Print extracted metadata
        printf("Metadata extracted from file: %s\n", file_name);
        if (strlen(author) > 0) {
            printf("Author: %s\n", author);
        }
        if (strlen(date) > 0) {
            printf("Date: %s\n", date);
        }
        if (strlen(version) > 0) {
            printf("Version: %s\n", version);
        }
        if (strlen(author) == 0 && strlen(date) == 0 && strlen(version) == 0) {
            printf("No metadata found in file.\n");
        }
    }

    return 0;
}