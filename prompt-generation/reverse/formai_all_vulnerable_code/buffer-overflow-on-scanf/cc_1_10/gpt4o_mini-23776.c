//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define GENRE_LENGTH 30

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char genre[GENRE_LENGTH];
    int release_year;
    float rating; // Scale of 0.0 to 5.0
} Album;

Album music_library[MAX_ALBUMS];
int album_count = 0;

void add_album() {
    if (album_count >= MAX_ALBUMS) {
        printf("Music Library is full! Cannot add more albums.\n");
        return;
    }
    Album new_album;
    printf("Enter album title: ");
    scanf(" %[^\n]", new_album.title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", new_album.artist);
    printf("Enter genre: ");
    scanf(" %[^\n]", new_album.genre);
    printf("Enter release year: ");
    scanf("%d", &new_album.release_year);
    printf("Enter rating (0.0 to 5.0): ");
    scanf("%f", &new_album.rating);

    music_library[album_count] = new_album;
    album_count++;
    printf("Album added successfully!\n");
}

void display_albums() {
    if (album_count == 0) {
        printf("No albums in the library.\n");
        return;
    }
    printf("\nMusic Library Albums:\n");
    for (int i = 0; i < album_count; i++) {
        printf("Album %d:\n", i + 1);
        printf("Title: %s\n", music_library[i].title);
        printf("Artist: %s\n", music_library[i].artist);
        printf("Genre: %s\n", music_library[i].genre);
        printf("Release Year: %d\n", music_library[i].release_year);
        printf("Rating: %.1f\n", music_library[i].rating);
        printf("------------\n");
    }
}

void search_album() {
    char search_title[TITLE_LENGTH];
    printf("Enter album title to search: ");
    scanf(" %[^\n]", search_title);
    int found = 0;
    
    for (int i = 0; i < album_count; i++) {
        if (strcmp(music_library[i].title, search_title) == 0) {
            printf("Album found!\n");
            printf("Title: %s\n", music_library[i].title);
            printf("Artist: %s\n", music_library[i].artist);
            printf("Genre: %s\n", music_library[i].genre);
            printf("Release Year: %d\n", music_library[i].release_year);
            printf("Rating: %.1f\n", music_library[i].rating);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Album not found.\n");
    }
}

void display_menu() {
    printf("Music Library Management System\n");
    printf("1. Add Album\n");
    printf("2. Display Albums\n");
    printf("3. Search Album\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                display_albums();
                break;
            case 3:
                search_album();
                break;
            case 4:
                printf("Exiting the Music Library Management System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}