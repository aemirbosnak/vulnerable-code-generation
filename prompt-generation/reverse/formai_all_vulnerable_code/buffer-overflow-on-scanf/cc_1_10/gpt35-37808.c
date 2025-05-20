//FormAI DATASET v1.0 Category: Music Library Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 1000

// Define structures
typedef struct song {
    char title[50];
    char artist[50];
    int year;
} Song;

// Declare functions
void add_song(Song[], int*);
int search_song(Song[], char[], int);
void edit_song(Song[], int);
void delete_song(Song[], int*);

int main() {
    Song library[MAX_SONGS];
    int num_songs = 0;
    int choice = 0;
    char search_title[50];
    int search_index;
    
    printf("Welcome to the C Music Library Management System!\n");
    printf("What would you like to do?\n");
    
    do {
        printf("\n1. Add a song\n2. Search for a song\n3. Edit a song\n4. Delete a song\n5. Quit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                printf("Enter the title of the song you are searching for: ");
                scanf("%s", search_title);
                search_index = search_song(library, search_title, num_songs);
                if (search_index != -1) {
                    printf("\n%s by %s (%d)\n", library[search_index].title, library[search_index].artist, library[search_index].year);
                } else {
                    printf("\nSong not found.\n");
                }
                break;
            case 3:
                edit_song(library, num_songs);
                break;
            case 4:
                delete_song(library, &num_songs);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}

// Function to add a song
void add_song(Song library[], int *num_songs) {
    if (*num_songs == MAX_SONGS) {
        printf("The library is full. No more songs can be added.\n");
    } else {
        printf("\nEnter the song title: ");
        scanf("%s", library[*num_songs].title);
        printf("Enter the artist name: ");
        scanf("%s", library[*num_songs].artist);
        printf("Enter the year the song was released: ");
        scanf("%d", &library[*num_songs].year);
        *num_songs += 1;
        printf("\nSong added successfully!\n");
    }
}

// Function to search for a song
int search_song(Song library[], char search_title[], int num_songs) {
    int i;
    for (i = 0; i < num_songs; i++) {
        if (strcmp(search_title, library[i].title) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to edit a song
void edit_song(Song library[], int num_songs) {
    char edit_title[50];
    int edit_index;
    printf("Enter the title of the song you want to edit: ");
    scanf("%s", edit_title);
    edit_index = search_song(library, edit_title, num_songs);
    if (edit_index != -1) {
        printf("\n%s by %s (%d)\n", library[edit_index].title, library[edit_index].artist, library[edit_index].year);
        printf("\nEnter the updated title (or press enter to keep the same): ");
        scanf("%s", library[edit_index].title);
        printf("Enter the updated artist name (or press enter to keep the same): ");
        scanf("%s", library[edit_index].artist);
        printf("Enter the updated year (or enter 0 to keep the same): ");
        scanf("%d", &library[edit_index].year);
        printf("\nSong updated successfully!\n");
    } else {
        printf("\nSong not found.\n");
    }
}

// Function to delete a song
void delete_song(Song library[], int *num_songs) {
    char delete_title[50];
    int delete_index, i;
    printf("Enter the title of the song you want to delete: ");
    scanf("%s", delete_title);
    delete_index = search_song(library, delete_title, *num_songs);
    if (delete_index != -1) {
        for (i = delete_index; i < *num_songs - 1; i++) {
            library[i] = library[i + 1];
        }
        *num_songs -= 1;
        printf("\nSong deleted successfully!\n");
    } else {
        printf("\nSong not found.\n");
    }
}