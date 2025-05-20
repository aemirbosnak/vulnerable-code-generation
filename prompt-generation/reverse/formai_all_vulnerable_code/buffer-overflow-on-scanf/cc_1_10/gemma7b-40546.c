//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: random
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

// Function to insert a new music into the library
void insertMusic(Music* head) {
    Music* newMusic = (Music*)malloc(sizeof(Music));
    printf("Enter the title: ");
    scanf("%s", newMusic->title);
    printf("Enter the artist: ");
    scanf("%s", newMusic->artist);
    printf("Enter the genre: ");
    scanf("%s", newMusic->genre);
    printf("Enter the year: ");
    scanf("%d", &newMusic->year);
    newMusic->next = NULL;

    if (head == NULL) {
        head = newMusic;
    } else {
        Music* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMusic;
    }
}

// Function to search for music in the library
void searchMusic(Music* head) {
    char searchTitle[50];
    printf("Enter the title of the music you want to search for: ");
    scanf("%s", searchTitle);

    Music* temp = head;
    while (temp) {
        if (strcmp(temp->title, searchTitle) == 0) {
            printf("Title: %s\n", temp->title);
            printf("Artist: %s\n", temp->artist);
            printf("Genre: %s\n", temp->genre);
            printf("Year: %d\n", temp->year);
            break;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No music found.\n");
    }
}

// Function to delete music from the library
void deleteMusic(Music* head) {
    char deleteTitle[50];
    printf("Enter the title of the music you want to delete: ");
    scanf("%s", deleteTitle);

    Music* temp = head;
    Music* prev = NULL;

    while (temp) {
        if (strcmp(temp->title, deleteTitle) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("No music found.\n");
    }
}

int main() {
    Music* head = NULL;

    // Insert some music into the library
    insertMusic(head);
    insertMusic(head);
    insertMusic(head);

    // Search for music in the library
    searchMusic(head);

    // Delete music from the library
    deleteMusic(head);

    return 0;
}