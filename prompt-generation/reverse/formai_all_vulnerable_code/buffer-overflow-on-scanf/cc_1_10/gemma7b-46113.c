//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music information
typedef struct Music {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct Music* next;
} Music;

// Function to insert a new music into the linked list
void insertMusic(Music** head) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    printf("Enter the title: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year: ");
    scanf("%d", &newMusic->year);

    if (*head == NULL) {
        *head = newMusic;
    } else {
        (*head)->next = newMusic;
    }
    *head = newMusic;
}

// Function to search for music by title
Music* searchMusicByTitle(Music* head, char* title) {
    while (head) {
        if (strcmp(head->title, title) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to search for music by artist
Music* searchMusicByArtist(Music* head, char* artist) {
    while (head) {
        if (strcmp(head->artist, artist) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to search for music by genre
Music* searchMusicByGenre(Music* head, char* genre) {
    while (head) {
        if (strcmp(head->genre, genre) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

// Function to print all music
void printMusic(Music* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Artist: %s\n", head->artist);
        printf("Genre: %s\n", head->genre);
        printf("Year: %d\n", head->year);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Music* head = NULL;

    // Insert some music
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Print all music
    printMusic(head);

    // Search for music by title
    Music* foundMusic = searchMusicByTitle(head, "Song 2");
    if (foundMusic) {
        printf("Found music: \n");
        printf("Title: %s\n", foundMusic->title);
        printf("Artist: %s\n", foundMusic->artist);
        printf("Genre: %s\n", foundMusic->genre);
        printf("Year: %d\n", foundMusic->year);
    } else {
        printf("Music not found.\n");
    }

    return 0;
}