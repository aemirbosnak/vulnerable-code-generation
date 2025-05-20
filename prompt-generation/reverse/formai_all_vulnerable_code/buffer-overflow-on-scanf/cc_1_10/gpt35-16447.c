//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    int year;
} Song;

void print_menu();
void add_song(Song *lib, int *size);
void search_song(Song *lib, int size);
void print_songs(Song *lib, int size);

int main() {
    Song library[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_song(library, &size); break;
            case 2: search_song(library, size); break;
            case 3: print_songs(library, size); break;
            case 4: printf("Exiting program..."); break;
            default: printf("Invalid choice! Try again.");
        }
    } while(choice != 4);

    return 0;
}

void print_menu() {
    printf("\n-----Music Library Management System-----");
    printf("\n1. Add a song");
    printf("\n2. Search for a song");
    printf("\n3. Print all songs");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

void add_song(Song *lib, int *size) {
    printf("\n-----Adding a song-----");
    printf("\nEnter the title: ");
    scanf(" %[^\n]s", lib[*size].title);
    printf("Enter the artist: ");
    scanf(" %[^\n]s", lib[*size].artist);
    printf("Enter the genre: ");
    scanf(" %[^\n]s", lib[*size].genre);
    printf("Enter the year: ");
    scanf("%d", &lib[*size].year);
    (*size)++;
    printf("Song successfully added!");
}

void search_song(Song *lib, int size) {
    char title[MAX_SIZE];
    int i, found = 0;
    printf("\n-----Searching for a song-----");
    printf("\nEnter the title: ");
    scanf(" %[^\n]s", title);

    for(i = 0; i < size; i++) {
        if(strcmp(title, lib[i].title) == 0) {
            printf("\nSong found!");
            printf("\nTitle: %s", lib[i].title);
            printf("\nArtist: %s", lib[i].artist);
            printf("\nGenre: %s", lib[i].genre);
            printf("\nYear: %d\n", lib[i].year);
            found = 1;
        }
    }
    if(!found) {
        printf("\nSong not found!");
    }
}

void print_songs(Song *lib, int size) {
    int i;
    if(size == 0) {
        printf("\nThere are no songs in the library!");
        return;
    }
    printf("\n-----Printing all songs-----");
    for(i = 0; i < size; i++) {
        printf("\nTitle: %s", lib[i].title);
        printf("\nArtist: %s", lib[i].artist);
        printf("\nGenre: %s", lib[i].genre);
        printf("\nYear: %d\n", lib[i].year);
    }
}