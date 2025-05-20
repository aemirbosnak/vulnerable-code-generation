//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Function to insert a new music entry into the library
void insertMusic(MusicLibrary** head) {
    // Allocate memory for the new music entry
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));

    // Get the music information from the user
    printf("Enter the title: ");
    scanf("%s", newMusic->title);

    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);

    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);

    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    // Link the new music entry to the head of the library
    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }

    // Print a confirmation message
    printf("Music entry inserted successfully.\n");
}

// Function to search for music in the library
void searchMusic(MusicLibrary* head) {
    // Get the music information from the user
    char searchTitle[50];
    printf("Enter the title of the music you are searching for: ");
    scanf("%s", searchTitle);

    // Search for the music entry
    MusicLibrary* currentMusic = head;
    while (currentMusic) {
        if (strcmp(currentMusic->title, searchTitle) == 0) {
            // Print the music information
            printf("Title: %s\n", currentMusic->title);
            printf("Artist: %s\n", currentMusic->artist);
            printf("Genre: %s\n", currentMusic->genre);
            printf("Year: %d\n", currentMusic->year);
            break;
        }
        currentMusic = currentMusic->next;
    }

    // If no music entry is found, print an error message
    if (currentMusic == NULL) {
        printf("No music entry found.\n");
    }
}

// Function to delete a music entry from the library
void deleteMusic(MusicLibrary* head) {
    // Get the music information from the user
    char deleteTitle[50];
    printf("Enter the title of the music you want to delete: ");
    scanf("%s", deleteTitle);

    // Search for the music entry
    MusicLibrary* currentMusic = head;
    MusicLibrary* previousMusic = NULL;
    while (currentMusic) {
        if (strcmp(currentMusic->title, deleteTitle) == 0) {
            // If the music entry is the first entry in the library, delete the first entry
            if (previousMusic == NULL) {
                head = currentMusic->next;
            } else {
                previousMusic->next = currentMusic->next;
            }
            free(currentMusic);
            break;
        }
        previousMusic = currentMusic;
        currentMusic = currentMusic->next;
    }

    // If no music entry is found, print an error message
    if (currentMusic == NULL) {
        printf("No music entry found.\n");
    }
}

int main() {
    // Create a head of the music library
    MusicLibrary* head = NULL;

    // Insert some music entries
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Search for music
    searchMusic(head);

    // Delete music
    deleteMusic(head);

    return 0;
}