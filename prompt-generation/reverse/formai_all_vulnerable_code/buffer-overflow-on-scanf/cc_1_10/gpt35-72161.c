//FormAI DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 30
#define MAX_ALBUM_LEN 30
#define MAX_YEAR_LEN 4
#define MAX_SONGS 100

struct Song {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char album[MAX_ALBUM_LEN];
    char year[MAX_YEAR_LEN];
};

int add_song(struct Song[], int);
void display_songs(struct Song[], int);
int search_song(struct Song[], int, char[], char[]);
void delete_song(struct Song[], int);

int main() {
    struct Song songs[MAX_SONGS];
    char choice, title[MAX_TITLE_LEN], artist[MAX_ARTIST_LEN];
    int num_songs = 0, index;

    do {
       printf("\n----C MUSIC LIBRARY MANAGEMENT SYSTEM----\n");
       printf("1. Add a song\n");
       printf("2. Display all songs\n");
       printf("3. Search a song\n");
       printf("4. Delete a song\n");
       printf("5. Exit\n\n");

       printf("Enter your choice: ");
       scanf(" %c", &choice);

       switch(choice) {
            case '1':
                num_songs = add_song(songs, num_songs);
                printf("\nSong added successfully!\n");
                break;

            case '2':
                display_songs(songs, num_songs);
                break;

            case '3':
                printf("\nEnter song title: ");
                scanf(" %[^\n]%*c", title);

                printf("Enter artist name: ");
                scanf(" %[^\n]%*c", artist);

                index = search_song(songs, num_songs, title, artist);

                if (index == -1) {
                    printf("\nSong not found!\n");
                } else {
                    printf("\nSong found at index %d.\n", index);
                }

                break;

            case '4':
                delete_song(songs, num_songs);
                printf("\nSong deleted successfully!\n");
                num_songs--;
                break;

            case '5':
                printf("\nExiting the program...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please select a valid option.\n");
        }

    } while (1);

    return 0;
}

int add_song(struct Song songs[], int num_songs) {
    printf("\nEnter song title: ");
    scanf(" %[^\n]%*c", songs[num_songs].title);

    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", songs[num_songs].artist);

    printf("Enter album name: ");
    scanf(" %[^\n]%*c", songs[num_songs].album);

    printf("Enter year: ");
    scanf(" %[^\n]%*c", songs[num_songs].year);

    num_songs++;

    return num_songs;
}

void display_songs(struct Song songs[], int num_songs) {
    printf("\nSONGS:\n");

    for (int i = 0; i < num_songs; i++) {
        printf("%d. Title: %s | Artist: %s | Album: %s | Year: %s\n", i+1, songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
    }
}

int search_song(struct Song songs[], int num_songs, char title[], char artist[]) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(songs[i].title, title) == 0 && strcmp(songs[i].artist, artist) == 0) {
            return i;
        }
    }

    return -1;
}

void delete_song(struct Song songs[], int num_songs) {
    char title[MAX_TITLE_LEN], artist[MAX_ARTIST_LEN]; 
    int index;

    printf("\nEnter song title: ");
    scanf(" %[^\n]%*c", title);

    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", artist);

    index = search_song(songs, num_songs, title, artist);

    if (index == -1) {
        printf("\nSong not found!\n");
    } else {
        for (int i = index; i < num_songs-1; i++) {
            strcpy(songs[i].title, songs[i+1].title);
            strcpy(songs[i].artist, songs[i+1].artist);
            strcpy(songs[i].album, songs[i+1].album);
            strcpy(songs[i].year, songs[i+1].year);
        }
    }
}