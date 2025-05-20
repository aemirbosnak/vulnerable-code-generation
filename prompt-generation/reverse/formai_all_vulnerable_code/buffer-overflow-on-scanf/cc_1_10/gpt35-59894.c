//FormAI DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining the maximum number of records in the library
#define MAX_RECORDS 100

// defining the maximum length of the song name and artist name
#define MAX_NAME_LENGTH 50

// structure of a Song record
typedef struct Song {
    char songName[MAX_NAME_LENGTH];
    char artistName[MAX_NAME_LENGTH];
    int releaseYear;
} Song;

// array of Song records representing a music library
Song musicLibrary[MAX_RECORDS];

// variable to keep track of the number of records in the music library
int numRecords = 0;

// function to add a new Song record to the musicLibrary array
void addSong() {
    // if the musicLibrary is already full
    if (numRecords >= MAX_RECORDS) {
        printf("Music Library is full!\n");
        return;
    }
    
    // prompt user for song name, artist name, and release year
    printf("Enter the Song name: ");
    scanf(" %[^\n]%*c", musicLibrary[numRecords].songName);
    printf("Enter the Artist name: ");
    scanf(" %[^\n]%*c", musicLibrary[numRecords].artistName);
    printf("Enter the Release Year: ");
    scanf("%d", &musicLibrary[numRecords].releaseYear);
    
    // increase the number of records count
    numRecords++;
    
    printf("Song record added successfully!\n");
}

// function to search for a Song record in the musicLibrary array by a given song name
int searchSong(char* songName) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (strcmp(musicLibrary[i].songName, songName) == 0) {
            return i;
        }
    }
    return -1;
}

// function to edit an existing Song record in the musicLibrary array
void editSong() {

    if (numRecords == 0) {
        printf("Music Library is empty!\n");
        return;
    }
    
    char songName[MAX_NAME_LENGTH];
    printf("Enter the Song name to edit: ");
    scanf(" %[^\n]%*c", songName);
    
    // search for the song record in the library
    int index = searchSong(songName);
    if (index == -1) {
        printf("Song '%s' not found!\n", songName);
        return;
    }
    
    // prompt user for new values for song name, artist name, and release year
    printf("Enter new Song name: ");
    scanf(" %[^\n]%*c", musicLibrary[index].songName);
    printf("Enter new Artist name: ");
    scanf(" %[^\n]%*c", musicLibrary[index].artistName);
    printf("Enter new Release Year: ");
    scanf("%d", &musicLibrary[index].releaseYear);

    printf("Song record edited successfully!\n");
}

// function to delete an existing Song record from the musicLibrary array
void deleteSong() {

    if (numRecords == 0) {
        printf("Music Library is empty!\n");
        return;
    }
    
    char songName[MAX_NAME_LENGTH];
    printf("Enter the Song name to delete: ");
    scanf(" %[^\n]%*c", songName);
    
    // search for the song record in the library
    int index = searchSong(songName);
    if (index == -1) {
        printf("Song '%s' not found!\n", songName);
        return;
    }
    
    // shift all records after the deleted record left
    int i;
    for (i = index; i < numRecords - 1; i++) {
        musicLibrary[i] = musicLibrary[i + 1];
    }
    
    // decrease the number of records count
    numRecords--;
    
    printf("Song record deleted successfully!\n");
}

// function to display all the Song records in the musicLibrary array
void displayLibrary() {

    if (numRecords == 0) {
        printf("Music Library is empty!\n");
        return;
    }
    
    // print table headers
    printf("%-30s   %-30s   %-10s\n", "SONG NAME", "ARTIST NAME", "RELEASE YEAR");
    
    // print each record
    int i;
    for (i = 0; i < numRecords; i++) {
        printf("%-30s | %-30s | %-10d\n", musicLibrary[i].songName, musicLibrary[i].artistName, musicLibrary[i].releaseYear);
    }
}

// main function to run the Music Library Management System
int main() {
    
    printf("Welcome to Music Library Management System!\n\n");
    
    while (1) {
        // print menu options
        printf("MENU OPTIONS:\n");
        printf("1. Add a new Song record\n");
        printf("2. Edit an existing Song record\n");
        printf("3. Delete an existing Song record\n");
        printf("4. Display the Music Library\n");
        printf("5. Quit the program\n\n");
        
        // prompt user for option choice
        int choice;
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                editSong();
                break;
            case 3:
                deleteSong();
                break;
            case 4:
                displayLibrary();
                break;
            case 5:
                printf("Thank you for using Music Library Management System!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("\n");
    }
    return 0;
}