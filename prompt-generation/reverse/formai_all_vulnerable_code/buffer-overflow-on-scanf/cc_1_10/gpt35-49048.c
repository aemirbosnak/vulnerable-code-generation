//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 2000

// Define structure for album
struct album {
    char title[50];
    char artist[50];
    int year;
    int num_songs;
    float rating;
    int song_list[MAX_SONGS];
};

// Declare global variables
struct album music_library[MAX_ALBUMS];
int num_albums = 0;

// Define functions
void add_album() {
    struct album new_album;
    
    // Prompt user for album info
    printf("Enter album title: ");
    scanf("%s", new_album.title);
    
    printf("Enter artist name: ");
    scanf("%s", new_album.artist);
    
    printf("Enter year of release: ");
    scanf("%d", &new_album.year);
    
    printf("Enter rating (out of 5): ");
    scanf("%f", &new_album.rating);
    
    printf("Enter number of songs: ");
    scanf("%d", &new_album.num_songs);
    
    printf("Enter song IDs (separated by spaces): ");
    for (int i = 0; i < new_album.num_songs; i++) {
        scanf("%d", &new_album.song_list[i]);
    }
    
    // Add new album to music library
    music_library[num_albums] = new_album;
    num_albums++;
    
    printf("Album added successfully!\n");
}

void list_albums() {
    // Print header
    printf("Title\t\tArtist\t\tYear\t\tRating\n");
    
    // Print each album's info
    for (int i = 0; i < num_albums; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.1f\n", music_library[i].title, music_library[i].artist, music_library[i].year, music_library[i].rating);
    }
}

void search_album() {
    char query[50];
    int matches = 0;
    
    // Prompt user for album title search query
    printf("Enter album title search query: ");
    scanf("%s", query);
    
    // Search for matching albums
    for (int i = 0; i < num_albums; i++) {
        if (strstr(music_library[i].title, query)) {
            // Print album info
            printf("%s by %s (%d)\n", music_library[i].title, music_library[i].artist, music_library[i].year);
            
            // Print song info
            for (int j = 0; j < music_library[i].num_songs; j++) {
                printf("\t%d. Song %d\n", j+1, music_library[i].song_list[j]);
            }
            
            matches++;
        }
    }
    
    // Print number of matches found
    printf("%d match(es) found.\n", matches);
}

void display_menu() {
    printf("\n===== Music Library Management System =====\n");
    printf("1. Add album\n");
    printf("2. List albums\n");
    printf("3. Search album\n");
    printf("4. Exit\n");
    printf("==========================================\n\n");
}

int main() {
    int choice;
    
    printf("\n================= Welcome to the Music Library Management System! =================\n");
    
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                list_albums();
                break;
            case 3:
                search_album();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select one of the options from the menu.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}