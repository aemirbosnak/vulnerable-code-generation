//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char artist[100];
    char album[100];
    int year;
} Song;

typedef struct node {
    Song data;
    struct node* next;
} Node;

Node* head = NULL;

void addSong() {
    Song newSong;

    printf("Enter song title: ");
    scanf("%[^\n]%*c", newSong.title);

    printf("Enter artist name: ");
    scanf("%[^\n]%*c", newSong.artist);

    printf("Enter album name: ");
    scanf("%[^\n]%*c", newSong.album);

    printf("Enter year of release: ");
    scanf("%d", &newSong.year);

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newSong;
    newNode->next = head;
    head = newNode;

    printf("\nSong added successfully!\n\n");
}

void searchSong() {
    char search[100];
    int found = 0;

    printf("Enter song title to search: ");
    scanf("%[^\n]%*c", search);

    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.title, search) == 0) {
            printf("\nSong Found!\n");
            printf("Title: %s\n", temp->data.title);
            printf("Artist: %s\n", temp->data.artist);
            printf("Album: %s\n", temp->data.album);
            printf("Year: %d\n\n", temp->data.year);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("\nSong not found!\n\n");
    }
}

void displaySongs() {
    if (head == NULL) {
        printf("\nNo songs in the library!\n\n");
        return;
    }

    printf("\nSong Library:\n\n");

    Node* temp = head;
    while (temp != NULL) {
        printf("Title: %s\n", temp->data.title);
        printf("Artist: %s\n", temp->data.artist);
        printf("Album: %s\n", temp->data.album);
        printf("Year: %d\n\n", temp->data.year);
        temp = temp->next;
    }
}

int main() {
    int choice;

    printf("Welcome to the Ada Lovelace Music Library Management System!\n\n");

    while (1) {
        printf("Please select an option below:\n");
        printf("1. Add a song to the library\n");
        printf("2. Search for a song in the library\n");
        printf("3. Display all songs in the library\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                searchSong();
                break;
            case 3:
                displaySongs();
                break;
            case 4:
                printf("\nThank you for using the Ada Lovelace Music Library Management System!\n\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice, please select again.\n\n");
                break;
        }
    }

    return 0;
}