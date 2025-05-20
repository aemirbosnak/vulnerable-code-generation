//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000

// Function to extract metadata from a file
void extract_metadata(FILE *fp, char *filename) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        // Extracting file size
        if (strstr(line, "File size:")!= NULL) {
            char *ptr = strstr(line, ":");
            int size = atoi(ptr + 1);
            printf("File size: %d bytes\n", size);
        }
        // Extracting file type
        else if (strstr(line, "File type:")!= NULL) {
            char *ptr = strstr(line, ":");
            char file_type[20];
            strncpy(file_type, ptr + 1, strlen(ptr + 1));
            printf("File type: %s\n", file_type);
        }
        // Extracting creation date
        else if (strstr(line, "Created:")!= NULL) {
            char *ptr = strstr(line, ":");
            char date[20];
            strncpy(date, ptr + 1, strlen(ptr + 1));
            printf("Created: %s\n", date);
        }
        // Extracting last modified date
        else if (strstr(line, "Modified:")!= NULL) {
            char *ptr = strstr(line, ":");
            char date[20];
            strncpy(date, ptr + 1, strlen(ptr + 1));
            printf("Last modified: %s\n", date);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    extract_metadata(fp, filename);

    fclose(fp);
    return 0;
}