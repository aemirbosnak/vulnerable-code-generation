//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store music library information
struct MusicLibrary {
    char title[50];
    char artist[50];
    char genre[50];
    int year;
    struct MusicLibrary* next;
};

// Function to insert a new music entry into the library
void insertMusic(struct MusicLibrary** head) {
    struct MusicLibrary* newMusic = (struct MusicLibrary*)malloc(sizeof(struct MusicLibrary));

    // Get the music information from the user
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
        struct MusicLibrary* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }

        // Insert the new music entry as the last node
        current->next = newMusic;
    }
}

// Function to print the music library
void printMusic(struct MusicLibrary* head) {
    // Traverse the library and print each music entry
    struct MusicLibrary* current = head;
    while (current) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Genre: %s\n", current->genre);
        printf("Year: %d\n", current->year);
        printf("\n");
        current = current->next;
    }
}

int main() {
    // Create a linked list to store the music library
    struct MusicLibrary* head = NULL;

    // Insert some music entries
    insertMusic(&head);
    insertMusic(&head);
    insertMusic(&head);

    // Print the music library
    printMusic(head);

    return 0;
}