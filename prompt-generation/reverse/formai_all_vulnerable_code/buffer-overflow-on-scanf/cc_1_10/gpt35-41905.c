//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 30
#define MAX_GENRE_LEN 20

// Structure for storing song details
struct song {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    char genre[MAX_GENRE_LEN];
    int year;
    int duration;
};

// Function prototypes
void add_song(struct song[], int*);
void delete_song(struct song[], int*);
void display_songs(struct song[], int);
void search_songs(struct song[], int);

int main() {
    int num_songs = 0;
    struct song songs[MAX_SONGS];
    int choice;

    while (1) {
        printf("\n\n*****C Music Library Management System*****\n");
        printf("1. Add a new song\n");
        printf("2. Delete a song\n");
        printf("3. Display all songs\n");
        printf("4. Search songs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(songs, &num_songs);
                break;
            case 2:
                delete_song(songs, &num_songs);
                break;
            case 3:
                display_songs(songs, num_songs);
                break;
            case 4:
                search_songs(songs, num_songs);
                break;
            case 5:
                printf("Thank you for using the C Music Library Management System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid one.\n");
        }
    }

    return 0;
}

// Function to add a new song
void add_song(struct song songs[], int *num_songs) {
    if (*num_songs == MAX_SONGS) {
        printf("Sorry, the library is full and can't store any more songs.\n");
        return;
    }

    printf("\nEnter the details of the song:\n");
    printf("Title: ");
    getchar();
    fgets(songs[*num_songs].title, MAX_TITLE_LEN, stdin);
    printf("Artist: ");
    fgets(songs[*num_songs].artist, MAX_ARTIST_LEN, stdin);
    printf("Genre: ");
    fgets(songs[*num_songs].genre, MAX_GENRE_LEN, stdin);
    printf("Year: ");
    scanf("%d", &songs[*num_songs].year);
    printf("Duration (in seconds): ");
    scanf("%d", &songs[*num_songs].duration);

    (*num_songs)++;
    printf("Song added successfully!\n");
}

// Function to delete a song
void delete_song(struct song songs[], int *num_songs) {
    if (*num_songs == 0) {
        printf("Sorry, the library is empty and there are no songs to delete.\n");
        return;
    }

    char title[MAX_TITLE_LEN];
    printf("\nEnter the title of the song to delete: ");
    getchar();
    fgets(title, MAX_TITLE_LEN, stdin);

    int found = 0;
    for (int i = 0; i < *num_songs; i++) {
        if (strcmp(songs[i].title, title) == 0) {
            found = 1;
            for (int j = i; j < (*num_songs - 1); j++) {
                songs[j] = songs[j + 1];
            }
            (*num_songs)--;
            printf("Song deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Sorry, the song could not be found in the library.\n");
    }
}

// Function to display all songs
void display_songs(struct song songs[], int num_songs) {
    if (num_songs == 0) {
        printf("Sorry, the library is empty and there are no songs to display.\n");
    } else {
        printf("\nList of all songs in the library:\n\n");
        printf("%-30s %-20s %-20s %-10s %-10s\n", "Title", "Artist", "Genre", "Year", "Duration");
        printf("------------------------------------------------------------------------------\n");
        for (int i = 0; i < num_songs; i++) {
            printf("%-30s %-20s %-20s %-10d %-10d\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].year, songs[i].duration);
        }
    }
}

// Function to search songs by title or artist
void search_songs(struct song songs[], int num_songs) {
    if (num_songs == 0) {
        printf("Sorry, the library is empty and there are no songs to search.\n");
        return;
    }

    char keyword[MAX_TITLE_LEN];
    printf("\nEnter a keyword to search: ");
    getchar();
    fgets(keyword, MAX_TITLE_LEN, stdin);

    int found = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strstr(songs[i].title, keyword) != NULL || strstr(songs[i].artist, keyword) != NULL) {
            found = 1;
            printf("%-30s %-20s %-20s %-10d %-10d\n", songs[i].title, songs[i].artist, songs[i].genre, songs[i].year, songs[i].duration);
        }
    }

    if (!found) {
        printf("Sorry, no songs matching the keyword were found in the library.\n");
    }
}