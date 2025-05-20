//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
} Song;

typedef struct node {
    Song data;
    struct node* next;
} Node;

void add_song(Node** playlist, Song song) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = song;
    new_node->next = *playlist;
    *playlist = new_node;
}

void show_songs(Node* playlist) {
    int i = 1;
    while (playlist != NULL) {
        printf("%d. %s - %s (%s, %d, %d sec)\n", i++, playlist->data.artist, playlist->data.title, playlist->data.album, playlist->data.year, playlist->data.duration);
        playlist = playlist->next;
    }
    printf("\n");
}

void search_by_artist(Node* playlist, char* artist) {
    int i = 1, found = 0;
    while (playlist != NULL) {
        if (strcmp(playlist->data.artist, artist) == 0) {
            printf("%d. %s - %s (%s, %d, %d sec)\n", i++, playlist->data.artist, playlist->data.title, playlist->data.album, playlist->data.year, playlist->data.duration);
            found = 1;
        }
        playlist = playlist->next;
    }
    if (!found) printf("No songs found from %s.\n", artist);
    printf("\n");
}

void search_by_title(Node* playlist, char* title) {
    int i = 1, found = 0;
    while (playlist != NULL) {
        if (strcmp(playlist->data.title, title) == 0) {
            printf("%d. %s - %s (%s, %d, %d sec)\n", i++, playlist->data.artist, playlist->data.title, playlist->data.album, playlist->data.year, playlist->data.duration);
            found = 1;
        }
        playlist = playlist->next;
    }
    if (!found) printf("No songs found with title %s.\n", title);
    printf("\n");
}

int main() {
    Node* playlist = NULL;
    int option;
    while (1) {
        printf("1. Add song\n");
        printf("2. Show songs\n");
        printf("3. Search by artist\n");
        printf("4. Search by title\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                Song song;
                printf("Enter song details:\n");
                printf("Title: ");
                scanf("%s", song.title);
                printf("Artist: ");
                scanf("%s", song.artist);
                printf("Album: ");
                scanf("%s", song.album);
                printf("Year: ");
                scanf("%d", &song.year);
                printf("Duration (in seconds): ");
                scanf("%d", &song.duration);
                add_song(&playlist, song);
                printf("Song added successfully.\n\n");
                break;
            }
            case 2: {
                if (playlist == NULL) {
                    printf("No songs found.\n\n");
                    break;
                }
                printf("Song list:\n");
                show_songs(playlist);
                break;
            }
            case 3: {
                char artist[50];
                printf("Enter artist name: ");
                scanf("%s", artist);
                search_by_artist(playlist, artist);
                break;
            }
            case 4: {
                char title[50];
                printf("Enter song title: ");
                scanf("%s", title);
                search_by_title(playlist, title);
                break;
            }
            case 5: {
                printf("Exiting program.\n");
                exit(0);
            }
            default: printf("Invalid option. Please try again.\n\n");
        }
    }
    return 0;
}