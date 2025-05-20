//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a file
void extract_metadata(FILE* file, char* filename) {
    fseek(file, 0, SEEK_SET); // Reset file position to beginning
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        if (strstr(buffer, "Title:")!= NULL) {
            printf("Title: ");
            char* title = strtok(buffer, ": ");
            title = strtok(NULL, ": ");
            printf("%s\n", title);
        }
        else if (strstr(buffer, "Author:")!= NULL) {
            printf("Author: ");
            char* author = strtok(buffer, ": ");
            author = strtok(NULL, ": ");
            printf("%s\n", author);
        }
        else if (strstr(buffer, "Date:")!= NULL) {
            printf("Date: ");
            char* date = strtok(buffer, ": ");
            date = strtok(NULL, ": ");
            printf("%s\n", date);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* filename = strdup(argv[1]);
    extract_metadata(file, filename);

    fclose(file);
    free(filename);

    return 0;
}