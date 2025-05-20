//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for songs
struct song_t {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

// Define struct for linked list node
struct node_t {
    struct song_t song;
    struct node_t* next;
};

// Function to add a song to the library
void add_song(struct node_t** library, char* title, char* artist, char* album, int year) {
    struct node_t* new_node = malloc(sizeof(struct node_t));
    strcpy(new_node->song.title, title);
    strcpy(new_node->song.artist, artist);
    strcpy(new_node->song.album, album);
    new_node->song.year = year;
    new_node->next = NULL;
    if (*library == NULL) {
        *library = new_node;
    } else {
        struct node_t* current = *library;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to delete a song from the library
void delete_song(struct node_t** library, char* title) {
    struct node_t* current = *library;
    struct node_t* prev = NULL;
    while (current != NULL && strcmp(current->song.title, title) != 0) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        if (prev == NULL) {
            *library = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
    } else {
        printf("Error: song not found\n");
    }
}

// Function to display all songs in the library
void display_library(struct node_t* library) {
    if (library == NULL) {
        printf("Library is empty\n");
    } else {
        printf("Title\t\tArtist\t\tAlbum\t\tYear\n");
        printf("------------------------------------------------\n");
        struct node_t* current = library;
        while (current != NULL) {
            printf("%s\t\t%s\t\t%s\t\t%d\n", current->song.title, current->song.artist, current->song.album, current->song.year);
            current = current->next;
        }
    }
}

int main() {
    struct node_t* library = NULL;
    printf("Welcome to the Cyber Music Library Management System\n\n");
    while (1) {
        printf("Enter command (add, delete, display, quit): ");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char title[50];
            char artist[50];
            char album[50];
            int year;
            printf("Enter title: ");
            scanf(" %[^\n]", title);
            printf("Enter artist: ");
            scanf(" %[^\n]", artist);
            printf("Enter album: ");
            scanf(" %[^\n]", album);
            printf("Enter year: ");
            scanf("%d", &year);
            add_song(&library, title, artist, album, year);
            printf("Song added.\n");
        } else if (strcmp(command, "delete") == 0) {
            char title[50];
            printf("Enter title: ");
            scanf(" %[^\n]", title);
            delete_song(&library, title);
            printf("Song deleted.\n");
        } else if (strcmp(command, "display") == 0) {
            display_library(library);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting.\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
        printf("\n");
    }
    return 0;
}