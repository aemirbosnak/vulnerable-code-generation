//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int year;
    char genre[30];
} Manuscript;

void displayManuscriptInfo(Manuscript *ms) {
    printf("\nBehold the Manuscript of Yore:\n");
    printf("Title: %s\n", ms->title);
    printf("Author: %s\n", ms->author);
    printf("Year of Creation: %d\n", ms->year);
    printf("Genre: %s\n", ms->genre);
    printf("May these words echo through eternity!\n");
}

void inputManuscriptInfo(Manuscript *ms) {
    printf("\nPray tell me of this revered tomes' details:\n");
    printf("Enter the Title of the Manuscript: ");
    fgets(ms->title, 50, stdin);
    strtok(ms->title, "\n"); // Remove newline character

    printf("Enter the Author's Noble Name: ");
    fgets(ms->author, 50, stdin);
    strtok(ms->author, "\n"); // Remove newline character

    printf("Enter the Year of Creation (e.g., 1453): ");
    scanf("%d", &ms->year);
    getchar(); // Capture newline after the integer input

    printf("Enter the Genre of this Sacred Script: ");
    fgets(ms->genre, 30, stdin);
    strtok(ms->genre, "\n"); // Remove newline character
}

void saveManuscriptToFile(Manuscript *ms) {
    FILE *file;
    file = fopen("manuscript.txt", "w");
    if (file == NULL) {
        printf("Dread! The manuscript could not be inscribed upon the scrolls.\n");
        return;
    }
    fprintf(file, "Title: %s\n", ms->title);
    fprintf(file, "Author: %s\n", ms->author);
    fprintf(file, "Year: %d\n", ms->year);
    fprintf(file, "Genre: %s\n", ms->genre);
    fclose(file);
    printf("Hark! The manuscript hath been saved to 'manuscript.txt'.\n");
}

void readManuscriptFromFile() {
    FILE *file;
    Manuscript ms;
    file = fopen("manuscript.txt", "r");
    if (file == NULL) {
        printf("Alas! The scroll is lost and cannot be found.\n");
        return;
    }
    
    printf("\nSearching the archives for the manuscript...\n");
    while (fscanf(file, "Title: %[^\n]\n", ms.title) != EOF &&
           fscanf(file, "Author: %[^\n]\n", ms.author) != EOF &&
           fscanf(file, "Year: %d\n", &ms.year) != EOF &&
           fscanf(file, "Genre: %[^\n]\n", ms.genre) != EOF) {
        displayManuscriptInfo(&ms);
    }
    fclose(file);
    printf("Thus concludes our exploration of the scrolls.\n");
}

int main() {
    Manuscript ms;
    int choice;

    printf("Welcome to the Great Scriptorium!\n");
    do {
        printf("\nChoose from whence you wish to proceed:\n");
        printf("1. Input a New Manuscript\n");
        printf("2. Save Manuscript to File\n");
        printf("3. Read Manuscript from File\n");
        printf("4. Exit the Scriptorium\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clean up the newline character

        switch (choice) {
            case 1:
                inputManuscriptInfo(&ms);
                break;
            case 2:
                saveManuscriptToFile(&ms);
                break;
            case 3:
                readManuscriptFromFile();
                break;
            case 4:
                printf("Farewell, noble scribe! Until we meet again!\n");
                break;
            default:
                printf("Pray pardon! Thy choice is unrecognized by this realm.\n");
        }
    } while (choice != 4);

    return 0;
}