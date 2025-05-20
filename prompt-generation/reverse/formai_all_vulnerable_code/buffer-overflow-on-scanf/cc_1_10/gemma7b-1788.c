//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store music library information
typedef struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
} MusicLibrary;

// Create a function to insert a new music entry into the library
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

    // Insert the new music entry into the library
    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Create a function to print the music library
void printMusic(MusicLibrary* head) {
    // Traverse the library and print each music entry
    while (head) {
        printf("%s - %s (%s, %d)\n", head->title, head->artist, head->genre, head->year);
        head = head->next;
    }
}

int main() {
    // Create a linked list to store the music library
    MusicLibrary* head = NULL;

    // Insert some music entries
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Print the music library
    printMusic(head);

    return 0;
}