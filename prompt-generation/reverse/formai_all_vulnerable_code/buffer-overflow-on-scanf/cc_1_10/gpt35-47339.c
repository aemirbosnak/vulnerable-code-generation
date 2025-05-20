//FormAI DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 50

struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int year;
    int rating;
};

void add_song(struct song* library, int* num_songs);
void print_song(struct song* library, int num_songs);
void search_song(struct song* library, int num_songs);
void remove_song(struct song* library, int* num_songs);

int main() {
    int num_songs = 0, choice;
    struct song* library = malloc(sizeof(struct song));
    printf("Welcome to the C Music Library Management System!\n");

    do {
        printf("Select an option:\n");
        printf("1. Add Song\n");
        printf("2. Print Library\n");
        printf("3. Search Song\n");
        printf("4. Remove Song\n");
        printf("5. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                print_song(library, num_songs);
                break;
            case 3:
                search_song(library, num_songs);
                break;
            case 4:
                remove_song(library, &num_songs);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    free(library);

    return 0;
}

void add_song(struct song* library, int* num_songs) {
    printf("Enter song title: ");
    scanf("%s", library[*num_songs].title);
    printf("Enter artist: ");
    scanf("%s", library[*num_songs].artist);
    printf("Enter album: ");
    scanf("%s", library[*num_songs].album);
    printf("Enter year: ");
    scanf("%d", &library[*num_songs].year);
    printf("Enter rating (1-5): ");
    scanf("%d", &library[*num_songs].rating);
    *num_songs += 1;
    library = realloc(library, (*num_songs + 1) * sizeof(struct song));
    printf("Song added!\n");
}

void print_song(struct song* library, int num_songs) {
    if(num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }
    printf("Song Title      Artist          Album               Year    Rating\n");
    printf("==================================================================\n");
    for(int i=0; i<num_songs; i++) {
        printf("%-15s %-15s %-20s %-7d %-5d\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].rating);
    }
}

void search_song(struct song* library, int num_songs) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter song title: ");
    scanf("%s", title);
    for(int i=0; i<num_songs; i++) {
        if(strcmp(title, library[i].title) == 0) {
            printf("Song Found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Artist: %s\n", library[i].artist);
            printf("Album: %s\n", library[i].album);
            printf("Year: %d\n", library[i].year);
            printf("Rating: %d\n", library[i].rating);
            return;
        }
    }
    printf("Song not found\n");
}

void remove_song(struct song* library, int* num_songs) {
    char title[MAX_TITLE_LENGTH];
    printf("Enter song title to remove: ");
    scanf("%s", title);
    for(int i=0; i<*num_songs; i++) {
        if(strcmp(title, library[i].title) == 0) {
            printf("Song Removed!\n");
            for(int j=i; j<*num_songs-1; j++) {
                library[j] = library[j+1];
            }
            *num_songs -= 1;
            library = realloc(library, (*num_songs + 1) * sizeof(struct song));
            return;
        }
    }
    printf("Song not found\n");
}