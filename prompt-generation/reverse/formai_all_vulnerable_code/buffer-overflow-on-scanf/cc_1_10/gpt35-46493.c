//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 100 // maximum length for string inputs
#define MAX_ALBUMS 100 // maximum number of albums allowed

typedef struct album {
    char title[MAX_LEN];
    char artist[MAX_LEN];
    char genre[MAX_LEN];
    int release_year;
    int num_songs;
    float rating;
} Album;

Album albums[MAX_ALBUMS];
int num_albums = 0;

void add_album() {
    if (num_albums == MAX_ALBUMS) {
        printf("Maximum number of albums reached. Cannot add more.\n");
        return;
    }
    
    Album new_album;
    printf("Enter album title: ");
    fgets(new_album.title, MAX_LEN, stdin);
    new_album.title[strcspn(new_album.title, "\n")] = '\0'; // remove newline character
    
    printf("Enter artist name: ");
    fgets(new_album.artist, MAX_LEN, stdin);
    new_album.artist[strcspn(new_album.artist, "\n")] = '\0'; // remove newline character
    
    printf("Enter genre: ");
    fgets(new_album.genre, MAX_LEN, stdin);
    new_album.genre[strcspn(new_album.genre, "\n")] = '\0'; // remove newline character
    
    printf("Enter release year: ");
    scanf("%d", &new_album.release_year);
    
    printf("Enter number of songs: ");
    scanf("%d", &new_album.num_songs);
    
    printf("Enter album rating (out of 5): ");
    scanf("%f", &new_album.rating);
    getchar(); // clear input buffer
    
    albums[num_albums] = new_album;
    num_albums++;
    printf("Album added successfully.\n");
}

void show_albums() {
    if (num_albums == 0) {
        printf("No albums found.\n");
        return;
    }
    
    printf("%-4s %-20s %-20s %-20s %-10s %-10s %-4s\n", "ID", "Title", "Artist", "Genre", "Year", "Songs", "Rating");
    for (int i = 0; i < num_albums; i++) {
        printf("%-4d %-20s %-20s %-20s %-10d %-10d %.2f\n", i+1, albums[i].title, albums[i].artist, albums[i].genre, albums[i].release_year, albums[i].num_songs, albums[i].rating);
    }
}

int main() {
    printf("Welcome to Music Library Management System!\n");
    printf("-------------------------------------------\n");
    
    while (1) {
        printf("\nOptions:\n");
        printf("1. Add album\n");
        printf("2. Show all albums\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // clear input buffer
        
        switch(choice) {
            case 1:
                add_album();
                break;
            case 2:
                show_albums();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}