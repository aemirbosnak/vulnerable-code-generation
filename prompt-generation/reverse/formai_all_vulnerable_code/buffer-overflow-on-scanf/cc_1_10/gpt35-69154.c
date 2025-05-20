//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int rating;
};

struct Node {
    struct Song song;
    struct Node* next;
};

struct Node* head = NULL;

void addSong() {
    struct Song newSong;

    printf("Enter title: ");
    scanf("%s", &newSong.title);
    printf("Enter artist: ");
    scanf("%s", &newSong.artist);
    printf("Enter album: ");
    scanf("%s", &newSong.album);
    printf("Enter rating: ");
    scanf("%d", &newSong.rating);

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->song = newSong;
    newNode->next = head;
    head = newNode;

    printf("Song added successfully!\n\n");
}

void searchSong() {
    char searchTitle[50];
    struct Node* current = head;

    printf("Enter title to search: ");
    scanf("%s", &searchTitle);

    while(current != NULL) {
        if(strcmp(current->song.title, searchTitle) == 0) {
            printf("Title: %s\nArtist: %s\nAlbum: %s\nRating: %d\n\n",
                current->song.title,
                current->song.artist,
                current->song.album,
                current->song.rating);
            return;
        }
        current = current->next;
    }

    printf("Song not found!\n\n");
}

void editSong() {
    char editTitle[50];
    struct Node* current = head;

    printf("Enter title to edit: ");
    scanf("%s", &editTitle);

    while(current != NULL) {
        if(strcmp(current->song.title, editTitle) == 0) {
            printf("Enter new title: ");
            scanf("%s", &current->song.title);
            printf("Enter new artist: ");
            scanf("%s", &current->song.artist);
            printf("Enter new album: ");
            scanf("%s", &current->song.album);
            printf("Enter new rating: ");
            scanf("%d", &current->song.rating);
            printf("Song edited successfully!\n\n");
            return;
        }
        current = current->next;
    }

    printf("Song not found!\n\n");
}

void deleteSong() {
    char deleteTitle[50];
    struct Node* current = head;
    struct Node* prev = NULL;

    printf("Enter title to delete: ");
    scanf("%s", &deleteTitle);

    while(current != NULL) {
        if(strcmp(current->song.title, deleteTitle) == 0) {
            if(prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Song deleted successfully!\n\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Song not found!\n\n");
}

void displaySongs() {
    struct Node* current = head;

    printf("All songs:\n");

    while(current != NULL) {
        printf("Title: %s\nArtist: %s\nAlbum: %s\nRating: %d\n\n",
            current->song.title,
            current->song.artist,
            current->song.album,
            current->song.rating);
        current = current->next;
    }
}

int main() {
    int choice;

    while(1) {
        printf("C Music Library Management System\n");
        printf("---------------------------------\n");
        printf("1. Add Song\n");
        printf("2. Search Song\n");
        printf("3. Edit Song\n");
        printf("4. Delete Song\n");
        printf("5. Display Songs\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong();
                break;
            case 2:
                searchSong();
                break;
            case 3:
                editSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                displaySongs();
                break;
            case 6:
                printf("Thank you for using C Music Library Management System!\n\n");
                return 0;
            default:
                printf("Invalid choice!\n\n");
        }
    }

    return 0;
}