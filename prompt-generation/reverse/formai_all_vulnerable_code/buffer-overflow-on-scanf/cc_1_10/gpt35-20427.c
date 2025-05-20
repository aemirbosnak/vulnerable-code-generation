//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int track_number;
};

int total_songs = 0;
struct Song song_list[100];

void add_song() {
    printf("Enter the song title: ");
    scanf("%s", song_list[total_songs].title);

    printf("Enter the song artist: ");
    scanf("%s", song_list[total_songs].artist);

    printf("Enter the song album: ");
    scanf("%s", song_list[total_songs].album);

    printf("Enter the song track number: ");
    scanf("%d", &song_list[total_songs].track_number);

    total_songs++;
}

void display_songs() {
    printf("\nSong Library:\n");
    for(int i=0; i<total_songs; i++) {
        printf("Title: %s\n", song_list[i].title);
        printf("Artist: %s\n", song_list[i].artist);
        printf("Album: %s\n", song_list[i].album);
        printf("Track Number: %d\n", song_list[i].track_number);
        printf("\n");
    }
}

void search_song() {
    char search_title[100];
    printf("Enter the song title to search: ");
    scanf("%s", search_title);

    for(int i=0; i<total_songs; i++) {
        if(strcmp(search_title, song_list[i].title) == 0) {
            printf("Title: %s\n", song_list[i].title);
            printf("Artist: %s\n", song_list[i].artist);
            printf("Album: %s\n", song_list[i].album);
            printf("Track Number: %d\n", song_list[i].track_number);
            return;
        }
    }

    printf("Song not found.\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Music Library Management System ---\n");
        printf("1. Add song\n");
        printf("2. Display songs\n");
        printf("3. Search song\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;

            case 2:
                display_songs();
                break;

            case 3:
                search_song();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}