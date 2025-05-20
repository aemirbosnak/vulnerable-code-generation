//FormAI DATASET v1.0 Category: Music Library Management System ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

// Define the maximum number of songs
#define MAX_SONGS 100

// Define the size of song name
#define MAX_NAME_LENGTH 50

// Define the size of artist name
#define MAX_ARTIST_LENGTH 50

struct Song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int rating;
};

// Function prototypes
void print_menu();
void add_song(struct Song song_array[], int *song_count);
void edit_song(struct Song song_array[], int song_count);
void delete_song(struct Song song_array[], int *song_count);
void search_song(struct Song song_array[], int song_count);
void display_songs(struct Song song_array[], int song_count);

int main() {

    struct Song songs[MAX_SONGS];
    int song_count = 0;
    int choice;
    
    while(1) {
        print_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_song(songs, &song_count);
                break;
            case 2:
                edit_song(songs, song_count);
                break;
            case 3:
                delete_song(songs, &song_count);
                break;
            case 4:
                search_song(songs, song_count);
                break;
            case 5:
                display_songs(songs, song_count);
                break;
            case 6:
                // Exit the program
                printf("Exiting from the program!\n");
                return 0;
            default:
                printf("Invalid Choice! Please enter a valid choice\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n\n");
    printf("************** C Music Library Management System **************\n");
    printf("*                                                            *\n");
    printf("*   1. Add New Song                                          *\n");
    printf("*   2. Edit Song                                              *\n");
    printf("*   3. Delete Song                                            *\n");
    printf("*   4. Search Song                                            *\n");
    printf("*   5. Display All Songs                                      *\n");
    printf("*   6. Exit                                                   *\n");
    printf("*                                                            *\n");
    printf("****************************************************************\n");
    printf("\n");
    printf("Enter your choice: ");
}

// Function to add a new Song
void add_song(struct Song song_array[], int *song_count) {
    printf("\n\n");

    // Check if there is enough space in the song_array
    if(*song_count >= MAX_SONGS) {
        printf("Error: Maximum Song Capacity (%d) reached. Unable to add a new Song.\n", MAX_SONGS);
        return;
    }

    // Read user input for song name, artist name and rating
    printf("Enter the name of the Song: ");
    scanf(" %[^\n]%*c", song_array[*song_count].name);
    printf("Enter the name of the Artist: ");
    scanf(" %[^\n]%*c", song_array[*song_count].artist);
    printf("Enter the rating of the Song (1 - 5): ");
    scanf("%d", &song_array[*song_count].rating);

    // Increase the song count by 1
    *song_count += 1;

    // Print a success message
    printf("The song is added successfully.\n");
}

// Function to edit a song
void edit_song(struct Song song_array[], int song_count) {
    printf("\n\n");

    // Check if the song_array is empty
    if(song_count == 0) {
        printf("Error: No Songs Available to Edit.\n");
        return;
    }

    char song_name[MAX_NAME_LENGTH];
    int i, found = 0;

    // Read the song name to be edited
    printf("Enter the name of the Song to be edited: ");
    scanf(" %[^\n]%*c", song_name);

    // Loop through all the songs in song_array and find the first occurrence of the song_name
    for(i=0; i<song_count; i++) {
        if(strcmp(song_name, song_array[i].name) == 0) {
            // If the song_name is found, read new values for song name, artist name and rating
            printf("Enter the new name of the Song: ");
            scanf(" %[^\n]%*c", song_array[i].name);
            printf("Enter the new name of the Artist: ");
            scanf(" %[^\n]%*c", song_array[i].artist);
            printf("Enter the new rating of the Song (1 - 5): ");
            scanf("%d", &song_array[i].rating);

            // Set the found variable to true
            found = 1;
            break;
        }
    }

    // If the song_name is not found, print an error message
    if(!found) {
        printf("Error: Song not Found!\n");
    } else {
        printf("The song is edited successfully.\n");
    }
}

// Function to delete a song
void delete_song(struct Song song_array[], int *song_count) {
    printf("\n\n");

    // Check if the song_array is empty
    if(*song_count == 0) {
        printf("Error: No Songs Available to Delete.\n");
        return;
    }

    char song_name[MAX_NAME_LENGTH];
    int i, j, found = 0;

    // Read the song name to be deleted
    printf("Enter the name of the Song to be deleted: ");
    scanf(" %[^\n]%*c", song_name);

    // Loop through all the songs in song_array and find the first occurrence of the song_name
    for(i=0; i<*song_count; i++) {
        if(strcmp(song_name, song_array[i].name) == 0) {
            // If the song_name is found, shift all the songs to the left by one position
            for(j=i; j<((*song_count)-1); j++) {
                strcpy(song_array[j].name, song_array[j+1].name);
                strcpy(song_array[j].artist, song_array[j+1].artist);
                song_array[j].rating = song_array[j+1].rating;
            }

            // Decrease the song count by 1
            *song_count -= 1;

            // Set the found variable to true
            found = 1;
            break;
        }
    }

    // If the song_name is not found, print an error message
    if(!found) {
        printf("Error: Song not Found!\n");
    } else {
        printf("The song is deleted successfully.\n");
    }
}

// Function to search a song by name
void search_song(struct Song song_array[], int song_count) {
    printf("\n\n");

    // Check if the song_array is empty
    if(song_count == 0) {
        printf("Error: No Songs Available to Search.\n");
        return;
    }

    char song_name[MAX_NAME_LENGTH];
    int i, found = 0;

    // Read the song name to be searched
    printf("Enter the name of the Song to be searched: ");
    scanf(" %[^\n]%*c", song_name);

    // Loop through all the songs in song_array and find the first occurrence of the song_name
    for(i=0; i<song_count; i++) {
        if(strcmp(song_name, song_array[i].name) == 0) {
            // If the song_name is found, print the song name, artist name and rating
            printf("\nSong Name: %s\n", song_array[i].name);
            printf("Artist Name: %s\n", song_array[i].artist);
            printf("Rating: %d\n", song_array[i].rating);

            // Set the found variable to true
            found = 1;
            break;
        }
    }

    // If the song_name is not found, print an error message
    if(!found) {
        printf("Error: Song not Found!\n");
    }
}

// Function to display all the songs in song_array
void display_songs(struct Song song_array[], int song_count) {
    printf("\n\n");

    // Check if the song_array is empty
    if(song_count == 0) {
        printf("Error: No Songs Available to Display.\n");
        return;
    }

    int i;
    // Print the headings for song name, artist name and rating
    printf("%-30s %-30s %-10s\n", "Song Name", "Artist Name", "Rating");
    printf("------------------------------------------------------------------------\n");

    // Loop through all the songs in song_array and print the song name, artist name and rating
    for(i=0; i<song_count; i++) {
        printf("%-30s %-30s %-10d\n", song_array[i].name, song_array[i].artist, song_array[i].rating);
    }
}