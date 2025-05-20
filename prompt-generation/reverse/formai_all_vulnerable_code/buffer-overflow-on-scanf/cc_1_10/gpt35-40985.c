//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct Metadata {
    char title[MAX_STRING_LENGTH];
    char artist[MAX_STRING_LENGTH];
    char album[MAX_STRING_LENGTH];
    int year;
} Metadata;

int main() {
    // Allocate memory for metadata
    Metadata *metadata = (Metadata *) malloc(sizeof(Metadata));
    if (metadata == NULL) {
        printf("Error: Could not allocate memory for metadata\n");
        return 1;
    }

    // Get title from user
    printf("Enter title: ");
    fgets(metadata->title, MAX_STRING_LENGTH, stdin);
    metadata->title[strcspn(metadata->title, "\n")] = '\0';

    // Get artist from user
    printf("Enter artist: ");
    fgets(metadata->artist, MAX_STRING_LENGTH, stdin);
    metadata->artist[strcspn(metadata->artist, "\n")] = '\0';

    // Get album from user
    printf("Enter album: ");
    fgets(metadata->album, MAX_STRING_LENGTH, stdin);
    metadata->album[strcspn(metadata->album, "\n")] = '\0';

    // Get year from user
    printf("Enter year: ");
    while (scanf("%d", &metadata->year) != 1) {
        // If user input is invalid, clear input buffer
        scanf("%*[^\n]");
        printf("Invalid input. Enter year: ");
    }

    // Print metadata
    printf("\nTitle: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %d\n", metadata->year);

    // Free memory
    free(metadata);

    return 0;
}