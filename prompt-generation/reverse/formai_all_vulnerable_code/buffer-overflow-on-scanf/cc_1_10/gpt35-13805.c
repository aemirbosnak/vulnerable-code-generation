//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SONGS 100
#define MAX_NAME_LEN 50
#define MAX_ARTIST_LEN 50

struct song {
    char name[MAX_NAME_LEN];
    char artist[MAX_ARTIST_LEN];
    int rating;
};

void add_song();
void remove_song();
void view_library();

int total_songs = 0;
struct song library[MAX_SONGS];

int main() {
    int choice;

    printf("Welcome to the Music Library Management System!\n");

    do {
        printf("\nMenu:\n1. Add a Song\n2. Remove a Song\n3. View the Library\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song();
                break;
            case 2:
                remove_song();
                break;
            case 3:
                view_library();
                break;
            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void add_song() {
    if (total_songs == MAX_SONGS) {
        printf("Cannot add more songs. Maximum limit reached!\n");
        return;
    }

    struct song new_song;
    printf("Enter song name: ");
    scanf("%s", new_song.name);
    printf("Enter artist name: ");
    scanf("%s", new_song.artist);
    printf("Enter rating (1-5): ");
    scanf("%d", &new_song.rating);

    library[total_songs++] = new_song;

    printf("Song added successfully!\n");
}

void remove_song() {
    char name[MAX_NAME_LEN];
    printf("Enter the name of the song you want to remove: ");
    scanf("%s", name);

    int index = -1;
    for (int i = 0; i < total_songs; i++) {
        if (strcmp(library[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found!\n");
        return;
    }

    for (int i = index; i < total_songs - 1; i++) {
        library[i] = library[i+1];
    }

    total_songs--;

    printf("Song removed successfully!\n");
}

void view_library() {
    printf("Name\t\tArtist\t\tRating\n-----------------------------------------------\n");

    for (int i = 0; i < total_songs; i++) {
        printf("%s\t\t%s\t\t%d\n", library[i].name, library[i].artist, library[i].rating);
    }

    if (total_songs == 0) {
        printf("The library is empty.\n");
    }
}