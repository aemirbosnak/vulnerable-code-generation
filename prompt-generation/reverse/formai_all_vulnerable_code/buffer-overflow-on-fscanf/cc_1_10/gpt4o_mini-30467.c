//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    char genre[50];
    int year;
} Metadata;

void initializeMetadata(Metadata *metadata, const char *title, const char *author, const char *genre, int year) {
    strncpy(metadata->title, title, sizeof(metadata->title) - 1);
    metadata->title[sizeof(metadata->title) - 1] = '\0';
    
    strncpy(metadata->author, author, sizeof(metadata->author) - 1);
    metadata->author[sizeof(metadata->author) - 1] = '\0';
    
    strncpy(metadata->genre, genre, sizeof(metadata->genre) - 1);
    metadata->genre[sizeof(metadata->genre) - 1] = '\0';
    
    metadata->year = year;
}

void printMetadata(const Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Author: %s\n", metadata->author);
    printf("Genre: %s\n", metadata->genre);
    printf("Year: %d\n", metadata->year);
}

void writeMetadataToFile(const Metadata *metadata, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fprintf(file, "Title: %s\n", metadata->title);
    fprintf(file, "Author: %s\n", metadata->author);
    fprintf(file, "Genre: %s\n", metadata->genre);
    fprintf(file, "Year: %d\n", metadata->year);
    
    fclose(file);
}

void readMetadataFromFile(Metadata *metadata, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fscanf(file, "Title: %[^\n]\n", metadata->title);
    fscanf(file, "Author: %[^\n]\n", metadata->author);
    fscanf(file, "Genre: %[^\n]\n", metadata->genre);
    fscanf(file, "Year: %d\n", &metadata->year);
    
    fclose(file);
}

int main() {
    Metadata library[5];
    int choice, year;
    char title[100], author[100], genre[50], filename[100];
    
    while (1) {
        printf("\nMetadata Manager Menu:\n");
        printf("1. Add Metadata\n");
        printf("2. View Metadata\n");
        printf("3. Save Metadata to File\n");
        printf("4. Load Metadata from File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character
        
        switch (choice) {
            case 1:
                for (int i = 0; i < 5; ++i) {
                    printf("Enter title: ");
                    fgets(title, sizeof(title), stdin);
                    title[strcspn(title, "\n")] = 0; // Remove newline character

                    printf("Enter author: ");
                    fgets(author, sizeof(author), stdin);
                    author[strcspn(author, "\n")] = 0;

                    printf("Enter genre: ");
                    fgets(genre, sizeof(genre), stdin);
                    genre[strcspn(genre, "\n")] = 0;

                    printf("Enter year: ");
                    scanf("%d", &year);
                    getchar(); // To consume the newline character
                    
                    initializeMetadata(&library[i], title, author, genre, year);
                }
                break;
                
            case 2:
                printf("Library Metadata:\n");
                for (int i = 0; i < 5; ++i) {
                    printf("\nEntry %d:\n", i + 1);
                    printMetadata(&library[i]);
                }
                break;
                
            case 3:
                printf("Enter filename to save metadata: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                writeMetadataToFile(library, filename);
                printf("Metadata saved to %s successfully.\n", filename);
                break;
                
            case 4:
                printf("Enter filename to load metadata: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline character
                for (int i = 0; i < 5; ++i) {
                    readMetadataFromFile(&library[i], filename);
                }
                printf("Metadata loaded from %s successfully.\n", filename);
                break;
                
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}