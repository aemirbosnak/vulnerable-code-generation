//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to extract metadata from a C file
void extract_metadata(char* file_path) {
    // Open file
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    // Extract metadata
    char line[MAX_SIZE];
    char name[MAX_SIZE];
    char date[MAX_SIZE];
    char time[MAX_SIZE];
    char author[MAX_SIZE];
    char email[MAX_SIZE];
    char description[MAX_SIZE];
    int count = 0;

    while (fgets(line, MAX_SIZE, file)) {
        if (strncmp(line, "/* Name:", 8) == 0) {
            sscanf(line, "/* Name: %[^\n]s", name);
            count++;
        }
        else if (strncmp(line, "/* Date:", 8) == 0) {
            sscanf(line, "/* Date: %[^\n]s", date);
            count++;
        }
        else if (strncmp(line, "/* Time:", 8) == 0) {
            sscanf(line, "/* Time: %[^\n]s", time);
            count++;
        }
        else if (strncmp(line, "/* Author:", 10) == 0) {
            sscanf(line, "/* Author: %[^\n]s", author);
            count++;
        }
        else if (strncmp(line, "/* Email:", 9) == 0) {
            sscanf(line, "/* Email: %[^\n]s", email);
            count++;
        }
        else if (strncmp(line, "/* Description:", 15) == 0) {
            sscanf(line, "/* Description: %[^\n]s", description);
            count++;
        }
        
        if (count == 6) {
            break;
        }
    }

    // Close file
    fclose(file);

    // Print metadata
    printf("Name: %s\n", name);
    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Author: %s\n", author);
    printf("Email: %s\n", email);
    printf("Description: %s\n", description);
}

int main() {
    char* file_path = "example.c";
    extract_metadata(file_path);
    return 0;
}