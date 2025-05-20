//FormAI DATASET v1.0 Category: Music Library Management System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct music {
    char title[50];
    char artist[50];
    int rating;
    int is_favorite;
} Music;

int main(){
    int menu_choice;
    int library_size = 0;
    Music* library = NULL;
    char temp_title[50], temp_artist[50];
    int temp_rating, temp_is_favorite;

    printf("Welcome to the Music Library Management System\n");

    do {
        // Display menu
        printf("\nMain Menu:");
        printf("\n1. Add a song");
        printf("\n2. Edit a song");
        printf("\n3. Remove a song");
        printf("\n4. Print all songs");
        printf("\n5. Quit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &menu_choice);

        // Handle menu choice
        switch(menu_choice) {
            case 1: // Add a song
                library_size++;
                library = (Music*)realloc(library, library_size*sizeof(Music));
                printf("\nEnter song title: ");
                scanf("%s", temp_title);
                strcpy(library[library_size-1].title, temp_title);
                printf("Enter song artist: ");
                scanf("%s", temp_artist);
                strcpy(library[library_size-1].artist, temp_artist);
                printf("Enter song rating (1-5): ");
                scanf("%d", &temp_rating);
                while(temp_rating < 1 || temp_rating > 5) { // Validate rating input
                    printf("Invalid rating. Enter a number between 1 and 5: ");
                    scanf("%d", &temp_rating);
                }
                library[library_size-1].rating = temp_rating;
                printf("Is this song a favorite? (0=no, 1=yes): ");
                scanf("%d", &temp_is_favorite);
                while(temp_is_favorite != 0 && temp_is_favorite != 1) { // Validate favorite input
                    printf("Invalid input. Enter 0 (no) or 1 (yes): ");
                    scanf("%d", &temp_is_favorite);
                }
                library[library_size-1].is_favorite = temp_is_favorite;
                break;
            case 2: // Edit a song
                if (library_size == 0) { // Check if library is empty
                    printf("Your library is empty.\n");
                }
                else {
                    int song_choice;
                    printf("\nChoose a song to edit (1-%d): ", library_size);
                    scanf("%d", &song_choice);
                    while(song_choice < 1 || song_choice > library_size) { // Validate song choice input
                        printf("Invalid input. Enter a number between 1 and %d: ", library_size);
                        scanf("%d", &song_choice);
                    }
                    printf("\nEnter the new song title: ");
                    scanf("%s", temp_title);
                    strcpy(library[song_choice-1].title, temp_title);
                    printf("Enter the new song artist: ");
                    scanf("%s", temp_artist);
                    strcpy(library[song_choice-1].artist, temp_artist);
                    printf("Enter the new song rating (1-5): ");
                    scanf("%d", &temp_rating);
                    while(temp_rating < 1 || temp_rating > 5) { // Validate rating input
                        printf("Invalid rating. Enter a number between 1 and 5: ");
                        scanf("%d", &temp_rating);
                    }
                    library[song_choice-1].rating = temp_rating;
                    printf("Is this song now a favorite? (0=no, 1=yes): ");
                    scanf("%d", &temp_is_favorite);
                    while(temp_is_favorite != 0 && temp_is_favorite != 1) { // Validate favorite input
                        printf("Invalid input. Enter 0 (no) or 1 (yes): ");
                        scanf("%d", &temp_is_favorite);
                    }
                    library[song_choice-1].is_favorite = temp_is_favorite;
                    printf("\nSong #%d successfully edited.\n", song_choice);
                }
                break;
            case 3: // Remove a song
                if (library_size == 0) { // Check if library is empty
                    printf("Your library is empty.\n");
                }
                else {
                    int song_choice;
                    printf("\nChoose a song to remove (1-%d): ", library_size);
                    scanf("%d", &song_choice);
                    while(song_choice < 1 || song_choice > library_size) { // Validate song choice input
                        printf("Invalid input. Enter a number between 1 and %d: ", library_size);
                        scanf("%d", &song_choice);
                    }
                    for (int i=song_choice-1; i<library_size-1; i++) { // Shift array elements left
                        strcpy(library[i].title, library[i+1].title);
                        strcpy(library[i].artist, library[i+1].artist);
                        library[i].rating = library[i+1].rating;
                        library[i].is_favorite = library[i+1].is_favorite;
                    }
                    library_size--;
                    library = (Music*)realloc(library, library_size*sizeof(Music));
                    printf("\nSong #%d successfully removed.\n", song_choice);
                }
                break;
            case 4: // Print all songs
                if (library_size == 0) { // Check if library is empty
                    printf("Your library is empty.\n");
                }
                else {
                    printf("\n%-25s%-25s%-10s%-10s\n", "Title", "Artist", "Rating", "Favorite");
                    printf("----------------------------------------------------\n");
                    for (int i=0; i<library_size; i++) {
                        printf("%-25s%-25s%-10d%-10s\n", library[i].title, library[i].artist, library[i].rating, library[i].is_favorite == 1 ? "Yes" : "No"); // Print "Yes" if is_favorite is 1, otherwise "No"
                    }
                }
                break;
            case 5: // Quit
                printf("\nGoodbye!\n");
                break;
            default: // Handle invalid choice input
                printf("\nInvalid choice. Enter a number between 1 and 5.\n");
                break;
        }

    } while(menu_choice != 5);

    free(library);
    return 0;
}