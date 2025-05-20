//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: accurate
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
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));
    printf("Enter the title: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    // If the library is empty, make the new music entry the first node
    if (*head == NULL) {
        *head = newMusic;
    } else {
        // Traverse the library until the last node is reached
        MusicLibrary* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Insert the new music entry at the end
        current->next = newMusic;
    }
}

// Function to display the music library
void displayMusic(MusicLibrary* head) {
    // Traverse the library and print each music entry
    MusicLibrary* current = head;
    while (current) {
        printf("%s by %s (%.1f, %s)\n", current->title, current->artist, current->year, current->genre);
        current = current->next;
    }
}

// Main function
int main() {
    MusicLibrary* head = NULL;

    // Insert some music entries
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Display the music library
    displayMusic(head);

    return 0;
}