//FormAI DATASET v1.0 Category: Music Library Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // maximum number of songs in the library
#define MAX_TITLE_LENGTH 50 // maximum length of song title
#define MAX_ARTIST_LENGTH 30 // maximum length of artist name
#define MAX_ALBUM_LENGTH 30 // maximum length of album title

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

void print_menu() {
    printf("\n\n");
    printf("C Music Library Management System\n");
    printf("1. Add Song\n");
    printf("2. Remove Song\n");
    printf("3. Search Song\n");
    printf("4. Print Library\n");
    printf("5. Exit\n\n");
}

void add_song(Library *lib) {
    if (lib->num_songs >= MAX_SONGS) {
        printf("Error: Library is full\n");
        return;
    }
    
    Song new_song;
    printf("Enter song title: ");
    scanf("%s", new_song.title);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter album title: ");
    scanf("%s", new_song.album);
    
    lib->songs[lib->num_songs] = new_song;
    lib->num_songs++;
    printf("Song added successfully!\n");
}

void remove_song(Library *lib) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter song title to remove: ");
    scanf("%s", title);
    
    int found_song = 0;
    for (int i=0; i<lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            found_song = 1;
            
            // shift all elements in the array after this song to the left
            for (int j=i; j<lib->num_songs-1; j++) {
                lib->songs[j] = lib->songs[j+1];
            }
            
            lib->num_songs--;
            printf("Song \"%s\" removed successfully!\n", title);
            break;
        }
    }
    
    if (!found_song) {
        printf("Error: Song not found\n");
    }
}

void search_song(Library *lib) {
    char keyword[MAX_TITLE_LENGTH];
    printf("Enter keyword to search for: ");
    scanf("%s", keyword);
    
    int found_song = 0;
    for (int i=0; i<lib->num_songs; i++) {
        if (strstr(lib->songs[i].title, keyword) != NULL || strstr(lib->songs[i].artist, keyword) != NULL || strstr(lib->songs[i].album, keyword) != NULL) {
            found_song = 1;
            printf("Title: %s\nArtist: %s\nAlbum: %s\n\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album);
        }
    }
    
    if (!found_song) {
        printf("No songs found\n");
    }
}

void print_library(Library *lib) {
    printf("Library:\n");
    for (int i=0; i<lib->num_songs; i++) {
        printf("Title: %s\nArtist: %s\nAlbum: %s\n\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album);
    }
}

int main() {
    Library my_library = {0};
    int choice = 0;
    
    while (choice != 5) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_song(&my_library);
                break;
            case 2:
                remove_song(&my_library);
                break;
            case 3:
                search_song(&my_library);
                break;
            case 4:
                print_library(&my_library);
                break;
            case 5:
                printf("Exiting...Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    
    return 0;
}