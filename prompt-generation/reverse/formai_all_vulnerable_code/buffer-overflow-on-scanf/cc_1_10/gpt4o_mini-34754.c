//GPT-4o-mini DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define TITLE_LENGTH 50
#define ARTIST_LENGTH 50
#define ALBUM_LENGTH 50

typedef struct {
    char title[TITLE_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[ALBUM_LENGTH];
    int year;
} Song;

Song library[MAX_SONGS];
int song_count = 0;

void add_song() {
    if (song_count >= MAX_SONGS) {
        printf("Library is full! Cannot add more songs.\n");
        return;
    }

    printf("Enter song title: ");
    scanf(" %[^\n]", library[song_count].title);
    printf("Enter artist name: ");
    scanf(" %[^\n]", library[song_count].artist);
    printf("Enter album name: ");
    scanf(" %[^\n]", library[song_count].album);
    printf("Enter release year: ");
    scanf("%d", &library[song_count].year);
    
    song_count++;
    printf("Song added successfully!\n");
}

void view_songs() {
    if (song_count == 0) {
        printf("No songs in the library!\n");
        return;
    }
    printf("\n--- Music Library ---\n");
    for (int i = 0; i < song_count; i++) {
        printf("Song %d:\n", i + 1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("-------------------------\n");
    }
}

void search_song() {
    char search_title[TITLE_LENGTH];
    printf("Enter song title to search: ");
    scanf(" %[^\n]", search_title);

    int found = 0;
    for (int i = 0; i < song_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) {
            printf("\nSong found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Song not found in the library.\n");
    }
}

void display_menu() {
    printf("\n--- Music Library Management System ---\n");
    printf("1. Add Song\n");
    printf("2. View All Songs\n");
    printf("3. Search Song\n");
    printf("4. Exit\n");
    printf("---------------------------------------\n");
}

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                view_songs();
                break;
            case 3:
                search_song();
                break;
            case 4:
                printf("Exiting the program! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}