//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    int year;
    struct song *next;
} Song;

Song *createSong(char *title, char *artist, int year);
void addSong(Song **head, char *title, char *artist, int year);
void removeSong(Song **head, char *title);
void clearLibrary(Song **head);
void displayLibrary(Song *head);

int main() {

    Song *head = NULL;
    int choice, year;
    char title[50], artist[50];

    printf("Welcome to the Cryptic C Music Library Management System!\n");

    do {
        printf("\nWhat would you like to do?");
        printf("\n1. Add a song to the library");
        printf("\n2. Remove a song from the library");
        printf("\n3. Display the library");
        printf("\n4. Clear the library");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the song title: ");
                scanf("%s", title);
                printf("Enter the artist name: ");
                scanf("%s", artist);
                printf("Enter the release year: ");
                scanf("%d", &year);
                addSong(&head, title, artist, year);
                printf("\nSong added to the library!");
                break;
            case 2:
                printf("\nEnter the title of the song to be removed: ");
                scanf("%s", title);
                removeSong(&head, title);
                printf("\nSong removed from the library!");
                break;
            case 3:
                printf("\nDisplaying the music library:\n");
                displayLibrary(head);
                break;
            case 4:
                printf("\nClearing the music library...");
                clearLibrary(&head);
                printf("\nLibrary cleared!");
                break;
            case 5:
                printf("\nExiting the program...");
                break;
            default:
                printf("\nInvalid choice!");
        }
    } while(choice != 5);

    return 0;
}

Song *createSong(char *title, char *artist, int year) {
    Song *newSong = (Song *) malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->year = year;
    newSong->next = NULL;
    return newSong;
}

void addSong(Song **head, char *title, char *artist, int year) {
    Song *newSong = createSong(title, artist, year);
    if (*head == NULL) {
        *head = newSong;
    } else {
        Song *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}

void removeSong(Song **head, char *title) {
    Song *temp = *head;
    Song *prev = NULL;
    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nSong not found in the library!");
        return;
    }
    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void displayLibrary(Song *head) {
    if (head == NULL) {
        printf("\nThe music library is empty!");
    } else {
        Song *temp = head;
        printf("\n%-30s %-30s %s\n", "Title", "Artist", "Year");
        while (temp != NULL) {
            printf("%-30s %-30s %d\n", temp->title, temp->artist, temp->year);
            temp = temp->next;
        }
    }
}

void clearLibrary(Song **head) {
    if (*head == NULL) {
        return;
    }
    Song *temp = *head;
    Song *next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}