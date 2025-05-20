//FormAI DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 //maximum size of the library

typedef struct {
    char song_title[50];
    char artist_name[50];
    char genre[20];
    int year;
} Song;

Song library[MAX_SIZE]; //array to store the songs in the library
int num_songs = 0; //store the number of songs in the library

int add_song(void) {
    if (num_songs == MAX_SIZE) { //check if the library is full
        printf("Sorry, the music library is full.\n");
        return 0;
    }
    else {
        Song new_song;
        printf("Enter the song title: ");
        scanf("%s", new_song.song_title);
        printf("Enter the artist name: ");
        scanf("%s", new_song.artist_name);
        printf("Enter the genre: ");
        scanf("%s", new_song.genre);
        printf("Enter the year: ");
        scanf("%d", &new_song.year);
        library[num_songs] = new_song;
        num_songs++;
        printf("Song added successfully.\n");
        return 1;
    }
}

int delete_song(void) {
    char song_title[50];
    printf("Enter the song title to delete: ");
    scanf("%s", song_title);
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].song_title, song_title) == 0) {
            for (int j = i; j < num_songs - 1; j++) {
                library[j] = library[j+1];
            }
            num_songs--;
            printf("Song deleted successfully.\n");
            return 1;
        }
    }
    printf("Song not found.\n");
    return 0;
}

void print_menu(void) {
    printf("\n\n");
    printf("C Music Library Management System\n");
    printf("==================================\n");
    printf("1. Add a new song\n");
    printf("2. Delete a song\n");
    printf("3. Print all songs\n");
    printf("4. Exit\n");
}

void print_songs(void) {
    printf("\n\n");
    printf("Song Title\t\tArtist\t\tGenre\tYear\n");
    printf("=========================================================\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%-20s\t%-20s\t%-10s\t%d\n", 
               library[i].song_title, library[i].artist_name, library[i].genre, library[i].year);
    }
}

int main(void) {
    int choice;
    do {
        print_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                delete_song();
                break;
            case 3:
                print_songs();
                break;
            case 4:
                printf("Thank you for using C Music Library Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}