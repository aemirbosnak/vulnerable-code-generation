//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    char keywords[200];
    char description[300];
    int publicationYear;
} Metadata;

// Function prototypes
void gatherMetadata(Metadata *meta);
void displayMetadata(const Metadata *meta);
void saveMetadata(const Metadata *meta, const char *filename);
void loadMetadata(Metadata *meta, const char *filename);

int main() {
    Metadata meta;
    int choice;
    char filename[50];

    printf("Welcome to the Metadata Extractor!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Gather Metadata\n");
        printf("2. Display Metadata\n");
        printf("3. Save Metadata to File\n");
        printf("4. Load Metadata from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline from input buffer

        switch (choice) {
            case 1:
                gatherMetadata(&meta);
                break;
            case 2:
                displayMetadata(&meta);
                break;
            case 3:
                printf("Enter filename to save metadata: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                saveMetadata(&meta, filename);
                break;
            case 4:
                printf("Enter filename to load metadata: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;  // Remove newline
                loadMetadata(&meta, filename);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void gatherMetadata(Metadata *meta) {
    printf("Enter the title: ");
    fgets(meta->title, sizeof(meta->title), stdin);
    meta->title[strcspn(meta->title, "\n")] = 0;  // Remove newline

    printf("Enter the author: ");
    fgets(meta->author, sizeof(meta->author), stdin);
    meta->author[strcspn(meta->author, "\n")] = 0;  // Remove newline

    printf("Enter keywords (comma separated): ");
    fgets(meta->keywords, sizeof(meta->keywords), stdin);
    meta->keywords[strcspn(meta->keywords, "\n")] = 0;  // Remove newline

    printf("Enter a brief description: ");
    fgets(meta->description, sizeof(meta->description), stdin);
    meta->description[strcspn(meta->description, "\n")] = 0;  // Remove newline

    printf("Enter the publication year: ");
    scanf("%d", &meta->publicationYear);
    getchar();  // Clear the newline from input buffer

    printf("Metadata gathered successfully!\n");
}

void displayMetadata(const Metadata *meta) {
    printf("\n--- Metadata Information ---\n");
    printf("Title: %s\n", meta->title);
    printf("Author: %s\n", meta->author);
    printf("Keywords: %s\n", meta->keywords);
    printf("Description: %s\n", meta->description);
    printf("Publication Year: %d\n", meta->publicationYear);
}

void saveMetadata(const Metadata *meta, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(file, "Title: %s\n", meta->title);
    fprintf(file, "Author: %s\n", meta->author);
    fprintf(file, "Keywords: %s\n", meta->keywords);
    fprintf(file, "Description: %s\n", meta->description);
    fprintf(file, "Publication Year: %d\n", meta->publicationYear);

    fclose(file);
    printf("Metadata saved successfully to %s\n", filename);
}

void loadMetadata(Metadata *meta, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    fscanf(file, "Title: %[^\n]\n", meta->title);
    fscanf(file, "Author: %[^\n]\n", meta->author);
    fscanf(file, "Keywords: %[^\n]\n", meta->keywords);
    fscanf(file, "Description: %[^\n]\n", meta->description);
    fscanf(file, "Publication Year: %d\n", &meta->publicationYear);

    fclose(file);
    printf("Metadata loaded successfully from %s\n", filename);
}