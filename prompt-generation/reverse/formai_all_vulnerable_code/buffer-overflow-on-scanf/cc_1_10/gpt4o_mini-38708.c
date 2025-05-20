//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold metadata information
typedef struct {
    char title[256];
    char artist[256];
    char album[256];
    int year;
} Metadata;

// Function prototypes
void print_metadata(Metadata *md);
void extract_metadata(const char *filename, Metadata *md);
void display_menu();
void list_files(const char *directory, const char *extension);

int main() {
    char filename[256];
    Metadata metadata;
    int choice;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume newline character

        switch (choice) {
            case 1:
                printf("Enter the file name (with extension): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Strip newline

                extract_metadata(filename, &metadata);
                print_metadata(&metadata);
                break;
            case 2:
                list_files(".", ".mp3");
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void print_metadata(Metadata *md) {
    printf("\n--- Metadata Extractor ---\n");
    printf("Title:  %s\n", md->title);
    printf("Artist: %s\n", md->artist);
    printf("Album:  %s\n", md->album);
    printf("Year:   %d\n", md->year);
    printf("--------------------------\n");
}

void extract_metadata(const char *filename, Metadata *md) {
    // Simulated extraction: In a real scenario, actual file reading and parsing would be done.
    // Hardcoding static values for illustration purpose.
    strcpy(md->title, "Sample Title");
    strcpy(md->artist, "Sample Artist");
    strcpy(md->album, "Sample Album");
    md->year = 2021;

    // In real life, you would read from the MP3 file and populate the metadata structure.
    printf("Extracting metadata from %s...\n", filename);
}

void display_menu() {
    printf("\n--- Welcome to Metadata Extractor ---\n");
    printf("1. Extract metadata from a file\n");
    printf("2. List MP3 files in the current directory\n");
    printf("3. Exit\n");
}

void list_files(const char *directory, const char *extension) {
    printf("\n--- Listing Files ---\n");
    // Using system command as a workaround
    char command[512];
    snprintf(command, sizeof(command), "find %s -name '*%s'", directory, extension);
    system(command);
    printf("---------------------\n");
}