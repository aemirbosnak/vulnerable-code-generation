//FormAI DATASET v1.0 Category: Music Library Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char name[50];
    char artist[50];
    int duration_minutes;
    int duration_seconds;
    char album[50];
} Song;

typedef struct song_node {
    Song data;
    struct song_node *next;
} SongNode;

SongNode *head = NULL;
SongNode *tail = NULL;

// Function for adding new songs to the library
void add_song() {
    SongNode *node = malloc(sizeof(SongNode));
    printf("Enter song name: ");
    fgets(node->data.name, 50, stdin);
    printf("Enter artist name: ");
    fgets(node->data.artist, 50, stdin);
    printf("Enter song duration (in minutes): ");
    scanf("%d", &node->data.duration_minutes);
    printf("Enter song duration (in seconds): ");
    scanf("%d", &node->data.duration_seconds);
    getchar(); // remove newline character from buffer
    printf("Enter album name: ");
    fgets(node->data.album, 50, stdin);
    node->next = NULL;
    if (head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
    printf("Song added successfully!\n");
}

// Function for displaying all songs in the library
void display_songs() {
    if (head == NULL) {
        printf("No songs in the library.\n");
        return;
    }
    SongNode *node = head;
    int i = 1;
    while (node != NULL) {
        printf("Song %d:\n", i++);
        printf("Name: %s", node->data.name);
        printf("Artist: %s", node->data.artist);
        printf("Duration: %d:%02d\n", node->data.duration_minutes, node->data.duration_seconds);
        printf("Album: %s", node->data.album);
        node = node->next;
    }
}

// Function for searching for a song by name
void search_by_name() {
    char name[50];
    printf("Enter song name: ");
    fgets(name, 50, stdin);
    SongNode *node = head;
    while (node != NULL) {
        if (strcmp(node->data.name, name) == 0) {
            printf("Song found!\n");
            printf("Name: %s", node->data.name);
            printf("Artist: %s", node->data.artist);
            printf("Duration: %d:%02d\n", node->data.duration_minutes, node->data.duration_seconds);
            printf("Album: %s", node->data.album);
            return;
        }
        node = node->next;
    }
    printf("Song not found.\n");
}

// Function for searching for a song by artist
void search_by_artist() {
    char artist[50];
    printf("Enter artist name: ");
    fgets(artist, 50, stdin);
    SongNode *node = head;
    int i = 1;
    while (node != NULL) {
        if (strcmp(node->data.artist, artist) == 0) {
            printf("Song %d:\n", i++);
            printf("Name: %s", node->data.name);
            printf("Duration: %d:%02d\n", node->data.duration_minutes, node->data.duration_seconds);
            printf("Album: %s", node->data.album);
        }
        node = node->next;
    }
    if (i == 1) {
        printf("No songs by that artist found.\n");
    }
}

// Function for deleting a song from the library
void delete_song() {
    if (head == NULL) {
        printf("No songs in the library to delete.\n");
        return;
    }
    char name[50];
    printf("Enter song name to delete: ");
    fgets(name, 50, stdin);
    SongNode *node = head;
    SongNode *prev = NULL;
    while (node != NULL) {
        if (strcmp(node->data.name, name) == 0) {
            if (node == head) {
                head = node->next;
            } else if (node == tail) {
                prev->next = NULL;
                tail = prev;
            } else {
                prev->next = node->next;
            }
            free(node);
            printf("Song deleted successfully!\n");
            return;
        }
        prev = node;
        node = node->next;
    }
    printf("Song not found in the library.\n");
}

int main() {
    int choice = 0;
    while (choice != 5) {
        printf("Enter your choice:\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search song by name\n");
        printf("4. Search songs by artist\n");
        printf("5. Delete song\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        getchar(); // remove newline character from buffer
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                display_songs();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                search_by_artist();
                break;
            case 5:
                delete_song();
                break;
            case 6:
                printf("Thank you for using our library!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;
}