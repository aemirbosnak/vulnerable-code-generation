//FormAI DATASET v1.0 Category: Music Library Management System ; Style: excited
/* Welcome to the C Music Library Management System! */

#include <stdio.h>
#include <string.h>

#define MAX_SONGS 1000

/* This program allows users to add, delete, and search for songs in their music library */

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

struct song music_library[MAX_SONGS]; //Initialize array of songs

int num_songs = 0; //Initialize number of songs

void add_song() {
    struct song new_song;
    printf("Enter title: ");
    scanf("%s", new_song.title);
    printf("Enter artist: ");
    scanf("%s", new_song.artist);
    printf("Enter album: ");
    scanf("%s", new_song.album);
    printf("Enter year: ");
    scanf("%d", &new_song.year);
    music_library[num_songs++] = new_song;
    printf("Song added to library!\n");
}

void delete_song() {
    char title[50];
    printf("Enter title: ");
    scanf("%s", title);
    for(int i = 0; i < num_songs; i++) {
        if(strcmp(title, music_library[i].title) == 0) {
            for(int j = i; j < num_songs - 1; j++) {
                music_library[j] = music_library[j+1];
            }
            num_songs--;
            printf("Song deleted from library!\n");
            return;
        }
    }
    printf("Song not found in library.\n");
}

void search_song() {
    char title[50];
    printf("Enter title: ");
    scanf("%s", title);
    for(int i = 0; i < num_songs; i++) {
        if(strcmp(title, music_library[i].title) == 0) {
            printf("Title: %s\n", music_library[i].title);
            printf("Artist: %s\n", music_library[i].artist);
            printf("Album: %s\n", music_library[i].album);
            printf("Year: %d\n", music_library[i].year);
            return;
        }
    }
    printf("Song not found in library.\n");
}

void display_library() {
    for(int i = 0; i < num_songs; i++) {
        printf("Title: %s\n", music_library[i].title);
        printf("Artist: %s\n", music_library[i].artist);
        printf("Album: %s\n", music_library[i].album);
        printf("Year: %d\n", music_library[i].year);
        printf("\n");
    }
}

int main() {
    int choice;
    printf("Welcome to the C Music Library Management System!\n");
    do {
        printf("Please select an option: \n");
        printf("1. Add song\n");
        printf("2. Delete song\n");
        printf("3. Search song\n");
        printf("4. Display library\n");
        printf("5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                delete_song();
                break;
            case 3:
                search_song();
                break;
            case 4:
                display_library();
                break;
            case 5:
                printf("Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}