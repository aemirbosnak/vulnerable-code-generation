//FormAI DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void print_menu();
void add_song();
void remove_song();
void display_library();
void search_song();

struct song {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char album[MAX_SIZE];
};

struct song library[MAX_SIZE];
int num_songs = 0;

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                display_library();
                break;
            case 4:
                search_song();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}

void print_menu() {
    printf("\n");
    printf("---------------\n");
    printf(" Music Library\n");
    printf("---------------\n");
    printf("[1] Add Song\n");
    printf("[2] Remove Song\n");
    printf("[3] Display Library\n");
    printf("[4] Search Song\n");
    printf("[0] Exit\n");
    printf("Enter your choice: ");
}

void add_song() {
    if(num_songs == MAX_SIZE) {
        printf("Library is full. Cannot add more songs.\n");
        return;
    }

    struct song new_song;

    printf("Enter song title: ");
    scanf(" %[^\n]s", new_song.title);

    printf("Enter artist name: ");
    scanf(" %[^\n]s", new_song.artist);

    printf("Enter album name: ");
    scanf(" %[^\n]s", new_song.album);

    library[num_songs] = new_song;
    num_songs++;

    printf("\nAdded song successfully.\n");
}

void remove_song() {
    if(num_songs == 0) {
        printf("Library is empty. Cannot remove any songs.\n");
        return;
    }

    char title[MAX_SIZE];
    char artist[MAX_SIZE];

    printf("Enter song title: ");
    scanf(" %[^\n]s", title);

    printf("Enter artist name: ");
    scanf(" %[^\n]s", artist);

    for(int i = 0; i < num_songs; i++) {
        if(strcmp(title, library[i].title) == 0 && strcmp(artist, library[i].artist) == 0) {
            for(int j = i; j < num_songs-1; j++) {
                library[j] = library[j+1];
            }
            num_songs--;
            printf("\nRemoved song successfully.\n");
            return;
        }
    }

    printf("\nCannot find song in library.\n");
}

void display_library() {
    printf("\n%s\t%15s\t%15s\n", "Title", "Artist", "Album");
    printf("-------------------------------------------------------------\n");
    if(num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    for(int i = 0; i < num_songs; i++) {
        printf("%s\t%15s\t%15s\n", library[i].title, library[i].artist, library[i].album);
    }
}

void search_song() {
    if(num_songs == 0) {
        printf("Library is empty. Cannot search for any songs.\n");
        return;
    }

    char search_query[MAX_SIZE];

    printf("Enter search query: ");
    scanf(" %[^\n]s", search_query);

    printf("\n%s\t%15s\t%15s\n", "Title", "Artist", "Album");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < num_songs; i++) {
        if(strstr(library[i].title, search_query) != NULL || strstr(library[i].artist, search_query) != NULL || strstr(library[i].album, search_query) != NULL) {
            printf("%s\t%15s\t%15s\n", library[i].title, library[i].artist, library[i].album);
        }
    }
}