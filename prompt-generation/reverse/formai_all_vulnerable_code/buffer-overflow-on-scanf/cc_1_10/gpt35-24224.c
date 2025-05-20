//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void extractMetadata(char *filename);

int main() {
    char filename[MAX_LENGTH];

    printf("Enter the name of the file to extract metadata from: ");
    scanf("%s", filename);

    extractMetadata(filename);

    return 0;
}

void extractMetadata(char *filename) {
    FILE *fptr;
    char line[MAX_LENGTH], *token;
    int length;

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening the file!\n");
        exit(1);
    }

    printf("Metadata extracted from file '%s':\n", filename);

    while (fgets(line, MAX_LENGTH, fptr)) {
        token = strtok(line, ":");

        if (strcmp(token, "Title") == 0) {
            token = strtok(NULL, "\n");
            printf("Title: %s\n", token);
        } else if (strcmp(token, "Artist") == 0) {
            token = strtok(NULL, "\n");
            printf("Artist: %s\n", token);
        } else if (strcmp(token, "Album") == 0) {
            token = strtok(NULL, "\n");
            printf("Album: %s\n", token);
        } else if (strcmp(token, "Genre") == 0) {
            token = strtok(NULL, "\n");
            printf("Genre: %s\n", token);
        } else if (strcmp(token, "Year") == 0) {
            token = strtok(NULL, "\n");
            printf("Year: %s\n", token);
        }
    }

    fclose(fptr);
}