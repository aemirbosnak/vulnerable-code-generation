//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 50
#define MAX_TITLE 30
#define MAX_ARTIST 20

struct song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
};

struct music_library {
    struct song songs[MAX_SONGS];
    int num_songs;
};

void display_menu();
void add_song(struct music_library *library);
void delete_song(struct music_library *library);
void search_song(struct music_library *library);
void display_songs(struct music_library *library);

int main() {
    struct music_library library;
    library.num_songs = 0;

    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&library);
                break;
            case 2:
                delete_song(&library);
                break;
            case 3:
                search_song(&library);
                break;
            case 4:
                display_songs(&library);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void display_menu() {
    printf("\n");
    printf("1. Add a song\n");
    printf("2. Delete a song\n");
    printf("3. Search for a song\n");
    printf("4. Display all songs\n");
    printf("0. Exit the program\n");
}

void add_song(struct music_library *library) {
    if (library->num_songs >= MAX_SONGS) {
        printf("Music library is full. Delete a song before adding a new one.\n");
        return;
    }

    printf("Enter the title of the song: ");
    scanf("%s", library->songs[library->num_songs].title);
    printf("Enter the artist of the song: ");
    scanf("%s", library->songs[library->num_songs].artist);

    library->num_songs++;
    printf("Song added to music library.\n");
}

void delete_song(struct music_library *library) {
    if (library->num_songs == 0) {
        printf("Music library is empty. Add a song before deleting one.\n");
        return;
    }

    int index;
    printf("Enter the index of the song to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > library->num_songs) {
        printf("Invalid index. Try again.\n");
        return;
    }

    for (int i = index - 1; i < library->num_songs - 1; i++) {
        strcpy(library->songs[i].title, library->songs[i+1].title);
        strcpy(library->songs[i].artist, library->songs[i+1].artist);
    }

    library->num_songs--;
    printf("Song deleted from music library.\n");
}

void search_song(struct music_library *library) {
    if (library->num_songs == 0) {
        printf("Music library is empty. Add a song before searching for one.\n");
        return;
    }

    char title[MAX_TITLE];
    printf("Enter the title of the song to search for: ");
    scanf("%s", title);

    int found = 0;
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(title, library->songs[i].title) == 0) {
            printf("Song found!\n");
            printf("Title: %s\n", library->songs[i].title);
            printf("Artist: %s\n", library->songs[i].artist);
            found = 1;
        }
    }

    if (!found) {
        printf("Song not found.\n");
    }
}

void display_songs(struct music_library *library) {
    if (library->num_songs == 0) {
        printf("Music library is empty. Add a song before displaying all songs.\n");
        return;
    }

    printf("Music library contents:\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("%d. %s - %s\n", i+1, library->songs[i].title, library->songs[i].artist);
    }
}