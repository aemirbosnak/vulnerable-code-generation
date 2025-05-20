//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: minimalist
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
MusicLibrary* insertMusic(MusicLibrary* head) {
    MusicLibrary* newMusic = (MusicLibrary*)malloc(sizeof(MusicLibrary));

    printf("Enter the title of the music: ");
    scanf("%s", newMusic->title);

    printf("Enter the artist of the music: ");
    scanf("%s", newMusic->artist);

    printf("Enter the genre of the music: ");
    scanf("%s", newMusic->genre);

    printf("Enter the year of the music: ");
    scanf("%d", &newMusic->year);

    newMusic->next = NULL;

    if (head == NULL) {
        head = newMusic;
    } else {
        head->next = newMusic;
    }

    return head;
}

// Function to print the music library
void printMusic(MusicLibrary* head) {
    MusicLibrary* current = head;

    while (current) {
        printf("%s by %s (%.1f, %s)\n", current->title, current->artist, current->year, current->genre);
        current = current->next;
    }
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music entries
    insertMusic(head);
    insertMusic(head);
    insertMusic(head);

    // Print the music library
    printMusic(head);

    return 0;
}