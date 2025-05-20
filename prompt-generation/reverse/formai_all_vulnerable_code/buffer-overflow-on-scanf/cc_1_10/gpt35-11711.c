//FormAI DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    int year;
};

void display_song(struct song s) { // function to display a song's details
    printf("\nTitle: %s\n", s.title);
    printf("Artist: %s\n", s.artist);
    printf("Year released: %d\n", s.year);
}

void add_song(struct song library[], int *num_songs) { // function to add a song to the library
    struct song new_song;
    printf("\nEnter the details of the new song below:\n");
    printf("Title: ");
    getchar(); // to absorb the newline character in the input buffer
    fgets(new_song.title, 50, stdin);
    new_song.title[strcspn(new_song.title, "\n")] = 0; // to remove the newline character from the end of the string
    printf("Artist: ");
    fgets(new_song.artist, 50, stdin);
    new_song.artist[strcspn(new_song.artist, "\n")] = 0;
    printf("Year released: ");
    scanf("%d", &new_song.year);
    library[*num_songs] = new_song;
    *num_songs += 1;
    printf("Song added successfully!\n");
}

void delete_song(struct song library[], int *num_songs) { // function to delete a song from the library
    char search_title[50];
    int found_song_index = -1;
    printf("\nEnter the title of the song you want to delete: ");
    getchar();
    fgets(search_title, 50, stdin);
    search_title[strcspn(search_title, "\n")] = 0;
    for (int i = 0; i < *num_songs; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            found_song_index = i;
            break;
        }
    }
    if (found_song_index != -1) {
        for (int i = found_song_index; i < *num_songs - 1; i++) {
            library[i] = library[i + 1];
        }
        *num_songs -= 1;
        printf("Song deleted successfully!\n");
    } else {
        printf("Sorry, that song is not in the library.\n");
    }
}

void search_song(struct song library[], int num_songs) { // function to search for a song in the library
    char search_title[50];
    int found_song_index = -1;
    printf("\nEnter the title of the song you want to search for: ");
    getchar();
    fgets(search_title, 50, stdin);
    search_title[strcspn(search_title, "\n")] = 0;
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            found_song_index = i;
            break;
        }
    }
    if (found_song_index != -1) {
        printf("Here are the details of the song:\n");
        display_song(library[found_song_index]);
    } else {
        printf("Sorry, that song is not in the library.\n");
    }
}

int main() {
    struct song library[100];
    int num_songs = 0;
    char choice;
    do {
        printf("\nWelcome to MyMusic Library Management System!\n");
        printf("Here are your options:\n");
        printf("1. Add a new song\n");
        printf("2. Delete a song\n");
        printf("3. Search for a song\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                add_song(library, &num_songs);
                break;
            case '2':
                delete_song(library, &num_songs);
                break;
            case '3':
                search_song(library, num_songs);
                break;
            case '4':
                printf("\nGoodbye! Thank you for using MyMusic Library Management System!\n");
                exit(0);
            default:
                printf("\nSorry, that is not a valid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}