//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for metadata
typedef struct metadata {
    char title[100];
    char author[50];
    char date[20];
    char keywords[200];
} metadata;

// Function to extract metadata from file
metadata extract_metadata(char* filename) {
    metadata meta;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        exit(1);
    }
    char line[200];
    while (fgets(line, 200, file)!= NULL) {
        if (strstr(line, "title")!= NULL) {
            strcpy(meta.title, strtok(line, ":"));
        } else if (strstr(line, "author")!= NULL) {
            strcpy(meta.author, strtok(line, ":"));
        } else if (strstr(line, "date")!= NULL) {
            strcpy(meta.date, strtok(line, ":"));
        } else if (strstr(line, "keywords")!= NULL) {
            strcpy(meta.keywords, strtok(line, ":"));
        }
    }
    fclose(file);
    return meta;
}

// Function to print metadata
void print_metadata(metadata meta) {
    printf("Title: %s\n", meta.title);
    printf("Author: %s\n", meta.author);
    printf("Date: %s\n", meta.date);
    printf("Keywords: %s\n", meta.keywords);
}

int main() {
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);
    metadata meta = extract_metadata(filename);
    print_metadata(meta);
    return 0;
}