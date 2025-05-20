//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store music library information
typedef struct MusicLibraryItem {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibraryItem* next;
} MusicLibraryItem;

// Function to insert a new music item into the library
void insertMusicItem(MusicLibraryItem** head) {
    MusicLibraryItem* newNode = (MusicLibraryItem*)malloc(sizeof(MusicLibraryItem));

    printf("Enter the title of the music item: ");
    scanf("%s", newNode->title);

    printf("Enter the artist of the music item: ");
    scanf("%s", newNode->artist);

    printf("Enter the genre of the music item: ");
    scanf("%s", newNode->genre);

    printf("Enter the year of the music item: ");
    scanf("%d", &newNode->year);

    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to search for a music item in the library
void searchMusicItem(MusicLibraryItem* head) {
    char searchTerm[50];

    printf("Enter the title, artist, or genre of the music item you want to find: ");
    scanf("%s", searchTerm);

    MusicLibraryItem* currentItem = head;

    while (currentItem) {
        if (strcmp(searchTerm, currentItem->title) == 0 || strcmp(searchTerm, currentItem->artist) == 0 || strcmp(searchTerm, currentItem->genre) == 0) {
            printf("Title: %s\n", currentItem->title);
            printf("Artist: %s\n", currentItem->artist);
            printf("Genre: %s\n", currentItem->genre);
            printf("Year: %d\n", currentItem->year);
            printf("\n");
        }
        currentItem = currentItem->next;
    }

    if (currentItem == NULL) {
        printf("No music item found.\n");
    }
}

// Function to delete a music item from the library
void deleteMusicItem(MusicLibraryItem** head) {
    char deleteItem[50];

    printf("Enter the title of the music item you want to delete: ");
    scanf("%s", deleteItem);

    MusicLibraryItem* currentItem = *head;
    MusicLibraryItem* previousItem = NULL;

    while (currentItem) {
        if (strcmp(deleteItem, currentItem->title) == 0) {
            if (previousItem != NULL) {
                previousItem->next = currentItem->next;
            } else {
                *head = currentItem->next;
            }
            free(currentItem);
            return;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    printf("No music item found.\n");
}

int main() {
    MusicLibraryItem* musicLibrary = NULL;

    // Insert some music items into the library
    insertMusicItem(&musicLibrary);
    insertMusicItem(&musicLibrary);
    insertMusicItem(&musicLibrary);

    // Search for a music item in the library
    searchMusicItem(musicLibrary);

    // Delete a music item from the library
    deleteMusicItem(&musicLibrary);

    return 0;
}