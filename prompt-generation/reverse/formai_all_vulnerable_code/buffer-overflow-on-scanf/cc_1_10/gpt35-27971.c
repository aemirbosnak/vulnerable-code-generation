//FormAI DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
} Song;

typedef struct Node {
    Song data;
    struct Node *next;
} Node;

Node *head = NULL;

void add_song() {
    Song song;
    printf("\nEnter details of the song\n\n");
    printf("Title: ");
    scanf("%s", song.title);
    printf("Artist: ");
    scanf("%s", song.artist);
    printf("Album: ");
    scanf("%s", song.album);
    printf("Year: ");
    scanf("%d", &song.year);

    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = song;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    printf("\nSong added successfully!\n");
}

void search_song() {
    char title[50];
    printf("\nEnter the title of the song: ");
    scanf("%s", title);

    Node *current = head;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->data.title, title) == 0) {
            found = 1;
            printf("\nFound the following song:\n\n");
            printf("Title: %s\n", current->data.title);
            printf("Artist: %s\n", current->data.artist);
            printf("Album: %s\n", current->data.album);
            printf("Year: %d\n", current->data.year);
        }
        current = current->next;
    }

    if (!found) {
        printf("\nSong not found!\n");
    }
}

void display_songs() {
    if (head == NULL) {
        printf("\nNo songs in the library!\n");
    } else {
        Node *current = head;
        printf("\nSongs in the library:\n\n");
        while (current != NULL) {
            printf("Title: %s\n", current->data.title);
            printf("Artist: %s\n", current->data.artist);
            printf("Album: %s\n", current->data.album);
            printf("Year: %d\n\n", current->data.year);
            current = current->next;
        }
    }
}

void delete_song() {
    if (head == NULL) {
        printf("\nNo songs in the library!\n");
        return;
    }

    char title[50];
    printf("\nEnter the title of the song to be deleted: ");
    scanf("%s", title);

    Node *current = head;
    Node *prev = NULL;
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->data.title, title) == 0) {
            found = 1;
            if (current == head) {
                head = head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("\nSong deleted successfully!\n");
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!found) {
        printf("\nSong not found!\n");
    }
}

void menu() {
    printf("\nMusic Library Management System\n");
    printf("------------------------------\n");
    printf("1. Add song\n");
    printf("2. Search song\n");
    printf("3. Display songs\n");
    printf("4. Delete song\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                search_song();
                break;
            case 3:
                display_songs();
                break;
            case 4:
                delete_song();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nEnter a valid choice!\n");
        }
    } while (1);

    return 0;
}