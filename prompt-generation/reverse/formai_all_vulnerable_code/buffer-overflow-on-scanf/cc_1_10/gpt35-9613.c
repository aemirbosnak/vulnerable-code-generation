//FormAI DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
};

void add_song(struct Song* song_array, int* song_count) {
    struct Song new_song;
    printf("Enter song name: ");
    scanf("%s", new_song.name);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter album name: ");
    scanf("%s", new_song.album);
    printf("Enter year: ");
    scanf("%d", &new_song.year);
    printf("Enter genre: ");
    scanf("%s", new_song.genre);
    song_array[*song_count] = new_song;
    (*song_count)++;
    printf("Song added successfully!\n");
}

void display_songs(struct Song* song_array, int song_count) {
    printf("Name\tArtist\tAlbum\tYear\tGenre\n");
    for (int i = 0; i < song_count; i++) {
        printf("%s\t%s\t%s\t%d\t%s\n", song_array[i].name, song_array[i].artist, song_array[i].album, song_array[i].year, song_array[i].genre);
    }
}

void search_song(struct Song* song_array, int song_count) {
    char search_name[50];
    printf("Enter song name to be searched: ");
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < song_count; i++) {
        if (strcmp(song_array[i].name, search_name) == 0) {
            printf("Song found!\n");
            printf("Name\tArtist\tAlbum\tYear\tGenre\n");
            printf("%s\t%s\t%s\t%d\t%s\n", song_array[i].name, song_array[i].artist, song_array[i].album, song_array[i].year, song_array[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found!\n");
    }
}

void delete_song(struct Song* song_array, int* song_count) {
    char delete_name[50];
    printf("Enter song name to be deleted: ");
    scanf("%s", delete_name);
    int found = 0;
    for (int i = 0; i < *song_count; i++) {
        if (strcmp(song_array[i].name, delete_name) == 0) {
            for (int j = i; j < *song_count - 1; j++) {
                song_array[j] = song_array[j + 1];
            }
            (*song_count)--;
            printf("Song deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found!\n");
    }
}

int main() {
    struct Song song_array[100];
    int song_count = 0;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song(song_array, &song_count);
                break;
            case 2:
                display_songs(song_array, song_count);
                break;
            case 3:
                search_song(song_array, song_count);
                break;
            case 4:
                delete_song(song_array, &song_count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}