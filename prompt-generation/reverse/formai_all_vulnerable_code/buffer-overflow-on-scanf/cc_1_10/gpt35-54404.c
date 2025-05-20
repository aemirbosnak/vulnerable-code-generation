//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct song {
    char title[MAX_STR_LEN];
    char artist[MAX_STR_LEN];
    char album[MAX_STR_LEN];
    char genre[MAX_STR_LEN];
    int year;
    int length; // length in seconds
} Song;

typedef struct node {
    Song data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
} List;

void print_menu() {
    printf("\nMENU:\n");
    printf("1. Add song\n");
    printf("2. Delete song\n");
    printf("3. Search song\n");
    printf("4. Display all songs\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
}

void add_song(List* playlist) {
    Song new_song;
    printf("\nEnter song information:\n");
    printf("Title: ");
    scanf(" %[^\n]s", new_song.title);
    printf("Artist: ");
    scanf(" %[^\n]s", new_song.artist);
    printf("Album: ");
    scanf(" %[^\n]s", new_song.album);
    printf("Genre: ");
    scanf(" %[^\n]s", new_song.genre);
    printf("Year: ");
    scanf("%d", &new_song.year);
    printf("Length (in seconds): ");
    scanf("%d", &new_song.length);

    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_song;
    new_node->next = NULL;

    if (playlist->head == NULL) {
        playlist->head = new_node;
        printf("\nAdded new song to library!");
        return;
    }

    Node* current = playlist->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    printf("\nAdded new song to library!");
}

void delete_song(List* playlist) {
    char title[MAX_STR_LEN];
    printf("\nEnter title of song to delete: ");
    scanf(" %[^\n]s", title);

    Node* current = playlist->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->data.title, title) == 0) {
            if (prev == NULL) {
                playlist->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("\nDeleted song from library!");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\nSong not found in library!");
}

void search_song(List* playlist) {
    char title[MAX_STR_LEN];
    printf("\nEnter title of song to search: ");
    scanf(" %[^\n]s", title);

    Node* current = playlist->head;
    while (current != NULL) {
        if (strcmp(current->data.title, title) == 0) {
            printf("\nTitle: %s\n", current->data.title);
            printf("Artist: %s\n", current->data.artist);
            printf("Album: %s\n", current->data.album);
            printf("Genre: %s\n", current->data.genre);
            printf("Year: %d\n", current->data.year);
            printf("Length: %d seconds\n", current->data.length);
            return;
        }
        current = current->next;
    }

    printf("\nSong not found in library!");
}

void display_songs(List* playlist) {
    Node* current = playlist->head;
    if (current == NULL) {
        printf("\nLibrary is empty!\n");
        return;
    }

    printf("\nSONGS IN LIBRARY:\n");
    while (current != NULL) {
        printf("\nTitle: %s\n", current->data.title);
        printf("Artist: %s\n", current->data.artist);
        printf("Album: %s\n", current->data.album);
        printf("Genre: %s\n", current->data.genre);
        printf("Year: %d\n", current->data.year);
        printf("Length: %d seconds\n", current->data.length);
        current = current->next;
    }
}

int main() {
    List playlist;
    playlist.head = NULL;

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&playlist);
                break;
            case 2:
                delete_song(&playlist);
                break;
            case 3:
                search_song(&playlist);
                break;
            case 4:
                display_songs(&playlist);
                break;
            case 5:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid option.");
                break;
        }
    } while (choice != 5);

    return 0;
}