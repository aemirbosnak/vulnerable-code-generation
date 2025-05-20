//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char author[50];
    char title[50];
    char date[11];
    char format[10];
} Metadata;

Metadata extract_metadata(const char *filename);

int main() {
    char filename[100];
    Metadata data;

    printf("Enter the name of the file to extract metadata from:\n");
    scanf("%s", filename);

    data = extract_metadata(filename);

    printf("\nMetadata extracted from %s:\n", filename);
    printf("Author: %s\n", data.author);
    printf("Title: %s\n", data.title);
    printf("Date Created: %s\n", data.date);
    printf("File Format: %s\n", data.format);

    return 0;
}

Metadata extract_metadata(const char *filename) {
    Metadata data;
    
    // assume that metadata is stored in the first few bytes of the file
    FILE *fp = fopen(filename, "r");
    char first_line[200];
    fgets(first_line, 200, fp);

    // parse author
    sscanf(first_line, "Author: %[^\n]s", data.author);

    // parse title
    fgets(first_line, 200, fp);
    sscanf(first_line, "Title: %[^\n]s", data.title);

    // parse date
    fgets(first_line, 200, fp);
    sscanf(first_line, "Date Created: %[^\n]s", data.date);

    // parse format
    fgets(first_line, 200, fp);
    sscanf(first_line, "File Format: %[^\n]s", data.format);

    fclose(fp);

    return data;
}