//FormAI DATASET v1.0 Category: Music Library Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char title[50];
    char artist[50];
    float duration;
    int rating;
} Song;

Song* songs[100];
int num_songs = 0;

void addSong(char title[], char artist[], float duration, int rating) {
    Song* new_song = (Song*) malloc(sizeof(Song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    new_song->duration = duration;
    new_song->rating = rating;
    songs[num_songs] = new_song;
    num_songs++;
}

Song* searchSong(char title[]) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i]->title, title) == 0) {
            return songs[i];
        }
    }
    return NULL;
}

void displaySong(Song* song) {
    printf("Title: %s\nArtist: %s\nDuration: %.2f\nRating: %d\n", 
            song->title, song->artist, song->duration, song->rating);
}

void displayAllSongs() {
    printf("All Songs:\n");
    for (int i = 0; i < num_songs; i++) {
        displaySong(songs[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    char title[50], artist[50];
    float duration;
    int rating;

    do {
        printf("1. Add song\n2. Search song\n3. Display all songs\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1:
                printf("Enter title: ");
                scanf("%s", title);
                fflush(stdin);
                printf("Enter artist: ");
                scanf("%s", artist);
                fflush(stdin);
                printf("Enter duration: ");
                scanf("%f", &duration);
                fflush(stdin);
                printf("Enter rating (out of 10): ");
                scanf("%d", &rating);
                fflush(stdin);
                addSong(title, artist, duration, rating);
                printf("Song added successfully!\n\n");
                break;
            
            case 2:
                printf("Enter title of song to search: ");
                scanf("%s", title);
                fflush(stdin);
                Song* found_song = searchSong(title);
                if (found_song == NULL) {
                    printf("Song not found.\n\n");
                } else {
                    displaySong(found_song);
                    printf("\n");
                }
                break;

            case 3:
                displayAllSongs();
                break;

            case 4:
                printf("Exiting program.");
                break;

            default:
                printf("Invalid choice. Please choose again.\n\n");
                break;
        }

    } while (choice != 4);
    
    return 0;
}