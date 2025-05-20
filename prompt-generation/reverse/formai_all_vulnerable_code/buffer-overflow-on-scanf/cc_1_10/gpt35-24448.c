//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 500
#define MAX_CHARS 1000
#define MAX_METADATA 10

char metadata[MAX_METADATA][50]; // Holds metadata values extracted from file
int metadata_count = 0; // Keep track of number of metadata extracted

void extract_metadata(char* file_content[]);
void print_metadata();

int main(int argc, char* argv[])
{
    char* file_content[MAX_LINES];
    int line_count = 0;
    char line[MAX_CHARS];

    printf("C Metadata Extractor - Post-Apocalyptic Edition\n");
    printf("-----------------------------------------------\n");

    // Prompt user for filename
    char filename[50];
    printf("Enter file name: ");
    scanf("%s", filename);

    // Open file for reading
    FILE* fp = fopen(filename, "r");

    // If file cannot be opened, exit program
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(0);
    }

    // Read file line by line and store each line in array
    while (fgets(line, MAX_CHARS, fp) != NULL) {
        file_content[line_count] = strdup(line);
        line_count++;
    }
    fclose(fp);

    // Extract metadata from file content
    extract_metadata(file_content);

    // Print extracted metadata values
    print_metadata();

    return 0;
}

// Extract metadata from file content
void extract_metadata(char* file_content[]) {
    int i = 0;
    while (strstr(file_content[i], "METADATA:") == NULL && i < MAX_LINES) { i++; }
    if (i == MAX_LINES) { return; }
    char* metadata_str = strtok(file_content[i], ":");
    metadata_str = strtok(NULL, "\n");
    char* token = strtok(metadata_str, ",");
    while (token != NULL && metadata_count < MAX_METADATA) {
        strcpy(metadata[metadata_count], token);
        metadata_count++;
        token = strtok(NULL, ",");
    }
}

// Print metadata values
void print_metadata() {
    printf("\nMetadata Values:\n");
    for (int i = 0; i < metadata_count; i++) {
        printf("%s\n", metadata[i]);
    }
}