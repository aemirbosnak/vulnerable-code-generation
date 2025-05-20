//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
// C Music Library Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store details of each song
struct song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

// Function to display menu
void displayMenu() {
    printf("\nWelcome to C Music Library Management System!\n");
    printf("1. Add Song\n");
    printf("2. Display All Songs\n");
    printf("3. Search for a Song\n");
    printf("4. Remove a Song\n");
    printf("5. Edit Song Details\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a song
void addSong(struct song all_songs[], int *num_of_songs) {
    printf("\nEnter details of the song:\n");
    printf("Title: ");
    scanf(" %[^\n]", all_songs[*num_of_songs].title);
    printf("Artist: ");
    scanf(" %[^\n]", all_songs[*num_of_songs].artist);
    printf("Album: ");
    scanf(" %[^\n]", all_songs[*num_of_songs].album);
    printf("Year of Release: ");
    scanf("%d", &all_songs[*num_of_songs].year);
    (*num_of_songs)++;
    printf("\nSong Added Successfully!\n");
}

// Function to display all songs
void displayAllSongs(struct song all_songs[], int num_of_songs) {
    printf("\nList of All Songs:\n");
    for (int i = 0; i < num_of_songs; i++) {
        printf("\nTitle: %s\n", all_songs[i].title);
        printf("Artist: %s\n", all_songs[i].artist);
        printf("Album: %s\n", all_songs[i].album);
        printf("Year of Release: %d\n", all_songs[i].year);
    }
}

// Function to search for a song
void searchSong(struct song all_songs[], int num_of_songs) {
    char search_title[100];
    printf("\nEnter the title of the song to search: ");
    scanf(" %[^\n]", search_title);
    for (int i = 0; i < num_of_songs; i++) {
        if (strcmp(search_title, all_songs[i].title) == 0) {
            printf("\nSong Found!\n");
            printf("Title: %s\n", all_songs[i].title);
            printf("Artist: %s\n", all_songs[i].artist);
            printf("Album: %s\n", all_songs[i].album);
            printf("Year of Release: %d\n", all_songs[i].year);
            return;
        }
    }
    printf("\nSong Not Found!\n");
}

// Function to remove a song
void removeSong(struct song all_songs[], int *num_of_songs) {
    char remove_title[100];
    printf("\nEnter the title of the song to remove: ");
    scanf(" %[^\n]", remove_title);
    for (int i = 0; i < *num_of_songs; i++) {
        if (strcmp(remove_title, all_songs[i].title) == 0) {
            for (int j = i; j < *num_of_songs - 1; j++) {
                all_songs[j] = all_songs[j+1];
            }
            (*num_of_songs)--;
            printf("\nSong Removed Successfully!\n");
            return;
        }
    }
    printf("\nSong Not Found!\n");
}

// Function to edit song details
void editSong(struct song all_songs[], int num_of_songs) {
    char edit_title[100];
    printf("\nEnter the title of the song to edit: ");
    scanf(" %[^\n]", edit_title);
    for (int i = 0; i < num_of_songs; i++) {
        if (strcmp(edit_title, all_songs[i].title) == 0) {
            printf("\nEnter new details of the song:\n");
            printf("Title: ");
            scanf(" %[^\n]", all_songs[i].title);
            printf("Artist: ");
            scanf(" %[^\n]", all_songs[i].artist);
            printf("Album: ");
            scanf(" %[^\n]", all_songs[i].album);
            printf("Year of Release: ");
            scanf("%d", &all_songs[i].year);
            printf("\nSong Details Edited Successfully!\n");
            return;
        }
    }
    printf("\nSong Not Found!\n");
}

// Main function
int main() {

    int num_of_songs = 0;
    struct song all_songs[100];

    while (1) {
        displayMenu();
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addSong(all_songs, &num_of_songs);
                break;
            case 2:
                displayAllSongs(all_songs, num_of_songs);
                break;
            case 3:
                searchSong(all_songs, num_of_songs);
                break;
            case 4:
                removeSong(all_songs, &num_of_songs);
                break;
            case 5:
                editSong(all_songs, num_of_songs);
                break;
            case 6:
                printf("\nThank you for using C Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Please select a valid option.\n");
        }
    }

    return 0;
}