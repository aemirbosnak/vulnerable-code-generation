//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct for music
typedef struct {
    char title[50];
    char artist[50];
    int year;
} Music;

// function prototypes
void add_music(Music *music_collection, int *num_of_music);
void delete_music(Music *music_collection, int *num_of_music);
void search_music(Music *music_collection, int num_of_music);
void print_music_catalogue(Music *music_collection, int num_of_music);

// main function
int main() {
    int choice, num_of_music = 0;
    Music music_collection[100];
    
    printf("Welcome to the Music Library Management System!\n");
    
    do {
        // display menu
        printf("\n------------------------\n");
        printf("1. Add Music\n");
        printf("2. Delete Music\n");
        printf("3. Search Music\n");
        printf("4. Print Music Catalogue\n");
        printf("5. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_music(music_collection, &num_of_music);
                break;
            case 2:
                delete_music(music_collection, &num_of_music);
                break;
            case 3:
                search_music(music_collection, num_of_music);
                break;
            case 4:
                print_music_catalogue(music_collection, num_of_music);
                break;
            case 5:
                printf("Exiting Music Library Management System...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 5.\n");
                break;
        }
        
    } while (choice != 5);
    
    return 0;
}

// function to add new music to the collection
void add_music(Music *music_collection, int *num_of_music) {
    char title[50], artist[50];
    int year;
    
    // prompt for user input
    printf("\nEnter the title of the music: ");
    scanf(" %[^\n]s", title);
    printf("Enter the artist's name: ");
    scanf(" %[^\n]s", artist);
    printf("Enter the year of release: ");
    scanf(" %d", &year);
    
    // create new music object and add it to the collection
    Music new_music = {strcpy(new_music.title, title), strcpy(new_music.artist, artist), year};
    music_collection[(*num_of_music)++] = new_music;
    
    printf("\nMusic added successfully!\n");
}

// function to delete music from the collection
void delete_music(Music *music_collection, int *num_of_music) {
    char title[50], artist[50];
    int year, found = 0;
    int i, j;
    
    // prompt for user input
    printf("\nEnter the title of the music to delete: ");
    scanf(" %[^\n]s", title);
    printf("Enter the artist's name: ");
    scanf(" %[^\n]s", artist);
    printf("Enter the year of release: ");
    scanf(" %d", &year);
    
    // search for the music to be deleted
    for (i = 0; i < *num_of_music; i++) {
        if (strcmp(music_collection[i].title, title) == 0 && strcmp(music_collection[i].artist, artist) == 0 && music_collection[i].year == year) {
            found = 1;
            break;
        }
    }
    
    // delete music and adjust array
    if (found) {
        for (j = i; j < *num_of_music - 1; j++) {
            music_collection[j] = music_collection[j + 1];
        }
        (*num_of_music)--;
        printf("\nMusic deleted successfully!\n");
    } else {
        printf("\nMusic not found.\n");
    }
}

// function to search for music in the collection
void search_music(Music *music_collection, int num_of_music) {
    char keyword[50];
    int i;
    
    // prompt for user input
    printf("\nEnter keyword to search for: ");
    scanf(" %[^\n]s", keyword);
    
    // search for music and display results
    printf("\nResults for '%s':\n", keyword);
    for (i = 0; i < num_of_music; i++) {
        if (strstr(music_collection[i].title, keyword) != NULL || strstr(music_collection[i].artist, keyword) != NULL) {
            printf("%2d. %-30s by %-20s Released in %d\n", i+1, music_collection[i].title, music_collection[i].artist, music_collection[i].year);
        }
    }
}

// function to print the entire music catalogue
void print_music_catalogue(Music *music_collection, int num_of_music) {
    int i;
    
    // display all music in catalogue
    printf("\n%-2s| %-30s | %-20s | %s\n", "No", "Title", "Artist", "Year");
    printf("--|------------------------------|----------------------|------\n");
    for (i = 0; i < num_of_music; i++) {
        printf("%-2d| %-30s | %-20s | %d\n", i+1, music_collection[i].title, music_collection[i].artist, music_collection[i].year);
    }
}