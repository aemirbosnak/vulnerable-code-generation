//FormAI DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_TITLE_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 30
#define MAX_ALBUM_NAME_LENGTH 30
#define MAX_LIBRARY_SIZE 50

typedef struct Song {
    char title[MAX_SONG_TITLE_LENGTH];
    char artist[MAX_ARTIST_NAME_LENGTH];
    char album[MAX_ALBUM_NAME_LENGTH];
    int year;
} Song;

void print_menu() {
    printf("1. Add a song\n");
    printf("2. Remove a song\n");
    printf("3. Print the list of songs\n");
    printf("4. Quit\n");
}

void add_song(Song library[], int *count) {
    if (*count >= MAX_LIBRARY_SIZE) {
        printf("Error adding song: library is full\n");
        return;
    }
    
    Song new_song;
    
    printf("Enter song title: ");
    fgets(new_song.title, MAX_SONG_TITLE_LENGTH, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = '\0'; // remove newline character from input
    
    printf("Enter artist name: ");
    fgets(new_song.artist, MAX_ARTIST_NAME_LENGTH, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = '\0'; // remove newline character from input
    
    printf("Enter album name: ");
    fgets(new_song.album, MAX_ALBUM_NAME_LENGTH, stdin);
    new_song.album[strcspn(new_song.album, "\n")] = '\0'; // remove newline character from input
    
    printf("Enter year: ");
    scanf("%d", &new_song.year);
    getchar(); // consumes newline character left by scanf
    
    library[*count] = new_song;
    (*count)++;
    
    printf("Song added successfully.\n");
}

void remove_song(Song library[], int *count) {
    char title[MAX_SONG_TITLE_LENGTH];
    
    printf("Enter the title of the song to remove: ");
    fgets(title, MAX_SONG_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0'; // remove newline character from input
    
    int found = 0;
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(library[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                library[j] = library[j+1];
            }
            (*count)--;
            printf("Song removed successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Error removing song: song not found\n");
    }
}

void print_library(Song library[], int count) {
    if (count == 0) {
        printf("Library is empty\n");
        return;
    }
    
    printf("%-30s %-30s %-30s %-10s\n", "Title", "Artist", "Album", "Year");
    printf("-------------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-30s %-30s %-30s %-10d\n", library[i].title, library[i].artist, library[i].album, library[i].year);
    }
}

int main() {
    Song library[MAX_LIBRARY_SIZE];
    int count = 0;
    int selection;
    
    while (1) {
        print_menu();
        printf("Enter your selection: ");
        scanf("%d", &selection);
        getchar(); // consumes newline character left by scanf
        
        switch (selection) {
            case 1:
                add_song(library, &count);
                break;
            case 2:
                remove_song(library, &count);
                break;
            case 3:
                print_library(library, count);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid selection.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}