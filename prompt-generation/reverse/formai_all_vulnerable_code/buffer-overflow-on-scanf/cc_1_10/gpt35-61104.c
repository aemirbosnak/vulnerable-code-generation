//FormAI DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_ARTISTS 100
#define MAX_GENRES 100

typedef struct {
    char title[100];
    char artist[50];
    char genre[50];
    int year;
} Song;

Song songs[MAX_SONGS];
char artists[MAX_ARTISTS][50];
char genres[MAX_GENRES][50];
int num_songs = 0;
int num_artists = 0;
int num_genres = 0;

void print_menu();
void add_song();
void list_songs();
void list_artists();
void list_genres();
void remove_song();
void search_songs();

int main() {
    printf("Welcome to the C Music Library Management System!\n");

    while (1) {
        print_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song();
                break;
            case 2:
                list_songs();
                break;
            case 3:
                list_artists();
                break;
            case 4:
                list_genres();
                break;
            case 5:
                remove_song();
                break;
            case 6:
                search_songs();
                break;
            case 7:
                printf("Thank you for using the C Music Library Management System!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

void print_menu() {
    printf("\n");
    printf("MENU\n");
    printf("1. Add a new song\n");
    printf("2. List all songs\n");
    printf("3. List all artists\n");
    printf("4. List all genres\n");
    printf("5. Remove a song\n");
    printf("6. Search for a song\n");
    printf("7. Quit\n");
}

void add_song() {
    Song new_song;

    printf("Enter title: ");
    scanf("%s", new_song.title);

    printf("Enter artist: ");
    scanf("%s", new_song.artist);

    printf("Enter genre: ");
    scanf("%s", new_song.genre);

    printf("Enter year: ");
    scanf("%d", &new_song.year);

    songs[num_songs++] = new_song;

    int i;
    for (i = 0; i < num_artists; i++) {
        if (strcmp(artists[i], new_song.artist) == 0) {
            break;
        }
    }

    if (i == num_artists) {
        strcpy(artists[num_artists++], new_song.artist);
    }

    for (i = 0; i < num_genres; i++) {
        if (strcmp(genres[i], new_song.genre) == 0) {
            break;
        }
    }

    if (i == num_genres) {
        strcpy(genres[num_genres++], new_song.genre);
    }

    printf("Song added successfully!\n");
}

void list_songs() {
    printf("\n");
    printf("LIST OF SONGS\n");

    int i;
    for (i = 0; i < num_songs; i++) {
        printf("%d. %s - %s (%s) [%d]\n", (i+1), songs[i].artist, songs[i].title, songs[i].genre, songs[i].year);
    }
}

void list_artists() {
    printf("\n");
    printf("LIST OF ARTISTS\n");

    int i;
    for (i = 0; i < num_artists; i++) {
        printf("%d. %s\n", (i+1), artists[i]);
    }
}

void list_genres() {
    printf("\n");
    printf("LIST OF GENRES\n");

    int i;
    for (i = 0; i < num_genres; i++) {
        printf("%d. %s\n", (i+1), genres[i]);
    }
}

void remove_song() {
    int index;

    printf("Enter song index to remove: ");
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= num_songs) {
        printf("Invalid song index!\n");
        return;
    }

    Song removed_song = songs[index];
    int i;
    for (i = index; i < num_songs - 1; i++) {
        songs[i] = songs[i+1];
    }
    num_songs--;

    for (i = 0; i < num_artists; i++) {
        if (strcmp(artists[i], removed_song.artist) == 0) {
            break;
        }
    }

    int j;
    for (j = i; j < num_artists - 1; j++) {
        strcpy(artists[j], artists[j+1]);
    }
    num_artists--;

    for (i = 0; i < num_genres; i++) {
        if (strcmp(genres[i], removed_song.genre) == 0) {
            break;
        }
    }

    for (j = i; j < num_genres - 1; j++) {
        strcpy(genres[j], genres[j+1]);
    }
    num_genres--;

    printf("Song removed successfully!\n");
}

void search_songs() {
    char term[50];

    printf("Enter search term: ");
    scanf("%s", term);

    int i;
    for (i = 0; i < num_songs; i++) {
        if (strstr(songs[i].title, term) || strstr(songs[i].artist, term) || strstr(songs[i].genre, term)) {
            printf("%d. %s - %s (%s) [%d]\n", (i+1), songs[i].artist, songs[i].title, songs[i].genre, songs[i].year);
        }
    }
}