//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_ARTIST 100

typedef struct Song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    struct Song *next;
} Song;

Song *head = NULL;

void addSong();
void deleteSong();
void searchSong();
void displaySongs();
void freeMemory();

int main() {
    int choice;

    while (1) {
        printf("\n---- Music Library Management ----\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Display Songs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                deleteSong();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                displaySongs();
                break;
            case 5:
                freeMemory();
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addSong() {
    Song *newSong = (Song *)malloc(sizeof(Song));
    if (!newSong) {
        printf("Memory allocation failed! Unable to add song!\n");
        return;
    }
    printf("Enter song title: ");
    fgets(newSong->title, MAX_TITLE, stdin);
    strtok(newSong->title, "\n"); // Remove newline character
    printf("Enter artist name: ");
    fgets(newSong->artist, MAX_ARTIST, stdin);
    strtok(newSong->artist, "\n"); // Remove newline character

    newSong->next = head;
    head = newSong;
    printf("Song added successfully!\n");
}

void deleteSong() {
    if (head == NULL) {
        printf("No songs to delete!\n");
        return;
    }
    char title[MAX_TITLE];
    printf("Enter song title to delete: ");
    fgets(title, MAX_TITLE, stdin);
    strtok(title, "\n");

    Song *temp = head, *prev = NULL;

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found!\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Song deleted successfully!\n");
}

void searchSong() {
    if (head == NULL) {
        printf("No songs in the library!\n");
        return;
    }
    char title[MAX_TITLE];
    printf("Enter song title to search: ");
    fgets(title, MAX_TITLE, stdin);
    strtok(title, "\n");

    Song *temp = head;

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("Song found: %s by %s\n", temp->title, temp->artist);
            return;
        }
        temp = temp->next;
    }
    printf("Song not found!\n");
}

void displaySongs() {
    if (head == NULL) {
        printf("No songs in the library!\n");
        return;
    }
    Song *temp = head;
    printf("\n---- List of Songs ----\n");
    while (temp != NULL) {
        printf("Title: %s, Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

void freeMemory() {
    Song *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All memory freed successfully.\n");
}