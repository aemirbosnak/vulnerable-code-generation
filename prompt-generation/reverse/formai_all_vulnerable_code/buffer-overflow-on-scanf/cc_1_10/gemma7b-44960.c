//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Insert the new music entry into the head of the library
    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Function to search for music in the library
void searchMusic(MusicLibrary* head) {
    // Get the music information from the user
    char searchTitle[50];
    printf("Enter the title: ");
    scanf("%s", searchTitle);

    // Search for the music entry in the library
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

    // If the music entry is not found, print an error message
    if (currentMusic == NULL) {
        printf("No music entry found.\n");
    }
}

// Function to print the music library
void printMusicLibrary(MusicLibrary* head) {
    // Traverse the music library and print each music entry
    MusicLibrary* currentMusic = head;
    while (currentMusic) {
        printf("Title: %s\n", currentMusic->title);
        printf("Artist: %s\n", currentMusic->artist);
        printf("Genre: %s\n", currentMusic->genre);
        printf("Year: %d\n", currentMusic->year);
        printf("\n");
        currentMusic = currentMusic->next;
    }
}

int main() {
    // Create a linked list to store the music library
    MusicLibrary* head = NULL;

    // Insert some music entries into the library
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Search for music in the library
    searchMusic(head);

    // Print the music library
    printMusicLibrary(head);

    return 0;
}