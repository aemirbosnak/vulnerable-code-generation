//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent metadata */
typedef struct metadata {
    char file_name[100];
    int file_size;
    char file_type[50];
    char creation_date[20];
} Metadata;

/* Define a function to extract metadata from a file */
Metadata extract_metadata(char *file_path) {
    FILE *fp;
    char line[256];
    Metadata data = {"", 0, "", ""};
    
    fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    /* Extract metadata from file */
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %s", data.file_name);
        }
        else if (strstr(line, "Size:")) {
            sscanf(line, "Size: %d", &data.file_size);
        }
        else if (strstr(line, "Type:")) {
            sscanf(line, "Type: %s", data.file_type);
        }
        else if (strstr(line, "Created On:")) {
            sscanf(line, "Created On: %s", data.creation_date);
        }
    }

    fclose(fp);
    return data;
}

int main() {
    char file_path[100];
    Metadata data;

    /* Get file path from user */
    printf("Enter file path: ");
    scanf("%s", file_path);

    /* Extract metadata from file */
    data = extract_metadata(file_path);

    /* Print extracted metadata */
    printf("\nFile Name: %s\n", data.file_name);
    printf("File Size: %d bytes\n", data.file_size);
    printf("File Type: %s\n", data.file_type);
    printf("Creation Date: %s\n", data.creation_date);

    return 0;
}