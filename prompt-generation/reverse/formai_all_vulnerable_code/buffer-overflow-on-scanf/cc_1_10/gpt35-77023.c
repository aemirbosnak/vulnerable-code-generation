//FormAI DATASET v1.0 Category: Music Library Management System ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_LIBRARIES 10
#define MAX_SONGS 100

typedef struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int rating;
} Song;

typedef struct Library {
    char name[50];
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

Library libraries[MAX_LIBRARIES];
int num_libraries = 0;

void add_song_to_library(int library_index, Song song) {
    if (libraries[library_index].num_songs >= MAX_SONGS) {
        printf("Error: maximum number of songs reached for library '%s'\n", libraries[library_index].name);
        return;
    }
    libraries[library_index].songs[libraries[library_index].num_songs] = song;
    libraries[library_index].num_songs++;
}

void add_library(char name[]) {
    if (num_libraries >= MAX_LIBRARIES) {
        printf("Error: maximum number of libraries reached\n");
        return;
    }
    strcpy(libraries[num_libraries].name, name);
    libraries[num_libraries].num_songs = 0;
    num_libraries++;
}

void print_song(Song song) {
    printf("%s\t%s\t%s\t%d\t%d/5\n", song.title, song.artist, song.album, song.year, song.rating);
}

void print_library(int library_index) {
    int i;
    printf("Library: %s\n", libraries[library_index].name);
    printf("Title\tArtist\tAlbum\tYear\tRating\n");
    for (i = 0; i < libraries[library_index].num_songs; i++) {
        print_song(libraries[library_index].songs[i]);
    }
}

int main() {
    int i;
    char input_choice;
    char input_string[50];
    int input_int;
    Song input_song;

    printf("Welcome to the Music Library Management System!\n");

    while (1) {
        printf("============================================\n");
        printf("Choose an option:\n");
        printf("a) Add a library\n");
        printf("b) Add a song to a library\n");
        printf("c) View a library\n");
        printf("x) Exit\n");
        printf("============================================\n");

        input_choice = getchar();
        while (getchar() != '\n');

        switch (input_choice) {
            case 'a':
                printf("Enter the name of the library: ");
                fgets(input_string, 50, stdin);
                input_string[strlen(input_string)-1] = '\0';
                add_library(input_string);
                break;
            case 'b':
                printf("Enter the index of the library: ");
                scanf("%d", &input_int);
                while (getchar() != '\n');

                if (input_int >= num_libraries) {
                    printf("Error: invalid library index\n");
                    break;
                }

                printf("Enter the title of the song: ");
                fgets(input_string, 50, stdin);
                input_string[strlen(input_string)-1] = '\0';
                strcpy(input_song.title, input_string);

                printf("Enter the artist of the song: ");
                fgets(input_string, 50, stdin);
                input_string[strlen(input_string)-1] = '\0';
                strcpy(input_song.artist, input_string);

                printf("Enter the album of the song: ");
                fgets(input_string, 50, stdin);
                input_string[strlen(input_string)-1] = '\0';
                strcpy(input_song.album, input_string);

                printf("Enter the year of the song: ");
                scanf("%d", &input_int);
                while (getchar() != '\n');
                input_song.year = input_int;

                printf("Enter the rating of the song (1-5): ");
                scanf("%d", &input_int);
                while (getchar() != '\n');
                input_song.rating = input_int;

                add_song_to_library(input_int, input_song);
                break;
            case 'c':
                printf("Enter the index of the library: ");
                scanf("%d", &input_int);
                while (getchar() != '\n');

                if (input_int >= num_libraries) {
                    printf("Error: invalid library index\n");
                    break;
                }

                print_library(input_int);
                break;
            case 'x':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Error: invalid input\n");
                break;
        }
    }
}