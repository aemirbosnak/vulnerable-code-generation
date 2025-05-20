//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50
#define MAX_GENRE_LEN 20

typedef struct Song {
    char title[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    char genre[MAX_GENRE_LEN];
} Song;

typedef struct Node {
    Song data;
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void addSong(Song song) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return;
    }
    newNode->data = song;
    newNode->next = head;
    head = newNode;
}

void displayLibrary() {
    current = head;
    int i = 1;
    printf("\nLibrary:\n");
    printf("--------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-15s |\n", "Sr. No.", "Title", "Artist");
    printf("--------------------------------------------------------\n");
    while (current != NULL) {
        printf("| %-10d | %-20s | %-15s |\n", i, current->data.title, current->data.artist);
        current = current->next;
        i++;
    }
    printf("--------------------------------------------------------\n");
}

int main() {
    Song newSong;
    int choice;

    while (1) {
        printf("\n1. Add Song\n2. Display Library\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter song title: ");
            scanf("%s", newSong.title);
            printf("Enter artist name: ");
            scanf("%s", newSong.artist);
            printf("Enter genre: ");
            scanf("%s", newSong.genre);
            addSong(newSong);
            printf("\nSong added successfully\n");
            break;
        case 2:
            displayLibrary();
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}