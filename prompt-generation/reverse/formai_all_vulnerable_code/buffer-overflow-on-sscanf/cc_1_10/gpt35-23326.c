//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct metadata {
    char author[MAX_SIZE];
    char title[MAX_SIZE];
    int year;
};

void extract_metadata(char *filename, struct metadata *data) {
    char str[MAX_SIZE];
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Extract author
    fgets(str, MAX_SIZE, fp);
    sscanf(str, "Author: %s", data->author);
    
    // Extract title
    fgets(str, MAX_SIZE, fp);
    sscanf(str, "Title: %[^\n]", data->title);
    
    // Extract year
    fgets(str, MAX_SIZE, fp);
    sscanf(str, "Year: %d", &data->year);

    fclose(fp);
}

int main() {
    char filename[MAX_SIZE];
    struct metadata data;

    // Get filename from user
    printf("Enter filename: ");
    fgets(filename, MAX_SIZE, stdin);
    filename[strcspn(filename, "\n")] = '\0';

    // Extract metadata from file
    extract_metadata(filename, &data);

    // Print metadata
    printf("Author: %s\n", data.author);
    printf("Title: %s\n", data.title);
    printf("Year: %d\n", data.year);

    return 0;
}