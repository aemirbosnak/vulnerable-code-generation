//MISTRAL-7B DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
} Song;

typedef struct Node {
    Song data;
    struct Node* next;
} Node;

Node* head = NULL;

void addSong(char* title, char* artist) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error!\n");
        return;
    }
    strcpy(newNode->data.title, title);
    strcpy(newNode->data.artist, artist);
    newNode->next = head;
    head = newNode;
}

void printLibrary() {
    Node* current = head;
    printf("\nMy Music Library:\n");
    while (current != NULL) {
        printf("%s by %s\n", current->data.title, current->data.artist);
        current = current->next;
    }
}

int main() {
    char title[MAX_TITLE_LENGTH], artist[MAX_ARTIST_LENGTH];
    int choice, index;

    while (1) {
        printf("\n1. Add Song\n2. Print Library\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                scanf("%s", title);
                printf("Enter artist name: ");
                scanf("%s", artist);
                addSong(title, artist);
                break;
            case 2:
                printLibrary();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}