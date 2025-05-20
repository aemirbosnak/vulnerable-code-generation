//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for music library entry */
typedef struct {
    char title[30];
    char artist[30];
    char album[30];
    int year;
} MusicEntry;

/* Function declarations */
void addEntry(MusicEntry library[], int *numEntries);
void searchEntry(MusicEntry library[], int numEntries);
void printLibrary(MusicEntry library[], int numEntries);
void saveLibraryToFile(MusicEntry library[], int numEntries, char *fileName);

/* Main function */
int main() {
    int numEntries = 0;
    MusicEntry library[100];
    char fileName[30];
    int choice;

    printf("Welcome to the C Music Library Management System!\n");

    /* Show menu and get user choice */
    while(1) {
        printf("\nMENU\n");
        printf("1. Add new entry\n");
        printf("2. Search by artist\n");
        printf("3. Print library\n");
        printf("4. Save library to file\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addEntry(library, &numEntries);
                break;
            case 2:
                searchEntry(library, numEntries);
                break;
            case 3:
                printLibrary(library, numEntries);
                break;
            case 4:
                printf("Enter file name: ");
                scanf("%s", fileName);
                saveLibraryToFile(library, numEntries, fileName);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

/* Function to add new entry to the music library */
void addEntry(MusicEntry library[], int *numEntries) {
    printf("Enter title: ");
    scanf("%s", library[*numEntries].title);
    printf("Enter artist: ");
    scanf("%s", library[*numEntries].artist);
    printf("Enter album: ");
    scanf("%s", library[*numEntries].album);
    printf("Enter year: ");
    scanf("%d", &library[*numEntries].year);
    (*numEntries)++;
    printf("Entry added successfully!\n");
}

/* Function to search for entries by artist */
void searchEntry(MusicEntry library[], int numEntries) {
    char artist[30];
    int numMatches = 0;
    printf("Enter artist to search for: ");
    scanf("%s", artist);

    /* Loop through music library and print matching entries */
    for(int i = 0; i < numEntries; i++) {
        if(strcmp(library[i].artist, artist) == 0) {
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            numMatches++;
        }
    }

    /* If no matching entries, print message */
    if(numMatches == 0) {
        printf("No entries found for artist '%s'.\n", artist);
    }
}

/* Function to print entire music library */
void printLibrary(MusicEntry library[], int numEntries) {
    printf("MUSIC LIBRARY\n");
    for(int i = 0; i < numEntries; i++) {
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n\n", library[i].year);
    }

    /* If no entries exist in library, print message */
    if(numEntries == 0) {
        printf("No entries in library.\n");
    }
}

/* Function to save music library to file */
void saveLibraryToFile(MusicEntry library[], int numEntries, char *fileName) {
    FILE *file = fopen(fileName, "w");

    /* Write each entry to file */
    for(int i = 0; i < numEntries; i++) {
        fprintf(file, "%s|%s|%s|%d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }

    fclose(file);
    printf("Library saved to %s successfully!\n", fileName);
}