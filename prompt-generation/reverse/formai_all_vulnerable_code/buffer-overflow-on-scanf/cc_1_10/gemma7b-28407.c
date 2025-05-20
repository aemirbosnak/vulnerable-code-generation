//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Music Library Management System structure
struct MusicLibrary {
    char title[256];
    char artist[256];
    char genre[256];
    int year;
    struct MusicLibrary* next;
};

// Function to insert a new music record into the library
void insertMusicRecord(struct MusicLibrary** head) {
    struct MusicLibrary* newRecord = malloc(sizeof(struct MusicLibrary));
    printf("Enter the title of the music record: ");
    scanf("%s", newRecord->title);
    printf("Enter the artist of the music record: ");
    scanf("%s", newRecord->artist);
    printf("Enter the genre of the music record: ");
    scanf("%s", newRecord->genre);
    printf("Enter the year of the music record: ");
    scanf("%d", &newRecord->year);

    if (*head == NULL) {
        *head = newRecord;
    } else {
        (*head)->next = newRecord;
        *head = newRecord;
    }
}

// Function to search for a music record in the library
void searchMusicRecord(struct MusicLibrary* head) {
    char searchTerm[256];
    printf("Enter the title, artist, or genre of the music record you are searching for: ");
    scanf("%s", searchTerm);

    struct MusicLibrary* currentRecord = head;
    while (currentRecord) {
        if (strcmp(searchTerm, currentRecord->title) == 0 || strcmp(searchTerm, currentRecord->artist) == 0 || strcmp(searchTerm, currentRecord->genre) == 0) {
            printf("Title: %s\n", currentRecord->title);
            printf("Artist: %s\n", currentRecord->artist);
            printf("Genre: %s\n", currentRecord->genre);
            printf("Year: %d\n", currentRecord->year);
            printf("\n");
        }
        currentRecord = currentRecord->next;
    }

    if (currentRecord == NULL) {
        printf("No music record found.\n");
    }
}

// Function to delete a music record from the library
void deleteMusicRecord(struct MusicLibrary* head) {
    char deleteTerm[256];
    printf("Enter the title, artist, or genre of the music record you want to delete: ");
    scanf("%s", deleteTerm);

    struct MusicLibrary* currentRecord = head;
    struct MusicLibrary* previousRecord = NULL;

    while (currentRecord) {
        if (strcmp(deleteTerm, currentRecord->title) == 0 || strcmp(deleteTerm, currentRecord->artist) == 0 || strcmp(deleteTerm, currentRecord->genre) == 0) {
            if (previousRecord) {
                previousRecord->next = currentRecord->next;
            } else {
                head = currentRecord->next;
            }
            free(currentRecord);
            currentRecord = NULL;
        } else {
            previousRecord = currentRecord;
            currentRecord = currentRecord->next;
        }
    }

    if (currentRecord == NULL) {
        printf("No music record found.\n");
    }
}

int main() {
    struct MusicLibrary* musicLibrary = NULL;

    // Insert some music records
    insertMusicRecord(&musicLibrary);
    insertMusicRecord(&musicLibrary);
    insertMusicRecord(&musicLibrary);

    // Search for a music record
    searchMusicRecord(musicLibrary);

    // Delete a music record
    deleteMusicRecord(musicLibrary);

    // Search for the music record that was deleted
    searchMusicRecord(musicLibrary);

    return 0;
}