//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: lively
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

    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
}

// Function to search for music in the library
void searchMusic(MusicLibrary* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            printf("Title: %s\n", head->title);
            printf("Artist: %s\n", head->artist);
            printf("Genre: %s\n", head->genre);
            printf("Year: %d\n", head->year);
            break;
        }
        head = head->next;
    }
    if (head == NULL) {
        printf("No music found with that title.\n");
    }
}

int main() {
    MusicLibrary* head = NULL;

    // Insert some music into the library
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Search for music in the library
    searchMusic(head, "Song 2");

    return 0;
}