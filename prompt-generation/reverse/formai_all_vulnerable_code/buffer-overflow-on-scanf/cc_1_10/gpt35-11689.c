//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
} Song;

void add_song(Song[], int*);
void remove_song(Song[], int*);
void display_songs(Song[], int*);

int main() {
    Song library[MAX_SONGS];
    int num_songs = 0;
    int choice;

    printf("Welcome to the C Music Library Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Display all songs\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                remove_song(library, &num_songs);
                break;
            case 3:
                display_songs(library, &num_songs);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void add_song(Song library[], int *num_songs) {
    if(*num_songs == MAX_SONGS) {
        printf("\nThe library is full! No more songs can be added.\n");
        return;
    }

    printf("\nEnter the following information about the song:\n");

    printf("Title: ");
    scanf("%s", library[*num_songs].title);

    printf("Artist: ");
    scanf("%s", library[*num_songs].artist);

    printf("Album: ");
    scanf("%s", library[*num_songs].album);

    printf("Year: ");
    scanf("%d", &library[*num_songs].year);

    printf("Duration (in minutes): ");
    scanf("%f", &library[*num_songs].duration);

    printf("\nSong added successfully!\n");

    (*num_songs)++;
}

void remove_song(Song library[], int *num_songs) {
    char title[50];
    int found = 0;
    int i;

    printf("\nEnter the title of the song you want to remove: ");
    scanf("%s", title);

    for(i = 0; i < *num_songs; i++) {
        if(strcmp(title, library[i].title) == 0) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(; i < *num_songs - 1; i++) {
            library[i] = library[i+1];
        }

        (*num_songs)--;

        printf("\n%s by %s has been removed from the library.\n", title, library[i].artist);
    } else {
        printf("\n%s was not found in the library!\n", title);
    }
}

void display_songs(Song library[], int *num_songs) {
    int i;

    printf("\nThere are currently %d songs in the library:\n", *num_songs);

    for(i = 0; i < *num_songs; i++) {
        printf("\nTitle: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Album: %s\n", library[i].album);
        printf("Year: %d\n", library[i].year);
        printf("Duration: %.2f minutes\n", library[i].duration);
    }
}