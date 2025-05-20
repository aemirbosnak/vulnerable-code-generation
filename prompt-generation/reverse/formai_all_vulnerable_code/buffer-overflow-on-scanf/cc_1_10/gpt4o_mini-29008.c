//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the max lengths for album titles and artists
#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

// Structure to hold music album information
typedef struct Album {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
    struct Album* next;
} Album;

// Function prototypes
void addAlbum(Album** head);
void viewAlbums(Album* head);
void searchAlbum(Album* head);
void freeAlbums(Album* head);

int main() {
    Album* head = NULL;
    int choice;

    while (1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add Album\n");
        printf("2. View Albums\n");
        printf("3. Search Album\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addAlbum(&head);
                break;
            case 2:
                viewAlbums(head);
                break;
            case 3:
                searchAlbum(head);
                break;
            case 4:
                freeAlbums(head);
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add an album to the list
void addAlbum(Album** head) {
    Album* newAlbum = (Album*)malloc(sizeof(Album));
    if (!newAlbum) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter album title: ");
    fgets(newAlbum->title, MAX_TITLE_LENGTH, stdin);
    newAlbum->title[strcspn(newAlbum->title, "\n")] = 0; // Remove newline character

    printf("Enter artist name: ");
    fgets(newAlbum->artist, MAX_ARTIST_LENGTH, stdin);
    newAlbum->artist[strcspn(newAlbum->artist, "\n")] = 0; // Remove newline character

    printf("Enter release year: ");
    scanf("%d", &newAlbum->year);
    getchar(); // Consume newline character

    newAlbum->next = *head; // New album points to previous first album
    *head = newAlbum; // Update head to the new album
    printf("Album added successfully!\n");
}

// Function to view all albums in the list
void viewAlbums(Album* head) {
    if (head == NULL) {
        printf("No albums in the library.\n");
        return;
    }

    printf("\n--- Music Albums ---\n");
    Album* current = head;
    while (current != NULL) {
        printf("Title: %s, Artist: %s, Year: %d\n",
               current->title, current->artist, current->year);
        current = current->next;
    }
}

// Function to search for an album by title
void searchAlbum(Album* head) {
    if (head == NULL) {
        printf("No albums in the library.\n");
        return;
    }

    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter album title to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; // Remove newline character

    Album* current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->title, searchTitle) == 0) {
            printf("Album found: Title: %s, Artist: %s, Year: %d\n",
                   current->title, current->artist, current->year);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Album titled '%s' not found in the library.\n", searchTitle);
    }
}

// Function to free the allocated memory for albums
void freeAlbums(Album* head) {
    Album* current = head;
    Album* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}